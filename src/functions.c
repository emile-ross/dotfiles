#include "dotfileshead.h"
#include <limits.h>

void clear(void)
{
	/* clears the screen */
	printf("\033[2J\033[H");
}

void clearbuffer(void)
{
	/* clears the imput buffer */
	while (getchar() != '\n');

	if (verbose)
	{
		printf("Buffer was cleared\n");
	}
}

void block(const bool prompt)
{
	if (prompt)
	{
	    	printf("Press any key to continue\n");
	}

	if (verbose)
	{
		printf("(Execution flow is blocked)\n");
	}
	
	getchar();
}

void pre_startup(void)
{
	get_os_name();
	is_debian_bl = false;
	is_arch_bl = false;
	
	if (strcmp(distro, "debian") == 0 || strcmp(distro, "ubuntu") == 0) 
	{
	    	is_debian_bl = true;
	    	/* sets debian as the parent distro of (debian) */
	    	snprintf(parent, sizeof(parent),
	    			"%s", distro);
	}
	else if (strcmp(distro, "arch") == 0)
	{
	    	is_arch_bl = true;
	    	/* sets arch as the parent distro of (arch) */
	    	snprintf(parent, sizeof(parent),
	    			"%s", distro);
	}
	else
	{
	    	error_message(UNSUPPORTED_DISTRO);
	}
	
	/* get home directory / username 
	 * and then, initialize [home] to the actual home dir */
	home = getenv("HOME");
	
	/* error message if username can't be fetched */
	if (home == NULL) 
	{
	    	error_message(FAIL_FIND_HOME_DIR);
	}
	/* Add user_config_path definition
	 * it needs to be the home dir + .config path */
	snprintf(config_path, sizeof(config_path),
			"%s/.config", home);

	/* get the current working directory */
	snprintf(inpath, sizeof(inpath), "%s", get_initial_path());
}

char *get_initial_path(void)
{
	/* change directory to the dotfiles root (if possible) */
	chdir("dotfiles/");
	
	FILE *fp;
	fp = popen("pwd", "r");
	
	if (fp == NULL) 
	{
	    	error_message(POPEN_FAILED);
	    	return NULL;
	}
	
	if (fgets(initial_path, sizeof(initial_path), fp) == NULL)
	{
		pclose(fp);
		return NULL;
	}
	
	initial_path[strcspn(initial_path, "\n")] = '\0';
	
	pclose(fp);
	return initial_path;
}

void wait_for_timeout(long quarters, long seconds)
{
	if (quarters < 4) /* 4 quarters per second */
	{
		quarters *= 250000000;   /* convert quarters to nanoseconds */
	}
	else
	{
		quarters = 0;
		seconds += 1;	/* adds 1 second if 4 >= quarters */
	}

	install_timer.tv_nsec = quarters;
    	install_timer.tv_sec = seconds;
    	nanosleep(&install_timer, NULL);
}


int get_os_name(void)
{
	/* open /etc/os-release */
	FILE *fp = fopen("/etc/os-release", "r");
	
	/* fallback to /usr/lib if /etc/os-release fails */
	if (!fp) fp = fopen("/usr/lib/os-release", "r"); 
	/* error checking */
	if (!fp) error_message(RENAME_FAIL);
	
	char t_line[256];

	while (fgets(t_line, sizeof(t_line), fp)) 
	{
		/* store the value after '=' in char val */
		char *val = strchr(t_line, '=') + 1;

		/* remove trailing newline */
		val[strcspn(val, "\"\n")] = '\0'; 
		
		if (strncmp(t_line, "ID=", 3) == 0) strcpy(distro, val);	    /* store the value in char distro */
		else if (strncmp(t_line, "ID_LIKE=", 8) == 0) strcpy(parent, val);  /* store the value in char parent */
	}

	/* close file */
	fclose(fp);
	return 0;
}

void exec_cmd(const int buffer_size, const char *command_to_execute)
{
	/* execute the command stored in command_to_execute
	 * using system() while ensuring output doesn't exceed buffer_size */
	char *command_exec = malloc((size_t)buffer_size);
	int return_value = snprintf(command_exec, (size_t)buffer_size, "%s", command_to_execute);

	if (return_value > buffer_size)
	{
		fprintf(stderr, "Failed to execute \"%s\"\n", command_to_execute);
		free(command_exec);
		error_message(CMD_EXEC_FAIL);
		exit(1);	/* in order to avoid a use after free */
	}
	system(command_exec);   /* execute command */

	free(command_exec);
}

void countdown(int counter, int lines_to_skip)
{
	/* total_time is the total time the execution should last 
	 * counter will be the variable used in the countdown */
	
	int total_time = counter;
	
	for (int i = 0; i < total_time; i++)
	{
		printf("%d ", counter);

		/* prints a "." to the screen each quarter of a second */
		for (int a = 0; a < 3; a++)
		{
			printf(".");
			fflush(stdout);
			wait_for_timeout(1, 0);
		}
	
		/* prints one newline everytime this is executed */
		for (int b = 0; b < lines_to_skip; b++)
		{
			printf("\n");
		}

		/* cant be replaced by LONG_TIMER since this needs to always be 1 seconds */
		wait_for_timeout(1, 0);	
		counter--;
	}
}

