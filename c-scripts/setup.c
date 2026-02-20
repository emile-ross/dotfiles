#include "dotfileshead.h"

int main()
{
    do
    {
    	// sets the text for each option and each menu title
    	clear();
    	char main_menu_text[128] = "Welcome to the setup utility for ImAwsumm's dotfiles";
    	char opt_one_text[128] = "Install the dotfiles";
    	char opt_two_text[128] = "Fix the dotfiles";
    	char opt_the_text[128] = "Update your dotfiles";
    	char opt_for_text[128] = "Custom configuration menu";
    	char opt_fiv_text[128] = "Something else";
    	char opt_exit_text[128] = "Exit";
    
    	printf(BOLD_S ANSI_CYAN "%s\n\n" STYLE_END, main_menu_text );
    	printf(BOLD_S " [1] " STYLE_END "%s\n", opt_one_text);
    	printf(BOLD_S " [2] " STYLE_END "%s\n", opt_two_text);
    	printf(BOLD_S " [3] " STYLE_END "%s\n", opt_the_text);
    	printf(BOLD_S " [4] " STYLE_END "%s\n", opt_for_text);
    	printf(BOLD_S " [5] " STYLE_END "%s\n\n", opt_fiv_text);
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
	    
    	    printf("\nProceed with installation (Y/n)\n");	// prompt user for imput
    	    scanf(" %c", &full_install_opt);
    	    if (full_install_opt == 'Y' || full_install_opt == 'y')
	    {
		full_install(ARCHIVE, 'y');
	    }
    	}
    	else if (menu_one_i == 2)
    	{
	    int fix_install_menu;
	    int after_install;
	    do
	    {
		float pver = 0.0f; // the user is presumed to be installing the dotfiles
    		clear();

    		printf(BOLD_S "%s\n"STYLE_END, opt_two_text );

		float *version = update();
		printf(ANSI_GREY"\nDetected Version: %.2f\n"STYLE_END, *version);
		printf(UDRL_S"Are you sure you want to fix your dotfiles?\n"STYLE_END);
		printf(BOLD_S"\n[1]"STYLE_END" %s", opt_two_text);
		printf(BOLD_S"\n[0]"STYLE_END" %s\n", opt_exit_text);

		while (getchar() != '\n'); // clear imput buffer
		scanf("%d", &fix_install_menu);

		if ( fix_install_menu == 1)
		{
		    printf(UDRL_S"\nDo you want to install the packages needed for the full configuration? (Y/n)\n"STYLE_END);

		    while (getchar() != '\n'); // clear imput buffer
		    char pkgtemp;
		    scanf("%c", &pkgtemp);

		    printf(BOLD_S"\nFixing dotfiles...\n"STYLE_END);
		    // call install functions for every config
		    BASH(ARCHIVE, pver, pkgtemp);
		    BTOP(ARCHIVE, pver, pkgtemp);
		    CAVA(ARCHIVE, pver, pkgtemp);
		    FAST(ARCHIVE, pver, pkgtemp);
		    FUZZ(ARCHIVE, pver, pkgtemp);
		    GTKL(ARCHIVE, pver, pkgtemp);
		    HYPR(ARCHIVE, pver, pkgtemp);
		    KITT(ARCHIVE, pver, pkgtemp);
		    NVIM(ARCHIVE, pver, pkgtemp);
		    MPVF(ARCHIVE, pver, pkgtemp);
		    SWAY(ARCHIVE, pver, pkgtemp);
		    WAYB(ARCHIVE, pver, pkgtemp);

		    printf(BOLD_S"\nInstall completed!...\n"STYLE_END);

	    	    wait_for_timeout(2, 0);
		    // I will implement something in order to fix this ^^ mark my words
		    // ^^ I did it :D
		    scanf(" %d", &after_install);
		    if (after_install == 0)
		    {
			return 0;
		    } 
		    // in other cases we just go back to the previous menu
		}
	    }
	    while(fix_install_menu > 0);
    	}
    	else if (menu_one_i == 3)
    	{
	    int update_config_menu;
	    do
	    {
	    	char updatecheck_opt_text[48] = "Template text";
	    	char update_opt_text[48] = "Template text";

    	    	clear();

		float *version = update();
		printf(ANSI_GREY"\nDetected Version: %.2f\n"STYLE_END, *version);

    	    	printf(BOLD_S "%s\n\n"STYLE_END, opt_the_text );
    	    	printf(BOLD_S " [1] " STYLE_END "%s\n", update_opt_text);
    	    	printf(BOLD_S " [2] " STYLE_END "%s\n", updatecheck_opt_text);
    	    	printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);

		while (getchar() != '\n');  // clear imput buffer 
	    	scanf("%d", &update_config_menu);
	    	if (update_config_menu == 1)
	    	{
		    printf("\nFix install script unavailable use the install script instead\n");
	    	}
	    	if (update_config_menu == 2)
	    	{
		    char cmd[1024];
		    snprintf(cmd, sizeof(cmd),
			    "gcc ~/dotfiles/c-scripts/setup.c "
			    "~/dotfiles/c-scripts/update.c "
			    "~/dotfiles/c-scripts/install.c "
			    "~/dotfiles/c-scripts/functions.c "
			    "-o setup -Wall");
		    system(cmd);
	    	}
	    }
	    while(update_config_menu > 0);
    	}
    	else if (menu_one_i == 4)
    	{
	    int dotfiles_config_menu;
    	    do
    	    {
	        clear();
    	        char fastfetch_config_menu_text[32] = "Customize fastfetch";
    	        char kitty_config_menu_text[32] = "Customize kitty";
    	        char fuzzel_config_menu_text[32] = "Customize fuzzel";
    	        
    	        printf(BOLD_S ANSI_WHITE "%s\n"STYLE_END, opt_for_text );
    	        printf(BOLD_S "\n [1] " STYLE_END UDRL_S"%s"STYLE_END"\n", fastfetch_config_menu_text);
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
    	                    snprintf(cmd, 128,
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
		    int fuzzel_config_menu_choice;
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
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini && "
					    "ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini");
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 2)
				{
				    snprintf(cmd, 192,
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini && "
					    "ln -sf ~/.config/fuzzel/old-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 3)
				{
				    float pver = 0.0f;
				    snprintf(cmd, sizeof(cmd),
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini && "
					    "ln -sf ~/.config/fuzzel/fuzzel-oldv%.1f.ini ~/.config/fuzzel/fuzzel.ini", pver);
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 4)
				{
				    snprintf(cmd, 192,
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini && "
					    "ln -sf ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/fuzzel.ini");
				    system(cmd);
				}
				else if (fuzzel_edit_menu_choice == 5)
				{
				    snprintf(cmd, 192,
					    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-backup.ini && "
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
    	else if (menu_one_i == 5)
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
	    	            "yay -S activate-linux-git && "
	    	            "activate-linux-git");
	    	    system(cmd);

    	    	    printf("\nHere is something cool!\n");
    	    	    printf("\nLook at the bottom right of your screen");
	    	    printf("\nUse ^C (Control+C) to close the program.\n");
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

void BASH(char ARCHIVE, float pver, char PKGINSTALL)
{
    char BRCNAME[12] = ".bashrc-new";
    // prompt to let the user know the bashrc isn't exported/replaced
    printf(UDRL_S"\nThe .bashrc file plays a very important role therefore, it was not replaced."STYLE_END);
    printf(UDRL_S"\nYou can find the new .bashrc file under the name %s\n"STYLE_END, BRCNAME);

    char cmd[64]; // BRCNAME has to be considered
    // export .bashrc
    snprintf(cmd, sizeof(cmd),
	    "cp -f dotfiles/.bashrc ~/%s", BRCNAME);
    system(cmd);

}

void BTOP(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[128];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive btop config
    	snprintf(cmd, sizeof(cmd),
    		"mv ~/.config/btop/btop.conf "
    		"~/.config/btop/btop-oldv%.2f.conf", pver);
    	system(cmd);
    }
    // export btop config
    snprintf(cmd, sizeof(cmd),
    	"mkdir -p ~/.config/btop ; "
    	"cp -f dotfiles/btop/btop.conf ~/.config/btop");
    system(cmd);
}

void CAVA(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[128];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        // backup cava config
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/cava/config "
		"~/.config/cava/config-oldv%.1f", pver);
        system(cmd);
    }
    // export cava config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/cava ; "
	    "cp -f dotfiles/cava/config ~/.config/cava/ ");
    system(cmd);
}

