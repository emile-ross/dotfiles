#include "dotfileshead.h"

void cli_arg_missing(char *first_command, char *type_of_missing_arg, char *user_flag_t)
{
    // prints an error message if there isn't a package specified in the command
    printf(BOLD_S ANSI_RED"%s: missing %s after -- '%s'\n"STYLE_END, first_command, type_of_missing_arg, user_flag_t);
}
