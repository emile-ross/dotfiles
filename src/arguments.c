#include "header.h"

#include "programs.h"
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

	/* checks if the command was ran with the --noconfirm flag */
	if (strcmp(cmd_arg_v[argi], "--noconfirm") == 0) 
	{
		printf(BOLD_S"Proceeding with full install\n"STYLE_END);
		/* full_install(true, true);*/
	}
	else if (strcmp(cmd_arg_v[argi], "-p") == 0 || strcmp(cmd_arg_v[argi], "-P") == 0)
	{
		if (num_cmd_arguments >= n_to_arg)
		{
			for (int i = n_to_arg - argi; i < num_cmd_arguments; i++)
			{
				install_package(parent_d, cmd_arg_v[i]); 
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
	}
	else if (strcmp(cmd_arg_v[argi], "-i") == 0)
	{
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
	exit(0);
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
