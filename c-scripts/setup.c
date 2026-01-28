#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOLD_S  	"\e[1m" // defines BOLD_S as a keyword to make text bold
#define UDRL_S  	"\e[4m" // UDRL_S starts an underline style
#define ITALICS_S 	"\e[3m"
#define ANSI_BLUE    	"\x1b[34m"
#define ANSI_WHITE    	"\x1b[97m"
#define ANSI_GREY    	"\x1b[90m"
#define ANSI_CYAN    	"\x1b[36m"
#define ANSI_RED 	"\x1b[31m"
#define STYLE_END   	"\e[m" // resets the styling

void clear()
{
    printf("\033[2J\033[H");
}

char ARCHIVE;
char confirm_full_inst;
float pver = 0.0f; // the user is presumed to be installing the dotfiles

char BASH();
char BTOP(char ARCHIVE);
char CAVA(char ARCHIVE);
char FAST(char ARCHIVE);
char FUZZ(char ARCHIVE);
char GTKL(char ARCHIVE);
char HYPR(char ARCHIVE);
char KITT(char ARCHIVE);
char NVIM(char ARCHIVE);
char WAYB(char ARCHIVE);

char full_inst_noconfirm(char ARCHIVE);
float* update();

int main()
{
    int menu_one_i;
    do
    {
    	clear();
    	// sets the text for each option and each menu title
    	char main_menu_text[128] = "Welcome to the setup utility for ImAwsumm's dotfiles";
    	char opt_one_text[128] = "Install the dotfiles";
    	char opt_two_text[128] = "Fix the dotfiles";
    	char opt_the_text[128] = "Update your dotfiles";
    	char opt_for_text[128] = "Custom configuration menu";
    	char opt_fiv_text[128] = "Something else";
    	char opt_exit_text[128] = "Exit";
    
    
    	printf(BOLD_S ANSI_CYAN "%s\n" STYLE_END, main_menu_text );
    	printf(BOLD_S "\n [1] " STYLE_END "%s\n", opt_one_text);
    	printf(BOLD_S " [2] " STYLE_END "%s\n", opt_two_text);
    	printf(BOLD_S " [3] " STYLE_END "%s\n", opt_the_text);
    	printf(BOLD_S " [4] " STYLE_END "%s\n", opt_for_text);
    	printf(BOLD_S " [5] " STYLE_END "%s\n", opt_fiv_text);
    	printf(BOLD_S "\n [0] " STYLE_END "%s\n", opt_exit_text);
    	scanf(" %d", &menu_one_i);
    
    	if (menu_one_i == 1)
    	{
	    clear();
    	    printf(BOLD_S "%s\n"STYLE_END, opt_one_text );
    	    printf("\nDo you want to backup your old dotfiles before proceeding? (Y/n)\n");
    	    scanf(" %c", &ARCHIVE);
    	    printf(ANSI_RED BOLD_S"\nWARNING\n"STYLE_END BOLD_S"This will install every config.\n"STYLE_END);
    	    printf(ITALICS_S"\nIn order to pick the configs you want, you need to use the custom configuration option\n"STYLE_END);
    	    printf("\nProceed with installation (Y/n)\n");
    	    fflush(stdin);
    	    scanf(" %c", &confirm_full_inst);
    	    if (confirm_full_inst == 'Y' || confirm_full_inst == 'y')
	    {
    		full_inst_noconfirm(ARCHIVE);
	    }
    	}
    	else if (menu_one_i == 2)
    	{
	    int fix_install_menu;
	    do
	    {
		float *version = update();

    		clear();

    		printf(BOLD_S "%s\n"STYLE_END, opt_two_text );

		printf(ANSI_GREY"\nDetected Version: %.2f\n"STYLE_END, *version);
		printf(UDRL_S"Are you sure you want to fix your dotfiles?\n"STYLE_END);
		printf(BOLD_S"\n[1]"STYLE_END" %s\n", opt_two_text);
		printf(BOLD_S"[0]"STYLE_END" %s\n", opt_exit_text);
		scanf("%d", &fix_install_menu);
		if ( fix_install_menu == 1)
		{
		    //do stuff
		    return 0;
		}
		else
		{
		    break;
		}
	    }
	    while(fix_install_menu != 0);
    	}
    	else if (menu_one_i == 3)
    	{
	    int update_config_menu;
	    do
	    {
		float *version = update();
	    	char updatecheck_opt_text[48] = "Template text";
	    	char update_opt_text[48] = "Template text";

    	    	clear();

		printf(ANSI_GREY"\nDetected Version: %.2f\n"STYLE_END, *version);

    	    	printf(BOLD_S "%s\n"STYLE_END, opt_the_text );
    	    	printf(BOLD_S "\n [1] " STYLE_END "%s\n", update_opt_text);
    	    	printf(BOLD_S " [2] " STYLE_END "%s\n", updatecheck_opt_text);
    	    	printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);
	    	scanf("%d", &update_config_menu);
	    	if (update_config_menu == 1)
	    	{
	    	    return 0;
	    	}
	    	else if (update_config_menu == 2)
	    	{
	    	    //update
	    	    return 0;
	    	}
	    	else
	    	{
	    	    //return 0;
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
    		    char hypr_config_menu_text[128] = "NOT COMPLETE Edit hyprland config";
    		    char kitty_config_menu_text[128] = "Edit kitty appearance and behavior";
    		    
    		    printf(BOLD_S ANSI_WHITE "%s\n"STYLE_END, opt_for_text );
    		    printf(BOLD_S "\n [1] " STYLE_END "%s\n", hypr_config_menu_text);
    		    printf(BOLD_S " [2] " STYLE_END "%s\n", kitty_config_menu_text);
    		    printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);
    		    fflush(stdin);
    		    scanf(" %d", &dotfiles_config_menu);
    		    
    		    if (dotfiles_config_menu == 2)
    		    {
    		    	int kitty_config_choice;
    		    	do
    		    	{
			    clear();
    		    	    char kitty_color_text[128] = "Change Kitty color scheme";
    		    	    char kitty_fonts_text[128] = "Change Kitty fonts";
    		    	    
    		    	    printf(BOLD_S ANSI_WHITE "%s\n\n"STYLE_END, kitty_config_menu_text );
    		    	    printf(BOLD_S " [1] " STYLE_END "%s\n", kitty_color_text);
    		    	    printf(BOLD_S " [2] " STYLE_END "%s\n", kitty_fonts_text);
    		    	    printf(BOLD_S " [0] " STYLE_END "%s\n", opt_exit_text);
    		    	    scanf("\n%d", &kitty_config_choice);
    		    	    fflush(stdin);
    		    	    if (kitty_config_choice == 0)
    		    	    {
    		    	    	break;
    		    	    }
    		    	    else if (kitty_config_choice == 1)
    		    	    {
    		    	    	char cmd[24];
    		    	    	snprintf(cmd, sizeof(cmd),
					"kitten themes");
    		    	    	system(cmd);
    		    	    }
    		    	    else if (kitty_config_choice == 2)
    		    	    {
    		    	    	char cmd[24];
    		    	    	snprintf(cmd, sizeof(cmd),
					"kitty +list-fonts");
    		    	    	system(cmd);
    
    		    	    	printf("\nThe install script can be used to install more fonts.");
    		    	    }
    		    	    else 
    		    	    {
    		    	    	// typo? perhaps?
    		    	    	clear();
    		    	    	fflush(stdin);
				return 0;
    		    	    	break;
    		    	    }
    		    	}
    		    	while(kitty_config_choice != 0.0);
    		    	// exits the while loop when the user types 0
    		    }
    		    else
    		    {
    		    	clear();
    		    	fflush(stdin);
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
    	else if (menu_one_i == '0')
    	{
    		clear();
    		printf("\nExiting..\n");
    		//printf("\n");
    		return 0;
    	}
    	else
    	{
    	    printf("\nExiting..\n");
    	    return 1; // error code 1
    	}
    }
    while(menu_one_i != 0);
    // exits the while loop when the user types 0
    return 0;
}

char BASH()
{
    char BRCNAME[12] = ".bashrc-new";
    // prompt to let the user know the bashrc isn't exported/replaced
    printf("\nThe .bashrc file plays a very important role therefore, it was not replaced.");
    printf("\nYou can find the new .bashrc file under the name %s\n", BRCNAME);

    char cmd[128];
    // export .bashrc
    snprintf(cmd, sizeof(cmd),
	    "mv dotfiles/.bashrc dotfiles/%s && "
	    "cp -f dotfiles/.bashrc ~", BRCNAME);
    system(cmd);

    return 0;
}

char BTOP(char ARCHIVE)
{
	char cmd[256];
        if (ARCHIVE == 'Y' || ARCHIVE == 'y')
	{
		// archive btop config
		snprintf(cmd, sizeof(cmd),
			"mv ~/.config/btop/config.jsonc "
			"~/.config/btop/config-oldv%.1f.jsonc", pver);
        	system(cmd);
	}
        // export btop config
        snprintf(cmd, sizeof(cmd),
		"mkdir -p ~/.config/btop && "
		"cp -f dotfiles/btop/config.jsonc ~/.config/btop");
        system(cmd);
	return 0;
}

char CAVA(char ARCHIVE)
{
	char cmd[256];
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
		"mkdir -p ~/.config/cava && "
        	"cp -f dotfiles/cava/config ~/.config/cava/ && ");
        system(cmd);
	return 0;
}
char FAST(char ARCHIVE)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// backup fastfetch config
    	snprintf(cmd, sizeof(cmd),
		"mkdir -p ~/.config/fastfetch && "
		"mv ~/.config/fastfetch/config.jsonc "
		"~/.config/fastfetch/config-oldv%.1f.jsonc", pver);
    	system(cmd);
    }
    // export fastfetch config
    snprintf(cmd, sizeof(cmd),
	    "cp dotfiles/fastfetch/config.jsonc "
	    "~/.config/fastfetch");
    system(cmd);
    return 0;
}
char FUZZ(char ARCHIVE)
{
	char cmd[256];
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
                "cp -f dotfiles/fuzzel/old-fuzzel.ini && "
                "cp -f dotfiles/fuzzel/fuzzel.ini "
		"~/.config/fuzzel");
        system(cmd);  		
	return 0;
}
char GTKL(char ARCHIVE)
{
	char cmd[256];
        if (ARCHIVE == 'Y' || ARCHIVE == 'y')
	{
		// backup gtklock config
	    	snprintf(cmd, sizeof(cmd),
                	"mv ~/.config/gtklock/style.css "
			"~/.config/gtklock/style-oldv%.1f.css", pver);
		system(cmd);
	}
	// export gtklock config
        snprintf(cmd, sizeof(cmd),
	        "mkdir -p ~/.config/gtklock/assets && "
                "cp -f dotfiles/gtklock/style.css ~/.config/gtklock && "
                "cp -f dotfiles/gtklock/lockscreen.jpg ~/.config/gtklock/assets");
        system(cmd);
	return 0;
}

