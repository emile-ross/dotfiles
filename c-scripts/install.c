#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CMD 512

// error code 1 is caused by a missing dependency

char HYPR;
int is_hyprland() 
{
	// check current environment variable
	const char *hypr_sig = getenv("HYPRLAND_INSTANCE_SIGNATURE");
    	const char *current_desktop = getenv("XDG_CURRENT_DESKTOP");
    
    	// Return true if either check confirms Hyprland
    	return (hypr_sig != NULL) || (current_desktop != NULL && 
            (strcasestr(current_desktop, "hyprland") != NULL));
}

int main() 
{
    if (is_hyprland()) 
    {
        printf("Current desktop is Hyprland\n");
		char HYPR == 'Y';
    }
    else
    {
        printf("Current desktop is NOT Hyprland\n");
		printf("Would you like to install the Hyprland config? (Y/n)\n");
	    scanf(" %c", &HYPR);
    }
	
    // this float sets the past version (0 because this is the install script)
    float pver = 0.0f;
    int FIXINST;
    printf("\n What do you want to do?");
    printf("\n [1] proceed with installation");
    printf("\n [2] fix your installation");
	printf("\n [3] prompt for every config");
	printf("\n [4] exit this script\n");
    scanf(" %d", &FIXINST);
    if (FIXINST == '1')
	{
	    char BTOP == 'y';
		char CAVA == 'y';
	}
    if (FIXINST == '2')
    {
		if (HYPR == 'Y' || HYPR == 'y')
        {
			system("sudo pacman -S waybar hyprland");
		}
        // add commands for fixing script below
        system("sudo pacman -S --noconfim nvim git cava fuzzel");
        // system("yay -S --noconfirm ");

        // make directories
        system("mkdir -p ~/.config/nvim/lua/config && mkdir -p ~/.config/nvim/lua/plugins && mkdir -p ~/.config/fastfetch && mkdir -p ~/.config/hypr");
        system("mkdir -p ~/.config/cava && mkdir -p ~/.config/fuzzel");
    }
	if (FIXINST == '3')
	{
	    // prompt for everything
		char BTOP;
		char CAVA;
		char FAST;
		char FUZZ;
		char HYPR;
		char GTKL;
		return 0;
	}
	if (FIXINST == '4')
	{
		printf("\nExiting install script.\n");
		return 0;
	}
    else
    {
        printf("\n The installation is now starting. \n");
    }
    // Check if yay is installed
    if (system("test -f /sbin/yay") == 0)
    {
        printf("Yay is now installed, congrats!\n");
    }
    else
    {
        char YAY;
        printf("Yay is not installed, do you want to install it? (Y/n): ");
        scanf(" %c", &YAY); // asks the user if they wanna install yay (needed)
        if (YAY == 'Y' || YAY == 'y')
        {
            // Check if makepkg is installed ( it is needed in order to compile yay )
            if (system("command -v makepkg > /dev/null") != 0)
            {
                printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
                system("sudo pacman -S --noconfirm base-devel");

                // Check if makepkg is available after installing the base-devel package
                if (system("command -v makepkg > /dev/null") != 0)
                {
                    printf("Makepkg installation failed. Please check your system configuration.\n");
                    return 1;
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
            char cmd[256];
            snprintf(cmd, sizeof(cmd),
                "git clone https://aur.archlinux.org/yay.git &&"
                "cd yay &&"
                "makepkg -si");
            system(cmd);
            printf("\nYay is installed, congrats!\n");
        }
        else
        {
            printf("\nYay is needed in order to proceed with the script.\n");
            return 1;
        }
    }
    // Install dependencies
    char PKGINSTALL;
    printf("Do you want to proceed with the installation of packages? (Y/n): ");
    scanf(" %c", &PKGINSTALL);
    // ask the user if they want to install packages (needed)
    printf("\n");
    if (PKGINSTALL == 'Y' || PKGINSTALL == 'y')
    {
        // install packages
        if (HYPR == 'Y' || HYPR == 'y')
        {
    	char cmd[256];
	    snprintf(cmd, sizeof(cmd),
		    "yay -S --noconfirm kitty btop gtklock hyprpaper floorp-bin librewolf-bin xclip wl-clipboard && "
		    "sudo pacman -S --noconfirm ttf-jetbrains-mono nerd-fonts-jetbrains-mono fastfetch");
		system(cmd);
        }
        else
        {
    	char cmd[256];
	    snprintf(cmd, sizeof(cmd),
		    "yay -S --noconfirm kitty floorp-bin btop librewolf-bin xclip wl-clipboard && "
		    "sudo pacman -S --noconfirm ttf-jetbrains-mono nerd-fonts-jetbrains-mono fastfetch");
		system(cmd);
        }
    }
    // Propose saving the old config files before performing the update
    char ARCHIVE;
    printf("Do you want to save a copy of your old dotfiles before applying the new config? (Y/n): ");
    scanf(" %c", &ARCHIVE);
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        // renaming old configs before replacing them
        
        if (HYPR == 'Y' || HYPR == 'y')
        {
            char cmd[512];
                snprintf(cmd, sizeof(cmd),
                    "mkdir -p ~/.config/hypr && cd ~/.config/hypr && "
                    "mv hyprland.conf hyprland-oldv%.1f.conf && "
                    "mv hyprpaper.conf hyprpaper-oldv%.1f.conf && "
                    "mv hypridle.conf hypridle-oldv%.1f.conf",
                pver, pver, pver);
                system(cmd);

                snprintf(cmd, sizeof(cmd),
                    "mkdir -p ~/.config/waybar && cd ~/.config/waybar && "
                    "mv config.jsonc config-oldv%.1f.jsonc && "
                    "mv style.css style-oldv%.1f.css",
                pver, pver);
                system(cmd);
			    // archive btop config
			    snprintf(cmd, sizeof(cmd),
                    "mv ~/.config/btop/config.jsonc "
					"~/.config/btop/config-oldv%.1f.jsonc", pver);
                system(cmd);
        }

    snprintf(cmd, sizeof(cmd),
         "mkdir -p ~/.config/nvim && cd ~/.config/nvim && "
         "mv init.lua init-oldv%.1f.lua && "
         "mv lazy-lock.json lazy-lock-oldv%.1f.json",
         pver, pver);
    system(cmd);

    snprintf(cmd, sizeof(cmd),
		    "mkdir -p ~/.config/fastfetch && "
		    "mv ~/.config/fastfetch/config.jsonc "
		    "~/.config/fastfetch/config-oldv%.1f.jsonc", pver);
    system(cmd);
// backup kitty config
    snprintf(cmd, sizeof(cmd),
		    "mv ~/.config/kitty/kitty.conf "
		    "~/.config/kitty/kitty-oldv%.1f.conf", pver);
    snprintf(cmd, sizeof(cmd),
		    "mv ~/.config/cava/config "
		    "~/.config/cava/config-oldv%.1f", pver);
    system(cmd);

    	printf("Done. -oldv%.1f was appended to the end of the old config filenames.\n", pver);
    }
    // Install the dotfiles
    char DOTINSTALL;
    printf("Do you want to install the dotfiles? (Y/n): ");
    scanf(" %c", &DOTINSTALL);
    if (DOTINSTALL == 'Y' || DOTINSTALL == 'y')
    {
        char cmd[128];
		
        // export btop config
        snprintf(cmd, sizeof(cmd),
			        "mkdir -p ~/.config/btop && "
                	"cp ~/dotfiles/btop/config.jsonc ~/.config/btop");
        system(cmd);
		
		// export cava config
        snprintf(cmd, sizeof(cmd),
	        		"rm ~/.config/cava && "
			        "mkdir -p ~/.config/cava && "
                	"cd ~/dotfiles/cava && "
                	"cp config ~/.config/cava");
        system(cmd);
		
        // export fastfetch config
        snprintf(cmd, sizeof(cmd),
			        "mkdir -p ~/.config/fastfetch && "
                    "cd ~/dotfiles/fastfetch && "
                    "cp config.jsonc ~/.config/fastfetch");
        system(cmd);
         // export fuzzel appearance
        snprintf(cmd, sizeof(cmd),
                	"cd ~/dotfiles/fuzzel && "
                	"mkdir ~/.config/fuzzel && "
                	"cp fuzzel.ini ~/.config/fuzzel");
        system(cmd);  		
        // export hyprland dotfiles

        if (HYPR == 'Y' || HYPR == 'y')
        {
        snprintf(cmd, sizeof(cmd),
			"cd ~/dotfiles/hypr && "
			"cp -f hyprland.conf ~/.config/hypr && "
			"cp -f hypridle.conf ~/.config/hypr && "
			"cp -f hyprpaper.conf ~/.config/hypr");
        system(cmd);
         // export waybar config and appearance
        snprintf(cmd, sizeof(cmd),
		        	"cd ~/dotfiles/waybar && "
               		"cp -f style.css ~/.config/waybar && "
               		"cp -f config.jsonc ~/.config/waybar");
        system(cmd);
        }

	// export gtklock config
        snprintf(cmd, sizeof(cmd),
	             	"mkdir -p ~/.config/gtklock/assets && "
                	"cd ~/dotfiles/gtklock && "
                	"cp -f style.css ~/.config/gtklock && "
                	"cp -f lockscreen.jpg ~/.config/gtklock/assets");
        system(cmd);
		
	// export kitty config
	snprintf(cmd, sizeof(cmd),
			"mkdir ~/.config/kitty && "
                	"cp -f ~/dotfiles/kitty/kitty.conf ~/.config/kitty");
	system(cmd);

        // export neovim config
        snprintf(cmd, sizeof(cmd),
			"cd ~/dotfiles/nvim && "
			"cp -f init.lua ~/.config/nvim && "
			//" cp -rf lua ~/.config/nvim && "
			//"cp -f lazy-lock.json ~/.config/nvim");
        system(cmd);
    }
        else
    {
        return 0;
    }
    return 0;
}
