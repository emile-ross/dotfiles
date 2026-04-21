#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define COMPILER_NAME_SIZE (16)

char object_fpath[16] = "c-scripts/";
char source_fpath[16] = "c-scripts/";

const char output_binary_name[16] = "setup";	/* set the name of the binary file */

/* Warnings flags */
#define FLAG_BUFFER_SIZE (16)

const char *base_flags = " -W";
const char Wextra_flag[FLAG_BUFFER_SIZE] = " -Wextra";
const char Werror_flag[FLAG_BUFFER_SIZE] = " -Werror";
const char Wpedantic_flag[FLAG_BUFFER_SIZE] = " -Wpedantic";
const char Wall_flag[FLAG_BUFFER_SIZE] = " -Wall";
const char c99_flag[FLAG_BUFFER_SIZE] = " -std=c99";
const char Wconversion_flag[FLAG_BUFFER_SIZE] = " -Wconversion";

int num_flags = 0;

int size_source_filename = 24;

const char *source_files[] = 
{ 
    "arguments",
    "configuring",
    "error-handling",
    "functions",
    "programs",
    "globals",
    "install",
    "setup",
    "update",
    NULL 
};

typedef enum 
{
    CLANG,
    ZIG,
    GCC
} compiler_enum;

void clean_objects(void);
void compile_all_files(char *compiler, char *flags);
void link_object_files(compiler_enum compiler_name_def, char *flags);
void compilation(compiler_enum compiler_name_temp, bool error_flag_temp_bl, bool pedantic_flag_temp_bl, bool all_flag_temp_bl, bool extra_flag_temp_bl, bool c99_flag_temp_bl, bool conversion_bl);

int main(int argc, char *argv[])
{
    /* declare compiler_name enum */
    compiler_enum compiler_name;

    bool Werror_flag_bl = false;    /* default is false */
    bool Wpedantic_bl = false;	    /* default is false */
    bool Wall_flag_bl = false;	    /* default is false */
    bool Wextra_flag_bl = false;    /* default is false */
    bool c99_flag_bl = false;	    /* default is false */
    bool Wconversion_bl = false;    /* default is false */ 

    bool compile_bl = true;	    /* default is true */

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
	    Wextra_flag_bl = true;
	    Wconversion_bl = true;
	    num_flags += 4;
    	}
	else if (strcmp(argv[i], "-c") == 0)
	{
	    Wconversion_bl = true;
	    num_flags++;
	}
	else if (strcmp(argv[i], "-a") == 0)
	{
	    Wall_flag_bl = true;
	    num_flags++;
	}
	else if (strcmp(argv[i], "-x") == 0)
	{
    	    Wextra_flag_bl = true;
	    num_flags++;
	}
	else if (strcmp(argv[i], "-e") == 0)
	{
    	    Werror_flag_bl = true;
	    num_flags++;
	}
	else if (strcmp(argv[i], "-c99") == 0)
	{
	    c99_flag_bl = true;
	    num_flags++;
	}
    	else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "pedantic") == 0)
    	{
	    Wpedantic_bl = true;
	    num_flags++;
    	}
    	else if (strcmp(argv[i], "clean") == 0)
    	{
	    clean_objects();
	    compile_bl = false;	/* ignore the compilation step */
    	}
    	else if (strcmp(argv[i], "std") == 0)
	{
    	    compiler_name = ZIG;

	    c99_flag_bl = true;
	    Wall_flag_bl = true;
	    Wpedantic_bl = true;
	    Wextra_flag_bl = true;
	    Wconversion_bl = true;
	    num_flags += 5;
	}
    	else
    	{
    	    printf("Unknown argument: %s\n", argv[i]);
    	}
    }
    
    if (compile_bl)
    {
	compilation(compiler_name, Werror_flag_bl, Wpedantic_bl, Wall_flag_bl, Wextra_flag_bl, c99_flag_bl, Wconversion_bl);
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
	system(cmd);
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
    system(link_cmd);
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

void compilation(compiler_enum compiler_name_temp, bool error_flag_temp_bl, bool pedantic_flag_temp_bl, bool all_flag_temp_bl, bool extra_flag_temp_bl, bool c99_flag_temp_bl, bool conversion_bl)
{
    char compiler_name_cmd_temp[COMPILER_NAME_SIZE];
    compiler_name_cmd_temp[0] = '\0';
    switch (compiler_name_temp)
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
    
    int size_all_flags_temp = num_flags * FLAG_BUFFER_SIZE ;
    size_all_flags_temp++;

    char all_flags[size_all_flags_temp];    /* initialize the all_flags buffer */
    snprintf(all_flags, sizeof(all_flags), "%s", base_flags);	/* move base flags to all_flags */

    if (error_flag_temp_bl == true)
    {
	/* append error flags to the end of the all_flags buffer */
        strcat(all_flags, Werror_flag);	
    }

    if (num_flags > 0)
    {
	if (pedantic_flag_temp_bl == true)
    	{
    	    /* append Wpedantic flag to the end of the all_flags buffer */
    	    strcat(all_flags, Wpedantic_flag);   
    	}

    	if (extra_flag_temp_bl == true)
    	{
    	    /* append extra flag to the end of the all_flags buffer */
    	    strcat(all_flags, Wextra_flag);   
    	}

    	if (all_flag_temp_bl == true)
    	{
    	    strcat(all_flags, Wall_flag);   
    	}

    	if (c99_flag_temp_bl)
    	{
    	    strcat(all_flags, c99_flag);   
    	}

	if (conversion_bl)
	{
	    strcat(all_flags, Wconversion_flag);
	}
    }

    compile_all_files(compiler_name_cmd_temp, all_flags);
    link_object_files(compiler_name_temp, all_flags);
}
