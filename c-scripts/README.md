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
    -Wall -Wextra -pedantic -std=c99
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
    -Wall -Wextra -pedantic -std=c99
./setup
```

This will compile the source code into a single binary.  

The -std=c99 will display errors in accordance with the C99 standard
