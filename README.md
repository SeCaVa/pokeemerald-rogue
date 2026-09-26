# Emerald Rogue EX — Traducción al castellano

*[English version below](#english-version)*

Traducción no oficial al **castellano de España** de **Emerald Rogue EX v2.2.1a**, el *roguelite* basado en Pokémon Esmeralda creado por **[Pokabbie](https://github.com/Pokabbie/pokeemerald-rogue)**.

> Todo el juego (diseño, programación, contenido, gráficos y equilibrio) es obra de **Pokabbie** y de quienes han colaborado en Emerald Rogue. Este fork **solo traduce los textos y los gráficos con texto** y hace los ajustes de código imprescindibles para que el castellano quepa y se vea bien. Si te gusta el juego, apoya el proyecto original.

La rama que contiene la traducción es **`castellano`**.

---

## Qué está traducido

- **Diálogos de Rogue**: la base, los laboratorios, la tienda de ropa, la panadería, la escuela, los eventos de aventura, los tutoriales, etc.
- **Misiones** y **entrenadores**: nombres de misiones, descripciones y todas las frases de los Líderes, el Alto Mando, los Campeones, los rivales y los equipos villanos.
- **Menús e interfaz**: menú principal, opciones, ajustes de Rogue, tablero de misiones, estadísticas, recuadro del menú START, Pokédex de Rogue, avisos emergentes, personalización del personaje…
- **Combate**: todos los mensajes, los menús de combate, la eficacia de los movimientos, los tipos y los climas.
- **Nombres oficiales** de movimientos, habilidades, objetos, bayas, naturalezas, clases de entrenador y categorías de especie.
- **Descripciones** de movimientos, habilidades, objetos y bayas.
- **Nombres de personajes** con su versión oficial en España (por ejemplo, Blasco, Máximo, Treto o Aria).
- **Textos de sistema de Pokémon Esmeralda que Rogue sigue usando**: guardar partida, interacciones del mapa (rocas, árboles, cascadas, Surf, Buceo), Centro Pokémon, bayas, PC, Repelente, Buscapelea, la presentación del Prof. Abedul y los avisos de la Zona Safari.
- **Gráficos con texto**, tomados de Pokémon Edición Esmeralda en castellano para que se vean igual que en el juego original:
  - "PULSA START" de la pantalla de título.
  - Iconos de tipos y de categorías de concurso, y etiquetas TIPO / POTENC. / PRECIS. / EFECTO.
  - Iconos de estado (ENV, PAR, DOR, CON, QUE, DEB).
  - Pantalla de datos del Pokémon (PERFIL, HABILIDAD, CARACTERÍST., EXPERIENCIA, MOVIMIENTOS, DESCRIPCIÓN…).
  - Ficha de entrenador, menú de las cajas y botones del teclado de nombres.
  - Etiquetas MT, DT y MO del bolsillo de máquinas de la Mochila.
  - Pantalla de intercambio y aviso de emulador poco preciso ("¡AVISO!").
  - Propios de Rogue, redibujados con su mismo estilo de letra: "PS" de la barra de vida, iconos de teratipo (LUCHA, VOLAD, FUEGO…), estados DOR y QUE del marcador de combate y botón "NOTAS" de Voltorb Flip.
  - Lo que no existe en Esmeralda se ha dibujado con las mismas letras: tipos HADA y ASTRAL, estado CGL (congelación), AMISTAD, "MISIONES" del libro de misiones y "A·ABRIR / SELECT·EDITAR" de la Pokédex de Rogue.

### Criterios de la traducción

- **Castellano de España** y terminología oficial de los juegos.
- **Nombres oficiales**:
  - Los nombres y abreviaturas cortas se han comprobado con Pokémon Edición Esmeralda en castellano.
  - Los de generaciones posteriores se han comprobado con [WikiDex](https://www.wikidex.net) y con los datos en castellano de España (idioma `es`) de [PokeAPI](https://pokeapi.co).
- **Descripciones de movimientos y habilidades**:
  - Se usa el texto oficial de los juegos recopilado en [PkParaíso](https://pkparaiso.com): el de 5ª generación y, si no cabe, el de 4ª o el de 3ª (Esmeralda), siempre que describa cómo funciona en Rogue.
  - Si ninguno cabe, se usa la descripción oficial en castellano de España de PokeAPI **resumida** para las ventanas de GBA.
- **Descripciones de objetos**: descripciones oficiales de PokeAPI, resumidas hasta el ancho real del cuadro de la Mochila (102 px, el mismo que en Esmeralda).
- **Textos propios**: donde el texto oficial describe una mecánica que Rogue cambia (congelación, turnos de las ataduras, efectos de Ácido y Triturar…) o se refiere a otro juego, se ha redactado un texto propio.
- **Límites de GBA**:
  - Los nombres largos se abrevian al estilo de los juegos de GBA ("Pantalla Humo", "Colmillo Ven.", "Torm. Arena").
  - Todo se ha medido en píxeles con las fuentes reales del juego para que nada se corte (las descripciones de movimientos, a la ventana más estrecha en que aparecen: la de aprender movimientos).
- **Mensajes de combate** con la estructura del Esmeralda en castellano: "¡Ataque de Zigzagoon bajó!", "¡Defensa de Zigzagoon bajó mucho!".
- **Abreviaturas de características**: PS, Atq, Def, At. Esp, Df. Esp, Vel.

---

## Cambios en el código

Son los cambios mínimos para que la traducción funcione:

| Cambio | Motivo |
|---|---|
| Textos con variante masculina y femenina según el personaje elegido | "¡Bienvenido/a!", "¿Estás listo/a?", "chaval/chavala"… Se usan los códigos de texto nuevos `{MASC}…{FEM}…{ENDG}`. |
| Tildes y eñe en el teclado de nombres | Se añaden á é í ó ú ñ Á É Í Ó Ú Ñ a la página de símbolos, para el nombre del jugador, los motes y las cajas. |
| Nombres de movimiento de hasta 16 caracteres | Muchos nombres oficiales en castellano superan los 12 caracteres. |
| Fuente estrecha en la pantalla de datos del Pokémon | Nombres y descripciones de movimientos, descripción de la habilidad y columna de estadísticas. |
| Categoría de especie en orden castellano | "Pokémon Semilla" en lugar de "Semilla Pokémon". |
| Nombre del Pokémon en su sitio en la pantalla de motes | "¿Mote de Doduo?". |
| Marca de salvaje o rival detrás del nombre | "Zigzagoon salvaje" en lugar de "Salvaje Zigzagoon". |
| Números alineados a la izquierda en el menú START | Las etiquetas en castellano son más largas. |
| Diálogos reorganizados en páginas de 2 líneas | El castellano ocupa más que el inglés. |
| Verbo antes del adverbio en los cambios de características | "bajó mucho" en lugar de "mucho bajó". |
| Cantidad de objetos en la segunda línea de los avisos emergentes | Los nombres de objeto en castellano son más largos y cortaban el "x2". |
| Pista "SELECT·EDITAR" de la Pokédex de Rogue dos casillas más ancha | "EDITAR" es más largo que "EDIT". |
| Cantidades de objetos como "Hiperpoción x3" y bayas como "3 Bayas Zreza" | En castellano el plural no se forma añadiendo una "s" al nombre. |
| Ventana de la habilidad en la pantalla de datos una casilla más ancha | Más espacio para la descripción oficial de la habilidad. |
| Descripciones de los objetos propios de Rogue ajustadas a 102 px | El ancho que realmente se ve en la Mochila. |
| Nombres de habilidad abreviados en la columna de la Pokédex de Rogue | La columna solo mide 62 px; el resumen sigue mostrando el nombre completo. |
| Sin "'s" tras el nombre en el recuadro de habilidad del combate | En castellano no existe ese posesivo. |
| Campo `display_name` para el EO de los Pokémon de regalo | El nombre interno también es el identificador del código. |
| Títulos de misión en fuente estrecha y títulos visibles separados del identificador interno | Para que los títulos traducidos quepan sin romper las misiones. |
| Arreglos para compilar con GCC moderno | `json11` y `scaninc`. |

---

## Cómo compilar

La rama `castellano` se compila igual que Emerald Rogue original:

1. Sigue las instrucciones de [INSTALL.md](INSTALL.md) (traducidas al castellano) para preparar el entorno.
2. Descarga la rama `castellano`.
3. Compila con `make`.

El resultado es una ROM de Emerald Rogue EX en castellano. **Este repositorio no incluye ninguna ROM**: para jugar necesitas tu propia copia de Pokémon Esmeralda y aplicar el parche o compilar el juego.

---

## Qué no está traducido

- **Entradas de la Pokédex**: Emerald Rogue no las incluye en la ROM.
- **Funciones de Pokémon Esmeralda que Rogue no usa**: Sala Unión, Regalo Misterioso, PokéNav, televisión, Frente Batalla y Pase Frontera, Pokédex original, casino, concursos, caja de Pokécubos, Tritura Bayas, decoraciones y los mapas originales de la Zona Safari (textos y gráficos).
- **Logotipos**: el logotipo del título, el de pokeemerald-expansion y el de la Pokédex se dejan como en el original.

Si encuentras un texto sin traducir, cortado o con errores, abre una *issue* en este repositorio.

---

## Créditos

- **Emerald Rogue / Emerald Rogue EX**: [Pokabbie](https://github.com/Pokabbie/pokeemerald-rogue) y colaboradores. Todo el mérito del juego es suyo.
- **pokeemerald-expansion**: [RHH (ROM Hacking Hideout)](https://github.com/rh-hideout/pokeemerald-expansion) y su [lista de colaboradores](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits). Emerald Rogue se basa en su proyecto.
- **pokeemerald**: el proyecto de descompilación de [pret](https://github.com/pret/pokeemerald).
- **Datos de referencia**: [PokeAPI](https://pokeapi.co), [PkParaíso](https://pkparaiso.com) y [WikiDex](https://www.wikidex.net) para los nombres y las descripciones oficiales en castellano; Pokémon Edición Esmeralda en castellano para los nombres cortos, los mensajes de sistema y los gráficos con texto.
- **Traducción al castellano**: SeCaVa, con ayuda de Claude (Anthropic).

El README original del proyecto se conserva en [README_ORIGINAL.md](README_ORIGINAL.md).

---

## Aviso legal

Proyecto hecho por fans y sin ánimo de lucro. No está afiliado ni respaldado por Nintendo, Game Freak, The Pokémon Company, Pokabbie ni RHH. Pokémon y todos los nombres relacionados son marcas registradas de sus respectivos propietarios. Este repositorio no distribuye ROMs.

---
---

## English version

Unofficial **Castilian Spanish** (Spain) translation of **Emerald Rogue EX v2.2.1a**, the Pokémon Emerald-based *roguelite* created by **[Pokabbie](https://github.com/Pokabbie/pokeemerald-rogue)**.

> The whole game (design, programming, content, graphics and balance) is the work of **Pokabbie** and the Emerald Rogue contributors. This fork **only translates the text and the graphics that contain text**, plus the minimum code changes needed for Spanish to fit and display correctly. If you enjoy the game, please support the original project.

The translation lives in the **`castellano`** branch.

### What is translated

- **Rogue dialogue**: the hub, the labs, the clothes shop, the bakery, the school, adventure events, tutorials, etc.
- **Quests** and **trainers**: quest names, descriptions and every line of the Gym Leaders, Elite Four, Champions, rivals and villain teams.
- **Menus and UI**: main menu, options, Rogue settings, quest board, stats, START menu info box, Rogue Pokédex, pop-ups, character customisation…
- **Battle**: all messages, battle menus, move effectiveness, types and weather.
- **Official Spanish names** of moves, abilities, items, berries, natures, trainer classes and species categories.
- **Descriptions** of moves, abilities, items and berries.
- **Character names** using their official Spanish (Spain) versions (e.g. Blasco, Máximo, Treto, Aria).
- **Pokémon Emerald system text still used by Rogue**: saving, map interactions (rocks, trees, waterfalls, Surf, Dive), Pokémon Center, berries, PC, Repel, VS Seeker, Prof. Birch's introduction and Safari Zone prompts.
- **Graphics containing text**, taken from the Spanish release of Pokémon Emerald so they look like the original game: "PULSA START", type and contest icons, TIPO / POTENC. / PRECIS. / EFECTO labels, status icons, summary screen, trainer card, PC box menu, naming screen buttons, the MT / DT / MO labels in the Bag, the trade screen and the inaccurate-emulator warning ("¡AVISO!"). Rogue's own graphics were redrawn in their original lettering: the "PS" (HP) label on the health bar, the Tera type icons, the DOR/QUE (sleep/burn) battle status labels and Voltorb Flip's "NOTAS" button. Graphics that don't exist in Emerald (Fairy and Stellar types, frostbite status, friendship label, the quest book title and the Rogue Pokédex hints) were drawn with the same lettering.

### Translation guidelines

- **Spanish from Spain** and the games' official terminology.
- **Official names**: checked against the Spanish release of Pokémon Emerald and, for later generations, against [WikiDex](https://www.wikidex.net) and the Spanish (Spain) data from [PokeAPI](https://pokeapi.co).
- **Move and ability descriptions**: official in-game text collected by [PkParaíso](https://pkparaiso.com), using the Gen 5 text or, if it doesn't fit, the Gen 4 or Gen 3 (Emerald) one, as long as it matches how the move or ability works in Rogue. When none fits, the official PokeAPI text is **condensed** to fit the GBA windows.
- **Item descriptions**: official PokeAPI texts, condensed to the real width of the Bag window (102 px, the same as in Emerald).
- **Own wording**: where the official text describes a mechanic Rogue changes, or refers to another game, the description was written from scratch.
- **GBA limits**: long names are abbreviated GBA-style, and everything was measured in pixels with the game's actual fonts so nothing gets cut off.
- **Battle messages** follow the structure of the Spanish Emerald ("¡Ataque de Zigzagoon bajó!").

### Code changes

Only the changes needed for the translation to work:

| Change | Reason |
|---|---|
| Text with masculine and feminine variants depending on the player character | Spanish adjectives agree with gender ("¡Bienvenido/a!"). New text codes `{MASC}…{FEM}…{ENDG}`. |
| Accented letters and ñ on the naming keyboard | á é í ó ú ñ Á É Í Ó Ú Ñ added to the symbols page. |
| Move names up to 16 characters | Many official Spanish names are longer than 12 characters. |
| Narrow font on the Pokémon summary screen | Move names and descriptions, ability description and stat column. |
| Species category in Spanish word order | "Pokémon Semilla" instead of "Semilla Pokémon". |
| Pokémon name placed correctly on the nickname screen | "¿Mote de Doduo?". |
| Wild / foe marker after the name | "Zigzagoon salvaje" instead of "Salvaje Zigzagoon". |
| Left-aligned numbers in the START menu | Spanish labels are longer. |
| Dialogue re-paginated into 2-line pages | Spanish is longer than English. |
| Verb before adverb in stat-change messages | "bajó mucho" ("fell sharply") word order. |
| Item amount on the second line of pop-ups | Spanish item names are longer and cut off the "x2". |
| Rogue Pokédex "SELECT·EDITAR" hint two tiles wider | "EDITAR" is longer than "EDIT". |
| Item amounts shown as "Hiperpoción x3", berries as "3 Bayas Zreza" | Spanish plurals can't be built by appending "s". |
| Summary screen ability window one tile wider | More room for the official ability description. |
| Rogue's own item descriptions wrapped at 102 px | The width actually visible in the Bag. |
| Abbreviated ability names in the Rogue Pokédex ability column | The column is only 62 px wide; the summary still shows full names. |
| No "'s" after the name in the battle ability pop-up | Spanish has no such possessive. |
| `display_name` field for gift Pokémon OT names | The internal name is also the code identifier. |
| Quest titles in narrow font, display titles separate from internal IDs | Translated titles fit without breaking quests. |
| Fixes to build with modern GCC | `json11` and `scaninc`. |

### How to build

The `castellano` branch builds exactly like the original Emerald Rogue:

1. Follow [INSTALL_ORIGINAL.md](INSTALL_ORIGINAL.md) (English) or [INSTALL.md](INSTALL.md) (Spanish) to set up the environment.
2. Clone the `castellano` branch: `git clone -b castellano https://github.com/SeCaVa/PokeRogue-Castellano`
3. Build with `make`.

**This repository contains no ROMs**: you need your own copy of Pokémon Emerald to patch or build the game.

### Not translated

- **Pokédex entries**: Emerald Rogue doesn't include them in the ROM.
- **Pokémon Emerald features Rogue doesn't use**: Union Room, Mystery Gift, PokéNav, TV, Battle Frontier and Frontier Pass, the original Pokédex, Game Corner, contests, Pokéblock case, Berry Crush, decorations and the original Safari Zone maps (text and graphics).
- **Logos**: the title screen, pokeemerald-expansion and Pokédex logos are left as in the original.

If you find untranslated, cut-off or wrong text, please open an issue in this repository.

### Credits

- **Emerald Rogue / Emerald Rogue EX**: [Pokabbie](https://github.com/Pokabbie/pokeemerald-rogue) and contributors. All credit for the game goes to them.
- **pokeemerald-expansion**: [RHH (ROM Hacking Hideout)](https://github.com/rh-hideout/pokeemerald-expansion) and its [contributors](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits). Emerald Rogue is built on their project.
- **pokeemerald**: the [pret](https://github.com/pret/pokeemerald) decompilation project.
- **Reference data**: [PokeAPI](https://pokeapi.co), [PkParaíso](https://pkparaiso.com) and [WikiDex](https://www.wikidex.net) for official Spanish names and descriptions; the Spanish release of Pokémon Emerald for short names, system messages and text graphics.
- **Spanish translation**: SeCaVa, with help from Claude (Anthropic).

The project's original README is kept in [README_ORIGINAL.md](README_ORIGINAL.md).

### Legal notice

Non-profit fan project. Not affiliated with or endorsed by Nintendo, Game Freak, The Pokémon Company, Pokabbie or RHH. Pokémon and all related names are trademarks of their respective owners. This repository does not distribute ROMs.
