#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool verbose_log_output;

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

    for (int i = 1; i < argc; i++)
    {
	if (strcmp(argv[i], "gcc") == 0)
    	{
    	    compiler_name = GCC;
    	}
    	else if (strcmp(argv[i], "zig") == 0)
    	{
    	    compiler_name = ZIG;
    	}
    	else if (strcmp(argv[i], "clang") == 0)
    	{
    	    compiler_name = CLANG;
    	}
	else if (strcmp(argv[i], "verbose") == 0)
    	{
    	    verbose_log_output = true;
    	}
    	else
    	{
    	    printf("Unknown argument: %s\n", argv[i]);
    	}
    }

    switch(compiler_name)
    {
	case CLANG:
	    printf("Clang compiler\n");
	    break;
	case GCC:
	    printf("GCC compiler\n");
	    break;
	case ZIG:
	    printf("zig compiler\n");
	    break;
        default: 
	    printf("Unknown compiler\n");
	    return 1;
    }

    return 0;
}
