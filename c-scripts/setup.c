#include "dotfileshead.h"

int main(int argc, char *argv[])
{
    pre_startup();
    
    if (argc > 1) // checks how many arguments were used
    {
	// checks if the command was ran with the --noconfirm flag
	if (strcmp(argv[1], "--noconfirm") == 0) 
	{
	    printf(BOLD_S"Proceeding with full install\n"STYLE_END);
	    full_install('y', 'y');
	}
	else if (strcmp(argv[1], "-p") == 0)
	{
	    error_message(6);
	}
	else
	{
	    // prints an error message if the argument is invalid
	    printf(BOLD_S ANSI_RED"%s: invalid option -- '%s'\n"STYLE_END, argv[0], argv[1]);
	    return 1;
	}
    }

    do
    {
    	// sets the text for each option and each menu title
    	clear();
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
    	        printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, opt_for_text );
    	        printf(BOLD_S " [1] " STYLE_END UDRL_S"%s"STYLE_END"\n", fastfetch_config_menu_text);
    	        printf(BOLD_S " [2] " STYLE_END UDRL_S"%s"STYLE_END"\n", kitty_config_menu_text);
    	        printf(BOLD_S " [3] " STYLE_END UDRL_S"%s"STYLE_END"\n", fuzzel_config_menu_text);
    	        printf(BOLD_S " [4] " STYLE_END UDRL_S"%s"STYLE_END"\n", zshforhumans_config_menu_text);
    	        printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

	        while (getchar() != '\n');  // clear imput buffer 
		;
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
			;
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
    	                printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, kitty_config_menu_text );
    	                printf(BOLD_S " [1] " STYLE_END "%s\n", kitty_color_text);
    	                printf(BOLD_S " [2] " STYLE_END "%s\n", kitty_fonts_text);
    	                printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

		        while (getchar() != '\n');  // clear imput buffer 
			;
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
    	            while(kitty_config_choice != 0.0); // exits the while loop when the user types 0
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

				while (getchar() != '\n');  // clear imput buffer 
				scanf(" %d", &fuzzel_edit_menu_choice);

				switch(fuzzel_edit_menu_choice)
				{
				    case 1:
					snprintf(cmd, sizeof(cmd),
				    	        "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
				    	        "ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini");
				    	system(cmd);
				    goto endthree;
				    case 2:
					snprintf(cmd, 192,
				    	        "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
				    	        "ln -sf ~/.config/fuzzel/old-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
				    	system(cmd);
				    	goto endthree;
				    case 3:
					pver = 0.0f;
				    	snprintf(cmd, sizeof(cmd),
				    	        "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
				    	        "ln -sf ~/.config/fuzzel/fuzzel-oldv%.1f.ini ~/.config/fuzzel/fuzzel.ini", pver);
				    	system(cmd);
				    	goto endthree;
				    case 4:
					snprintf(cmd, 192,
				    	        "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
				    	        "ln -sf ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
				    	system(cmd);
				    	goto endthree;
				    case 5:
					snprintf(cmd, 192,
				    	        "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini ; "
				    	        "ln -sf ~/.config/fuzzel/custom-edited-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
				    	system(cmd);
				    	goto endthree;
				    case 6:
					// edit config
				    	snprintf(cmd, 64,
				    	        "nvim ~/.config/fuzzel/custom-edited-fuzzel.ini ");
				    	system(cmd);
				    	printf("The custom config was saved successfully\n");
				    	wait_for_timeout(1, 0);
				    	goto endthree;
				    default:
					goto endthree;

				    endthree:
				    ;
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
		else if (dotfiles_config_menu == 4)
		{
		    int zshforhumans_choice;
		    do
		    {
		        clear();
			printf(ANSI_CYAN BOLD_S "%s\n"STYLE_END, zshforhumans_config_menu_text);
			printf(BOLD_S "This will execute the zsh for humans script\n"STYLE_END);
			printf(BOLD_S "Do you want to proceed with the configuration?\n\n"STYLE_END);
    	            	printf(BOLD_S " [1] " STYLE_END "Yes\n");
    	            	printf(BOLD_S " [0] " STYLE_END "%s (no)\n", opt_exit_text);

			scanf(" %d", &zshforhumans_choice);
			if (zshforhumans_choice == 1)
			{
			    clear();
			    system("if command -v curl >/dev/null 2>&1; then "
				    "  sh -c \"$(curl -fsSL https://raw.githubusercontent.com/romkatv/zsh4humans/v5/install)\"; "
				    "else "
				    "  sh -c \"$(wget -O- https://raw.githubusercontent.com/romkatv/zsh4humans/v5/install)\"; " 
				    "fi");
			    while (getchar() != '\n');  // clear imput buffer 
			    getchar();
			}
		    }
		    while (zshforhumans_choice > 0);
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
		    char cmd[64];
	    	    snprintf(cmd, sizeof(cmd),
	    	            "yay -S activate-linux-git --noconfirm ; "
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
