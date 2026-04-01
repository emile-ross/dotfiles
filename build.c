#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum 
{
    CLANG,
    ZIG,
    GCC

} compiler_enum;

int main(int argc, char *argv[])
{
    // declare compiler_name enum
    compiler_enum compiler_name;

    switch(compiler_name)
    {
	case ZIG:
	    printf("zig compiler\n");
	    break;
        default: 
	    printf("not special\n");
	    break;
    }

    if (strcmp(argv[1], "gcc") == 0)
    {
	compiler_name = GCC;
    }

    return 0;

}
