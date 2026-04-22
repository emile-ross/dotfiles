#include "dotfileshead.h"

int error_message(int err_code)
{
    char err_text_temp[128];
    char err_solution_temp[128];
    
    bool critical = false;	/* default is false */
    bool skip_warning = false;	/* default is false */
    
    if (err_code >= 300 && err_code <= 400)
    {
	critical = true;
	skip_warning = true;
    }

    error_code_e error_msg_code = (error_code_e)err_code;
    
    /* error code assignment from the err_code variable
     * enum error_code_e error_message_code = err_code;	*/

    switch (error_msg_code)
    {
	case INVALID_INPUT:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Exiting.. (invalid character)");
	    critical = true;
	    break;

	case YAY_INST_U:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Yay is needed for the k4dd..installation");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Give the program permission to install Yay");
	    break;

	case FEATURE_IN_DEV:
	    snprintf(err_text_temp, sizeof(err_text_temp), "This feature hasn't been implemented");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Try updating the dotfiles");
	    break;

	case FEAT_DEPRECATED:
	    snprintf(err_text_temp, sizeof(err_text_temp), "This feature will be removed/deprecated");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Read the documentation to learn about the existing features");
	    break;

	case 51:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Makepkg installation failed. Please check your system configuration.");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Helpful link: \"https://wiki.archlinux.org/title/Makepkg\"");
	    break;

	case 101:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Unsupported distribution");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Supported distros: \nArch Based \nDebian Based");
	    break;

	case 103:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Could not apply fuzzel theme");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Try again.  Report the issue if this keeps happening.");
	    break;

	case 104:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Could not find kitty package"); // not in use
	    break;

	case 204:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Can't find home directory");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Try running \"ls /home/\"\nif that doesn't do it \"useradd -m -d /home/[YOUR_USERNAME]/ -s /bin/bash -G sudo [YOUR_USERNAME]\"");
	    critical = true;
	    break;

	case 205:
	    snprintf(err_text_temp, sizeof(err_text_temp), "No such file or directory"); // for hyprland.conf (when looking for version # )
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "This could display if you haven't installed the hyprland config");	// also sway and .zshrc
	    break;

	case 206:
	    snprintf(err_text_temp, sizeof(err_text_temp), "popen failed");
	    snprintf(err_text_temp, sizeof(err_text_temp), "This could happen if your system only supports c99");
	    break;
	    
	case 207:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Unknown version");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Try installing the dotfiles in order to fix the unknown version");
	    break;

	case 301:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Unknown package");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Type the config name in lowercase");
	    break;

	case 302:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Invalid command syntax");
	    break;

	case CLI_INVALID_FLAG:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Invalid flag");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Use the %s flag to display the valid flags", help_flag_arg_text);
	    break;
		
	case CLI_ARGS_MISSING:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Missing arguments in the command");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), " ");
	    break;
		
	default:
	    snprintf(err_text_temp, sizeof(err_text_temp), "This error code isn't known");
	    break;
    }

    switch (err_code)
    {
	case 909:
	    printf("This error should never display (in theory) \n");
	    printf("Meaning.. this is a bug inside of another bug...\n");
	    break;

	default:
	    break;
    }

    if (!skip_warning)
    {
        // print error code
        printf(ANSI_RED UDRL_S BOLD_S"Error\n"STYLE_END);
        printf(ANSI_RED BOLD_S"Error code: %d \n"STYLE_END, err_code);
    }

    printf(ANSI_RED BOLD_S"%s \n"STYLE_END, err_text_temp);
    printf(ANSI_RED BOLD_S"%s \n"STYLE_END, err_solution_temp);

    if (critical)
    {
        exit(err_code);
    }

    if (!skip_warning)	/* cannot be removed — even though this is the second check */
    {
    	printf("Press "UDRL_S"CTRL + C"STYLE_END BOLD_S" to exit\n"STYLE_END);
    	printf("Press any key to continue\n");

	clearbuffer();
    	getchar();	// blocking behaviour 
    }
    return 0;
}
