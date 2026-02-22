#include "dotfileshead.h"

int main()
{
    do
    {
    	// sets the text for each option and each menu title
    	clear();
    	char main_menu_text[128] = "Welcome to the setup utility for ImAwsumm's dotfiles";
    	char opt_one_text[128] = "Install the dotfiles";
    	char opt_the_text[128] = "Update your dotfiles";
    	char opt_for_text[128] = "Custom configuration menu";
    	char opt_fiv_text[128] = "Something else";
    	char opt_exit_text[128] = "Exit";
    
    	printf(BOLD_S ANSI_CYAN "%s\n\n" STYLE_END, main_menu_text );
    	printf(BOLD_S " [1] " STYLE_END "%s\n", opt_one_text);
    	printf(BOLD_S " [2] " STYLE_END "%s\n", opt_the_text);
    	printf(BOLD_S " [3] " STYLE_END "%s\n", opt_for_text);
    	printf(BOLD_S " [4] " STYLE_END "%s\n\n", opt_fiv_text);
    	printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

    	scanf(" %d", &menu_one_i);
    	if (menu_one_i == 1)
    	{
	    char full_install_opt;
	    clear();
    	    printf(BOLD_S "%s\n"STYLE_END, opt_one_text );
    	    printf("\nDo you want to backup your old dotfiles before proceeding? (Y/n)\n");

    	    scanf(" %c", &ARCHIVE);
	    printf(ANSI_RED BOLD_S"\nWARNING\n"STYLE_END BOLD_S"This will install every config.\n"STYLE_END);
	    printf(ITALICS_S"\nIn order to pick the configs you want, you need to use the custom configuration option\n"STYLE_END);
	    
    	    printf(BOLD_S"\nProceed with installation (Y/n)\n"STYLE_END);	// prompt user for imput
    	    scanf(" %c", &full_install_opt);
    	    if (full_install_opt == 'Y' || full_install_opt == 'y')
	    {
		full_install(ARCHIVE, 'y');
	    }
    	}
    	else if (menu_one_i == 2)
    	{
	    clear();
	    float *version = update();
	    printf(ANSI_GREY"\nDetected Version: %.2f\n"STYLE_END, *version);
    	    printf(BOLD_S "%s\n\n"STYLE_END, opt_the_text );
	    printf("\nDo you want to backup your old dotfiles before updating? (Y/n)\n");
	    char backuptemp;

	    while (getchar() != '\n');  // clear imput buffer 
	    scanf("%c", &backuptemp);
	    full_update(backuptemp, *version);
    	}
    	else if (menu_one_i == 3)
    	{
	    int dotfiles_config_menu;
    	    do
    	    {
	        clear();
    	        char fastfetch_config_menu_text[32] = "Customize fastfetch";
    	        char kitty_config_menu_text[32] = "Customize kitty";
    	        char fuzzel_config_menu_text[32] = "Customize fuzzel";
    	        
    	        printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, opt_for_text );
    	        printf(BOLD_S " [1] " STYLE_END UDRL_S"%s"STYLE_END"\n", fastfetch_config_menu_text);
    	        printf(BOLD_S " [2] " STYLE_END UDRL_S"%s"STYLE_END"\n", kitty_config_menu_text);
    	        printf(BOLD_S " [3] " STYLE_END UDRL_S"%s"STYLE_END"\n", fuzzel_config_menu_text);
    	        printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

	        while (getchar() != '\n');  // clear imput buffer 
    	        scanf(" %d", &dotfiles_config_menu);
	        if (dotfiles_config_menu == 1)
	        {
		    int fastfetch_config_choice;
    	            do
    	            {
		        clear();
    	                char fastfetch_edit_config_text[48] = "Change the config fastfetch uses by default";
    	                char fastfetch_preview_text[32] = "Preview fastfetch output";
		        char cmd[128];
    	                
    	                printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, fastfetch_config_menu_text );
    	                printf(BOLD_S " [1] " STYLE_END "%s\n", fastfetch_preview_text);
    	                printf(BOLD_S " [2] " STYLE_END "%s\n", fastfetch_edit_config_text);
    	                printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);
		        while (getchar() != '\n');  // clear imput buffer 

    	                scanf("\n%d", &fastfetch_config_choice);
    	                if (fastfetch_config_choice == 1)
    	                {
    	                    snprintf(cmd, 16,
				    "fastfetch");
    	                    system(cmd);
			    wait_for_timeout(0, 2);
    	                }
		        if (fastfetch_config_choice == 2)
    	                {
			    do
	    	            {
				clear();
	    	            	printf(BOLD_S"What file would you like to use as your fastfetch config?\n\n"STYLE_END);
	    	            	printf(BOLD_S " [1] "STYLE_END"config-default.jsonc\n");
	    	            	printf(BOLD_S " [2] "STYLE_END"config-other.jsonc\n");
	    	            	printf(BOLD_S " [3] "STYLE_END"config-duplicated.jsonc\n");
	    	            	printf(BOLD_S " [0] "STYLE_END "%s\n", opt_exit_text);

	    	            	int link_fastfetch_configs_opt = -1;
    	    	            	char cmd[128];

    	    	            	while (getchar() != '\n');  // clear imput buffer 
    	    	            	scanf("%d", &link_fastfetch_configs_opt);

    	    	            	if (link_fastfetch_configs_opt == 1)
    	    	            	{
    	    	            	    snprintf(cmd, sizeof(cmd),
					    "ln -fs ~/.config/fastfetch/config-default.jsonc ~/.config/fastfetch/config.jsonc");
    	    	            	    system(cmd);
    	    	            	    printf("\nThe fastfetch config was applied successfully\n");
	    	            	    wait_for_timeout(1, 0);
    	    	            	}
    	    	            	else if (link_fastfetch_configs_opt == 2)
    	    	            	{
    	    	            	    snprintf(cmd, sizeof(cmd),
					    "ln -fs ~/.config/fastfetch/config-other.jsonc ~/.config/fastfetch/config.jsonc");
    	    	            	    system(cmd);
    	    	            	    printf("\nThe fastfetch config was applied successfully\n");
	    	            	    wait_for_timeout(1, 0);
    	    	            	}
    	    	            	else if (link_fastfetch_configs_opt == 3)
    	    	            	{
    	    	            	    snprintf(cmd, sizeof(cmd),
					    "ln -fs ~/.config/fastfetch/config-duplicated.jsonc ~/.config/fastfetch/config.jsonc");
    	    	            	    system(cmd);

    	    	            	    printf("\nThe fastfetch config was applied successfully\n");
	    	            	    wait_for_timeout(1, 0);
    	    	            	}
		    	    	else
		    	    	{}
	    	            }
	    	            while (fastfetch_conf_export > 0.0);
    	                }
    	            }
    	            while(fastfetch_config_choice > 0.0);
    	            // exits the while loop when the user types 0
	        }
		else if (dotfiles_config_menu == 2)
    	        {
		    int kitty_config_choice;
		    do
    	            {
		        clear();
    	                char kitty_color_text[32] = "Change Kitty color scheme";
    	                char kitty_fonts_text[32] = "Change Kitty fonts";
    	                
    	                printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, kitty_config_menu_text );
    	                printf(BOLD_S " [1] " STYLE_END "%s\n", kitty_color_text);
    	                printf(BOLD_S " [2] " STYLE_END "%s\n", kitty_fonts_text);
    	                printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

		        while (getchar() != '\n');  // clear imput buffer 
    	                scanf("%d", &kitty_config_choice);

    	                char cmd[24];
    	                if (kitty_config_choice == 1)
    	                {
			    snprintf(cmd, 24,
				    "kitten themes");
    	                    system(cmd);
    	                }
    	                if (kitty_config_choice == 2)
    	                {
			    snprintf(cmd, 24,
				    "kitty +list-fonts");
    	                    system(cmd);
    
    	                    printf("\nThe install script can be used to install more fonts.");
    	                }
    	            }
    	            while(kitty_config_choice != 0.0);
    	            // exits the while loop when the user types 0
    	        }
		else if (dotfiles_config_menu == 3)
		{
		    do
		    {
		        clear();

			printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, fuzzel_config_menu_text);
    	            	printf(BOLD_S " [1] " STYLE_END "%s\n", fuzzel_view_config_text);
    	            	printf(BOLD_S " [2] " STYLE_END "%s\n",	fuzzel_edit_config_text);
    	            	printf(BOLD_S " [3] " STYLE_END "%s\n",	fuzzel_catppuccin_text);
    	            	printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

			while (getchar() != '\n');  // clear imput buffer 
			scanf(" %d", &fuzzel_config_menu_choice);

			if (fuzzel_config_menu_choice == 1)
			{
			    char cmd[128];
			    snprintf(cmd, 16,
				    "fuzzel");
    	                    system(cmd);

	    	            wait_for_timeout(1, 0);
			}
			else if (fuzzel_config_menu_choice == 2)
			{
			    int fuzzel_edit_menu_choice;
			    do
			    {
				clear();
				char cmd[256];
				char fuzzel_config_one[32] = "Use fuzzel-duplicated.ini";
    	                	char fuzzel_config_old[32] = "Use old-fuzzel.ini";
    	                	char fuzzel_config_vzero[32] = "Use fuzzel-v0.0.ini";
    	                	char fuzzel_config_default[32] = "Use default fuzzel config";
    	                	char fuzzel_config_custom[32] = "Use custom config";
				char fuzzel_config_edit_custom[32] = "Edit custom config";

				printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, fuzzel_edit_config_text);
    	            		printf(BOLD_S " [1] " STYLE_END "%s\n", fuzzel_config_one);
    	            		printf(BOLD_S " [2] " STYLE_END "%s\n",	fuzzel_config_old);
    	            		printf(BOLD_S " [3] " STYLE_END "%s\n",	fuzzel_config_vzero);
    	            		printf(BOLD_S " [4] " STYLE_END "%s\n\n", fuzzel_config_default);

    	            		printf(BOLD_S " [5] " STYLE_END "%s\n",	fuzzel_config_custom);
    	            		printf(BOLD_S " [6] " STYLE_END "%s\n\n", fuzzel_config_edit_custom);
    	            		printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);
				
				// might clone this in the future https://github.com/catppuccin/fuzzel.git

				while (getchar() != '\n');  // clear imput buffer 
				scanf(" %d", &fuzzel_edit_menu_choice);

				if (fuzzel_edit_menu_choice == 1)
				{
				    snprintf(cmd, sizeof(cmd),
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
					    "ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini");
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 2)
				{
				    snprintf(cmd, 192,
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
					    "ln -sf ~/.config/fuzzel/old-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 3)
				{
				    float pver = 0.0f;
				    snprintf(cmd, sizeof(cmd),
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
					    "ln -sf ~/.config/fuzzel/fuzzel-oldv%.1f.ini ~/.config/fuzzel/fuzzel.ini", pver);
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 4)
				{
				    snprintf(cmd, 192,
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
					    "ln -sf ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 5)
				{
				    snprintf(cmd, 192,
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
					    "ln -sf ~/.config/fuzzel/custom-edited-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 6)
				{
				    // edit config
				    snprintf(cmd, 64,
					    "nvim ~/.config/fuzzel/custom-edited-fuzzel.ini ");
				    system(cmd);
				    printf("The custom config was saved successfully\n");
				    wait_for_timeout(1, 0);
				}
			    }
			    while (fuzzel_edit_menu_choice > 0);
			}
			else if (fuzzel_config_menu_choice == 3)
			{
			    fuzzel_config_importing();
			    wait_for_timeout(1, 0);
			}
		    }
		    while (fuzzel_config_menu_choice > 0);
		}
    	    } 
    	    while(dotfiles_config_menu != 0.0);
    	    // exits the while loop when the user types 0
    	}
    	else if (menu_one_i == 4)
    	{
	    int menu_activate_linux;
	    do
	    {
		while (getchar() != '\n');  // clear imput buffer 
		clear();
    	    	printf(BOLD_S "%s\n"STYLE_END, opt_fiv_text );
		
    		char act_linux_water_text[128] = "Do you want to add the \"Activate Linux\" watermark?";

		printf(BOLD_S "\n [1] %s\n"STYLE_END, act_linux_water_text);
		printf(BOLD_S "\n [0] %s (no)\n"STYLE_END, opt_exit_text);
	    	scanf("%d", &menu_activate_linux);

		if (menu_activate_linux == 1)
		{
		    char cmd[48];
	    	    snprintf(cmd, sizeof(cmd),
	    	            "yay -S activate-linux-git ; "
	    	            "activate-linux-git");
	    	    system(cmd);

    	    	    printf("\nHere is something cool!\n\n");
    	    	    printf("Look at the bottom right of your screen\n");
	    	    printf("Use "BOLD_S"^C (Control+C)"STYLE_END" to close the program.\n");
	    	    printf("You can use a command like \""UDRL_S"activate-linux -t Activate\\ Arch-Linux -m Go\\ to\\ archlinux.org/donate/\\ to\\ activate"STYLE_END"\" \n");
	    	    printf("These flags allow you to add a custom message or title\n");
		}
	    }
	    while(menu_activate_linux != 0.0);
    	}
    	else if (menu_one_i == 0)
    	{
    		printf("\nExiting..\n");
    		return 0;
    	}
    	else
    	{
	    error_message(2);
    	    return 2;
    	}
    }
    while(menu_one_i != 0);	// exits the while loop when the user types 0
    return 0;
}