char HYPR(char ARCHIVE)
{
	char cmd[256];
        if (ARCHIVE == 'Y' || ARCHIVE == 'y')
	{
		// archive hyprland configs
                snprintf(cmd, sizeof(cmd),
			"mkdir -p ~/.config/hypr && "
                	"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-oldv%.1f.conf && "
                	"mv ~/.config/hypr/hyprpaper.conf ~/.config/hypr/hyprpaper-oldv%.1f.conf && "
                	"mv ~/.config/hypr/hypridle.conf ~/.config/hypr/hypridle-oldv%.1f.conf",
                pver, pver, pver);
                system(cmd);
	}
	// export hyprland configs
        snprintf(cmd, sizeof(cmd),
		"cp -f dotfiles/hypr/hyprland.conf ~/.config/hypr && "
		"cp -f dotfiles/hypr/hypridle.conf ~/.config/hypr && "
		"cp -f dotfiles/hypr/hyprpaper.conf ~/.config/hypr");
        system(cmd);
	return 0;
}
char KITT(char ARCHIVE)
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
	// export kitty config
	snprintf(cmd, sizeof(cmd),
		"mkdir ~/.config/kitty && "
		"cp -f dotfiles/kitty/current-theme.conf ~/.config/kitty && "
		"cp -f dotfiles/kitty/kitty.conf ~/.config/kitty");
	system(cmd);
	return 0;
}

