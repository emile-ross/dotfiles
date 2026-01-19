#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CMD 512
// error code 1 is caused by a missing dependency

// this float sets the past version (0 because this is the install script)
float pver = 0.0f;
char HYPRI;

char BTOP(char ARCHIVE);
char CAVA(char ARCHIVE);
char FAST(char ARCHIVE);
char FUZZ(char ARCHIVE);
char GTKL(char ARCHIVE);
char HYPR(char ARCHIVE);
char KITT(char ARCHIVE);
char NVIM(char ARCHIVE);
char WAYB(char ARCHIVE);

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
	    char HYPRI = 'Y';
    }
    else
    {
	    printf("Current desktop is NOT Hyprland\n");
	    printf("Would you like to install the Hyprland config? (Y/n)\n");
	    scanf(" %c", &HYPRI);
    }
	
	int FIXINST;
	printf("\n What do you want to do?");
	printf("\n [1] proceed with installation");
	printf("\n [2] fix your installation");
	printf("\n [3] prompt for every config");
	printf("\n [4] exit this script\n");
	scanf(" %d", &FIXINST);
	if (FIXINST == '1')
	{
		char BTOPI = 'y';
		char CAVAI = 'y';
	}
    	if (FIXINST == '2')
    	{
		if (HYPRI == 'Y' || HYPRI == 'y')
        	{
			system("sudo pacman -S waybar hyprland hypridle");
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
		char BTOP(char ARCHIVE);
		char CAVA(char ARCHIVE);
		char FAST(char ARCHIVE);
		char FUZZ(char ARCHIVE);
		char HYPR(char ARCHIVE);
		char GTKL(char ARCHIVE);


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
                "makepkg -si &&"
	    	"cd ..");
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
        if (HYPRI == 'Y' || HYPRI == 'y')
        {
    	char cmd[256];
	    snprintf(cmd, sizeof(cmd),
		    "yay -S --noconfirm kitty btop gtklock hyprpaper floorp-bin librewolf-bin xclip wl-clipboard && "
		    "sudo pacman -S --noconfirm ttf-jetbrains-mono nerd-fonts-jetbrains-mono ttf-ubuntu-font-family fastfetch");
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
        
	char cmd[256];
        if (HYPRI == 'Y' || HYPRI == 'y')
        {
            	//char cmd[512];
		char HYPR(char ARCHIVE);
        }

    snprintf(cmd, sizeof(cmd),
         "mkdir -p ~/.config/nvim && cd ~/.config/nvim && "
         "mv init.lua init-oldv%.1f.lua && "
         "mv lazy-lock.json lazy-lock-oldv%.1f.json",
         pver, pver);
    system(cmd);

// backup kitty config
    snprintf(cmd, sizeof(cmd),
			"mv ~/.config/kitty/current-theme.conf "
			"~/.config/kitty/current-theme-old%.1f.conf && "
		    	"mv ~/.config/kitty/kitty.conf "
		    	"~/.config/kitty/kitty-oldv%.1f.conf", pver);
	system(cmd);
		
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
	char BTOP(char ARCHIVE);
	char CAVA(char ARCHIVE);
	char FAST(char ARCHIVE);
	char FUZZ(char ARCHIVE);
	char GTKL(char ARCHIVE);
	char KITT(char ARCHIVE);
	char NVIM(char ARCHIVE);
        if (HYPRI == 'Y' || HYPRI == 'y')
        {
		char WAYB(char ARCHIVE);
		char HYPR(char ARCHIVE);
        }
    }
        else
    {
        return 0;
    }
	printf("\nNext time you want to customize your dotfiles,");
	printf(" a user friendly script might be available (setup.c).  I enourage you to go check it out.\n");
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
                	"cp ~/dotfiles/btop/config.jsonc ~/.config/btop");
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
                	"cp dotfiles/fuzzel/fuzzel.ini "
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
                	"cp -f ~/dotfiles/kitty/kitty.conf ~/.config/kitty");
	system(cmd);
	return 0;
}

char NVIM(char ARCHIVE)
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
			"cd ~/dotfiles/waybar && "
               		"cp -f style.css ~/.config/waybar && "
               		"cp -f config.jsonc ~/.config/waybar");
	system(cmd);
	return 0;
}