void full_install(char ARCHIVE, char full_install_opt)
{
    if (full_install_opt == 'Y' || full_install_opt == 'y')
    {
	float pver = 0.0f; // the user is presumed to be installing the dotfiles
	int timerinstall = 3;
	printf(BOLD_S"\nInstalling every configuration\n"STYLE_END);
	printf(BOLD_S"\nStarting in:\n"STYLE_END);
	
	for (int i = 0; i < 3; i++)
	{
	    printf("%d ", timerinstall);
	
	    for (int j = 0; j < 3; j++)
	    {
	        printf(".");
	        fflush(stdout);
	
		wait_for_timeout(1, 0);
	    }
	    for (int k = 0; k < 1; k++)
	    {
		printf("\n");
		wait_for_timeout(1, 0);
	    }
	    timerinstall--;
	}
	
	if (system("test -f /sbin/yay") == 0)
    	{
    	    printf("Yay already installed, congrats!\n");
    	}
    	else
    	{
    	    printf("Yay is not installed, do you want to install it? (Y/n): ");

    	    char YAY;
	    while (getchar() != '\n');  // clear imput buffer 
    	    scanf(" %c", &YAY); // asks the user if they wanna install yay (needed)
    	    if (YAY == 'Y' || YAY == 'y')
    	    {
    	        // Check if makepkg is installed ( it is needed in order to compile yay )
    	        if (system("command -v makepkg > /dev/null") != 0)
    	        {
    	        	printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");

	    	char cmd[128];
	    	snprintf(cmd, sizeof(cmd),
	    		"sudo pacman -S --noconfirm base-devel");
	    	system(cmd);
    	            
    	            // Check if makepkg is available after installing the base-devel package
    	            if (system("command -v makepkg > /dev/null") != 0)
    	            {
			error_message(51);
    	            }
    	            else
    	            {
			printf("Makepkg has been successfully installed!\n");
    	            }
    	        }
    	        else
    	        {
    	            printf("Makepkg is already installed.\n");
    	        }
	        // install yay \/
    	        char cmd[256];
    	        snprintf(cmd, sizeof(cmd),
			"git clone https://aur.archlinux.org/yay.git ; "	// download yay from aur
    	                "cd yay ; "						//
			"makepkg -si ; "					// build package from source
    	                "cd ..");						//
    	        system(cmd);

    	        printf("\nYay is installed, congrats!\n");
    	    }
    	    else
    	    {
	        error_message(5);
	    }
	}
	// actually install the dotfiles
	BASH(ARCHIVE, pver, PKGINSTALL);
	SWAY(ARCHIVE, pver, PKGINSTALL);
	BTOP(ARCHIVE, pver, PKGINSTALL);
	CAVA(ARCHIVE, pver, PKGINSTALL);
	FAST(ARCHIVE, pver, PKGINSTALL);
	FUZZ(ARCHIVE, pver, PKGINSTALL);
	GTKL(ARCHIVE, pver, PKGINSTALL);
	HYPR(ARCHIVE, pver, PKGINSTALL);
	KITT(ARCHIVE, pver, PKGINSTALL);
	MPVF(ARCHIVE, pver, PKGINSTALL);
	NVIM(ARCHIVE, pver, PKGINSTALL);
	WAYB(ARCHIVE, pver, PKGINSTALL);
	ZSHH(ARCHIVE, pver, PKGINSTALL);
    }
    else
    {
	int install_pkg_opt;
	do
	{
	    printf("\n[1] Install %s ", TEXT_C_BASH);
	    printf("\n[2] Install %s ", TEXT_C_SWAY);
	    printf("\n[3] Install %s ", TEXT_C_BTOP);
	    printf("\n[4] Install %s ", TEXT_C_CAVA);
	    printf("\n[5] Install %s ", TEXT_C_FAST);
	    printf("\n[6] Install %s ", TEXT_C_FUZZ);
	    printf("\n[7] Install %s ", TEXT_C_GTKL);
	    printf("\n[8] Install %s ", TEXT_C_HYPR);
	    printf("\n[9] Install %s ", TEXT_C_KITT);
	    printf("\n[10] Install %s ", TEXT_C_MPVF);
	    printf("\n[11] Install %s ", TEXT_C_NVIM);
	    printf("\n[12] Install %s ", TEXT_C_WAYB);
	    printf("\n[13] Install %s ", TEXT_C_ZSHH);
	    
	    while (getchar() != '\n');  // clear imput buffer 
	    scanf(" %d", &install_pkg_opt);
	}
	while (install_pkg_opt > 0);
    }
    printf(BOLD_S"\nInstallation completed!\n"STYLE_END);
}

