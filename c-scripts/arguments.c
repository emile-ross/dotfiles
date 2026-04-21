#include "dotfileshead.h"

void cli_arg_missing(char *first_command, char *type_of_missing_arg, char *user_flag_t)
{
    // prints an error message if there isn't a package specified in the command
    printf(BOLD_S ANSI_RED"%s: missing %s after -- '%s'\n"STYLE_END, first_command, type_of_missing_arg, user_flag_t);
}

int parse_arguments(int num_cmd_arguments, char *cmd_arg_v[])
{
    if (num_cmd_arguments > 1) // checks how many arguments were used
    {
	// checks if the command was ran with the --noconfirm flag

	if (strcmp(cmd_arg_v[1], "--noconfirm") == 0) 
	{
	    printf(BOLD_S"Proceeding with full install\n"STYLE_END);
	    full_install('y', 'y');
	}
	else if (strcmp(cmd_arg_v[1], "-p") == 0 || strcmp(cmd_arg_v[1], "-P") == 0)
	{
	    if (num_cmd_arguments >= n_to_arg)
	    {
		for (int i = n_to_arg - 1; i < num_cmd_arguments; i++)
		{
		    install_package(parent, cmd_arg_v[i]); 
		}
	    }
	    else
	    {
		// prints an error message if there isn't a package specified in the command
		cli_arg_missing(cmd_arg_v[0], "package", cmd_arg_v[1]);
		error_message(304);
	    }
	}
	else if (strcmp(cmd_arg_v[1], "-c") == 0 || strcmp(cmd_arg_v[1], "-C") == 0)
	{
	    if (strcmp(cmd_arg_v[1], "-C") == 0)
	    {
		error_message(7);
	    }
	    cmd_arg_install(num_cmd_arguments, cmd_arg_v, 'Y', 'N');
	}
	else if (strcmp(cmd_arg_v[1], "-i") == 0 || strcmp(cmd_arg_v[1], "-I") == 0)
	{
	    // loops through the arguments in order to pass them one at a time
	    if (strcmp(cmd_arg_v[1], "-I") == 0)
	    {
		error_message(7);
	    }

	    if (num_cmd_arguments >= n_to_arg)
	    {
		for (int i = n_to_arg - 1; i < num_cmd_arguments; i++)
		{
		    // will print a short description for the package
		    config_description(cmd_arg_v[i]);
		}
	    }
	    else
	    {
		// prints an error message if there isn't a package specified in the command
		cli_arg_missing(cmd_arg_v[0], "package", cmd_arg_v[1]);
		error_message(304);
	    }
	}
	else if (strcmp(cmd_arg_v[1], "--help") == 0)
	{
	    printf(BOLD_S"Help menu\n"STYLE_END);
	    printf("-c	    	[CONFIG NAME] \n");
	    printf("	apply specified config \n");
	    printf("-p	    	[PACKAGE] \n");
	    printf("	install specified package \n");
	    printf("-i	    	[CONFIG NAME] \n");
	    printf("	print a short description of the package\n");
	}
	else
	{
	    // prints an error message if the argument is invalid
	    printf(BOLD_S ANSI_RED"%s: invalid option -- '%s'\n"STYLE_END, cmd_arg_v[0], cmd_arg_v[1]);
	    error_message(303);
	}
    }
    else
    {
	// if no argument is found (most cases)
	return 0;
    }
    exit(0);
}

void config_description(char *package_t)
{
    switch (detect_config_name(package_t)) 
    {
        case bash:
            printf("Bash, (Bourne Again SHell) is the default shell on most Linux distributions.\n");
            break;

        case bpyt:
            printf("bpytop is a system resource monitor.\n");
            break;

        case btop:
            printf("btop is a system resource monitor.\n");
            break;

        case cava:
            printf("Cava is a Cross-platform Audio Visualizer.\n");
            break;

        case fast:
            printf("Fastfetch is a fast system information tool made in C.\n");
            break;

        case fuzz:
            printf("Fuzzel is an App launcher and fuzzy finder based on rofi & dmenu.\n");
            break;

        case gtkl:
            printf("Gtklock is a GTK lockscreen for Wayland.\n");
            break;

        case hypr:
            printf("Hyprland is a dynamic tiling window manager made for Wayland.\n");
            break;

	case kitt:
            printf("Kitty is a fast, GPU based terminal emulator.\n");
            break;

        case mpvf:
            printf("MPV is a cross-platform media player made for the command line.\n");
            break;

        case nvim:
            printf("Neovim is a modern Vi-based text editor.\n");
            break;
 
        case wayb:
            printf("Waybar is an highly customizable\n");
            break;

	case zshh:
            printf("Zsh (Z shell) is a command line interpreter focused on speed and efficiency.\n");
	    break;
        default:
            printf("Unknown program.\n");
    }
}

void argument_config_install(char *package_t, char archiving_t, char pkginstall_t)
{
    float version = 0.0;

    switch (detect_config_name(package_t)) 
    {
        case bash:
	    BASH();
            break;

        case bpyt:
	    BPYT(archiving_t, version, pkginstall_t);
            break;

        case btop:
	    BTOP(archiving_t, version, pkginstall_t);
            break;

        case cava:
	    CAVA(archiving_t, version, pkginstall_t);
            break;

        case fast:
	    FAST(archiving_t, version, pkginstall_t);
            break;

        case fuzz:
	    FUZZ(archiving_t, version, pkginstall_t);
            break;

        case gtkl:
	    GTKL(archiving_t, version, pkginstall_t);
            break;

        case hypr:
	    HYPR(archiving_t, version, pkginstall_t);
            break;

	case kitt:
	    KITT(archiving_t, version, pkginstall_t);
            break;

        case mpvf:
	    MPVF(archiving_t, version, pkginstall_t);
            break;

        case nvim:
	    NVIM(archiving_t, version, pkginstall_t);
            break;
 
        case sway:
	    SWAY(archiving_t, version, pkginstall_t);
            break;

        case wayb:
	    WAYB(archiving_t, version, pkginstall_t);
            break;

	case zshh:
	    ZSHH(archiving_t, version, pkginstall_t);
	    break;

        default:
	    error_message(301);
	    break;
    }
}

void cmd_arg_install(int num_cmd_arguments_t, char *cmd_arg_v_t[], char config_archive_t, char pkg_install_t)
{
    if (num_cmd_arguments_t >= n_to_arg)
    {
	for (int i = n_to_arg - 1; i < num_cmd_arguments_t; i++)
	{
	    // support for different operating systems might come in the future...
	    // will print the arguments instead of executing the command (useless)
	    argument_config_install(cmd_arg_v_t[i], config_archive_t, pkg_install_t);
	}
    }
    else
    {
	// prints an error message if there isn't any config name specified in the command
	cli_arg_missing(cmd_arg_v_t[0], "config name", cmd_arg_v_t[1]);
	error_message(304);
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

    // match the name to the correct config name
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

    // alternative names
    // check for hyprland
    int i = 1;
    while (HYPR_ARG_NAME[i] != NULL)
    {
	if (strcmp(input, HYPR_ARG_NAME[i]) == 0) return hypr;
	i++;
    }
    // check for nvim
    i = 1;
    while (NVIM_ARG_NAME[i] != NULL)
    {
	if (strcmp(input, NVIM_ARG_NAME[i]) == 0) return nvim;
	i++;
    }

    if (strcmp(input, "swaywm") == 0) return sway;
    if (strcmp(input, "fast") == 0) return fast;
    if (strcmp(input, "fuzz") == 0) return fuzz;
    return unknown;
}
