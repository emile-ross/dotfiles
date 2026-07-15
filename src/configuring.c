#include "header.h"

void fuzzel_config_importing(void)
{
	char *path_template = "%s/.config/fuzzel/imported/fuzzel";
	
	size_t path_size = 1 + (size_t)snprintf(NULL, 0, path_template, home);
	char *path = malloc(path_size);
	snprintf(path, path_size, path_template, home);
	
	struct stat st;
	char cmd[768];
	
	if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) /* check if the configs were already downloaded */
	{
		free(path);
		printf("The fuzzel themes are already installed.\n");
	}
	else 
	{
		free(path);
		size_t cmd_size = 1 + (size_t)snprintf(NULL, 0,
				"mkdir -p ~/.config/fuzzel/imported/ ; " 
				"cd ~/.config/fuzzel/imported/ ; "
				"git clone https://github.com/catppuccin/fuzzel.git ; "
				"cd %s ", inpath);

		snprintf(cmd, cmd_size,
				"mkdir -p ~/.config/fuzzel/imported/ ; " 
				"cd ~/.config/fuzzel/imported/ ; "
				"git clone https://github.com/catppuccin/fuzzel.git ; "
				"cd %s ", inpath);
		system(cmd);
	}


	long theme_type_user_opt;
	const size_t max_len = 32;
	char* theme_type_text = malloc(max_len);
	
	clear();
	printf(BOLD_S"Choose your fuzzel theme type\n"STYLE_END);
	
	printf(BOLD_S"  [1]"STYLE_END" catppuccin-latte (light mode)\n");
	printf(BOLD_S"  [2]"STYLE_END" catppuccin-frappe (grey)\n");
	printf(BOLD_S"  [3]"STYLE_END" catppuccin-macchiato (dark)\n");
	printf(BOLD_S"  [4]"STYLE_END" catppuccin-mocha (very dark)\n");
	
	theme_type_user_opt = get_long(" ", 1, 4);
	
	switch(theme_type_user_opt)
	{
	case 1:
		strncpy(theme_type_text, "catppuccin-latte", max_len);
		break;
	case 2:
		strncpy(theme_type_text, "catppuccin-frappe", max_len);
		break;
	case 3:
		strncpy(theme_type_text, "catppuccin-macchiato", max_len);
		break;
	case 4:
		strncpy(theme_type_text, "catppuccin-mocha", max_len);
		break;
	default:
		error_message(FUZZ_THEME_INVALID);
		printf("Invalid input.\n");
		strncpy(theme_type_text, "Invalid-theme", max_len);
		break;
	}
	/* theme color */
	printf(BOLD_S"Set the colour for your fuzzel config\n"STYLE_END);
	
	long user_colour_opt;
	char colour_message_text[16] = "Use the colour";
	
	fuzzel_colour_e fuzz_colour;
	
	/* TODO replace with for loop */
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"blue"STYLE_END"\n", fuzz_colour = blue, colour_message_text);
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"flamingo"STYLE_END"\n", fuzz_colour = flamingo, colour_message_text);
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"green"STYLE_END"\n", fuzz_colour = green, colour_message_text);
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"lavender"STYLE_END"\n", fuzz_colour = lavender, colour_message_text);
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"maroon"STYLE_END"\n", fuzz_colour = maroon, colour_message_text);
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"mauve"STYLE_END"\n", fuzz_colour = mauve, colour_message_text);
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"peach"STYLE_END"\n", fuzz_colour = peach, colour_message_text);
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"pink"STYLE_END"\n", fuzz_colour = pink, colour_message_text);
	printf(BOLD_S"  [%d] "STYLE_END" %s "BOLD_S"red"STYLE_END"\n", fuzz_colour = red, colour_message_text);
	printf(BOLD_S"  [%d]"STYLE_END" %s "BOLD_S"rosewater"STYLE_END"\n", fuzz_colour = rosewater, colour_message_text);
	printf(BOLD_S"  [%d]"STYLE_END" %s "BOLD_S"sapphire"STYLE_END"\n", fuzz_colour = sapphire, colour_message_text);
	printf(BOLD_S"  [%d]"STYLE_END" %s "BOLD_S"sky"STYLE_END"\n", fuzz_colour = sky, colour_message_text);
	printf(BOLD_S"  [%d]"STYLE_END" %s "BOLD_S"teal"STYLE_END"\n", fuzz_colour = teal, colour_message_text);
	printf(BOLD_S"  [%d]"STYLE_END" %s "BOLD_S"yellow"STYLE_END"\n", fuzz_colour = yellow, colour_message_text);
	
	user_colour_opt = get_long(NULL, 1, 14);
	
	fuzzel_colour_e theme_colour_name = (fuzzel_colour_e)user_colour_opt;
	
	switch (theme_colour_name)
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
	
	if ((lstat(fuz_conf_path, &st) == 0) && S_ISLNK(st.st_mode)) 
	{
		printf("Successfully applied Fuzzel theme\n");
		printf("Theme type:"BOLD_S UDRL_S" %s \n"STYLE_END, theme_type_text);
		printf("Theme colour:"BOLD_S UDRL_S" %s \n"STYLE_END, theme_colour_text);
		wait_for_timeout(0, LONG_TIMER);
		free(theme_type_text);
	}
	else
	{
		free(theme_type_text);
		error_message(FUZZ_THEME_FAIL);
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
	long fastfetch_opt = -1;
	/* create command buffer */
	size_t buffer_size = 128;
	char *command_buffer = malloc(buffer_size);
	do
	{
		clear();
		
		printf(BOLD_S"What file would you like to use as your fastfetch config?\n"STYLE_END);
		
		if (fastfetch_config_apply == true)
		{
			if (fastfetch_opt == -1)
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
		
		printf(BOLD_S "  [1] "STYLE_END"config-default.jsonc\n");
		printf(BOLD_S "  [2] "STYLE_END"config-other.jsonc\n");
		printf(BOLD_S "  [3] "STYLE_END"config-duplicated.jsonc\n\n");
		printf(BOLD_S "  [0] "STYLE_END "%s\n", opt_exit_text);
		
		fastfetch_opt = get_long(NULL, 0, 3);
		
		if (fastfetch_opt == 1)
		{
			snprintf(command_buffer, buffer_size,
					"ln -fs ~/.config/fastfetch/config-default.jsonc ~/.config/fastfetch/config.jsonc");
			system(command_buffer);
			fastfetch_config_apply = true;
		}
		else if (fastfetch_opt == 2)
		{
			snprintf(command_buffer, buffer_size,
					"ln -fs ~/.config/fastfetch/config-other.jsonc ~/.config/fastfetch/config.jsonc");
			system(command_buffer);
			fastfetch_config_apply = true;
		}
		else if (fastfetch_opt == 3)
		{
			snprintf(command_buffer, buffer_size,
					"ln -fs ~/.config/fastfetch/config-duplicated.jsonc ~/.config/fastfetch/config.jsonc");
			system(command_buffer);
			fastfetch_config_apply = true;
		}
	}
    	while (fastfetch_opt > 0);

	free(command_buffer);
    	/* exits the while loop when the user types 0 */
}
