# c-scripts 

C source code

Compile before executing. 

## Compile using make 

```bash
make full
```
or ``make base`` if you don't want any warning

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
    -Wall -Wextra -Wpedantic -std=c99
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
    -Wall -Wextra -Wpedantic -std=c99
./setup
```

This will compile the source code into a single binary.  

This source code follows ISO C and ISO C++ standards — you can verify this by using the ``-Wpedantic`` flag when compiling.  

This source code follows C99 standards — you can verify this by using the ``-std=c99`` flag. 
