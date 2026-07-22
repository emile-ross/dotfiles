#include "header.h"

#include <stdint.h>

void cli_arg_missing(char *first_command, char *type_of_missing_arg, char *user_flag_t)
{
	/* prints an error message if there isn't a package specified in the command */
	printf(BOLD_S ANSI_RED"%s: missing %s after -- '%s'\n"STYLE_END, first_command, type_of_missing_arg, user_flag_t);
}

int parse_arguments(int num_cmd_arguments, char *cmd_arg_v[])
{
	const uint8_t min_args = 1;
	uint8_t argi = min_args;
	if (num_cmd_arguments > min_args) /* checks how many arguments were used */
	{
		/* checks if the command was ran with the --noconfirm flag */
		if (strcmp(cmd_arg_v[argi], "--noconfirm") == 0) 
		{
			printf(BOLD_S"Proceeding with full install\n"STYLE_END);
			full_install(true, true);
		}
		else if (strcmp(cmd_arg_v[argi], "-p") == 0 || strcmp(cmd_arg_v[argi], "-P") == 0)
		{
			if (num_cmd_arguments >= n_to_arg)
			{
				for (int i = n_to_arg - argi; i < num_cmd_arguments; i++)
				{
					install_package(parent, cmd_arg_v[i]); 
				}
			}
			else
			{
				/* prints an error message if there isn't a package specified in the command */
				cli_arg_missing(cmd_arg_v[0], "package", cmd_arg_v[argi]);
				error_message(CLI_ARGS_MISSING);
			}
		}
		else if (strcmp(cmd_arg_v[argi], "-c") == 0)
		{
			config_name config_to_install = detect_config_name(cmd_arg_v[2]);
			int ret_value = config_fn_exec(config_to_install, true, false, 0.0);

			const size_t package_str_length = 100;
			char *package_name_str = malloc(package_str_length);

			if (ret_value != 0)
			{
				while (1)
				{
					char buffer[package_str_length];
					printf(ANSI_RED"Invalid package name\n"STYLE_END"Type package name: ");

					if (fgets(buffer, (int)package_str_length, stdin) == NULL)
					{
						fprintf(stderr, ANSI_RED"Failed to parse input.\n"STYLE_END);
						wait_for_timeout(0, SHORT_TIMER);
					}

					/* calculate string length for trailing newline removal */
					size_t len = strlen(buffer);
					if (len > 0 && buffer[len - 1] == '\n')
					{
						/* replace trailing \n with a NULL terminator */
						buffer[len - 1] = '\0';
					}

					config_name config_type = detect_config_name(buffer);
					
					ret_value = config_fn_exec(config_type, true, false, 0.0);
					if (ret_value == 0)
					{
						int ret = snprintf(package_name_str, package_str_length, "%s", buffer);
						/* if this condition is false, the string was truncated */
						if (!(ret > (int)package_str_length))
						{
							break;
						}
					}
					printf("\n");
				}
			}
			else
			{
				snprintf(package_name_str, package_str_length, "%s", cmd_arg_v[2]);
			}

			if (ret_value == 0)
			{
				printf(ANSI_GREEN"Successfully installed %s config\n"STYLE_END, package_name_str);
			}
			free(package_name_str);
		}
		else if (strcmp(cmd_arg_v[argi], "-i") == 0)
		{
			/* loops through the arguments in order to pass them one at a time */
			if (num_cmd_arguments >= n_to_arg)
			{
			    	for (int i = n_to_arg - argi; i < num_cmd_arguments; i++)
			    	{
					/* will print a short description for the package
					 *config_description(); */
					config_name description_index = detect_config_name(cmd_arg_v[i]);
					
					if ((config_name)description_index > n_configs)
					{
						error_message((error_code_e)CLI_ARGS_MISSING);
					}
					else if ((config_name)description_index == 0)
					{
						error_message((error_code_e)CLI_UNKNOWN_PKG);
					}
					char *description = description_arr[(config_name)description_index];
					printf("%s\n", description);
			    	}
			}
			else
			{
			    	/* prints an error message if there isn't a package specified in the command */
			    	cli_arg_missing(cmd_arg_v[0], "package", cmd_arg_v[argi]);
			    	error_message(CLI_ARGS_MISSING);
			}
		}
		else if (strcmp(cmd_arg_v[argi], "--help") == 0)
		{
			printf(BOLD_S"Help menu\n"STYLE_END);

			printf("--noconfirm     [CONFIG NAME] \n");
			printf("	install all configs and packages without confirmations\n");
			printf("-c              [CONFIG NAME] \n");
			printf("	apply specified config \n");
			printf("-i              [CONFIG NAME] \n");
			printf("	print a short description of the package\n");
			printf("-p              [PACKAGE] \n");
			printf("	install specified package \n");
		}
		else if (strcmp(cmd_arg_v[argi], "-v") == 0 || strcmp(cmd_arg_v[argi], "--version") == 0)
		{
			float program_version = *get_version();
			printf("Version is: "BOLD_S"%.2lf\n"STYLE_END, program_version);
		}
		else
		{
			/* triggers the "invalid command line argument" error
			 * this is a critical error and it will crash the program */
			printf(BOLD_S ANSI_RED"%s: invalid option -- '%s'\n"STYLE_END, cmd_arg_v[0], cmd_arg_v[argi]);
			error_message(CLI_INVALID_FLAG);
		}
	}
	else
	{
		/* if no argument is found (most cases) */
		return 0;
	}
	exit(0);
}