float* update() 
{
    char *USERNAME = getenv("HOME");

    // error message if username can't be fetched 
    if (USERNAME == NULL) 
    {
	error_message(204);
        return NULL;
    }

    // create path to config
    char HYPRPATH[64];
    snprintf(HYPRPATH, sizeof(HYPRPATH), 
	    "%s/.config/hypr/hyprland.conf", USERNAME);
	    // set the hyprland path with username

    // open the file with HYPRPATH
    FILE *file = fopen(HYPRPATH, "r");
    
    // return error message when file isn't found
    if (file == NULL) 
    {
	error_message(205);
	// returns null if the file can't be opened/found
        return NULL;
    }
    static float VAWSM[32] = {0};

    char line[384];
    while (fgets(line, sizeof(line), file)) 
    {
        if (sscanf(line, "# AWSMVERSION: %31f[0-9.]", VAWSM) == 1) 
	{
            fclose(file);
            return VAWSM;
        }
    }
    fclose(file);
    return 0;
}
void fuzzel_config_importing()
{
    // check if the configs were already downloaded 
    char path[512];
    char *home = getenv("HOME");
    snprintf(path, sizeof(path), "%s/.config/fuzzel/imported/fuzzel", home);

    struct stat st;
    char cmd[512];
    if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) 
    {
        printf("The fuzzel themes are already installed.\n");
    }
    else 
    {
    	snprintf(cmd, sizeof(cmd),
    	        "mkdir -p ~/.config/fuzzel/imported/ ; " 
    	        "cd ~/.config/fuzzel/imported/ ; "
    	        "git clone https://github.com/catppuccin/fuzzel.git");
    	system(cmd);
    }

    snprintf(cmd, sizeof(cmd),
	    "cd ~/.config/fuzzel/imported/fuzzel/themes");
    system(cmd);

    int theme_type_user_opt;

    char* theme_type_text;
    
    clear();
    printf(BOLD_S"Choose your fuzzel theme type\n"STYLE_END);
    
    printf(BOLD_S"[1]"STYLE_END" catppuccin-latte (light mode)\n");
    printf(BOLD_S"[2]"STYLE_END" catppuccin-frappe (grey)\n");
    printf(BOLD_S"[3]"STYLE_END" catppuccin-macchiato (dark)\n");
    printf(BOLD_S"[4]"STYLE_END" catppuccin-mocha (very dark)\n");
    
    while (getchar() != '\n'); // clear imput buffer
    scanf(" %d", &theme_type_user_opt);
    
    if (theme_type_user_opt == 1)
    {
        theme_type_text = "catppuccin-latte";
    }
    else if (theme_type_user_opt == 2)
    {
        theme_type_text = "catppuccin-frappe";
    }
    else if (theme_type_user_opt == 3)
    {
        theme_type_text = "catppuccin-macchiato";
    }
    else if (theme_type_user_opt == 4)
    {
        theme_type_text = "catppuccin-mocha";
    }
    else
    {
        printf("Try again.\n");
    }
    // theme color
    int theme_colour_user_opt;
    
    printf(BOLD_S"Set the colour for your fuzzel config\n"STYLE_END);
    
    char colour_message_text[16] = "Use the colour";
    
    printf(BOLD_S"[1] "STYLE_END" %s "BOLD_S"blue"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[2] "STYLE_END" %s "BOLD_S"flamingo"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[3] "STYLE_END" %s "BOLD_S"green"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[4] "STYLE_END" %s "BOLD_S"lavender"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[5] "STYLE_END" %s "BOLD_S"maroon"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[6] "STYLE_END" %s "BOLD_S"mauve"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[7] "STYLE_END" %s "BOLD_S"peach"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[8] "STYLE_END" %s "BOLD_S"pink"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[9] "STYLE_END" %s "BOLD_S"red"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[10]"STYLE_END" %s "BOLD_S"rosewater"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[11]"STYLE_END" %s "BOLD_S"sapphire"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[12]"STYLE_END" %s "BOLD_S"sky"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[13]"STYLE_END" %s "BOLD_S"teal"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[14]"STYLE_END" %s "BOLD_S"yellow"STYLE_END"\n", colour_message_text);
    
    while (getchar() != '\n'); // clear imput buffer
    scanf(" %d", &theme_colour_user_opt);
    switch(theme_colour_user_opt)
    {
	case 1:
	    theme_colour_text = "blue";
	    goto end;
	case 2:
	    theme_colour_text = "flamingo";
	    goto end;
	case 3:
	    theme_colour_text = "green";
	    goto end;
	case 4:
	    theme_colour_text = "lavender";
	    goto end;
	case 5:
	    theme_colour_text = "maroon";
	    goto end;
	case 6:
	    theme_colour_text = "mauve";
	    goto end;
	case 7:
	    theme_colour_text = "peach";
	    goto end;
	case 8:
	    theme_colour_text = "pink";
	    goto end;
	case 9:
	    theme_colour_text = "red";
	    goto end;
	case 10:
	    theme_colour_text = "rosewater";
	    goto end;
	case 11:
	    theme_colour_text = "sapphire";
	    goto end;
	case 12:
	    theme_colour_text = "sky";
	    goto end;
	case 13:
	    theme_colour_text = "teal";
	    goto end;
	case 14:
	    theme_colour_text = "yellow";
	    goto end;
	default:
	    printf("Try again.\n");
	end:
    }
    char fuz_theme_path[256];
    snprintf(fuz_theme_path, sizeof(fuz_theme_path),
	    "%s/.config/fuzzel/imported/fuzzel/themes/%s/%s.ini", home, theme_type_text, theme_colour_text);
    
    snprintf(cmd, sizeof(cmd),
	    "mv -f %s/.config/fuzzel/fuzzel.ini %s/.config/fuzzel/before-link-fuzzel.ini ; "
	    "ln -sf %s %s/.config/fuzzel/fuzzel.ini", home, home, fuz_theme_path, home);
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
