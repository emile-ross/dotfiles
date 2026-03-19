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
		    // arch is currently hardcoded since the distro parser isn't complete
		    printf("Distro: %s\n", distro);
		    printf("Parent distro: %s\n", parent);
		    install_package(parent, cmd_arg_v[i]); 
		}
		exit(0);
	    }
	    else
	    {
		// prints an error message if there isn't a package specified in the command
		cli_arg_missing(cmd_arg_v[0], "package", cmd_arg_v[1]);
		exit(-1);
	    }
	}
	else if (strcmp(cmd_arg_v[1], "-c") == 0 || strcmp(cmd_arg_v[1], "-C") == 0)
	{
	    if (num_cmd_arguments >= n_to_arg)
	    {
		for (int i = n_to_arg - 1; i < num_cmd_arguments; i++)
		{
		    // support for different operating systems might come in the future...
		    // will print the arguments instead of executing the command (useless)
		    argument_config_install(cmd_arg_v[i]);
		}
		exit(0);
	    }
	    else
	    {
		// prints an error message if there isn't any config name specified in the command
		cli_arg_missing(cmd_arg_v[0], "config name", cmd_arg_v[1]);
		exit(-1);
	    }
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
		exit(0);
	    }
	    else
	    {
		// prints an error message if there isn't a package specified in the command
		cli_arg_missing(cmd_arg_v[0], "package", cmd_arg_v[1]);
		exit(-1);
	    }
	}
	else if (strcmp(cmd_arg_v[1], "--help") == 0)
	{
	    printf("Help menu\n");
	    exit(0);
	}
	else
	{
	    // prints an error message if the argument is invalid
	    printf(BOLD_S ANSI_RED"%s: invalid option -- '%s'\n"STYLE_END, cmd_arg_v[0], cmd_arg_v[1]);
	    exit(-2);
	}
    }
    return 0;
}
