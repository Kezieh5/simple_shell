# Simple shell project
A simple UNIX command interpreter written as part of the low-level programming track at ALX School.
## Requirements
### General
- Allowed editors: *vi*, *vim*, *emacs*
- All your files will be compiled on Ubuntu 20.04 LTS using *gcc*, using the options *-Wall -Werror -Wextra -pedantic -std=gnu89*
- All your files should end with a new line
- A *README.md* file, at the root of the folder of the project is mandatory
- Your code should use the *Betty* style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl), [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to 
- Write a *README* with the description of your project
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker](https://intranet.alxswe.com/rltoken/UL8J3kgl7HBK_Z9iBL3JFg)
### The code can be compiled using:
`gcc -Wall -Wextra -pedantic *.c -o hsh`
## Files & content:
- **builtin.c** - Builtin functions for our shell
- **delim.c** - Functions that tokenize strings
- **environ.c** - Functions handling different environment variables
- ***exec_functions.c*** - Functions to execute given commands
- ***library_functions.c*** - gets user input from stdin to be exececuted
- ***linke_list.c*** - Prints and frees a linked list
- **main.c** - Main entry point for the program, also handles *ctrl-c* command
- **memory.c** - Frees a pointer
- ***parsing_functions.c*** - Contains functons for adding _PATH_ environment variable, handling the newline character and reading lines from stdin
- ***print_functions.c*** - Handles printing error messages and strings to the file descriptor
- **shell.h** - Contains all function prototypes, structs and header files necessary for all other functions
- ***shell_loop.c*** - Contains the main loop of the program
- ***string_functions.c*** - One of two files for managing string variables
- ***string_functions_2.c*** - the second file managing more string variables