void FAST(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[512];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// backup fastfetch config
    	snprintf(cmd, 96,
		"mv ~/.config/fastfetch/config.jsonc "
		"~/.config/fastfetch/config-oldv%.2f.jsonc", pver);
    	system(cmd);
    }
    // export fastfetch config
    snprintf(cmd, sizeof(cmd),
	    "rm ~/.config/fastfetch ; "
	    "mkdir -p ~/.config/fastfetch/assets ; "
	    "cp -f dotfiles/fastfetch/assets/*.png ~/.config/fastfetch/assets ; "
	    "cp -f dotfiles/fastfetch/config.jsonc ~/.config/fastfetch ; "
	    "cp -f ~/.config/fastfetch/config.jsonc ~/.config/fastfetch/config-duplicated.jsonc ; "
	    "cp -f dotfiles/fastfetch/config-other.jsonc ~/.config/fastfetch ; "
	    "cp -f dotfiles/fastfetch/config-default.jsonc ~/.config/fastfetch");
    system(cmd);
}
void FUZZ(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[512];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// backup fuzzel config
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/fuzzel/fuzzel.ini"
    		"~/.config/fuzzel/fuzzel-oldv%.1f.ini", pver);
    	system(cmd);
    }
    // export fuzzel appearance
    snprintf(cmd, sizeof(cmd),
            "mkdir ~/.config/fuzzel && "
            "cp -f dotfiles/fuzzel/old-fuzzel.ini ~/.config/fuzzel ; "
            "cp -f dotfiles/fuzzel/default-fuzzel.ini ~/.config/fuzzel ; "
	    "cp -f ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/custom-edited-fuzzel.ini ; "
            "cp -f dotfiles/fuzzel/fuzzel.ini ~/.config/fuzzel ; "
	    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-duplicated.ini ; "
	    "ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini ");
    system(cmd);  		
}
void GTKL(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// backup gtklock config
        snprintf(cmd, sizeof(cmd),
            	"mv ~/.config/gtklock/style.css "
    		"~/.config/gtklock/style-oldv%.1f.css", 
    		pver);
    	system(cmd);
    }
    // export gtklock config
    snprintf(cmd, sizeof(cmd),
            "mkdir -p ~/.config/gtklock/assets ; "
            "cp -f dotfiles/gtklock/style.css ~/.config/gtklock ; "
            "cp -f dotfiles/gtklock/lockscreen.jpg ~/.config/gtklock/assets");
    system(cmd);
}

