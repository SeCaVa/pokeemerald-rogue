# Emerald Rogue EX — Traducción al castellano

Traducción no oficial al **castellano de España** de **Emerald Rogue EX v2.2.1a**, el *roguelite* basado en Pokémon Esmeralda creado por **[Pokabbie](https://github.com/Pokabbie/pokeemerald-rogue)**.

> Todo el juego (diseño, programación, contenido, gráficos y equilibrio) es obra de **Pokabbie** y de quienes han colaborado en Emerald Rogue. Este fork **solo traduce los textos** y hace los ajustes de código imprescindibles para que el castellano quepa y se vea bien. Si te gusta el juego, apoya el proyecto original.

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

### Criterios de la traducción

- **Castellano de España** y terminología oficial de los juegos.
- **Nombres oficiales**:
  - Los nombres y abreviaturas cortas se han comprobado con Pokémon Edición Esmeralda en castellano.
  - Los de generaciones posteriores se han comprobado con [WikiDex](https://www.wikidex.net) y con los datos en castellano de España (idioma `es`) de [PokeAPI](https://pokeapi.co).
- **Descripciones de movimientos**:
  - Movimientos 1–354: textos de Pokémon Esmeralda en castellano.
  - Movimientos posteriores, habilidades y objetos: descripciones oficiales en castellano de España de PokeAPI, **resumidas** para que quepan en las ventanas de GBA.
  - Donde el texto oficial describe una mecánica que Rogue cambia (congelación, turnos de las ataduras, efectos de Ácido y Triturar…) o se refiere a otro juego, se ha redactado un texto propio.
- **Límites de GBA**:
  - Los nombres largos se abrevian al estilo de los juegos de GBA ("Pantalla Humo", "Colmillo Ven.", "Torm. Arena").
  - Todo se ha medido en píxeles con las fuentes reales del juego para que nada se corte.

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
| Títulos de misión en fuente estrecha y títulos visibles separados del identificador interno | Para que los títulos traducidos quepan sin romper las misiones. |
| Arreglos para compilar con GCC moderno | `json11` y `scaninc`. |

---

## Cómo compilar

La rama `castellano` se compila igual que Emerald Rogue original:

1. Sigue las instrucciones de [INSTALL.md](INSTALL.md) para preparar el entorno.
2. Descarga la rama `castellano`.
3. Compila con `make`.

El resultado es una ROM de Emerald Rogue EX en castellano. **Este repositorio no incluye ninguna ROM**: para jugar necesitas tu propia copia de Pokémon Esmeralda y aplicar el parche o compilar el juego.

---

## Qué no está traducido

- **Pantalla de título**: el "PRESS START" y otros textos que forman parte de imágenes.
- **Entradas de la Pokédex**: Emerald Rogue no las incluye en la ROM.
- **Funciones de Pokémon Esmeralda que Rogue no usa**: Sala Unión, Regalo Misterioso, llamadas del PokéNav, Frente Batalla, Tritura Bayas y decoraciones.

Si encuentras un texto sin traducir, cortado o con errores, abre una *issue* en este repositorio.

---

## Créditos

- **Emerald Rogue / Emerald Rogue EX**: [Pokabbie](https://github.com/Pokabbie/pokeemerald-rogue) y colaboradores. Todo el mérito del juego es suyo.
- **pokeemerald-expansion**: [RHH (ROM Hacking Hideout)](https://github.com/rh-hideout/pokeemerald-expansion) y su [lista de colaboradores](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits). Emerald Rogue se basa en su proyecto.
- **pokeemerald**: el proyecto de descompilación de [pret](https://github.com/pret/pokeemerald).
- **Datos de referencia**: [PokeAPI](https://pokeapi.co) y [WikiDex](https://www.wikidex.net) para los nombres y las descripciones oficiales en castellano.
- **Traducción al castellano**: SeCaVa, con ayuda de Claude (Anthropic).

El README original del proyecto se conserva en [README_ORIGINAL.md](README_ORIGINAL.md).

---

## Aviso legal

Proyecto hecho por fans y sin ánimo de lucro. No está afiliado ni respaldado por Nintendo, Game Freak, The Pokémon Company, Pokabbie ni RHH. Pokémon y todos los nombres relacionados son marcas registradas de sus respectivos propietarios. Este repositorio no distribuye ROMs.
