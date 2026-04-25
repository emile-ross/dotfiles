#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define COMPILER_NAME_SIZE (16)

char object_fpath[16] = "c-scripts/";
char source_fpath[16] = "c-scripts/";

const char output_binary_name[16] = "setup";	/* set the name of the binary file */

bool verbose = false;   /* default is false */ 

/* Warnings flags */
#define FLAG_BUFFER_SIZE (18)
#define LOGGING_CMD_SIZE (48)

const char *base_flags = " -W";
const char Wextra_flag[FLAG_BUFFER_SIZE] = " -Wextra";
const char Werror_flag[FLAG_BUFFER_SIZE] = " -Werror";
const char Wpedantic_flag[FLAG_BUFFER_SIZE] = " -Wpedantic";
const char Wall_flag[FLAG_BUFFER_SIZE] = " -Wall";
const char c99_flag[FLAG_BUFFER_SIZE] = " -std=c99";
const char Wconversion_flag[FLAG_BUFFER_SIZE] = " -Wconversion";

const char logging_cmd[LOGGING_CMD_SIZE] = " 2>&1 | tee compile_log.txt"; /* this will overwrite the compile_log.txt */

int size_all_flags;
int size_source_filename = 24;

#define num_src_files (9)

const char *source_files[] = 
{ 
    "arguments",
    "configuring",
    "error-handling",
    "functions",
    "globals",
    "install",
    "programs",
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
void compile_all_files(bool log, char *compiler, char *flags);
void link_object_files(bool log, compiler_enum compiler_name_def, char *flags);
void compilation(int number_flags, compiler_enum compiler_name_temp, bool log_bl, bool error_flag_temp_bl, bool pedantic_flag_temp_bl, bool all_flag_temp_bl, bool extra_flag_temp_bl, bool c99_flag_temp_bl, bool conversion_bl);

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

    bool compile_bl = true; /* default is true */
    bool log_bl = false;    /* default is false */


    int num_flags = 0;

    /* convert command line arguments to flags/compiler/options */
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
    	else if (strcmp(argv[i], "log") == 0)
	{
	    log_bl = true;
	}
    	else if (strcmp(argv[i], "-v") == 0)
	{
	    verbose = true;
	}
    	else
    	{
    	    printf("Unknown argument: %s\n", argv[i]);
    	}
    }
    
    if (compile_bl)
    {
	compilation(num_flags, compiler_name, log_bl, Werror_flag_bl, Wpedantic_bl, Wall_flag_bl, Wextra_flag_bl, c99_flag_bl, Wconversion_bl);
    }
    return 0;
}

void compile_all_files(bool log, char *compiler, char *flags)
{
    int base_size = 1;
    if (log)
    {
	base_size += LOGGING_CMD_SIZE;
    }

    for (int i = 0; source_files[i] != NULL; i++) 
    {
	int command_size = base_size + snprintf(NULL, 0,
        	"%s %s%s.c -o %s%s.o%s "
        	, compiler, source_fpath, source_files[i], object_fpath, source_files[i], flags);
		
        char cmd[command_size];
        snprintf(cmd, sizeof(cmd),
        	"%s %s%s.c -o %s%s.o%s "
        	, compiler, source_fpath, source_files[i], object_fpath, source_files[i], flags);
	if (log)
	{
	    strcat(cmd, logging_cmd);
	}
	if (verbose)
	{
	    printf("%s\n", cmd);
	}
	system(cmd);
    }
}