void HYPR(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive hyprland configs
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-oldv%.2f.conf ; "
        	"mv ~/.config/hypr/hyprpaper.conf ~/.config/hypr/hyprpaper-oldv%.2f.conf ; "
        	"mv ~/.config/hypr/hypridle.conf ~/.config/hypr/hypridle-oldv%.2f.conf", pver, pver, pver);
        system(cmd);
    }
    // export hyprland configs
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/hypr && "
	    "cp -f dotfiles/hypr/hyprland.conf ~/.config/hypr ; "
    	    "cp -f dotfiles/hypr/hypridle.conf ~/.config/hypr ; "
    	    "cp -f dotfiles/hypr/hyprpaper.conf ~/.config/hypr");
    system(cmd);
}
void KITT(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// backup kitty config
        snprintf(cmd, sizeof(cmd),
    		"mv ~/.config/kitty/kitty.conf "
    		"~/.config/kitty/kitty-oldv%.1f.conf", pver);
    	system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install kitty package
	//  the kitty terminal is most likely already installed on your system
        snprintf(cmd, 32,
		"yay -S --noconfirm kitty");
	system(cmd);
    }
    // export kitty config
    snprintf(cmd, sizeof(cmd),
	    "mkdir ~/.config/kitty && "
	    "cp -f dotfiles/kitty/current-theme.conf ~/.config/kitty ; "
	    "cp -f dotfiles/kitty/kitty.conf ~/.config/kitty");
    system(cmd);
}

void MPVF(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[128];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive mpv config
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/mpv/mpv.conf ~/.config/mpv/mpv-oldv%.2f.conf ", pver);
	system(cmd);
	printf(BOLD_S"\nThe old "UDRL_S"mpv"STYLE_END BOLD_S" config was archived\n"STYLE_END);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
        snprintf(cmd, 32,
		"yay -S --noconfirm mpv");
	system(cmd);

	printf(BOLD_S"\nMPV was installed!\n"STYLE_END);
    }
    // export mpv config with shaders
    snprintf(cmd, 96,
	    "mkdir -p ~/.config/mpv/ ; "
            "cp -f dotfiles/mpv/mpv.conf ~/.config/mpv ");
    system(cmd);
}

