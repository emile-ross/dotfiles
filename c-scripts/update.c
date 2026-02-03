#include "dotfileshead.h"


int full_update(char ARCHIVE, float pver)
{
    //float *pver = update();
    int VAWSM = (int)(pver * 100);


    switch (VAWSM)
    {
    case 100:
	printf("\nUpdating from %d\n", VAWSM);
	char cmd[512];
	snprintf(cmd, sizeof(cmd),
		"yay -S --noconfirm btop gtklock cava fuzzel kitty fastfetch nvim waybar && "
		"cp -f dotfiles/kitty/kitty.conf ~/.config/kitty && "
		"cp -f dotfiles/kitty/current-theme.conf ~/.config/current-theme.conf && "
		"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-v%.2f.conf && "
		"mv ~/.config/nvim/init.lua ~/.config/nvim/init-v%.2f.lua", pver, pver);
	system(cmd);

	snprintf(cmd, sizeof(cmd),
		"cp dotfiles/hypr/hyprland.conf ~/.config/hypr && "
		"cp dotfiles/hypr/hypridle.conf ~/.config/hypr && "
		"cp dotfiles/hypr/hyprpaper.conf ~/.config/hypr && "
		"cp dotfiles/waybar/style.css ~/.config/waybar && "
		"cp dotfiles/waybar/config.jsonc ~/.config/waybar");
	system(cmd);

        // nvim config
	snprintf(cmd, sizeof(cmd),
		"cp dotfiles/nvim/init.lua ~/.config/nvim");
	system(cmd);
	
	// do not break because we are also installing everything below
    case 120:
    
	printf("\nUpdating from v1.2%d\n", VAWSM);
	
	// do not break because we are also installing everything below
    case 130:
	printf("\nUpdating from asiodjhasidj%d\n", VAWSM);

	// do not break because we are also installing everything below
    case 140:



	// do not break because we are also installing everything below
    case 200:
	//"yay -S --noconfirm ttf-ubuntu-font-family ttf-ibmplex-mono-nerd ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd && "


    goto end;
    default:
	printf("\nUnknown version\n");
	return 1;
    end:
	printf("Update completed!\n");
    }
    return 0;
}
