#include "dotfileshead.h"

void fuzzel_config_importing(void)
{
    char path[512];
    char *home = getenv("HOME");
    snprintf(path, sizeof(path), "%s/.config/fuzzel/imported/fuzzel", home);

    struct stat st;
    char cmd[768];
    if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) /* check if the configs were already downloaded */
    {
        printf("The fuzzel themes are already installed.\n");
    }
    else 
    {
    	snprintf(cmd, 256,
    	        "mkdir -p ~/.config/fuzzel/imported/ ; " 
    	        "cd ~/.config/fuzzel/imported/ ; "
    	        "git clone https://github.com/catppuccin/fuzzel.git ; "
		"cd %s ", inpath);
    	system(cmd);
    }

    int theme_type_user_opt;
    char* theme_type_text;
    
    clear();
    printf(BOLD_S"Choose your fuzzel theme type\n"STYLE_END);
    
    printf(BOLD_S"[1]"STYLE_END" catppuccin-latte (light mode)\n");
    printf(BOLD_S"[2]"STYLE_END" catppuccin-frappe (grey)\n");
    printf(BOLD_S"[3]"STYLE_END" catppuccin-macchiato (dark)\n");
    printf(BOLD_S"[4]"STYLE_END" catppuccin-mocha (very dark)\n");
    
    clearbuffer();
    scanf(" %d", &theme_type_user_opt);
    
    switch(theme_type_user_opt)
    {
	case 1:
    	    theme_type_text = "catppuccin-latte";
    	    goto endone;
    	case 2:
    	    theme_type_text = "catppuccin-frappe";
    	    goto endone;
    	case 3:
    	    theme_type_text = "catppuccin-macchiato";
    	    goto endone;
    	case 4:
    	    theme_type_text = "catppuccin-mocha";
    	    goto endone;
    	default:
    	    theme_type_text = NULL;
    	    printf("Try again.\n");
    	    goto endone;
    	endone:
	;
    }
    /* theme color */
    printf(BOLD_S"Set the colour for your fuzzel config\n"STYLE_END);

    int theme_colour_user_opt;
    char colour_message_text[16] = "Use the colour";

    fuzzel_colour_e fuzz_colour;

    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"blue"STYLE_END"\n", fuzz_colour = blue, colour_message_text);
    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"flamingo"STYLE_END"\n", fuzz_colour = flamingo, colour_message_text);
    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"green"STYLE_END"\n", fuzz_colour = green, colour_message_text);
    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"lavender"STYLE_END"\n", fuzz_colour = lavender, colour_message_text);
    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"maroon"STYLE_END"\n", fuzz_colour = maroon, colour_message_text);
    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"mauve"STYLE_END"\n", fuzz_colour = mauve, colour_message_text);
    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"peach"STYLE_END"\n", fuzz_colour = peach, colour_message_text);
    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"pink"STYLE_END"\n", fuzz_colour = pink, colour_message_text);
    printf(BOLD_S"[%d] "STYLE_END" %s "BOLD_S"red"STYLE_END"\n", fuzz_colour = red, colour_message_text);
    printf(BOLD_S"[%d]"STYLE_END" %s "BOLD_S"rosewater"STYLE_END"\n", fuzz_colour = rosewater, colour_message_text);
    printf(BOLD_S"[%d]"STYLE_END" %s "BOLD_S"sapphire"STYLE_END"\n", fuzz_colour = sapphire, colour_message_text);
    printf(BOLD_S"[%d]"STYLE_END" %s "BOLD_S"sky"STYLE_END"\n", fuzz_colour = sky, colour_message_text);
    printf(BOLD_S"[%d]"STYLE_END" %s "BOLD_S"teal"STYLE_END"\n", fuzz_colour = teal, colour_message_text);
    printf(BOLD_S"[%d]"STYLE_END" %s "BOLD_S"yellow"STYLE_END"\n", fuzz_colour = yellow, colour_message_text);
    
    clearbuffer();
    scanf(" %d", &theme_colour_user_opt);

    fuzzel_colour_e theme_colour_name = (fuzzel_colour_e)theme_colour_user_opt;

    switch(theme_colour_name)
    {
	case blue:
	    theme_colour_text = "blue";
	    break;
	case flamingo:
	    theme_colour_text = "flamingo";
	    break;
	case green:
	    theme_colour_text = "green";
	    break;
	case lavender:
	    theme_colour_text = "lavender";
	    break;
	case maroon:
	    theme_colour_text = "maroon";
	    break;
	case mauve:
	    theme_colour_text = "mauve";
	    break;
	case peach:
	    theme_colour_text = "peach";
	    break;
	case pink:
	    theme_colour_text = "pink";
	    break;
	case red:
	    theme_colour_text = "red";
	    break;
	case rosewater:
	    theme_colour_text = "rosewater";
	    break;
	case sapphire:
	    theme_colour_text = "sapphire";
	    break;
	case sky:
	    theme_colour_text = "sky";
	    break;
	case teal:
	    theme_colour_text = "teal";
	    break;
	case yellow:
	    theme_colour_text = "yellow";
	    break;
	default:
	    printf("Try again.\n");
	    break;
    }

    char fuz_theme_path[256];
    snprintf(fuz_theme_path, sizeof(fuz_theme_path),
	    "%s/.config/fuzzel/imported/fuzzel/themes/%s/%s.ini", home, theme_type_text, theme_colour_text);
    
    snprintf(cmd, sizeof(cmd),
	    "mv -f %s/.config/fuzzel/fuzzel.ini %s/.config/fuzzel/before-link-fuzzel.ini ; "
	    "ln -sf %s %s/.config/fuzzel/fuzzel.ini ; " /* apply theme */
	    "ln -sf %s %s/.config/fuzzel/catppucin-fuzzel.ini" /* keep track of the correct config with a symlink */
	    , home, home, fuz_theme_path, home, fuz_theme_path, home);
    system(cmd);
    fflush(stdout);
    
    char fuz_conf_path[64];
    snprintf(fuz_conf_path, sizeof(fuz_conf_path), "%s/.config/fuzzel/fuzzel.ini", home);
    
    if (lstat(fuz_conf_path, &st) == 0 && S_ISLNK(st.st_mode)) 
    {
        printf("Successfully applied Fuzzel theme\n");
        printf("Theme type:"BOLD_S UDRL_S" %s \n"STYLE_END, theme_type_text);
        printf("Theme colour:"BOLD_S UDRL_S" %s \n"STYLE_END, theme_colour_text);
	wait_for_timeout(0, 1);
    }
    else
    {
        error_message(103);
    }
}

