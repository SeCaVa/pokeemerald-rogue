# Instrucciones

Estas instrucciones explican cómo preparar las herramientas necesarias para compilar **pokeemerald Expansion** (la base de Emerald Rogue), que ensambla los archivos fuente en una ROM (pokeemerald.gba).

> **Traducción al castellano:** esta es la traducción de la guía original, que se conserva en inglés en [INSTALL_ORIGINAL.md](INSTALL_ORIGINAL.md). Para compilar la versión en castellano, en el paso de [Instalación](#instalación) descarga la rama `castellano` de este repositorio.

Las instrucciones incluyen notas que se despliegan haciendo clic en el texto "<i>Nota...</i>".
En general no hace falta abrirlas, salvo que aparezca un error o necesites una aclaración.

Si tienes problemas, pide ayuda en Discord o IRC (consulta [README_ORIGINAL.md](README_ORIGINAL.md)).

## Windows
Para Windows hay instrucciones con tres terminales distintos, así tienes 3 opciones por si aparece algún error inesperado.
- [Windows 10/11 (WSL1)](#windows-1011-wsl1) (**la más rápida, muy recomendada**, solo Windows 10 y 11)
- [Windows (msys2)](#windows-msys2) (la segunda más rápida)
- [Windows (Cygwin)](#windows-cygwin) (la más lenta)

Según pruebas poco científicas, **msys2 es 2 veces más lento** que WSL1 y **Cygwin, de 5 a 6 veces más lento** que WSL1.
<details>
    <summary><i>Nota para usuarios avanzados: <b>WSL2</b>...</i></summary>

>   <b>WSL2</b> también es una opción, y es incluso más rápido que <b>WSL1</b> si los archivos están en el sistema de archivos de WSL2, pero algunas herramientas pueden tener problemas al acceder
>   al sistema de archivos de WSL2 a través de la unidad de red. Por ejemplo, las herramientas que usan versiones de Qt anteriores a la 5.15.2, como <a href="https://github.com/huderlem/porymap">porymap</a>,
>   pueden <a href="https://bugreports.qt.io/browse/QTBUG-86277">tener problemas para interpretar la ruta de red <code>\\wsl$</code></a>.
</details>

Todas las instrucciones de Windows suponen que la unidad principal es C:\\. Si tu unidad tiene otra letra, cambia la C por la correcta al seguir las instrucciones.

**Aviso**: como Microsoft ya no da soporte oficial a Windows 7 y Windows 8 apenas se usa, algunos mantenedores no quieren mantener las instrucciones para Windows 7/8. Por eso, esas instrucciones podrían dejar de funcionar en el futuro y tardar más en arreglarse que las de Windows 10.

## Windows 10/11 (WSL1)
WSL1 es el terminal recomendado para compilar **pokeemerald Expansion**. Las siguientes instrucciones explican cómo instalar WSL1 (también llamado simplemente WSL).
- Si WSL (Debian o Ubuntu) **no está instalado**, ve a [Instalar WSL1](#instalar-wsl1).
- Si WSL está instalado pero **no lo has configurado antes para otro proyecto de descompilación**, ve a [Configurar WSL1](#configurar-wsl1).
- En otro caso, **abre WSL** y ve a [Elegir dónde guardar pokeemerald Expansion (WSL1)](#elegir-dónde-guardar-pokeemerald-expansion-wsl1).

### Instalar WSL1
1. Abre [Windows PowerShell **como administrador**](https://i.imgur.com/QKmVbP9.png) y ejecuta el siguiente comando (en PowerShell se pega con clic derecho o Mayús+Insert).

    ```powershell
    dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
    ```

2. Cuando termine, reinicia el ordenador.

3. El siguiente paso es elegir e instalar una distribución de Linux desde Microsoft Store. Las instrucciones suponen que eliges Ubuntu.
    <details>
        <summary><i>Nota para usuarios avanzados...</i></summary>

    >   Puedes elegir la distribución que prefieras, pero la configuración puede ser distinta. Debian debería funcionar con estas instrucciones, pero no se ha probado.
    </details>

4. Abre la [selección de Linux de Microsoft Store](https://aka.ms/wslstore), haz clic en Ubuntu y después en Obtener; así se instalará la distribución Ubuntu.
    <details>
        <summary><i>Notas...</i></summary>

    >   Nota 1: si aparece una ventana pidiendo que inicies sesión con una cuenta de Microsoft, simplemente ciérrala.
    >   Nota 2: si el enlace no funciona, abre Microsoft Store a mano y busca la aplicación Ubuntu (elige la que no tiene número de versión).
    </details>

### Configurar WSL1
Algunos consejos antes de seguir:
- En WSL, copiar y pegar se hace con
    - **clic derecho** (selecciona y haz clic derecho para copiar; clic derecho sin nada seleccionado para pegar)
    - **Ctrl+Mayús+C/Ctrl+Mayús+V** (se activa haciendo clic derecho en la barra de título, entrando en Propiedades y marcando la casilla "Usar Ctrl+Mayús+C/V para copiar/pegar").
- Algunos comandos te pedirán la contraseña de WSL o que confirmes la acción. Es normal: escribe tu contraseña de WSL o confirma cuando haga falta.

1. Abre **Ubuntu** (por ejemplo, con la búsqueda de Windows).
2. La primera vez que se ejecuta, WSL/Ubuntu termina de instalarse solo. Cuando acabe, te pedirá un nombre de usuario y una contraseña.
    <details>
        <summary><i>Nota...</i></summary>

    >   Al escribir la contraseña no se ve nada en pantalla, pero el terminal sí la está recibiendo.
    </details>

3. Actualiza WSL/Ubuntu antes de continuar ejecutando el siguiente comando. Seguramente tardará bastante:

    ```bash
    sudo apt update && sudo apt upgrade
    ```

> Nota: si el repositorio que vas a compilar tiene una **[versión antigua de INSTALL.md](https://github.com/pret/pokeemerald/blob/571c598/INSTALL.md)**, sigue a partir de aquí las [instrucciones antiguas para WSL1](docs/legacy_WSL1_INSTALL.md).

4. Para compilar pokeemerald Expansion hacen falta algunos paquetes. Instálalos con el siguiente comando:

    ```bash
    sudo apt install build-essential binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi git libpng-dev
    ```
    <details>
        <summary><i>Nota...</i></summary>

    >   Si el comando no funciona, prueba el mismo comando cambiando `apt` por `apt-get`.
    </details>
    Esto instalará GCC v10 en Ubuntu 22.04. pokeemerald Expansion funciona con GCC v10, pero los repositorios remotos y el equipo de RHH usan GCC v13, que comprueba los errores de forma más estricta. Si quieres pasar de la v10 a la v13, sigue también las instrucciones de instalación de devkitPro.

### Instalar devkitARM en WSL1

1. Cambia a una carpeta donde puedas descargar un paquete, como **C:\Users\\_\<usuario>_\Downloads** (la carpeta Descargas de la mayoría de usuarios). Para ello, escribe este comando, donde *\<usuario>* es tu nombre de usuario de **Windows**:

    ```bash
    cd /mnt/c/Users/<usuario>/Downloads
    ```

2. Una vez en esa carpeta, ejecuta los siguientes comandos para instalar devkitARM.

    ```bash
    sudo apt install wget
    wget https://apt.devkitpro.org/install-devkitpro-pacman
    chmod +x ./install-devkitpro-pacman
    sudo ./install-devkitpro-pacman
    sudo dkp-pacman -S gba-dev
    ```
    El último comando te preguntará qué paquetes instalar. Pulsa Intro para instalarlos todos y después escribe Y para continuar con la instalación.

3. Ejecuta el siguiente comando para configurar las variables de entorno de devkitPro (o cierra y vuelve a abrir WSL):

    ```bash
    source /etc/profile.d/devkit-env.sh
    ```

devkitARM ya está instalado.

### Elegir dónde guardar pokeemerald Expansion (WSL1)
WSL tiene su propio sistema de archivos, al que Windows no accede directamente, pero desde WSL *sí* se accede a los archivos de Windows. Por eso conviene guardar pokeemerald Expansion en Windows.

Por ejemplo, si quieres guardar pokeemerald Expansion en **C:\Users\\_\<usuario>_\Desktop\decomps**, primero asegúrate de que la carpeta existe. Después, escribe este comando para **cambiar a** esa carpeta, donde *\<usuario>* es tu nombre de usuario de **Windows**:

```bash
cd /mnt/c/Users/<usuario>/Desktop/decomps
```

<details>
    <summary><i>Notas...</i></summary>

>   Nota 1: la unidad C:\ de Windows se llama /mnt/c/ en WSL.
>   Nota 2: si la ruta tiene espacios, hay que ponerla entre comillas, por ejemplo `cd "/mnt/c/users/<usuario>/Desktop/carpeta decomp"`.
>   Nota 3: en Windows las rutas no distinguen mayúsculas y minúsculas, así que no hace falta respetarlas.
</details>

Si funciona, continúa con la [Instalación](#instalación).

Si no, pide ayuda en Discord o IRC (consulta [README_ORIGINAL.md](README_ORIGINAL.md)), o sigue leyendo las [instrucciones de Windows con msys2](#windows-msys2).

## Windows (msys2)

- Si devkitARM **no está instalado**, ve a [Instalar devkitARM](#instalar-devkitarm).
- Si devkitARM está instalado pero **no has configurado msys2 antes para otro proyecto de descompilación**, ve a [Configurar msys2](#configurar-msys2).
- En otro caso, **abre msys2** y ve a [Elegir dónde guardar pokeemerald Expansion (msys2)](#elegir-dónde-guardar-pokeemerald-expansion-msys2).

### Instalar devkitARM
1. Descarga el instalador de devkitPro [aquí](https://github.com/devkitPro/installer/releases).
2. Ejecuta el instalador de devkitPro. En la pantalla "Choose Components", desmarca todo excepto GBA Development, salvo que quieras instalar otros componentes de devkitPro para otras cosas. Deja la carpeta de instalación en C:\devkitPro y no cambies la opción del menú Inicio.

### Configurar msys2

En msys2, copiar es Ctrl+Insert y pegar es Mayús+Insert.

1. Abre msys2 en C:\devkitPro\msys2\msys2_shell.bat.

2. Para compilar pokeemerald Expansion hacen falta algunos paquetes. Instálalos con estos dos comandos:

    ```bash
    pacman -Sy msys2-keyring
    pacman -S make gcc zlib-devel git
    ```
    <details>
        <summary><i>Nota...</i></summary>

    >   Los comandos pedirán confirmación; acepta cuando te lo pregunten.
    </details>

3. Descarga [libpng](https://sourceforge.net/projects/libpng/files/libpng16/1.6.37/libpng-1.6.37.tar.xz/download).

4. Cambia a la carpeta donde se descargó libpng. Por defecto, msys2 empieza en la carpeta de perfil del usuario, que está en **C:\Users\\&#8288;_\<usuario>_**, donde *\<usuario>* es tu nombre de usuario de Windows. Lo normal es que libpng esté en una subcarpeta de esa carpeta de perfil. Por ejemplo, si libpng se guardó en **C:\Users\\_\<usuario>_\Downloads** (la carpeta Descargas de la mayoría de usuarios), escribe este comando:

    ```bash
    cd Downloads
    ```

    <details>
        <summary><i>Notas...</i></summary>

    >   Nota 1: aunque no se vea, msys usa barras normales `/` en lugar de barras invertidas `\` para separar carpetas.
    >   Nota 2: si la ruta tiene espacios, hay que ponerla entre comillas, por ejemplo `cd "Downloads/Mis descargas"`.
    >   Nota 3: en Windows las rutas no distinguen mayúsculas y minúsculas, así que no hace falta respetarlas.
    >   Nota 4: si libpng se guardó en otro sitio, tendrás que indicar la ruta completa de donde se descargó, por ejemplo `cd c:/devkitpro/msys2` si se guardó ahí.
    </details>

5. Ejecuta los siguientes comandos para descomprimir e instalar libpng.

    ```bash
    tar xf libpng-1.6.37.tar.xz
    cd libpng-1.6.37
    ./configure --prefix=/usr
    make check
    make install
    ```

6. Por último, ejecuta el siguiente comando para volver a la carpeta de perfil del usuario.

    ```bash
    cd
    ```

### Elegir dónde guardar pokeemerald Expansion (msys2)
Ahora puedes elegir la carpeta donde guardar pokeemerald Expansion. Si te parece bien guardarlo en la carpeta de perfil del usuario, continúa con la [Instalación](#instalación). Si no, tendrás que tener en cuenta dónde lo guardas al cambiar a la carpeta del proyecto.

Por ejemplo, si quieres guardar pokeemerald Expansion en **C:\Users\\_\<usuario>_\Desktop\decomps** (donde *\<usuario>* es tu nombre de usuario de **Windows**), escribe este comando:

```bash
cd Desktop/decomps
```

Si funciona, continúa con la [Instalación](#instalación).

Si no, pide ayuda en Discord o IRC (consulta [README_ORIGINAL.md](README_ORIGINAL.md)), o sigue leyendo las [instrucciones de Windows con Cygwin](#windows-cygwin).

## Windows (Cygwin)
1. Si devkitARM **no está instalado**, sigue antes las instrucciones para [instalar devkitARM](#instalar-devkitarm) de la configuración de msys2. *¡Ten cuidado de no seguir por error con las instrucciones de msys2!*

2.
    - Si Cygwin **no está instalado**, o no tiene todos los paquetes necesarios, ve a [Instalar Cygwin](#instalar-cygwin).
    - Si Cygwin está instalado pero **no está configurado para funcionar con devkitARM**, ve a [Configurar devkitARM para Cygwin](#configurar-devkitarm-para-cygwin).
    - En otro caso, **abre Cygwin** y ve a [Elegir dónde guardar pokeemerald Expansion (Cygwin)](#elegir-dónde-guardar-pokeemerald-expansion-cygwin).

### Instalar Cygwin
1. Descarga [Cygwin](https://cygwin.com/install.html): setup-x86_64.exe para Windows de 64 bits, setup-x86.exe para 32 bits.

2. Ejecuta el instalador de Cygwin. Deja la configuración por defecto hasta llegar a la pantalla "Choose A Download Site".

3. En "Choose a Download Site", elige cualquier servidor de la lista "Available Download Sites".

4. En "Select Packages", cambia la vista a "Full" (arriba a la izquierda) y busca estos paquetes:
    - `make`
    - `git`
    - `gcc-core`
    - `gcc-g++`
    - `libpng-devel`

    Para encontrarlos rápido, escribe el nombre de cada paquete en la barra de búsqueda. Asegúrate de que el nombre del paquete elegido es **exactamente** el mismo que buscas: por ejemplo, `cmake` **NO** es lo mismo que `make`.

5. En cada paquete, haz doble clic en el texto "**Skip**" que hay junto a él para elegir la versión más reciente. Si pone otra cosa distinta de "**Skip**" (por ejemplo, Keep o un número de versión), el paquete ya está o se va a instalar y no tienes que hacer nada.

6. Cuando hayas elegido todos los paquetes necesarios, termina la instalación.

### Configurar devkitARM para Cygwin

En Cygwin, copiar es Ctrl+Insert y pegar es Mayús+Insert.

1. Abre **Cygwin**.

2. Ejecuta los siguientes comandos para configurar devkitPro con Cygwin.

    ```bash
    export DEVKITPRO=/cygdrive/c/devkitpro
    echo export DEVKITPRO=$DEVKITPRO >> ~/.bashrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo export DEVKITARM=$DEVKITARM >> ~/.bashrc
    ```

    <details>
        <summary><i>Nota...</i></summary>

    >   Si tu unidad no es la c, cambia la letra c por la de tu unidad.
    </details>

### Elegir dónde guardar pokeemerald Expansion (Cygwin)

Cygwin tiene su propio sistema de archivos dentro de Windows, en **C:\cygwin64\home\\_\<usuario>_**. Si no quieres guardar pokeemerald Expansion ahí, tendrás que tener en cuenta dónde lo guardas al **cambiar a** la carpeta del proyecto.

Por ejemplo, si quieres guardar pokeemerald Expansion en **C:\Users\\_\<usuario>_\Desktop\decomps**, escribe este comando, donde *\<usuario>* es tu nombre de usuario de **Windows**:
```bash
cd c:/Users/<usuario>/Desktop/decomps
```
La carpeta **tiene que existir** en Windows. Si quieres guardar pokeemerald Expansion en una carpeta propia que todavía no existe (como la del ejemplo), créala antes (por ejemplo, con el Explorador de Windows) y después ejecuta el comando `cd`.

<details>
    <summary><i>Notas...</i></summary>

>   Nota 1: si la ruta tiene espacios, hay que ponerla entre comillas, por ejemplo `cd "c:/users/<usuario>/Desktop/carpeta decomp"`.
>   Nota 2: en Windows las rutas no distinguen mayúsculas y minúsculas, así que no hace falta respetarlas.
</details>

Si funciona, continúa con la [Instalación](#instalación). Si no, pide ayuda en Discord o IRC (consulta [README_ORIGINAL.md](README_ORIGINAL.md)).

## macOS
1. Si no tienes instaladas las Xcode Command Line Tools, descárgalas [aquí](https://developer.apple.com/xcode/resources/), abre el Terminal y ejecuta el siguiente comando:

    ```bash
    xcode-select --install
    ```

2.  - Si libpng **no está instalado**, ve a [Instalar libpng (macOS)](#instalar-libpng-macos).
    - Si devkitARM **no está instalado**, ve a [Instalar devkitARM (macOS)](#instalar-devkitarm-macos).
    - En otro caso, **abre el Terminal** y ve a [Elegir dónde guardar pokeemerald Expansion (macOS)](#elegir-dónde-guardar-pokeemerald-expansion-macos).

### Instalar libpng (macOS)
<details>
    <summary><i>Nota para usuarios avanzados...</i></summary>

>   Esta guía instala libpng con Homebrew porque es el método más sencillo, pero los usuarios avanzados pueden instalarlo de otra forma si lo prefieren.
</details>

1. Abre el Terminal.
2. Si no tienes Homebrew, instala [Homebrew](https://brew.sh/) siguiendo las instrucciones de su web.
3. Ejecuta el siguiente comando para instalar libpng.

    ```bash
    brew install libpng
    ```
    libpng ya está instalado.

    Continúa con [Instalar devkitARM (macOS)](#instalar-devkitarm-macos) si **devkitARM no está instalado**; si no, ve a [Elegir dónde guardar pokeemerald Expansion (macOS)](#elegir-dónde-guardar-pokeemerald-expansion-macos).

### Instalar devkitARM (macOS)
1. Descarga el paquete `devkitpro-pacman-installer.pkg` desde [aquí](https://github.com/devkitPro/pacman/releases).
2. Abre el paquete para instalar el pacman de devkitPro.
3. En el Terminal, ejecuta los siguientes comandos para instalar devkitARM:

    ```bash
    sudo dkp-pacman -Sy
    sudo dkp-pacman -S gba-dev
    sudo dkp-pacman -S devkitarm-rules
    ```

    El comando con gba-dev te preguntará qué paquetes instalar. Pulsa Intro para instalarlos todos y después escribe Y para continuar con la instalación.

4. Una vez instaladas las herramientas, hay que hacer que el sistema encuentre devkitARM desde cualquier sitio. Para ello, ejecuta los siguientes comandos:

    ```bash
    export DEVKITPRO=/opt/devkitpro
    echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc

    echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile
    ```

### Elegir dónde guardar pokeemerald Expansion (macOS)
Ahora puedes elegir la carpeta donde guardar pokeemerald Expansion. Si te parece bien guardarlo en la carpeta de usuario, continúa con la [Instalación](#instalación). Si no, tendrás que tener en cuenta dónde lo guardas al cambiar a la carpeta del proyecto.

Por ejemplo, si quieres guardar pokeemerald Expansion en **~/Desktop/decomps**, escribe este comando para **cambiar a** esa carpeta:
```bash
cd Desktop/decomps
```
La carpeta **tiene que existir**. Si quieres guardar pokeemerald Expansion en una carpeta propia que todavía no existe (como la del ejemplo), créala antes (por ejemplo, con el Finder) y después ejecuta el comando `cd`.

<details>
    <summary><i>Nota...</i></summary>

>   Nota: si la ruta tiene espacios, hay que ponerla entre comillas, por ejemplo `cd "Desktop/carpeta decomp"`
</details>

Si funciona, continúa con la [Instalación](#instalación). Si no, pide ayuda en Discord o IRC (consulta [README_ORIGINAL.md](README_ORIGINAL.md)).

## Linux
Abre el Terminal y escribe los siguientes comandos, según la distribución que uses.

### Distribuciones basadas en Debian/Ubuntu
Ejecuta el siguiente comando para instalar los paquetes necesarios:
```bash
sudo apt install build-essential binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi git libpng-dev
```
Después continúa con [Elegir dónde guardar pokeemerald Expansion (Linux)](#elegir-dónde-guardar-pokeemerald-expansion-linux).
<details>
    <summary><i>Nota para repositorios antiguos...</i></summary>

>   Si el repositorio que vas a compilar tiene una **[versión antigua de INSTALL.md](https://github.com/pret/pokeemerald/blob/571c598/INSTALL.md)**,
>   tendrás que instalar devkitARM. Instala todos los paquetes anteriores excepto los arm-none-eabi y sigue las instrucciones para
>   [instalar devkitARM en distribuciones basadas en Debian/Ubuntu](#instalar-devkitarm-en-distribuciones-basadas-en-debianubuntu).
</details>

### Instalar devkitARM en distribuciones basadas en Debian/Ubuntu

1. Cambia a una carpeta donde puedas descargar paquetes, como la de Descargas. Después, ejecuta los siguientes comandos para instalar devkitARM:

    ```bash
    wget https://apt.devkitpro.org/install-devkitpro-pacman
    chmod +x ./install-devkitpro-pacman
    sudo ./install-devkitpro-pacman
    sudo dkp-pacman -S gba-dev
    ```
    El último comando te preguntará qué paquetes instalar. Pulsa Intro para instalarlos todos y después escribe Y para continuar con la instalación.

2. Ejecuta el siguiente comando para configurar las variables de entorno de devkitPro (o cierra y vuelve a abrir el Terminal):

    ```bash
    source /etc/profile.d/devkit-env.sh
    ```

devkitARM ya está instalado.

### Arch Linux
Ejecuta este comando como root para instalar los paquetes necesarios:
```bash
pacman -S base-devel arm-none-eabi-binutils arm-none-eabi-gcc arm-none-eabi-newlib git libpng
```

### Instalar devkitARM en Arch Linux

1. Sigue las [instrucciones de devkitPro](https://devkitpro.org/wiki/devkitPro_pacman#Customising_Existing_Pacman_Install) para configurar `pacman` y que descargue los paquetes de devkitPro.
2. Instala `gba-dev` ejecutando el siguiente comando como root.

    ```console
    pacman -S gba-dev
    ```
    Te preguntará qué paquetes instalar. Pulsa Intro para instalarlos todos y después escribe Y para continuar con la instalación.

3. Ejecuta el siguiente comando para configurar las variables de entorno de devkitPro (o cierra y vuelve a abrir el Terminal):

    ```bash
    source /etc/profile.d/devkit-env.sh
    ```

devkitARM ya está instalado.

Después continúa con [Elegir dónde guardar pokeemerald Expansion (Linux)](#elegir-dónde-guardar-pokeemerald-expansion-linux).

### Otras distribuciones
_(¡Se agradecerán mucho instrucciones específicas para otras distribuciones!)_

1. Busca el software necesario en sus repositorios:
    - `gcc`
    - `g++`
    - `make`
    - `git`
    - `libpng-dev`

2. Sigue las instrucciones de [esta página](https://devkitpro.org/wiki/devkitPro_pacman) para instalar el pacman de devkitPro. Recuerda que el objetivo es configurar una instalación de pacman ya existente para que reconozca los repositorios de devkitPro.
3. Una vez configurado el pacman de devkitPro, ejecuta los siguientes comandos:

    ```bash
    sudo pacman -Sy
    sudo pacman -S gba-dev
    ```

    El último comando te preguntará qué paquetes instalar. Pulsa Intro para instalarlos todos y después escribe Y para continuar con la instalación.

### Elegir dónde guardar pokeemerald Expansion (Linux)
Ahora puedes elegir la carpeta donde guardar pokeemerald Expansion. Si lo haces, tendrás que tener en cuenta esa ruta al cambiar a la carpeta del proyecto.

Si funciona, continúa con la [Instalación](#instalación). Si no, pide ayuda en Discord o IRC (consulta [README_ORIGINAL.md](README_ORIGINAL.md)).

## Instalación

<details>
    <summary><i>Nota para usuarios de Windows...</i></summary>

>   Puedes añadir una exclusión para la carpeta `pokeemerald-rogue` y/o `decomps` en Seguridad de Windows siguiendo
>   [estas instrucciones](https://support.microsoft.com/help/4028485). Así Microsoft Defender no las analiza,
>   lo que puede acelerar la compilación.
</details>

1. Si todavía no has descargado el proyecto (algunos usuarios prefieren descargarlo con un cliente de git como GitHub Desktop), ejecuta este comando para descargar la rama `castellano` de la traducción:

    ```bash
    git clone -b castellano https://github.com/SeCaVa/pokeemerald-rogue
    ```

    <details>
        <summary><i>Nota para el original en inglés...</i></summary>

    >   Para compilar el Emerald Rogue original de Pokabbie, descarga [su repositorio](https://github.com/Pokabbie/pokeemerald-rogue) en lugar de este.
    </details>

    <details>
        <summary><i>Nota para WSL1...</i></summary>

    >   Si aparece un error que dice `fatal: could not set 'core.filemode' to 'false'`, ejecuta los siguientes comandos:
    >   ```bash
    >   cd
    >   sudo umount /mnt/c
    >   sudo mount -t drvfs C: /mnt/c -o metadata,noatime
    >   cd <carpeta donde vas a guardar el proyecto>
    >   ```
    >   Donde *\<carpeta donde vas a guardar el proyecto>* es la ruta de la carpeta [que elegiste para guardar pokeemerald Expansion](#elegir-dónde-guardar-pokeemerald-expansion-wsl1). Después, vuelve a ejecutar el comando `git clone`.
    </details>

Ya lo tienes todo listo para compilar.

## Compilar pokeemerald Expansion

Si no estás ya en la carpeta del proyecto, **cambia a** ella:
```bash
cd pokeemerald-rogue
```
Para compilar **pokeemerald.gba** (nota: para compilar más rápido, consulta [Compilación en paralelo](#compilación-en-paralelo)):
```bash
make
```
Si la compilación termina bien, tendrás el archivo **pokeemerald.gba** en la carpeta del proyecto.
<details>
<summary>Nota para Windows...</summary>
> Si has cambiado de terminal desde la última compilación (por ejemplo, de msys2 a WSL1), tienes que ejecutar `make clean-tools` una vez antes de volver a ejecutar `make`.
</details>

# Consejos de compilación

## Compilación en paralelo

Consulta [la documentación de GNU](https://www.gnu.org/software/make/manual/html_node/Parallel.html) y [este hilo de Stack Exchange](https://unix.stackexchange.com/questions/208568) para más información.

Para compilar más rápido, primero averigua el valor de `nproc` ejecutando el siguiente comando:
```bash
nproc
```
Después puedes acelerar la compilación con el siguiente comando:
```bash
make -j<resultado de nproc>
```
Cambia `<resultado de nproc>` por el número que devolvió el comando `nproc`.

`nproc` no existe en macOS. La alternativa es `sysctl -n hw.ncpu` ([hilo de Stack Overflow sobre el tema](https://stackoverflow.com/questions/1715580)).

### Otras toolchains

Para compilar con una toolchain distinta de devkitARM, cambia la variable de entorno `TOOLCHAIN` por la ruta de tu toolchain, que debe contener la subcarpeta `bin`.
```bash
make TOOLCHAIN="/ruta/a/la/toolchain"
```
Por ejemplo:
```bash
make TOOLCHAIN="/usr/local/arm-none-eabi"
```
Para compilar el objetivo `modern` con esta toolchain, también deben existir las subcarpetas `lib`, `include` y `arm-none-eabi`.

### Compilar con información de depuración

Para compilar **pokeemerald.elf** con símbolos de depuración con una toolchain moderna:
```bash
make DINFO=1
```
No hace falta en una compilación no moderna (agbcc), porque esas ya incluyen los símbolos de depuración por defecto.

### agbcc

<details>
    <summary><i>Obsoleto; instalar agbcc es opcional desde la versión 1.7.0</i>.</summary>
2. Instala agbcc en la carpeta del proyecto. Los comandos dependen de tu situación. **Sigue solo una de estas opciones**:
- Si **nunca has compilado agbcc** en la carpeta donde guardas el proyecto, ejecuta los siguientes comandos para compilarlo e instalarlo en pokeemerald-rogue:

    ```bash
    git clone https://github.com/pret/agbcc
    cd agbcc
    ./build.sh
    ./install.sh ../pokeemerald-rogue
    ```

- **Si no**, y ya habías compilado agbcc (por ejemplo, si el git clone anterior falla) pero **la última vez fue con otro terminal** distinto del actual (solo en Windows, por ejemplo al pasar de msys2 a WSL1), ejecuta los siguientes comandos para compilarlo e instalarlo en pokeemerald-rogue:

    ```bash
    cd agbcc
    git clean -fX
    ./build.sh
    ./install.sh ../pokeemerald-rogue
    ```

- **Si no**, y ya habías compilado agbcc con el mismo terminal, ejecuta los siguientes comandos para instalarlo en pokeemerald-rogue:

    ```bash
    cd agbcc
    ./install.sh ../pokeemerald-rogue
    ```

    <details>
        <summary><i>Nota...</i></summary>

        > Si al compilar agbcc o el juego aparece un error, prueba a borrar la carpeta agbcc y a reinstalarlo como si nunca lo hubieras compilado.
    </details>

3. Una vez instalado agbcc, vuelve a la carpeta donde están pokeemerald-rogue y agbcc:

    ```bash
    cd ..
    ```

4. Para compilar con agbcc:

    ```make agbcc```

</details>

# Herramientas adicionales útiles

* [porymap](https://github.com/huderlem/porymap) para ver y editar mapas
* [poryscript](https://github.com/huderlem/poryscript) para programar scripts ([extensión de VS Code](https://marketplace.visualstudio.com/items?itemName=karathan.poryscript))
