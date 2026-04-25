#include "dotfileshead.h"

int main(int argc, char *argv[])
{
    pre_startup();

    parse_arguments(argc, argv);

    do
    {
    	/* sets the text for each option and each menu title
	* this isn't really needed, it could all be replaced by a loop and an array */
    	clear();
    	printf(BOLD_S ANSI_CYAN "%s\n\n" STYLE_END, main_menu_text );
    	printf(BOLD_S " [1] " STYLE_END "%s\n", opt_one_text);
    	printf(BOLD_S " [2] " STYLE_END "%s\n", opt_the_text);
    	printf(BOLD_S " [%d] " STYLE_END "%s\n", KEY_MAIN_MENU_CONFIGURE, opt_for_text);
    	printf(BOLD_S " [4] " STYLE_END "%s\n\n", opt_fiv_text);
    	printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

    	scanf(" %d", &menu_one_i);
    	if (menu_one_i == 1)
    	{
	    /* launch the install menu it suggests some options to the user and then it executes full_install() */
	    install_menu();
    	}
    	else if (menu_one_i == 2)
    	{
	    clear();
	    float *version = update();
	    printf(ANSI_GREY"\nDetected Version: %.2f\n"STYLE_END, *version);
    	    printf(BOLD_S "%s\n\n"STYLE_END, opt_the_text );
	    printf("\nDo you want to backup your old dotfiles before updating? (Y/n)\n");
	    char backuptemp;

	    clearbuffer();
	    scanf("%c", &backuptemp);
	    full_update(backuptemp, *version);
    	}
    	else if (menu_one_i == KEY_MAIN_MENU_CONFIGURE)
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

		clearbuffer();
    	        scanf(" %d", &dotfiles_config_menu);
	        if (dotfiles_config_menu == 1)
	        {
		    int fastfetch_config_choice;
    	            do
    	            {
		        clear();

    	                char fastfetch_edit_config_text[48] = "Change the config fastfetch uses by default";
    	                char fastfetch_preview_text[32] = "Preview fastfetch output";
    	                
    	                printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, fastfetch_config_menu_text );
    	                printf(BOLD_S " [1] " STYLE_END "%s\n", fastfetch_preview_text);
    	                printf(BOLD_S " [2] " STYLE_END "%s\n", fastfetch_edit_config_text);
    	                printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

			clearbuffer();
    	                scanf("\n%d", &fastfetch_config_choice);

    	                if (fastfetch_config_choice == 1)
    	                {
			    exec_cmd(16, "fastfetch");
			    wait_for_timeout(0, 2);
    	                }
			else if (fastfetch_config_choice == 2)
    	                {
			    configure_fastfetch();
    	                }
    	            }
    	            while (fastfetch_config_choice > INPUT_BACK_VALUE);
    	            /* exits the while loop when the user types 0 */
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

			clearbuffer();
    	                scanf("%d", &kitty_config_choice);

    	                if (kitty_config_choice == 1)
    	                {
			    exec_cmd(16, "kitten themes");
    	                }
			else if (kitty_config_choice == 2)
    	                {
			    exec_cmd(24, "kitty +list-fonts");
    
    	                    printf("\nThe install script can be used to install more fonts.");
    	                }
    	            }
    	            while (kitty_config_choice > INPUT_BACK_VALUE); /* exits the while loop when the user types 0 */
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

			clearbuffer();
			scanf(" %d", &fuzzel_config_menu_choice);

			if (fuzzel_config_menu_choice == 1)
			{
			    exec_cmd(24, "fuzzel");
	    	            wait_for_timeout(1, 0);
			}
			else if (fuzzel_config_menu_choice == 2)
			{
			    int fuzzel_edit_menu_choice;
			    do
			    {
				clear();

				char fuzzel_config_one[32] = "Use fuzzel-duplicated.ini";
				char fuzzel_config_old[32] = "Use old-fuzzel.ini";
				char fuzzel_config_vzero[32] = "Use fuzzel-v0.0.ini";
				char fuzzel_config_default[32] = "Use default config";
				char fuzzel_config_catp[48] = "Use the customized Catppuccin theme";
				char fuzzel_config_custom[32] = "Use custom config";
				char fuzzel_config_edit_custom[32] = "Edit custom config";
				
				printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, fuzzel_edit_config_text);
				printf(BOLD_S " [1] " STYLE_END "%s\n", fuzzel_config_one);
				printf(BOLD_S " [2] " STYLE_END "%s\n",	fuzzel_config_old);
				printf(BOLD_S " [3] " STYLE_END "%s\n",	fuzzel_config_vzero);
				printf(BOLD_S " [4] " STYLE_END "%s\n\n", fuzzel_config_default);
				printf(BOLD_S " [5] " STYLE_END "%s\n\n", fuzzel_config_catp);
				
				printf(BOLD_S " [6] " STYLE_END "%s\n",	fuzzel_config_custom);
				printf(BOLD_S " [7] " STYLE_END "%s\n\n", fuzzel_config_edit_custom);
				printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

				clearbuffer();
				scanf(" %d", &fuzzel_edit_menu_choice);

				apply_fuzzel_config(fuzzel_edit_menu_choice);
			    }
			    while (fuzzel_edit_menu_choice > INPUT_BACK_VALUE);
			}
			else if (fuzzel_config_menu_choice == 3)
			{
			    fuzzel_config_importing();
			    wait_for_timeout(1, 0);
			}
		    }
		    while (fuzzel_config_menu_choice > INPUT_BACK_VALUE);
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
			    configure_oh_my_zsh();
			}
		    }
		    while (zshforhumans_choice > INPUT_BACK_VALUE);
		}
    	    } 
    	    while (dotfiles_config_menu > INPUT_BACK_VALUE);
    	    /* exits the while loop when the user types 0 */
    	}
    	else if (menu_one_i == 4)
    	{
	    int menu_activate_linux;
	    do
	    {
		clear();
    	    	printf(BOLD_S "%s\n"STYLE_END, opt_fiv_text );
		
    		char act_linux_water_text[128] = "Do you want to add the \"Activate Linux\" watermark?";

		printf("\n%s\n", act_linux_water_text);

		printf(BOLD_S "\n [1] Yes \n"STYLE_END);
		printf(BOLD_S "\n [0] No \n"STYLE_END);

		clearbuffer();
	    	scanf("%d", &menu_activate_linux);

		if (menu_activate_linux == 1)
		{
		    install_package("arch", "activate-linux-git");
		    exec_cmd(24, "activate-linux-git");

    	    	    printf("\nHere is something cool!\n\n");
    	    	    printf("Look at the bottom right of your screen\n");
	    	    printf("Use "BOLD_S"^C (Control+C)"STYLE_END" to close the program.\n");
	    	    printf("You can use a command like \""UDRL_S"activate-linux -t Activate\\ Arch-Linux -m Go\\ to\\ archlinux.org/donate/\\ to\\ activate"STYLE_END"\" \n");
	    	    printf("These flags allow you to add a custom message or title\n");
		}
	    }
	    while (menu_activate_linux > INPUT_BACK_VALUE);
    	}
    	else if (menu_one_i == INPUT_EXIT_VALUE || menu_one_i > 4)
    	{
    		printf("\nExiting..\n");
    		return 0;
    	}
    	else
    	{
	    /* this is caused by invalid input */
	    error_message(INVALID_INPUT);
    	}
    }
    while (menu_one_i != 0);	/* exits the while loop when the user types 0 */
    return 0;
}
