#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// for the system() function

int main(void) 
{
    FILE *f = fopen("hyprland.conf", "r");
    if (!f) return 1; // exit with errcode 1 if it fails
    char line[128]; // down from 512 bytes
    char VAWSM[12] = {0}; // only loads the actual version

    while (fgets(line, sizeof(line), f)) 
    {
        char *p = line;

        // skip whitespace
        while (isspace((unsigned char)*p)) p++;

        // only check comments
        if (*p != '#')
            continue;

        p++; // skip '#'
        while (isspace((unsigned char)*p)) p++;

        if (strncmp(p, "AWSMVERSION:", 12) == 0) 
        {
            p += 12;
            while (isspace((unsigned char)*p)) p++;

            p[strcspn(p, "\r\n")] = 0; // strip newline
            strncpy(VAWSM, p, sizeof(VAWSM) - 1);
            break;
        }
    }

    fclose(f);

    if (VAWSM[0]) 
    {
        printf("VAWSM = %s\n", VAWSM);

        // Only execute if version is exactly 1.0
        if (strcmp(VAWSM, "1.0") == 0) 
        {
		char cmd[512];
		snprintf(cmd, sizeof(cmd),
				"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-v%s.conf", VAWSM);
		system(cmd);
			
            // system("cd ~/.config/hypr && mv hyprland.conf hyprland-oldv0.conf && mv hyprpaper.conf hyprpaper-oldv0.conf && mv hypridle.conf hypridle-oldv0.conf");
			snprintf(cmd, sizeof(cmd),
				"yay -S --noconfirm btop gtklock cava fuzzel kitty fastfetch nvim waybar && "
				"cp -f dotfiles/kitty/kitty.conf ~/.config/kitty && "
				"cp -f dotfiles/kitty/current-theme.conf ~/.config/current-theme.conf && "
		    		"mv ~/.config/nvim/init.lua ~/.config/nvim/init-v%s.lua", VAWSM);
			system(cmd);
            // system("cd ~/.config/hypr && mv hyprland.conf");
            
            // backup old configs with the current version name 
            // only the modifed files are backed up

            // hyprland + waybar config
			snprintf(cmd, sizeof(cmd),
				"cd dotfiles/hypr && "
				"cp hyprland.conf ~/.config/hypr && "
				"yay -S --noconfirm ttf-ubuntu-font-family ttf-ibmplex-mono-nerd ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd && "
				"cp hypridle.conf ~/.config/hypr && "
				"cp hyprpaper.conf ~/.config/hypr && "
				"cd .. && "
				"cd .. && "
				"cd dotfiles/waybar && "
				"cp style.css ~/.config/waybar && "
				"cp config.jsonc ~/.config/waybar && "
				"cd .. && "
				"cd .. ");
			system(cmd);

            		// nvim config
			snprintf(cmd, sizeof(cmd),
				"cd dotfiles/nvim && "
				"cp init.lua ~/.config/nvim && "
				"cp -rf lua ~/.config/nvim && "
				"cp lazy-lock.json ~/.config/nvim"
				"cd .. && "
				"cd .. ");
			system(cmd);
            //system("cd ~/dotfiles/nvim && cp init.lua ~/.config/nvim && cp -rf lua ~/.config/nvim && cp lazy-lock.json ~/.config/nvim");

            // waybar config
            // system("cd ~/dotfiles/waybar && cp style.css ~/.config/waybar && cp config.jsonc ~/.config/waybar");

            // fastfetch config
            system("cd ~/dotfiles/fastfetch && cp config.jsonc ~/.config/fastfetch");
        } 
        else if (strcmp(VAWSM, "1.2") == 0) 
        {	
			char cmd[1024];
			snprintf(cmd, sizeof(cmd),
				"sudo pacman --noconfirm btop cava fuzzel kitty hyprland && "
			    	"yay -S --noconfirm ttf-ubuntu-font-family ttf-ibmplex-mono-nerd ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd && "
			    	"rm ~/.config/cava && "
			    	"mkdir ~/.config/cava && "
			    	"cp -f ~/dotfiles/cava/config ~/.config/cava/ && "
			    	"mv ~/.config/kitty/kitty.conf ~/.config/kitty/kitty-oldv0.conf && "
			    	"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-oldv1.4.conf && "
			    	"cp -f ~/dotfiles/hypr/hyprland.conf ~/.config/hypr/ && "
			    	"cp -f ~/dotfiles/fuzzel/fuzzel.ini ~/.config/fuzzel && "
				"cp -f dotfiles/kitty/kitty.conf ~/.config/kitty && "
				"cp -f dotfiles/kitty/current-theme.conf ~/.config/current-theme.conf");
			system(cmd);
			system("yay -S --noconfirm btop gtklock cava fuzzel kitty && ");
    		// import fuzzel config	
		    system("cd ~/dotfiles/ && cp -r fuzzel");
        }
        else if (strcmp(VAWSM, "1.3") == 0)
        {
			char cmd[1024];
			snprintf(cmd, sizeof(cmd),
				"sudo pacman --noconfirm btop cava fuzzel kitty hyprland && "
				"yay -S --noconfirm ttf-ubuntu-font-family ttf-ibmplex-mono-nerd ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd && "
				"rm ~/.config/cava && "
				"mkdir ~/.config/cava && "
				"cp -f dotfiles/cava/config ~/.config/cava/ && "
				"yay -S --noconfirm ttf-ubuntu-font-family && "
				"mv ~/.config/kitty/kitty.conf ~/.config/kitty/kitty-oldv0.conf && "
				"cp -f dotfiles/kitty/kitty.conf ~/.config/kitty && "
				"cp -f dotfiles/kitty/current-theme.conf ~/.config/current-theme.conf");
			system(cmd);
        }
		else if (strcmp(VAWSM, "1.4") == 0)
		{
			char cmd[1024];
			snprintf(cmd, sizeof(cmd),
				"sudo pacman --noconfirm btop kitty && "
			    	"yay -S --noconfirm btop gtklock && "
			    	"yay -S --noconfirm ttf-ubuntu-font-family ttf-ibmplex-mono-nerd ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd && "
			    	"rm ~/.config/cava && "
			    	"mkdir ~/.config/cava && "
			    	"cp -f ~/dotfiles/cava/config ~/.config/cava/ && "
			    	"mv ~/.config/kitty/kitty.conf ~/.config/kitty/kitty-oldv0.conf && "
			    	"cp -f ~/dotfiles/kitty/kitty.conf ~/.config/kitty && "
			    	"cp -f ~/dotfiles/kitty/current-theme.conf ~/.config/current-theme.conf");
			system(cmd);

			printf("\n Update completed.");
			printf("\n Would you like to install the Neovim plugins? (Y/n)\n");
			char ENVIM;
			scanf(" %c", &ENVIM);
				if (ENVIM == 'Y' || ENVIM == 'y')
				{
				    system("nvim");
				}
				    else
				{
				    return 0;
				}
		}
		else if (strcmp(VAWSM, "2.0") == 0)
		{
		    char cmd[1024];
		    snprintf(cmd, sizeof(cmd),
			    "sudo pacman --noconfirm sway mpv && "
		            "yay -S --noconfirm btop gtklock && "
		            "yay -S --noconfirm ttf-ubuntu-font-family ttf-ibmplex-mono-nerd ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd && "
		            "rm ~/.config/cava && "
		            "mkdir ~/.config/cava && "
		            "cp -f ~/dotfiles/cava/config ~/.config/cava/ && "
		            "mv ~/.config/kitty/kitty.conf ~/.config/kitty/kitty-oldv0.conf && "
		            "cp -f ~/dotfiles/kitty/kitty.conf ~/.config/kitty && "
		            "cp -f ~/dotfiles/kitty/current-theme.conf ~/.config/current-theme.conf");
		    system(cmd);

		    printf("\n Update completed.");
		}
		else if (strcmp(VAWSM, "2.0") == 0) // check if latest version is installed
		{
			printf("\n Your dotfiles are up to date\n");
		}
        else 
        {
            printf("\nUnsupported VAWSM version. No files were copied.\n");
        }
    } 
    else 
    {
            printf("You need to install the dotfiles before updating them.\n");
    }
printf("\n If you encountered any issues, you can execute the install.c script and use the fixing option.\n");
    return 0;
}
