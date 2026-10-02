#include "header.h"

/* returns the VAWSM variable */
float* get_version(void) 
{
	/* create path to config */
	char *hyprpath_template = "%s/.config/hypr/hyprland.conf";
	size_t hyprpath_size = 1 + (size_t)snprintf(NULL, 0, hyprpath_template, home);
	char *hyprpath = malloc(hyprpath_size);
	if (hyprpath == NULL)
		error_message(MALLOC_FAIL);

	snprintf(hyprpath, hyprpath_size, hyprpath_template, home);
	/* set the hyprland path with username */

	/* open the file with hyprpath */
	FILE *file = fopen(hyprpath, "r");
	free(hyprpath);
	
	/* return error message when file isn't found */
	if (file == NULL) 
	{
		/* error message no such file or directory */
		error_message(NO_SUCH_FILE_OR_DIR);
		/* returns null if the file can't be opened/found */
		return NULL;
	}

	static float VAWSM[32] = {0};
	
	char *line = malloc(512);
	if (line == NULL)
		error_message(MALLOC_FAIL);
		
	while (fgets(line, sizeof(line), file)) 
	{
		/* this is true if the line contains:
		 * "# AWSMVERSION: " followed by a floating point number ranging from 0 to 9 */
		if (sscanf(line, "# AWSMVERSION: %31f[0-9.]", VAWSM) == 1)
		{
			fclose(file);
			free(line);
			return VAWSM;
		}
	}
	fclose(file);
	free(line);
	return 0;
}
