#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define COMPILER_NAME_SIZE 16

char object_fpath[12] = "c-scripts";
char source_fpath[12] = "c-scripts";

char error_flag[16] = " -Werror";

char output_binary_name[16] = "setup";

char *base_flags = "-Wall -Wextra -Wpedantic";

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
void compilation(compiler_enum compiler_name_temp, bool error_flag_temp);

//extern compiler_enum compiler_name_def;

int main(int argc, char *argv[])
{
    char compiler_name_cmd[COMPILER_NAME_SIZE];
    compiler_name_cmd[0] = '\0';

    // declare compiler_name enum
    compiler_enum compiler_name;

    bool treat_as_errors = false;
    bool compile_op = true;

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
	else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-e") == 0)
	{
    	    treat_as_errors = true;
	}
    	else if (strcmp(argv[i], "clean") == 0)
    	{
	    clean_objects();
	    compile_op = false;	// ignore the compilation step
    	}
    	else
    	{
    	    printf("Unknown argument: %s\n", argv[i]);
    	}
    }

    
    if (compile_op)
    {
	compilation(compiler_name, treat_as_errors);
    }
    return 0;
}

void compile_all_files(char *compiler, char *flags)
{
    for (int i = 0; source_files[i] != NULL; i++) 
    {
        char cmd[256];
        snprintf(cmd, sizeof(cmd),
        	"%s %s/%s.c -o %s/%s.o %s \n"
        	, compiler, source_fpath, source_files[i], object_fpath, source_files[i], flags);
	system(cmd);
    }
}

void link_object_files(compiler_enum compiler_name_def, char *flags)
{
    // define the memory needed for the command buffer
    int buffer_size_flags = snprintf(NULL, 0,
	    "%s -o -c", flags);
    ssize_t num_src_files = (sizeof(source_files) / sizeof(source_files[0]) -1 );

    int size_obj_fpath = sizeof(object_fpath) + size_source_filename + 8;
    char temp_obj_path[size_obj_fpath];

    // set object buffer size based on the size of path+filename
    int obj_buffer_size = sizeof(temp_obj_path) * num_src_files;

    char source_files_obj_cmd[obj_buffer_size];
    source_files_obj_cmd[0] = '\0';

    // calculate total command buffer size
    // this avoids all buffer overflows since it is based on the size of 
    // all the strings composing this command
    int link_cmd_size = COMPILER_NAME_SIZE + obj_buffer_size + buffer_size_flags;
    char link_cmd[link_cmd_size];


    for (int i = 0; num_src_files > i; i++)
    {
	snprintf(temp_obj_path, size_obj_fpath,
		"%s/%s.o ", object_fpath, source_files[i]);
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
        char cmd[256];
        snprintf(cmd, sizeof(cmd),
        	"rm %s/%s.o"
        	, object_fpath, source_files[i]);
	system(cmd);
    }
}


void compilation(compiler_enum compiler_name_temp, bool error_flag_temp)
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
    
    char all_flags[128];
    if (error_flag_temp == true )
    {
        snprintf(all_flags, sizeof(all_flags),
        	"%s %s", base_flags, error_flag);
    }
    else
    {
        snprintf(all_flags, sizeof(all_flags),
        	"%s ", base_flags);
    }
    
    compile_all_files(compiler_name_cmd_temp, all_flags);
    link_object_files(compiler_name_temp, all_flags);
}