char NVIM(char ARCHIVE)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        snprintf(cmd, sizeof(cmd),
		"mkdir -p ~/.config/nvim && "
    	    	"mv ~/.config/nvim/init.lua ~/.config/nvim/init-oldv%.1f.lua && "
    	    	"mv ~/.config/nvim/lua/config/lazy.lua ~/.config/nvim/lua/config/lazy-oldv%.1f.lua && "
    	    	"mv ~/.config/nvim/lazy-lock.json ~/.config/nvim/lazy-lock-oldv%.1f.json",
    	    	pver, pver, pver);
        system(cmd);
    }
    // export nvim config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/nvim && "
    	    "cp -f dotfiles/nvim/init.lua ~/.config/nvim");
    	    //" cp -rf lua ~/.config/nvim && "
    	    //"cp -f lazy-lock.json ~/.config/nvim");
    system(cmd);
    return 0;
}
char WAYB(char ARCHIVE)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive waybar
        snprintf(cmd, sizeof(cmd),
		"mkdir -p ~/.config/waybar && "
		"mv ~/.config/waybar/config.jsonc ~/.config/waybar/config-oldv%.1f.jsonc && "
		"mv ~/.config/waybar/style.css ~/.config/waybar/style-oldv%.1f.css",
        pver, pver);
    }
    // export waybar config and appearance
    snprintf(cmd, sizeof(cmd),
	    "yay -S --noconfirm waybar && "
	    "mkdir -p ~/.config/waybar && "
	    "cp -f dotfiles/waybar/style.css ~/.config/waybar && "
            "cp -f dotfiles/waybar/config.jsonc ~/.config/waybar && ");
    system(cmd);
    return 0;
}

