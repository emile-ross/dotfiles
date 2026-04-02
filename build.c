#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX 24

void compile_all_files(bool treat_as_errors, char *compiler, char *base_flags);

char *object_fpath = "c-scripts";
char *source_fpath = "c-scripts";

const char *source_files[] = { 
    "arguments",
    "configuring",
    "error-handling",
    "functions",
    "programs",
    "globals",
    "install",
    "setup",
    "update",
    NULL };

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

    bool verbose_log_output = false;

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
	else if (strcmp(argv[i], "error") == 0)
    	{
    	    verbose_log_output = true;
	}
	else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-e") == 0)
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

    compile_all_files(verbose_log_output, compiler_name_cmd, "-Wall -Wextra -Wpedantic");

    // link all files together

    return 0;
}

void compile_all_files(bool treat_as_errors, char *compiler, char *base_flags)
{
    char all_flags[128];
    if (treat_as_errors == true )
    {
	snprintf(all_flags, sizeof(all_flags),
		"%s -Werror", base_flags);
    }
    else
    {
	snprintf(all_flags, sizeof(all_flags),
		"%s ", base_flags);
    }

    for (int i = 0; source_files[i] != NULL; i++) 
    {
	char cmd[256];
	snprintf(cmd, sizeof(cmd),
		"%s %s/%s.c -o %s/%s.o %s \n"
		, compiler, source_fpath, source_files[i], object_fpath, source_files[i], all_flags);

    char *source_files_obj_cmd = NULL;
    char *link_cmd = compiler;

    strcat(link_cmd, source_files_obj_cmd);
	  printf("%s", link_cmd);
    }
}
