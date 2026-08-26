#include "header.h"

void file_exporting(const char *program_name, const char *config_name, const char *file_extention)
{
	const char *dest_fp_template = "%s/%s/%s";

	size_t file_path_size = 1;
	size_t fp_size = 1;

	if (file_extention == NULL)
	{
		fp_size += strlen(config_name);
	}
	else
	{
		fp_size += string_size(NULL, false, dest_fp_template, "%s%s", config_name, file_extention);
	}

	char *config_file_name = malloc((size_t)fp_size);
	if (config_file_name == NULL)
		error_message(MALLOC_FAIL);

	if (file_extention == NULL)
	{
		snprintf(config_file_name, (size_t)fp_size, "%s", config_name);
	}
	else
	{
		snprintf(config_file_name, (size_t)fp_size, "%s%s", config_name, file_extention);
	}

	void *arr[4] = { config_file_name, NULL, NULL, NULL };
	file_path_size += fp_size;
	file_path_size += string_size(arr, false, dest_fp_template, config_path, program_name, config_name);

	char *dest_fp = malloc((size_t)file_path_size); /* allocate memory */
	snprintf(dest_fp, (size_t)file_path_size, dest_fp_template, config_path, program_name, config_file_name); /* write to memory/buffer */

	char *source_path_template = "%s/%s/%s";
	arr[1] = dest_fp;
	size_t source_path_size = string_size(arr, true, source_path_template, inpath, program_name, config_file_name);

	char *source_path = malloc(source_path_size);	/* allocate memory */

	snprintf(source_path, source_path_size, source_path_template, inpath, program_name, config_file_name);
	free(config_file_name);
	arr[0] = source_path;	/* add to the arr (buffers to free) 
	also overwrites the config_file_name buffer at the same time */


	/* the 2 spaces are intentional, the command expects 2 arguments separated by a space */
	char *exporting_cmd_template = "cp -f %s %s";
	size_t exporting_cmd_size = 1 + string_size(arr, false, exporting_cmd_template);
	exporting_cmd_size += file_path_size + source_path_size;

	char *exporting_cmd = malloc(exporting_cmd_size); /* allocate memory */
	snprintf(exporting_cmd, exporting_cmd_size, exporting_cmd_template, source_path, dest_fp);

	if (verbose)
	{
		printf("%s\n", dest_fp);
		printf("%s\n", source_path);
		printf("%s\n", exporting_cmd);
	}
	free(dest_fp);
	free(source_path);
	
	system(exporting_cmd); /* execute final command */
	free(exporting_cmd);
}

size_t string_size(void *buf_to_free[], bool terminate, const char *restrict format, ...)
{
	va_list args;
	va_start(args, format);
	int return_value = vsnprintf(NULL, 0, format, args);
	va_end(args);

	if (return_value >= 0)
	{
		free_buffers(buf_to_free);
		error_message(INVALID_BUFFER_SIZE);
	}

	size_t size = (size_t)return_value;
	if (terminate)
	{
		size++;
	}
	return size;
}