char full_inst_noconfirm(char ARCHIVE)
{
    printf("\nInstalling dotfiles...\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd),
	    "gcc dotfiles/c-scripts/install.c -o cinstall && " 
    	    "./cinstall");
    system(cmd);
    printf("\nInstalling dotfiles...\n");
    return 0;
}

float* update() 
{
    char *USERNAME = getenv("HOME");

    // error message if username can't be fetched 
    if (USERNAME == NULL) 
    {
        printf(BOLD_S UDRL_S"\nCan't find home directory\n"STYLE_END);
        return NULL;
    }

    // create path to config
    char HYPRPATH[256];
    snprintf(HYPRPATH, sizeof(HYPRPATH), 
	    "%s/.config/hypr/hyprland.conf", USERNAME);

    // open the file with HYPRPATH
    FILE *file = fopen(HYPRPATH, "r");
    
    // error checking 
    if (file == NULL) 
    {
	printf(BOLD_S UDRL_S"\nNo such file or directory\n"STYLE_END);
	// returns null if the file can't be opened/found
        return NULL;
    }
    static float VAWSM[32] = {0};

    char line[256];
    while (fgets(line, sizeof(line), file)) 
    {
        if (sscanf(line, "# AWSMVERSION: %31f[0-9.]", VAWSM) == 1) 
		{
            //printf("VAWSM: %s\n", VAWSM); // for troubleshooting purposes
            fclose(file);
            return VAWSM;
        }
    }

    fclose(file);
    return 0;
}
