#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX 24
#define NUM_SRC_FILES 9

void compile_all_files(char *compiler, char *flags);

char *object_fpath = "c-scripts";

const char *source_files[] = { "setup", "update", "install", NULL };

typedef enum 
{
    CLANG,
    ZIG,
    GCC
} compiler_enum;

int main(int argc, char *argv[])
{
    char compiler_name_cmd[CMD_MAX];
    compiler_name_cmd[0] = '\0';

    // declare compiler_name enum
    compiler_enum compiler_name;

    bool verbose_log_output;

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
	    return 1;
    }

    compile_all_files(compiler_name_cmd, "-Wall -Wextra -Wpedantic");

    // compile_all_files()
    // link all files together

    return 0;
}

void compile_all_files(char *compiler, char *flags)
{
    for (int i = 0; source_files[i] != NULL; i++) 
    {
	char cmd[256];
	snprintf(cmd, sizeof(cmd),
		"%s %s/%s.c -o %s/%s.o %s \n"
		, compiler, object_fpath, source_files[i], object_fpath, source_files[i], flags);
	printf(cmd);
    }
}
