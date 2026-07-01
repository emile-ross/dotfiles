# c-scripts 

C source code

Compile before executing. 

## Compile using make 

Compile with all warnings using the zig cc compiler

> make sure you are in the root directory of the repository when executing the makefile

```bash
make base
```

You can log the errors to a file using 
```sh
make log
```

Compile for MacOs
```sh
make macos
```

Use ``make gcc`` if you don't want any warnings

If this causes some problems, try removing the binary files and try again


## Compile using GCC 

```bash
gcc arguments.c \
    configuring.c \
    functions.c \
    install.c \
    error-handling.c \
    programs.c \
    setup.c \
    globals.c \
    update.c \
    -o setup \
    -Wall -Wextra -Wpedantic -std=c99 -Wconversion -Werror -Wshadow
./setup
```

## Compile using zig 

```bash
zig cc arguments.c \
    configuring.c \
    error-handling.c \
    functions.c \
    install.c \
    programs.c \
    setup.c \
    globals.c \
    update.c \
    -o setup \
    -Wall -Wextra -Wpedantic -std=c99 -Wconversion  -Wshadow
./setup
```

This will compile the source code into a single binary.  

This source code follows ISO C and ISO C++ standards — you can verify this by using the ``-Wpedantic`` flag when compiling.  

This source code follows C99 standards — you can verify this by using the ``-std=c99`` flag. 
