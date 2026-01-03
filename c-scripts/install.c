#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CMD 512
// error code 1 is caused by a missing dependency
int main() 
{
    int FIXINST;
    printf("\n What do you want to do?");
    printf("\n [1] proceed with installation");
    printf("\n [2] fix your installation");
    printf("\n : ");
    scanf(" %d", &FIXINST);
    if (FIXINST == '2')
    {
        // add commands for fixing script below
        system("sudo pacman -S --noconfim nvim waybar git cava fuzzel");
        // system("yay -S --noconfirm ");

        // make directories
        system("mkdir -p ~/.config/nvim/lua/config && mkdir -p ~/.config/nvim/lua/plugins && mkdir -p ~/.config/fastfetch && mkdir -p ~/.config/hypr");
        system("mkdir -p ~/.config/cava && mkdir -p ~/.config/fuzzel");
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
            system("git clone https://aur.archlinux.org/yay.git");
            system("cd yay && makepkg -si");
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
        system("yay -S --noconfirm hyprland kitty waybar gtklock hyprpaper fuzzel fastfetch floorp-bin librewolf-bin xclip wl-clipboard");
    }
    // Propose saving the old config files before performing the update
    char ARCHIVE;
    printf("Do you want to save a copy of your old dotfiles before applying the new config? (Y/n): ");
    scanf(" %c", &ARCHIVE);
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        // renaming old configs before replacing them
        system("mkdir ~/.config/hypr && cd ~/.config/hypr && mv hyprland.conf hyprland-oldv0.conf && mv hyprpaper.conf hyprpaper-oldv0.conf && mv hypridle.conf hypridle-oldv0.conf");
        system("mkdir ~/.config/waybar && cd ~/.config/waybar && mv config.jsonc config-oldv0.jsonc && mv style.css style-oldv0.css");
        system("mkdir ~/.config/nvim cd ~/.config/nvim && mv init.lua init-oldv0.lua && mv lazy-lock.json lazy-lock-oldv0.json");
        // waybar archiving is missing
        // fastfetch archiving is missing
        
        printf("Done. -oldv0 was appended to the end of the old config filenames.\n");
    }
    // Install the dotfiles
    char DOTINSTALL;
    printf("Do you want to install the dotfiles? (Y/n): ");
    scanf(" %c", &DOTINSTALL);
    if (DOTINSTALL == 'Y' || DOTINSTALL == 'y') 
    {
        // export hyprland dotfiles
        system("cd ~/dotfiles/hypr && cp hyprland.conf ~/.config/hypr && cp hypridle.conf ~/.config/hypr && cp hyprpaper.conf ~/.config/hypr");
        
        // export neovim config
            system("cd ~/dotfiles/nvim && cp -f init.lua ~/.config/nvim && cp -rf lua ~/.config/nvim && cp -f lazy-lock.json ~/.config/nvim");
        
         // export waybar config and appearance
         system("cd ~/dotfiles/waybar && cp -f style.css ~/.config/waybar && cp -f config.jsonc ~/.config/waybar");

         // export fuzzel appearance
         system("cd ~/dotfiles/fuzzel && mkdir ~/.config/fuzzel && cp fuzzel.ini ~/.config/fuzzel");

        // export fastfetch config
        system("cd ~/dotfiles/fastfetch && cp config.jsonc ~/.config/fastfetch");

        // export cava config 
        system("cd ~/dotfiles/cava && cp config ~/.config/cava");
    }
        else 
    {
        return 0;
    }
    return 0;
}
