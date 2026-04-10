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

This will compile both c source code files into a single binary.  
If it produces any errors, make sure to report it as an issue in the parent github repo.  

-std=c99 will display errors one could encounter while compiling this with a compiler using the C99 standard
