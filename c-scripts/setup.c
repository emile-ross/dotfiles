#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

float pver = 0.0f;
char HYPRI;
int fexit()
{
	endwin();
	return 0;
}

int menu();

void install_script();
void fix_script();
void advanced_mode();

char BTOP(char ARCHIVE);
void CAVA(char ARCHIVE);
void FAST(char ARCHIVE);
void FUZZ(char ARCHIVE);
void GTKL(char ARCHIVE);
void HYPR(char ARCHIVE);
void KITT(char ARCHIVE);
void NVIM(char ARCHIVE);
void WAYB(char ARCHIVE);

int install_yay();
int install_noconfirm();

int main()
{
		menu();
}
int menu() 
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    const char *menu[] = 
    {
        "Install",
        "Fix install",
        "Advanced configuration",
        "Exit"
    };
    int n_options = sizeof(menu) / sizeof(menu[0]);
    int highlight = 0;
    int choice;

    while (1) 
    {
	    clear();
        	for (int i = 0; i < n_options; ++i) 
        	{	if (i == highlight) 
			attron(A_REVERSE);
			mvprintw(i + 1, 1, menu[i]);
        	    	if (i == highlight) 
        	        attroff(A_REVERSE);
        	}
        	refresh();
        	choice = getch();

        	switch (choice) 
        	{
        	    	case KEY_UP:
		    	        highlight = (highlight == 0) ? n_options - 1 : highlight - 1;
        	    	        break;
        	    	case KEY_DOWN:
        	    	        highlight = (highlight == n_options - 1) ? 0 : highlight + 1;
        	    	        break;
        	    	case 10: // Enter key
				 if (highlight == 0) 
				 {
					 clear();
					 printw("success\n");
					 refresh();
				//	        BTOP('Y');
				//	        CAVA('Y');
				//	 
        	    	        //	install_script();
		    	        // 	install_noconfirm();
				 } 
				 else if (highlight == 1)
				 {
		    	    		
		    	    		fix_script();   // display a prompt
		    	    		install_yay();  // Check if yay is installed

		    	    		// update after yay was checked
					
		    	    		       	char cmd[256];
		    	    		       	snprintf(cmd, sizeof(cmd),
		    	    					"yay -Syu && "
		    	    		       	    		"yay -S --noconfirm fastfetch cava btop gtklock");
		    	    		       	system(cmd);
		    	    			printw("\nInstall was fixed\n");
        	    	    } 
        	    	    else if (highlight == 2) 
        	    	    {
		    	    	endwin();
		    	    	char cmd[256];
		    	    	snprintf(cmd, sizeof(cmd),
		    	    			"cd dotfiles/c-scripts && "
		    	    			"gcc install.c -o cinstall && "
		    	    			"./cinstall");
		    	    	system(cmd);

		    	    } 
        	    	    else if (highlight == 3) 
        	    	    {
		    	    	fexit();
        	    	        return 0;
        	    	    }
        	    	    break;
		}
    }

    endwin();
    return 0;
}
void install_script() 
{
	clear();
	printw("\nThis will execute install script.");
	printw("\n Are you sure you want to proceed (Y/n)\n");
	getch();
	char CONFIRM_FULL_INSTALL;
	scanf("%c", CONFIRM_FULL_INSTALL);
	refresh();
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
                	"cp ~/dotfiles/btop/config.jsonc ~/.config/btop");
        system(cmd);
}
void CAVA(char ARCHIVE)
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
}
void FAST(char ARCHIVE)
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
}
void FUZZ(char ARCHIVE)
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
                	"cp dotfiles/fuzzel/fuzzel.ini "
			"~/.config/fuzzel");
        system(cmd);  		
}
void GTKL(char ARCHIVE)
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
}

void HYPR(char ARCHIVE)
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
}
void KITT(char ARCHIVE)
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
                	"cp -f ~/dotfiles/kitty/kitty.conf ~/.config/kitty");
	system(cmd);
}

void NVIM(char ARCHIVE)
{
	char cmd[256];
        if (ARCHIVE == 'Y' || ARCHIVE == 'y')
	{
	    snprintf(cmd, sizeof(cmd),
			    "mkdir -p ~/.config/nvim && cd ~/.config/nvim && "
	    		    "mv init.lua init-oldv%.1f.lua && "
			    "mv lazy-lock.json lazy-lock-oldv%.1f.json",
			    pver, pver);
	    system(cmd);
	}
	// export nvim config
        snprintf(cmd, sizeof(cmd),
			"mkdir -p ~/.config/nvim && cd ~/.config/nvim && "
			"cp -f dotfiles/nvim/init.lua ~/.config/nvim");
			//" cp -rf lua ~/.config/nvim && "
			//"cp -f lazy-lock.json ~/.config/nvim");
        system(cmd);
}
void WAYB(char ARCHIVE)
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
			"mkdir -p ~/.config/waybar && "
               		"cp -f dotfiles/waybar/style.css ~/.config/waybar && "
               		"cp -f dotfiles/waybar/config.jsonc ~/.config/waybar && ");
	system(cmd);
}


int install_yay()
{
	// Check if yay is installed
    	if (system("test -f /sbin/yay") == 0)
    	{
    	    printw("\nYay is already installed, moving on...\n");
    	}
    	else
    	{
		char YAY;
    	    	printw("Yay is not installed, do you want to install it? (Y/n): ");
    	    	scanf(" %c", &YAY); // asks the user if they wanna install yay (needed)
    	    	if (YAY == 'Y' || YAY == 'y')
    	    	{
			// Check if makepkg is installed ( it is needed in order to compile yay )
    	    	    	if (system("command -v makepkg > /dev/null") != 0)
    	    	    	{
    	    	    	    	printw("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
    	    	    	    	system("sudo pacman -S --noconfirm base-devel");

    	    	    	    	// Check if makepkg is available after installing the base-devel package
    	    	    	    	if (system("command -v makepkg > /dev/null") != 0)
    	    	    	    	{
    	    	    	    	    	printw("\nMakepkg installation failed. Please check your system configuration.\n");
    	    	    	    	    	return 1;
    	    	    	    	}
    	    	    	    	else
    	    	    	    	{
					printw("Makepkg has been successfully installed!\n");
    	    	    	    	}
    	    	    	}
    	    	    else
    	    	    {
			    printw("Makepkg is already installed.\n");
    	    	    }
    	    	    char cmd[256];
    	    	    snprintf(cmd, sizeof(cmd),
				    "git clone https://aur.archlinux.org/yay.git &&"
				    "cd yay &&"
				    "makepkg -si && "
				    "cd ..");
    	    	    system(cmd);
    	    	    printw("\nYay is installed, congrats!\n");
    	    	}
    	    	else
    	    	{
			printw("\nYay is needed in order to proceed with the script.\n");
			return 1;
    	    	}
    	}
}


void fix_script() 
{
    printw("\nFixing the installation...\n");
    refresh();
    //getch(); // Wait for user input
}
void advanced_mode() 
{
	printw("\nAdvanced configuration isn't available yet.\n");
	refresh();
	getch(); // Wait for user input
}

int install_noconfirm()
{
	printw("\nInstalling\n");
	return 0;
}
