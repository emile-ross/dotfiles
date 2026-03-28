# c-scripts 

C source code

Compile before executing. 

## Compile using make 

```bash
make full
```
or ``make setup`` if you don't want any warning

## Compile using GCC 

```bash
gcc arguments.c \
    configuring.c \
    functions.c \
    install.c \
    error-handling.c \
    programs.c \
    setup.c \
    update.c \
    -o setup \
    -Wall -Wextra
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
    update.c \
    -o setup \
    -Wall -Wextra
./setup
```


this will compile both c source code files into a single binary
if it produces any errors, make sure to report it as an issue in github