void link_object_files(bool log, compiler_enum compiler_name_def, char *flags)
{
    /* define the memory needed for the command buffer */
    int buffer_size_flags = snprintf(NULL, 0,
	    "%s -o -c", flags);

    int buf_size[num_src_files];

    int total_obj_path_size = 1;
    /* first loop to get the size of each object path
     * and then store it in an array of sizes */
    for (int i = 0; source_files[i] != NULL; i++)
    {
	int temp_obj_path_size = snprintf(NULL, 0,
		" %s%s.o ", object_fpath, source_files[i]);
	temp_obj_path_size++;
	buf_size[i] = temp_obj_path_size;
	total_obj_path_size += temp_obj_path_size;
    }
    total_obj_path_size++;
    char source_files_obj_cmd[total_obj_path_size];
    source_files_obj_cmd[0] = '\0';

    int total_size = total_obj_path_size + buffer_size_flags + 1;

    for (int i = 0; num_src_files > i; i++)
    {
	char temp_obj_path[buf_size[i] + 1];
	snprintf(temp_obj_path, sizeof(temp_obj_path),
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
    total_size += snprintf(NULL, 0,
	    "%s %s %s", compiler_linking_string, output_binary_name, flags);
    total_size++;

    /* add the logging command buffer size if logging is enabled */
    if (log)
    {
	total_size += LOGGING_CMD_SIZE;
    }

    char link_cmd[total_size];
    snprintf(link_cmd, sizeof(link_cmd),
	    "%s %s -o %s %s", compiler_linking_string, source_files_obj_cmd, output_binary_name, flags);

    /* append the logging command if it's enabled */
    if (log)
    {
	strcat(link_cmd, logging_cmd);
    }
    if (verbose)
    {
	printf("%s\n", link_cmd);
    }
    system(link_cmd); /* execute the command */
}

void clean_objects(void)
{
    for (int i = 0; source_files[i] != NULL; i++) 
    {
	int buffer_size = snprintf(NULL, 0,
		"rm %s%s.o", object_fpath, source_files[i]);
        char cmd[buffer_size + 1];	/* initialize cmd buffer */
        snprintf(cmd, sizeof(cmd),
        	"rm %s%s.o"
        	, object_fpath, source_files[i]);

	if (verbose)
    	{
    	    printf("%s\n", cmd);
    	}

	system(cmd);
    }
}

void compilation(int number_flags, compiler_enum compiler_name_temp, bool log_bl, bool error_flag_temp_bl, bool pedantic_flag_temp_bl, bool all_flag_temp_bl, bool extra_flag_temp_bl, bool c99_flag_temp_bl, bool conversion_bl)
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
    
    /* calculate the size of all flags
     * you get the size by multiplying the number of flags by the size of each flag */
    int size_all_flags = number_flags * FLAG_BUFFER_SIZE ;
    size_all_flags++;

    char all_flags[size_all_flags];    /* initialize the all_flags buffer */
    snprintf(all_flags, sizeof(all_flags), "%s", base_flags);	/* move base flags to all_flags */

    if (error_flag_temp_bl)
    {
	/* append error flags to the end of the all_flags buffer */
        strcat(all_flags, Werror_flag);	
    }

    if (number_flags > 0)
    {
	if (pedantic_flag_temp_bl)
    	{
    	    /* append Wpedantic flag to the end of the all_flags buffer */
    	    strcat(all_flags, Wpedantic_flag);   
    	}

    	if (extra_flag_temp_bl)
    	{
    	    /* append Wextra flag to the end of the all_flags buffer */
    	    strcat(all_flags, Wextra_flag);   
    	}

    	if (all_flag_temp_bl)
    	{
    	    /* append Wall flag to the end of the all_flags buffer */
    	    strcat(all_flags, Wall_flag);   
    	}

    	if (c99_flag_temp_bl)
    	{
    	    /* append -std=c99 flag to the end of the all_flags buffer */
    	    strcat(all_flags, c99_flag);   
    	}

	if (conversion_bl)
	{
    	    /* append -Wconversion flag to the end of the all_flags buffer */
	    strcat(all_flags, Wconversion_flag);
	}
    }

    compile_all_files(log_bl, compiler_name_cmd_temp, all_flags);
    link_object_files(log_bl, compiler_name_temp, all_flags);
}
