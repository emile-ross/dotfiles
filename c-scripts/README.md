# c-scripts 

c source code

make sure you compile the c-scripts

## Compile using GCC 

```bash
gcc setup.c functions.c install.c update.c programs.c -o setup -Wall
./setup
```
## Compile using zig 

```bash
zig cc setup.c functions.c install.c update.c programs.c -o setup -Wall -Wextra
./setup
```

this will compile both c source code files into a single binary
if it produces any errors, make sure to report it as an issue in github
