#include "dotfileshead.h"

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

void block(bool prompt)
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
	
	if (strcmp(distro, "debian") == 0) 
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

void wait_for_timeout(int timer_quarters, int timer_seconds)
{
	if (timer_quarters < 4) /* 4 quarters per second */
	{
		time_timer_quarters = timer_quarters * 250000000;   /* convert quarters to nanoseconds */
		time_timer_seconds = timer_seconds;		    /* set seconds */
	}
	else
	{
		time_timer_quarters = 0;
		time_timer_seconds = timer_seconds + 1;	/* adds 1 second if 4 >= quarters */
	}

	install_timer.tv_nsec = time_timer_quarters;
    	install_timer.tv_sec = time_timer_seconds;
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

void exec_cmd(int buffer_size, char *command_to_execute)
{
	/* execute the command stored in command_to_execute
	 * using system() while ensuring output doesn't exceed buffer_size */
	char command_exec[buffer_size];
	snprintf(command_exec, sizeof(command_exec), "%s", command_to_execute);
	system(command_exec);   /* execute command */
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
			
		wait_for_timeout(1, 0);
		counter--;
	}
}

bool y_n(char yes_no)
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

void link_file(char *source_path, char *link_path)
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

void make_dir(char *program_name)
{
	char *directory_path_template = "mkdir -p %s/.config/%s";

	size_t directory_path_size = 1 + (size_t)snprintf(NULL, 0, directory_path_template, home, program_name);
	char *mkdir_cmd = malloc(directory_path_size);

	snprintf(mkdir_cmd, directory_path_size, directory_path_template, home, program_name);
	printf("%s", mkdir_cmd);
	free(mkdir_cmd);
}

