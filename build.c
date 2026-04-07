#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define COMPILER_NAME_SIZE 16

char object_fpath[16] = "c-scripts/";
char source_fpath[16] = "c-scripts/";

char output_binary_name[16] = "setup";

// Warnings flags
char *base_flags = " -Wextra";
char error_flag[16] = " -Werror";
char pedantic_flag[16] = " -Wpedantic";
char Wall_flag[16] = " -Wall";

int size_source_filename = 24;

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

void clean_objects(void);
void compile_all_files(char *compiler, char *flags);
void link_object_files(compiler_enum compiler_name_def, char *flags);
void compilation(compiler_enum compiler_name_temp, bool error_flag_temp, bool pedantic_flag_bl, bool Wall_bl);

int main(int argc, char *argv[])
{
    /* declare compiler_name enum */
    compiler_enum compiler_name;

    bool treat_as_errors = false;   // default is false
    bool Wpedantic_bl = false;	    // default is false
    bool Wall_flag_bl = false;	    // default is false

    bool compile_bl = true;

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
    	else if (strcmp(argv[i], "--base") == 0)
    	{
	    Wall_flag_bl = true;
	    Wpedantic_bl = true;
    	}
	else if (strcmp(argv[i], "-a") == 0)
	{
	    Wall_flag_bl = true;
	}
	else if (strcmp(argv[i], "-e") == 0)
	{
    	    treat_as_errors = true;
	}
    	else if (strcmp(argv[i], "clean") == 0)
    	{
	    clean_objects();
	    compile_bl = false;	/* ignore the compilation step */
    	}
    	else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "pedantic") == 0)
    	{
	    Wpedantic_bl = true;
    	}
    	else
    	{
    	    printf("Unknown argument: %s\n", argv[i]);
    	}
    }
    
    if (compile_bl)
    {
	compilation(compiler_name, treat_as_errors, Wpedantic_bl, Wall_flag_bl);
    }
    return 0;
}

void compile_all_files(char *compiler, char *flags)
{
    for (int i = 0; source_files[i] != NULL; i++) 
    {
        char cmd[256];
        snprintf(cmd, sizeof(cmd),
        	"%s %s%s.c -o %s%s.o%s \n"
        	, compiler, source_fpath, source_files[i], object_fpath, source_files[i], flags);
	//system(cmd);
	printf(cmd);
    }
}

void link_object_files(compiler_enum compiler_name_def, char *flags)
{
    /* define the memory needed for the command buffer */
    int buffer_size_flags = snprintf(NULL, 0,
	    "%s -o -c", flags);
    long num_src_files = (sizeof(source_files) / sizeof(source_files[0]) - 1);

    int size_obj_fpath = sizeof(object_fpath) + size_source_filename + 8;
    char temp_obj_path[size_obj_fpath];

    /* set object buffer size based on the size of path+filename */
    int obj_buffer_size = sizeof(temp_obj_path) * num_src_files;

    char source_files_obj_cmd[obj_buffer_size];
    source_files_obj_cmd[0] = '\0';

    /* calculate total command buffer size
    this avoids all buffer overflows since it is based on the size of 
    all the strings composing this command */
    int link_cmd_size = COMPILER_NAME_SIZE + obj_buffer_size + buffer_size_flags;
    char link_cmd[link_cmd_size];

    for (int i = 0; num_src_files > i; i++)
    {
	snprintf(temp_obj_path, size_obj_fpath,
		"%s%s.o ", object_fpath, source_files[i]);
	strcat(source_files_obj_cmd, temp_obj_path);
    }

    char compiler_linking_string[COMPILER_NAME_SIZE];
    switch(compiler_name_def)
    {
	case CLANG:
	    snprintf(compiler_linking_string, COMPILER_NAME_SIZE - 1,
		    "clang");
	    break;
	case GCC:
	    snprintf(compiler_linking_string, COMPILER_NAME_SIZE - 1,
		    "gcc");
	    break;
	case ZIG:
	    snprintf(compiler_linking_string, COMPILER_NAME_SIZE - 1,
		    "zig cc");
	    break;
        default: 
	    printf("Unknown compiler\n");
	    exit(1);
    }

    snprintf(link_cmd, sizeof(link_cmd),
	    "%s %s -o %s %s", compiler_linking_string, source_files_obj_cmd, output_binary_name, flags);
    //system(link_cmd);
    printf(link_cmd);
}

void clean_objects(void)
{
    for (int i = 0; source_files[i] != NULL; i++) 
    {
        char cmd[128];	/* initialize cmd buffer */
        snprintf(cmd, sizeof(cmd),
        	"rm %s%s.o"
        	, object_fpath, source_files[i]);
	system(cmd);
    }
}

void compilation(compiler_enum compiler_name_temp, bool error_flag_temp, bool pedantic_flag_bl, bool Wall_bl)
{
    char compiler_name_cmd_temp[COMPILER_NAME_SIZE];
    compiler_name_cmd_temp[0] = '\0';
    switch(compiler_name_temp)
    {
        case CLANG:
            strncpy(compiler_name_cmd_temp, "clang -c", COMPILER_NAME_SIZE - 1);
            break;
        case GCC:
            strncpy(compiler_name_cmd_temp, "gcc -c", COMPILER_NAME_SIZE - 1);
            break;
        case ZIG:
            strncpy(compiler_name_cmd_temp, "zig cc -c", COMPILER_NAME_SIZE - 1);
            break;
        default: 
            printf("Unknown compiler\n");
	    exit(1);
    }
    
    char all_flags[128];    /* initialize the all_flags buffer */
    snprintf(all_flags, sizeof(all_flags), "%s", base_flags);	/* move base flags to all_flags */

    if (error_flag_temp == true)
    {
	/* append error flags to the end of the all_flags buffer */
        strcat(all_flags, error_flag);	
    }

    if (pedantic_flag_bl == true)
    {
	/* append pedantic flags to the end of the all_flags buffer */
	strcat(all_flags, pedantic_flag);   
    }

    if (Wall_bl == true)
    {
	strcat(all_flags, Wall_flag);   
    }

    compile_all_files(compiler_name_cmd_temp, all_flags);
    link_object_files(compiler_name_temp, all_flags);
}
