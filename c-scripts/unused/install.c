#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dotfileshead.h"

#define UDRL_S  	"\e[4m" // UDRL_S starts an underline style
#define STYLE_END   	"\e[m" // resets the styling
#define MAX_CMD 512
// error code 1 is caused by a missing dependency

// this float sets the past version (0 because this is the install script)
float pver = 0.0f;
char HYPRI;
char ARCHIVE;
char PKGINSTALL;

void BASH(char ARCHIVE, float pver, char PKGINSTALL);
void SWAY(char ARCHIVE, float pver, char PKGINSTALL);
void BTOP(char ARCHIVE, float pver, char PKGINSTALL);
void CAVA(char ARCHIVE, float pver, char PKGINSTALL);
void FAST(char ARCHIVE, float pver, char PKGINSTALL);
void FUZZ(char ARCHIVE, float pver, char PKGINSTALL);
void GTKL(char ARCHIVE, float pver, char PKGINSTALL);
void HYPR(char ARCHIVE, float pver, char PKGINSTALL);
void KITT(char ARCHIVE, float pver, char PKGINSTALL);
void NVIM(char ARCHIVE, float pver, char PKGINSTALL);
void WAYB(char ARCHIVE, float pver, char PKGINSTALL);

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
	printf("\n [0] exit this script\n");
	scanf(" %d", &FIXINST);
	if (FIXINST == '1')
	{
	    //char BTOPI = 'y';
	    //char CAVAI = 'y';
	    BTOP(ARCHIVE, 0.0, 'Y');
	    CAVA(ARCHIVE, 0.0, 'Y');
	    FAST(ARCHIVE, 0.0, 'Y');
	    FUZZ(ARCHIVE, 0.0, 'Y');
	    GTKL(ARCHIVE, 0.0, 'Y');
	    HYPR(ARCHIVE, 0.0, 'Y');
	    KITT(ARCHIVE, 0.0, 'Y');
	    NVIM(ARCHIVE, 0.0, 'Y');
	    WAYB(ARCHIVE, 0.0, 'Y');
	    
	}
	else if (FIXINST == '2')
    	{
	    if (HYPRI == 'Y' || HYPRI == 'y')
            {
	    	system("sudo pacman -S --noconfim waybar hyprland hypridle");
	    }
        // add commands for fixing script below
            	char cmd[256];
            	snprintf(cmd, sizeof(cmd),
			"sudo pacman -S --noconfim nvim git fastfetch fuzzel btop kitty gtop");
		system(cmd);
			
        // system("sudo pacman -S --noconfim nvim git cava fuzzel");
        // system("yay -S --noconfirm ");

        // make directories
        system("mkdir -p ~/.config/nvim/lua/config && mkdir -p ~/.config/nvim/lua/plugins && mkdir -p ~/.config/fastfetch && mkdir -p ~/.config/hypr");
        system("mkdir -p ~/.config/cava && mkdir -p ~/.config/fuzzel");
	}
	else if (FIXINST == '0')
	{
	    printf("\nExiting install script.\n");
	    return 0;
	}
	else
	{
	    printf("\nExiting install script.\n");
	    return 1;
	}
    //
    // (I have no clue what this is supposed to be)
    // else
    // {
    //     printf("\n The installation is now starting. \n");
    // }

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
		    printf("Helpful link: \"https://wiki.archlinux.org/title/Makepkg\"\n");
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
            return 0;
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
		    "yay -S --noconfirm kitty btop gtklock hyprpaper activate-linux-git "
		    "floorp-bin librewolf-bin xclip wl-clipboard cava fastfetch && "
		    "sudo pacman -S --noconfirm ttf-jetbrains-mono "
		    "nerd-fonts-jetbrains-mono ttf-ubuntu-font-family");
	    system(cmd);
        }
        else
        {
    	char cmd[256];
	snprintf(cmd, sizeof(cmd),
		"yay -S --noconfirm kitty floorp-bin btop librewolf-bin xclip wl-clipboard fastfetch "
		"sway swaylock ly cava wlroots && "
		"sudo pacman -S --noconfirm ttf-jetbrains-mono ttf-ibm-plex ttf-roboto nerd-fonts-jetbrains-mono");
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
	    HYPR(ARCHIVE, 0.0, 'Y');
	    printf("\nHyprland install completed\n");
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
	BTOP(ARCHIVE, 0.0, 'Y');
	CAVA(ARCHIVE, 0.0, 'Y');
	FAST(ARCHIVE, 0.0, 'Y');
	FUZZ(ARCHIVE, 0.0, 'Y');
	GTKL(ARCHIVE, 0.0, 'Y');
	KITT(ARCHIVE, 0.0, 'Y');
	NVIM(ARCHIVE, 0.0, 'Y');

        if (HYPRI == 'Y' || HYPRI == 'y')
        {
		WAYB(ARCHIVE, 0.0, 'Y');
		HYPR(ARCHIVE, 0.0, 'Y');
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
		"mkdir -p ~/.config/btop && "
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
	    "mkdir -p ~/.config/cava && "
	    "cp -f dotfiles/cava/config ~/.config/cava/ && ");
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
	    "rm ~/.config/fastfetch && "
	    "mkdir -p ~/.config/fastfetch/assets && "
	    "cp -f dotfiles/fastfetch/assets/*.png ~/.config/fastfetch/assets && "
	    "cp -f dotfiles/fastfetch/config.jsonc ~/.config/fastfetch && "
	    "cp -f dotfiles/fastfetch/config-other.jsonc ~/.config/fastfetch && "
	    "cp -f dotfiles/fastfetch/config-default.jsonc ~/.config/fastfetch");
    system(cmd);
}
void FUZZ(char ARCHIVE, float pver, char PKGINSTALL)
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
	        "mkdir -p ~/.config/gtklock/assets && "
                "cp -f dotfiles/gtklock/style.css ~/.config/gtklock && "
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
		"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-oldv%.2f.conf && "
        	"mv ~/.config/hypr/hyprpaper.conf ~/.config/hypr/hyprpaper-oldv%.2f.conf && "
        	"mv ~/.config/hypr/hypridle.conf ~/.config/hypr/hypridle-oldv%.2f.conf", pver, pver, pver);
        system(cmd);
    }
    // export hyprland configs
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/hypr && "
	    "cp -f dotfiles/hypr/hyprland.conf ~/.config/hypr && "
    	    "cp -f dotfiles/hypr/hypridle.conf ~/.config/hypr && "
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
    // export kitty config
    snprintf(cmd, sizeof(cmd),
	    "mkdir ~/.config/kitty && "
	    "cp -f dotfiles/kitty/current-theme.conf ~/.config/kitty && "
	    "cp -f dotfiles/kitty/kitty.conf ~/.config/kitty");
    system(cmd);
}

void NVIM(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        snprintf(cmd, sizeof(cmd),
    	    	"mv ~/.config/nvim/init.lua ~/.config/nvim/init-oldv%.1f.lua && "
    	    	"mv ~/.config/nvim/lua/config/lazy.lua ~/.config/nvim/lua/config/lazy-oldv%.1f.lua && "
    	    	"mv ~/.config/nvim/lazy-lock.json ~/.config/nvim/lazy-lock-oldv%.1f.json",
    	    	pver, pver, pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install neovim (nvim) package
	// nvim is most likely already installed 
        snprintf(cmd, 32,
		"yay -S --noconfirm nvim");
	system(cmd);
    }

    // export nvim config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/nvim && "
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
	    "mkdir -p ~/.config/sway && "
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
		"mv ~/.config/waybar/config.jsonc ~/.config/waybar/config-oldv%.2f.jsonc && "
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
	    "mkdir -p ~/.config/waybar && "
	    "cp -f dotfiles/waybar/style.css ~/.config/waybar && "
            "cp -f dotfiles/waybar/config.jsonc ~/.config/waybar");
    system(cmd);
}
