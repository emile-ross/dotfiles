make sure you compile the c-scripts using this command

```bash
gcc -c setup.c
gcc -c install.c
gcc setup.o install.o -o setup
```
this will compile both c source code files into a single binary
if it produces any errors, make sure to report it as an issue in github