bool y_n(const char yes_no)
{
	if (yes_no == 'Y' || yes_no == 'y')
	{
		return true;
	}
	else if (yes_no == 'T' || yes_no == 't')
	{
	    	return true;
	}
	else
	{
		return false;
	}
}

void yes_no_prompt(void)
{
	printf(BOLD_S "\n  [1] Yes \n"STYLE_END);
	printf(BOLD_S "\n  [0] No \n"STYLE_END);
}

char *package_name(config_name config)
{
	switch (config)
	{
	case bash:
		return ".bashrc";
	case bpyt:
		return "bpytop config";
	case btop:
		return "btop config";
	case cava:
		return "cava config";
	case fast:
		return "fastfetch configs";
	case fuzz:
		return "fuzzel configs";
	case gtkl:
		return "gtklock config and style (appearance) ";
	case hypr:
		return "Hyprland-WM config + Hypridle config";
	case kitt:
		return "kitty terminal configs";
	case mpvf:
		return "mpv config";
	case nvim:
		return "neovim config with lazy";
	case sway:
		return "Sway-WM config";
	case wayb:
		return "waybar config and style (appearance)";
	case zshh:
		return "zsh config (.zshrc)";
	case unknown:
	default:
		return NULL;
	}
}

void verbose_path_print(char *file_path, char *file_name)
{
	printf("The %s file \nwas exported to: %s\n", file_name, file_path);
}

void link_file(const char *source_path, const char *link_path)
{
	char *link_command_path_template = "ln -sf %s %s";

	/* calculate the size of the string */
	int link_command_size = 1 + snprintf(NULL, 0, link_command_path_template, source_path, link_path);
	char *link_command = malloc((size_t)link_command_size); /* allocate memory */

	/* write to the buffer */
	snprintf(link_command, (size_t)link_command_size, link_command_path_template, source_path, link_path);

	/* execute the command */
	if (verbose)
	{
		printf("%s\n", link_command);
	}

	system(link_command);
	free(link_command);
}


void make_dir(const char *program_name)
{
	const char *directory_path_template = "mkdir -p %s/.config/%s/";

	/* calculate the directory_path string size */
	size_t directory_path_size = 1 + (size_t)snprintf(NULL, 0, directory_path_template, home, program_name);
	char *mkdir_cmd = malloc(directory_path_size);	/* allocate memory for the mkdir_cmd */

	/* write to the mkdir_cmd buffer */
	snprintf(mkdir_cmd, directory_path_size, directory_path_template, home, program_name);

	if (verbose)
	{
		printf("%s", mkdir_cmd);
	}

	system(mkdir_cmd);	/* execute command */
	free(mkdir_cmd);
}

long get_long(const char *message, const long lower_bound, const long upper_bound)
{
	const size_t max_size = 192;
	const int max_attempts = 6;
	int i = 0;

	char *input_buffer = malloc(max_size);

	while (1)
	{
		if (message != NULL)
			printf("%s ", message);

		long user_input = -1;
		char *endptr;

		if (fgets(input_buffer, (int)max_size, stdin) != NULL)
		{
			/* convert from string to long */
			user_input = strtol(input_buffer, &endptr, 10);

			/* avoids checking for \n by simply checking the number of characters
			 * contained in the endptr string 
			 * if the length is greater than 1, this means that the input contained 
			 * at least 1 invalid character (1 + 1) so 2 including \n */
			size_t invalid_input_length = strlen(endptr);	

			if (strcmp(input_buffer, endptr) == 0)
			{
				/* no number was found */
				if (i >= max_attempts)
				{
					free(input_buffer);
					error_message(INVALID_INPUT);
					exit(1);	/* avoid use after free */
				}
			}
			else if (invalid_input_length > 1)
			{
				/* some character was rejected since it isn't a number */
				if (i >= max_attempts)
				{
					free(input_buffer);
					error_message(INVALID_INPUT);
					exit(1);	/* avoid use after free */
				}
			}
			else if (user_input > upper_bound || user_input < lower_bound)	/* bound checking */
			{
				if (i >= max_attempts)
				{
					free(input_buffer);
					error_message(OOB_INPUT);
					exit(1);	/* avoid use after free */
				}
			}
			else
			{
				free(input_buffer);
				return user_input;
			}
		}
		else
		{
			if (i >= max_attempts)
			{
				printf("Failed to parse input.\n");
				free(input_buffer);
				error_message(INVALID_INPUT);
				exit(1);	/* avoid use after free */
			}
		}

		printf(UDRL_S"Invalid input"STYLE_END", try again\n");
		i++;
	}

	free(input_buffer);
	error_message(INPUT_FAIL);
	return -1;
}

/* unspecified array size 
 * the array must be null terminated */
int free_buffers(void *buffers_to_free[])
{
	if (buffers_to_free == NULL)
	{
		return 0;
	}

	uint8_t i = 0;
	do 
	{
		free(buffers_to_free[i]);
		i++;
	}
	while (buffers_to_free[i] != NULL && i < UINT8MAX);
	
	if (i >= UINT8MAX)
	{
		error_message(NON_NULL_TERMINATED);
	}

	return 0;
}