void NVIM(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        snprintf(cmd, sizeof(cmd),
    	    	"mv ~/.config/nvim/init.lua ~/.config/nvim/init-oldv%.1f.lua ; "
    	    	"mv ~/.config/nvim/lua/config/lazy.lua ~/.config/nvim/lua/config/lazy-oldv%.1f.lua ; "
    	    	"mv ~/.config/nvim/lazy-lock.json ~/.config/nvim/lazy-lock-oldv%.1f.json",
    	    	pver, pver, pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install neovim (nvim) package
	// nvim is most likely already installed 
        snprintf(cmd, 32,
		"yay -S --noconfirm nvim lazygit");
	system(cmd);
    }

    // export nvim config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/nvim ; "
    	    "cp -f dotfiles/nvim/init.lua ~/.config/nvim");
    system(cmd);
}

void SWAY(char ARCHIVE, float pver, char PKGINSTALL)
{
    // sway window manager doesn't work without wlroots
    char cmd[128];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        snprintf(cmd, sizeof(cmd),
    	    	"mv ~/.config/sway/config ~/.config/sway/config-oldv%.1f ",
		pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install sway package
        snprintf(cmd, 32,
		"yay -S --noconfirm wlroots sway");
	system(cmd);
	// a system update is strongly recommended 
    }
    // export sway config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/sway ; "
    	    "cp -f dotfiles/sway/config ~/.config/sway");
    system(cmd);
}

void WAYB(char ARCHIVE, float pver, char PKGINSTALL)
{
    
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive waybar
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/waybar/config.jsonc ~/.config/waybar/config-oldv%.2f.jsonc ; "
		"mv ~/.config/waybar/style.css ~/.config/waybar/style-oldv%.2f.css",
		pver, pver);
	system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
        snprintf(cmd, 32,
		"yay -S --noconfirm waybar");
	system(cmd);
    }
    // export waybar config and appearance
    snprintf(cmd, sizeof(cmd),
	    //"yay -S --noconfirm waybar && "
	    "mkdir -p ~/.config/waybar ; "
	    "cp -f dotfiles/waybar/style.css ~/.config/waybar ; "
            "cp -f dotfiles/waybar/config.jsonc ~/.config/waybar");
    system(cmd);
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
    	    printf("Yay is now installed, congrats!\n");
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
			"git clone https://aur.archlinux.org/yay.git &&"	// download yay from aur
    	                "cd yay &&"						//
			"makepkg -si &&"					// build package from source
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
    	        "mkdir -p ~/.config/fuzzel/imported/ && " 
    	        "cd ~/.config/fuzzel/imported/ && "
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
    
    char* theme_colour_text;
    
    if (theme_colour_user_opt == 1)
    {
        theme_colour_text = "blue";
    }
    else if (theme_colour_user_opt == 2)
    {
        theme_colour_text = "flamingo";
    }
    else if (theme_colour_user_opt == 3)
    {
        theme_colour_text = "green";
    }
    else if (theme_colour_user_opt == 4)
    {
        theme_colour_text = "lavender";
    }
    else if (theme_colour_user_opt == 5)
    {
        theme_colour_text = "maroon";
    }
    else if (theme_colour_user_opt == 6)
    {
        theme_colour_text = "mauve";
    }
    else if (theme_colour_user_opt == 7)
    {
        theme_colour_text = "peach";
    }
    else if (theme_colour_user_opt == 8)
    {
        theme_colour_text = "pink";
    }
    else if (theme_colour_user_opt == 9)
    {
        theme_colour_text = "red";
    }
    else if (theme_colour_user_opt == 10)
    {
        theme_colour_text = "rosewater";
    }
    else if (theme_colour_user_opt == 11)
    {
        theme_colour_text = "sapphire";
    }
    else if (theme_colour_user_opt == 12)
    {
        theme_colour_text = "sky";
    }
    else if (theme_colour_user_opt == 13)
    {
        theme_colour_text = "teal";
    }
    else if (theme_colour_user_opt == 14)
    {
        theme_colour_text = "yellow";
    }
    else
    {
        printf("Try again.\n");
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
