# Bashtida
## Sobre el proyecto:

Con ese proyecto y poniendo en práctica lo aprendido hasta ahora por fin tenemos una shell simple que funciona. Lo que nos pedían en el proyecto era  crear nuestro propio interpretador de las líneas de comandos que el usuario introduce en la consola o en el terminal, basándonos siempre en como lo haría bash o zsh. 

Para más detalles de los requisitos del proyecto dejamos aquí el subject of this project

## Sobre cómo se estructura el codigo:

📁 > **inc: b** contains the program's headers.
📁 > **libftprint:** contains the source code of the libft library, which is used in the program.
📁 > **src:** contains the source code of the program.
📁 > **Makefile** contains instructions for compiling the program and testing it.
**Note: program covers only mandatory requirements of the project's subject.**

## El programa se ejecuta así: sobre cómo se ejecuta

Requirements
The program is written in C language for Linux distributions and thus needs the clang compiler and some standard C libraries to run.

Instructions

1 → Descargar/clonar el repositorio

```git clone https://github.com/Minishell.git```

2 →  Compiling the program

To compile the program, run:

```$ make```

3 → Executing the program

To execute the program, run:

```$ ./minishell```


## Sobre los autores:

Este proyecto lo hemos realizado las hermanas Bastida. $$Alicia y Patricia.$$

El perfil de Patricia en la intranet de 42 es ```pabastid```






















Parts of a Shell Program
The shell implementation is divided into three parts: The Parser, The Executor, and Shell Subsystems.

The Parser: reads the command line and puts it into a data structure called Command Table that will store the commands that will be executed.

The Executor: takes the Command Table and for every SimpleCommand in the array it creates a new process; also, if necessary, it creates pipes to communicate the output of one process to the input of the next one; additionally, it redirects the standard input, standard output, and standard error if there are any redirections.
Shell Subsystems: such as Environment Variables expansions, Wildcardsexpansions, Subshells executions.
The Parser

A parser is divided into two parts: a Lexical Analyzer or Lexer takes the input characters and puts the characters together into words called tokens, and a Parserthat processes the tokens according to a grammar and build the Command Table.

The Command Table

The Command Table is an array of  SimpleCommand structs. A SimpleCommand struct contains members for the command and arguments of a single entry in the pipeline. The parser will look also at the command line and determine if there is any input or output redirection based on symbols present in the command (i.e. < infile, or > outfile).


Descripción
La implementación de la shell se divide en 3 partes:

1️⃣ → Análisis de la línea de comandos: en esta parte, se debe dividir la línea de comandos en distintos tokens (palabras), teniendo en cuenta las distintos espacios y caracteres especiales.

2️⃣ → Ejecución de comandos: una vez analizada la línea de comandos, se debe determinar el comando a ejecutar y sus argumentos. Luego, se debe utilizar la función execve() para ejecutar el comando en el sistema o ejecutar tu función propia si es un builtin.

3️⃣ → Gestión de errores: es importante gestionar los errores que puedan surgir durante el proceso de análisis y ejecución de la línea de comandos.

4️⃣ → Gestión de redirecciones: se deben implementar las redirecciones de entrada y salida (>, <, >>, <<) para poder redirigir la entrada y salida de los comandos a archivos.

5️⃣ → Gestión de pipes: se deben implementar los pies | para poder encadenar varios comandos y enviar la salida de un comando como entrada del siguiente


Features
cd
pwd
echo
export
unset
env
exit
CTRL-C
CTRL-\
CTRL-D
| pipes
; semicolons
> >> < << redirections
&& || operators
* wildcard
local variable
env expansions + $?
line edition
termcaps
history (up/down arrows)
move cursor (left/right arrows)
move word by word (CTRL-left/CTRL-right)
move to beginning/end of line (HOME/END)
change line (CTRL-UP/CTRL-DOWN)
copy/paste/cut from cursor position (ALT-X/ALT-C/ALT-V)



2- Check_syntax:

> pipe_syntax.c

Comprueba que todo ok (…)
Something_before
Something_after
There_is_something
Check_sybtax


> utils_syntax.c

Int checking_syntax (char *str, t_master) > paired_quotes > para comprobar que las quotes están pareadas -> check_syntax_pipes > si todos los pipes están ok, entra -> redir > va recorriendo toda la str hasta que encuentra una redirection y USA check redir 1 y 2 > clean_line > retorna la línea son las comillas

Si todos los chequeos de sintaxis están ok, devuelve la línea sin comillas.

> redir_syntax.c

Comprueba si la sintaxis en las redirection es es correcta: que no haya más de dos redirecciones. 
Redir> es la función que llama a las dos para hacer la comprobación.

