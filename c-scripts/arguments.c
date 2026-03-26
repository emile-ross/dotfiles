#include "dotfileshead.h"

void cli_arg_missing(char *first_command, char *type_of_missing_arg, char *user_flag_t)
{
    // prints an error message if there isn't a package specified in the command
    printf(BOLD_S ANSI_RED"%s: missing %s after -- '%s'\n"STYLE_END, first_command, type_of_missing_arg, user_flag_t);
    error_message(302);
    exit(0);
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
		    // arch is currently hardcoded since the distro parser isn't complete
		    install_package(parent, cmd_arg_v[i]); 
		}
	    }
	    else
	    {
		// prints an error message if there isn't a package specified in the command
		cli_arg_missing(cmd_arg_v[0], "package", cmd_arg_v[1]);
	    }
	}
	else if (strcmp(cmd_arg_v[1], "-c") == 0 || strcmp(cmd_arg_v[1], "-C") == 0)
	{
	    cmd_arg_install(num_cmd_arguments, cmd_arg_v, 'Y', 'N');
	}
	else if (strcmp(cmd_arg_v[1], "-i") == 0 || strcmp(cmd_arg_v[1], "-I") == 0)
	{
	    // loops through the arguments in order to pass them one at a time
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
	    exit(-2);
	}
    }
    exit(0);
}

void config_description(char *package_t)
{
    switch (detect_config_name(package_t)) 
    {
        case CONF_BASH:
            printf("Bash, (Bourne Again SHell) is the default shell on most Linux distributions.\n");
            break;

        case CONF_BPYT:
            printf("bpytop is a system resource monitor.\n");
            break;

        case CONF_BTOP:
            printf("btop is a system resource monitor.\n");
            break;

        case CONF_CAVA:
            printf("Cava is a Cross-platform Audio Visualizer.\n");
            break;

        case CONF_FAST:
            printf("Fastfetch is a fast system information tool made in C.\n");
            break;

        case CONF_FUZZ:
            printf("Fuzzel is an App launcher and fuzzy finder based on rofi & dmenu.\n");
            break;

        case CONF_GTKL:
            printf("Gtklock is a GTK lockscreen for Wayland.\n");
            break;

        case CONF_HYPR:
            printf("Hyprland is a dynamic tiling window manager made for Wayland.\n");
            break;

	case CONF_KITT:
            printf("Kitty is a fast, GPU based terminal emulator.\n");
            break;

        case CONF_MPVF:
            printf("MPV is a cross-platform media player made for the command line.\n");
            break;

        case CONF_NVIM:
            printf("Neovim is a modern Vi-based text editor.\n");
            break;
 

        case CONF_WAYB:
            printf("Waybar is an highly customizable\n");
            break;

	case CONF_ZSHH:
            printf("Zsh (Z shell) is a command line interpreter focused on speed and efficiency.\n");
	    break;
        default:
            printf("Unknown program.\n");
    }
}

void argument_config_install(char *package_t, char archiving_t, char pkginstall_t)
{
    switch (detect_config_name(package_t)) 
    {
        case CONF_BASH:
	    BASH();
            break;

        case CONF_BPYT:
	    BPYT(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_BTOP:
	    BTOP(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_CAVA:
	    CAVA(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_FAST:
	    FAST(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_FUZZ:
	    FUZZ(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_GTKL:
	    GTKL(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_HYPR:
	    HYPR(archiving_t, 0.0, pkginstall_t);
            break;

	case CONF_KITT:
	    KITT(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_MPVF:
	    MPVF(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_NVIM:
	    NVIM(archiving_t, 0.0, pkginstall_t);
            break;
 
        case CONF_SWAY:
	    SWAY(archiving_t, 0.0, pkginstall_t);
            break;

        case CONF_WAYB:
	    WAYB(archiving_t, 0.0, pkginstall_t);
            break;

	case CONF_ZSHH:
	    ZSHH(archiving_t, 0.0, pkginstall_t);
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
    }
}