void argument_config_install(char *package_t, char archiving_t, char pkginstall_t)
{
	float version = 0.0;
	
	bool package_bl = y_n(pkginstall_t);
	bool archive_bl = y_n(archiving_t);

	config_fn_exec(detect_config_name(package_t), archive_bl, package_bl, version);
}

void cmd_arg_install(int num_cmd_arguments_t, char *cmd_arg_v_t[], char config_archive_t, char pkg_install_t)
{
	if (num_cmd_arguments_t >= n_to_arg)
	{
		for (int i = n_to_arg - 1; i < num_cmd_arguments_t; i++)
		{
			/* support for different operating systems might come in the future...
			 * will print the arguments instead of executing the command (useless) */
			argument_config_install(cmd_arg_v_t[i], config_archive_t, pkg_install_t);
		}
	}
	else
	{
		/* prints an error message if there isn't any config name specified in the command */
		cli_arg_missing(cmd_arg_v_t[0], "config name", cmd_arg_v_t[1]);
		error_message(CLI_ARGS_MISSING);
	}
}

config_name detect_config_name(char *input) 
{
	char *HYPR_ARG_NAME[5] = 
	{
		"hyprland",
		"Hyprland",
		"hypr",
		"Hypr",
		NULL,
	};
	char *NVIM_ARG_NAME[6] = 
	{
		"nvim",
		"neovim",
		"Neovim",
		"NeoVim",
		"Nvim",
		NULL,
	};
	
	/* match the name to the correct config name */
	if (strcmp(input, "bash") == 0) return bash;
	if (strcmp(input, "bpytop") == 0) return bpyt;
	if (strcmp(input, "btop") == 0) return btop;
	if (strcmp(input, "cava") == 0) return cava;
	if (strcmp(input, "fastfetch") == 0) return fast;
	if (strcmp(input, "fuzzel") == 0) return fuzz;
	if (strcmp(input, "gtklock") == 0) return gtkl;
	if (strcmp(input, HYPR_ARG_NAME[0]) == 0) return hypr;
	if (strcmp(input, "kitty") == 0) return kitt;
	if (strcmp(input, "mpv") == 0) return mpvf;
	if (strcmp(input, "nvim") == 0) return nvim;
	if (strcmp(input, "sway") == 0) return sway;
	if (strcmp(input, "waybar") == 0) return wayb;
	if (strcmp(input, "zsh") == 0) return zshh;
	
	/* alternative names
	 * check for hyprland */
	int i = 1;
	while (HYPR_ARG_NAME[i] != NULL)
	{
	    	if (strcmp(input, HYPR_ARG_NAME[i]) == 0) return hypr;
	    	i++;
	}
	/* check for nvim */
	i = 1;
	while (NVIM_ARG_NAME[i] != NULL)
	{
	    	if (strcmp(input, NVIM_ARG_NAME[i]) == 0) return nvim;
	    	i++;
	}
	
	if (strcmp(input, "swaywm") == 0) return sway;
	if (strcmp(input, "fast") == 0) return fast;
	if (strcmp(input, "bpyt") == 0) return bpyt;
	if (strcmp(input, "gtkl") == 0) return gtkl;
	if (strcmp(input, "wayb") == 0) return wayb;
	if (strcmp(input, "fuzz") == 0) return fuzz;
	return unknown;
}

int config_fn_exec(config_name config_type, bool archive_bl, bool package_bl, float version)
{
	switch (config_type) 
	{
	case bash:
		BASH();
		break;
	
	case bpyt:
		BPYT(archive_bl, package_bl);
		break;
	
	case btop:
		BTOP(archive_bl, package_bl);
		break;
	
	case cava:
		CAVA(archive_bl, package_bl);
	    	break;
	
	case fast:
		FAST(archive_bl, package_bl);
	    	break;
	
	case fuzz:
		FUZZ(archive_bl, package_bl);
	    	break;
	
	case gtkl:
		GTKL(archive_bl, package_bl);
	    	break;
	
	case hypr:
		HYPR(archive_bl, package_bl);
	    	break;
	
	case kitt:
		KITT(archive_bl, package_bl);
	    	break;
	
	case mpvf:
		MPVF(archive_bl, package_bl);
	    	break;
	
	case nvim:
		NVIM(archive_bl, package_bl);
	    	break;
	
	case sway:
		SWAY(archive_bl, package_bl);
	    	break;
	
	case wayb:
		WAYB(archive_bl, package_bl);
	    	break;
	
	case zshh:
		ZSHH(archive_bl, version, package_bl);
	    	break;
	
	default:
		return 1;
	}
	
	return 0;
}
