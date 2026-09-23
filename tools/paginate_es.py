"""Re-paginate poryscript output so dialog boxes never scroll.

The text box shows 2 lines. When a paragraph wraps to 3+ lines, poryscript
continues with \\n / \\l, which makes the game scroll and repeat the last line
at the top of the next box. Longer (e.g. Spanish) texts hit this far more
often, so every paragraph is regrouped into pages of 2 lines separated by \\p.

Usage: python3 paginate_es.py file.inc
"""
import re
import sys

STRING = re.compile(r'^(\s*)\.string "(.*)"\s*$')
SEP = re.compile(r'(\\n|\\l|\\p|\$)')


def paginate(text):
    parts = SEP.split(text)
    out = []
    lines_in_page = 0
    # parts alternates: text, sep, text, sep, ..., trailing text
    for i in range(0, len(parts) - 1, 2):
        chunk, sep = parts[i], parts[i + 1]
        if sep in ('\\n', '\\l'):
            lines_in_page += 1
            sep = '\\n' if lines_in_page == 1 else '\\p'
            if sep == '\\p':
                lines_in_page = 0
        else:
            lines_in_page = 0
        out.append((chunk, sep))
    tail = parts[-1] if len(parts) % 2 == 1 else ''
    return out, tail


def process(path):
    src = open(path, encoding='utf-8').read().split('\n')
    result, block, indent = [], [], '\t'

    def flush():
        if not block:
            return
        pieces, tail = paginate(''.join(block))
        for chunk, sep in pieces:
            result.append(f'{indent}.string "{chunk}{sep}"')
        if tail:
            result.append(f'{indent}.string "{tail}"')
        block.clear()

    for line in src:
        m = STRING.match(line)
        if m:
            indent = m.group(1) or '\t'
            block.append(m.group(2))
            # a block ends at the string terminator
            if m.group(2).endswith('$'):
                flush()
            continue
        flush()
        result.append(line)
    flush()
    open(path, 'w', encoding='utf-8', newline='\n').write('\n'.join(result))


if __name__ == '__main__':
    for p in sys.argv[1:]:
        process(p)
