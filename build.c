#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX 24

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

    bool verbose_log_output;

    char compiler_name_cmd[CMD_MAX];
    compiler_name_cmd[0] = '\0';

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
	else if (strcmp(argv[i], "-v") == 0)
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
	    strncpy(compiler_name_cmd, "clang", CMD_MAX - 1);
	    break;
	case GCC:
	    strncpy(compiler_name_cmd, "gcc", CMD_MAX - 1);
	    break;
	case ZIG:
	    strncpy(compiler_name_cmd, "zig cc", CMD_MAX - 1);
	    break;
        default: 
	    printf("Unknown compiler\n");
	    break;
    }

    char cmd[128];
    snprintf(cmd, sizeof(cmd),
	    "%s build.c -o a.out", compiler_name_cmd);
    printf(cmd);

    return 0;
}