void apply_fuzzel_config(int config_choice_t)
{
    /* create a 256 bytes buffer for the commands below */
    char cmd[256]; 
    switch(config_choice_t)
    {
        case 1:
	    snprintf(cmd, sizeof(cmd),
		    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
		    "ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini");
            system(cmd);
    	    break;
        case 2:
	    snprintf(cmd, 192,
        	    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
        	    "ln -sf ~/.config/fuzzel/old-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
            system(cmd);
	    break;
        case 3:
	    pver = 0.00f;
            snprintf(cmd, sizeof(cmd),
        	    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
        	    "ln -sf ~/.config/fuzzel/fuzzel-oldv%.2f.ini ~/.config/fuzzel/fuzzel.ini", pver);
            system(cmd);
	    break;
        case 4:
	    snprintf(cmd, 192,
        	    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
        	    "ln -sf ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
            system(cmd);
	    break;
        case 5:
	    snprintf(cmd, 192,
        	    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
        	    "ln -sf ~/.config/fuzzel/catppucin-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
	    system(cmd);
	    break;
        case 6:
	    snprintf(cmd, 192,
        	    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
        	    "ln -sf ~/.config/fuzzel/custom-edited-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
            system(cmd);
	    break;
        case 7:
	    snprintf(cmd, 48, /* requires 48 bytes exactly */
        	    "nvim ~/.config/fuzzel/custom-edited-fuzzel.ini "); /* command to edit config (with nvim) */
            system(cmd);
            printf("The custom config was saved successfully\n");
            wait_for_timeout(1, 0);
	    break;
        default:
	    break;
    }
}

void configure_fastfetch(void)
{
    int link_fastfetch_configs_opt = -20;
    do
    {
        clear();
    
	/* create command buffer */
    	char cmd[128];

    	printf(BOLD_S"What file would you like to use as your fastfetch config?\n"STYLE_END);

	if (fastfetch_config_apply == true)
	{
	    if (link_fastfetch_configs_opt == -20)
	    {
		printf(ANSI_LGREEN"The fastfetch config "BOLD_S"has already been applied.\n\n"STYLE_END);
	    }
	    else
	    {
		printf(ANSI_GREEN"The fastfetch config "BOLD_S"was applied successfully.\n\n"STYLE_END);
	    }
	}
	else
	{
	    printf("\n");
	}

    	printf(BOLD_S " [1] "STYLE_END"config-default.jsonc\n");
    	printf(BOLD_S " [2] "STYLE_END"config-other.jsonc\n");
    	printf(BOLD_S " [3] "STYLE_END"config-duplicated.jsonc\n");
    	printf(BOLD_S " [0] "STYLE_END "%s\n", opt_exit_text);

        clearbuffer();
    	scanf("%d", &link_fastfetch_configs_opt);
    
    	if (link_fastfetch_configs_opt == 1)
    	{
    	    snprintf(cmd, sizeof(cmd),
        	    "ln -fs ~/.config/fastfetch/config-default.jsonc ~/.config/fastfetch/config.jsonc");
    	    system(cmd);
	    fastfetch_config_apply = true;
    	}
    	else if (link_fastfetch_configs_opt == 2)
    	{
    	    snprintf(cmd, sizeof(cmd),
        	    "ln -fs ~/.config/fastfetch/config-other.jsonc ~/.config/fastfetch/config.jsonc");
    	    system(cmd);
	    fastfetch_config_apply = true;
    	}
    	else if (link_fastfetch_configs_opt == 3)
    	{
    	    snprintf(cmd, sizeof(cmd),
        	    "ln -fs ~/.config/fastfetch/config-duplicated.jsonc ~/.config/fastfetch/config.jsonc");
    	    system(cmd);
	    fastfetch_config_apply = true;
    	}
    }
    while (link_fastfetch_configs_opt > 0.0);
    /* exits the while loop when the user types 0 */
}
