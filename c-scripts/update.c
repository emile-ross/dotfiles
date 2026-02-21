#include "dotfileshead.h"

int full_update(char ARCHIVE, float pver)
{
    int VAWSM = (int)(pver * 100);
    switch (VAWSM)
    {
    case 100:
	printf("\nUpdating from %d\n", VAWSM);
	char cmd[512];
	snprintf(cmd, 192,
		"yay -S --noconfirm btop cava fuzzel kitty fastfetch nvim waybar ; "
		"cp -f dotfiles/kitty/kitty.conf ~/.config/kitty ; "
		"cp -f dotfiles/kitty/current-theme.conf ~/.config/current-theme.conf ");
	system(cmd);
	snprintf(cmd, 192,
		"cp dotfiles/hypr/hypridle.conf ~/.config/hypr ; "
		"cp dotfiles/hypr/hyprpaper.conf ~/.config/hypr ");
	system(cmd);
	// do not break because we are also installing everything below
    case 120:
	snprintf(cmd, 256,
		"cp -f dotfiles/fuzzel/fuzzel.ini ~/.config/fuzzel/ ; "
		"cp -f dotfiles/fuzzel/old-fuzzel.ini ~/.config/fuzzel/ ; "
		"cp dotfiles/waybar/style.css ~/.config/waybar ; "
		"cp dotfiles/waybar/config.jsonc ~/.config/waybar");
	system(cmd);
	// do not break because we are also installing everything below
    case 130:
	if (ARCHIVE == 'Y' || ARCHIVE == 'y')
	{
	    char cmd[512];
	    snprintf(cmd, 64,
		    "mv -f ~/.config/cava/config ~/.config/cava/config-oldv%.2f", pver);
	    system(cmd);
	}
	// export cava + kitty
	snprintf(cmd, sizeof(cmd),
		"yay -S --noconfirm ttf-ubuntu-font-family ttf-ibmplex-mono-nerd ; "
		"ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd ; "
		"cp -f dotfiles/kitty/current-theme.conf ~/.config/kitty/ ; "
		"mkdir -p ~/.config/cava/ ; "
		"rm ~/.config/cava/config ; "
		"cp -f dotfiles/cava/config ~/.config/cava/ ");
	system(cmd);

	// do not break because we are also installing everything below
    case 140:
	snprintf(cmd, 192,
		"mv ~/.config/btop/btop.conf ~/.config/btop/btop-oldv%.2f ; "
		"mkdir -p ~/.config/btop/ ; "
		"cp -f dotfiles/btop/btop.conf ~/.config/btop/ ", pver);
	system(cmd);
	// do not break because we are also installing everything below
    case 200:


	snprintf(cmd, sizeof(cmd),
		"mkdir ~/.config/gtklock ; "
		"yay -S --noconfirm nvim gtklock ; "
		"mv ~/.config/gtklock/style.css ~/.config/gtklock/style-v%.2f.css ; "	// gtklock exporting
		"cp -f dotfiles/gtklock/style.css ~/.config/gtklock/style.css ; "
		"mv ~/.config/nvim/init.lua ~/.config/nvim/init-v%.2f.lua ; "		// nvim exporting
		"cp -f dotfiles/nvim/init.lua ~/.config/nvim/init.lua ", pver, pver);
	system(cmd);
	// do not break because we are also installing everything below
    case 210:
	snprintf(cmd, 2048,
		"mkdir -p ~/.config/sway ; "
		"mkdir ~/.config/nvim ; "
		"yay -S --noconfirm sway ; "
		"mv ~/.config/nvim/init.lua ~/.config/nvim/init-oldv%.2f.lua ; "
		"cp -f dotfiles/nvim/init.lua ~/.config/nvim ; "
		"mv ~/.config/gtklock/style.css ~/.config/gtklock/style-v%.2f.css ; "
		"cp -f dotfiles/gtklock/style.css ~/.config/gtklock/style.css ; "
		"mv ~/.config/kitty/kitty.conf ~/.config/kitty/kitty-oldv%.2f.conf ; "
		"cp -f dotfiles/kitty/kitty.conf ~/.config/kitty/ ; "	// update kitty config
		, pver, pver, pver, pver);
	system(cmd);
	// do not break because we are also installing everything below
    case 220:
	
	snprintf(cmd, sizeof(cmd),
		"mv ~/.config/sway/config ~/.config/sway/config-oldv%.2f ; "
		"cp dotfiles/sway/config ~/.config/sway/ ; "	// update sway config
		"cp dotfiles/sway/config-default ~/.config/sway/ ; "
		"mkdir -p ~/.config/mpv/ ; "
		"mv ~/.config/mpv/mpv.conf ~/.config/mpv/mpv-oldv%.2f.conf ; "
		"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-v%.2f.conf ; "
		"cp -f dotfiles/hypr/hyprland.conf ~/.config/hypr/ ; "
		"cp dotfiles/mpv/mpv.conf ~/.config/mpv/ ", pver, pver, pver);
	system(cmd);

    goto end;

    case 230:
	printf("\nYou are running the latest version.\n");
    goto end;

    default:
	printf("\nUnknown version\n");
	return 1;
    end:
	printf("Update completed!\n");
    }
    return 0;
}
