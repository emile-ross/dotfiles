#include "dotfileshead.h"

int full_update(char ARCHIVE, float pver)
{
    int VAWSM = (int)(pver * 100);
    switch (VAWSM)
    {
    char cmd[2048];
    case 100:
	printf("\nUpdating from %d\n", VAWSM);
	snprintf(cmd, 192,
		"yay -S --noconfirm btop cava fuzzel kitty fastfetch waybar ; "
		"cp -f kitty/kitty.conf ~/.config/kitty ; "
		"cp -f kitty/current-theme.conf ~/.config/current-theme.conf ");
	system(cmd);
	snprintf(cmd, 192,
		"cp hypr/hypridle.conf ~/.config/hypr ; "
		"cp hypr/hyprpaper.conf ~/.config/hypr ");
	system(cmd);
	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 120:
	snprintf(cmd, 256,
		"cp -f fuzzel/fuzzel.ini ~/.config/fuzzel/ ; "
		"cp -f fuzzel/old-fuzzel.ini ~/.config/fuzzel/ ; "
		"cp waybar/style.css ~/.config/waybar ; "
		"cp waybar/config.jsonc ~/.config/waybar");
	system(cmd);
	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 130:
	if (ARCHIVE == 'Y' || ARCHIVE == 'y')
	{
	    snprintf(cmd, 64,
		    "mv -f ~/.config/cava/config ~/.config/cava/config-oldv%.2f", pver);
	    system(cmd);
	}
	// export cava + kitty
	snprintf(cmd, 512,
		"yay -S --noconfirm ttf-ubuntu-font-family ttf-ibmplex-mono-nerd ; "
		"ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd ; "
		"cp -f kitty/current-theme.conf ~/.config/kitty/ ; "
		"mkdir -p ~/.config/cava/ ; "
		"rm ~/.config/cava/config ; "
		"cp -f cava/config ~/.config/cava/ ");
	system(cmd);
	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 140:
	snprintf(cmd, 192,
		"mv ~/.config/btop/btop.conf ~/.config/btop/btop-oldv%.2f ; "
		"mkdir -p ~/.config/btop/ ; "
		"cp -f btop/btop.conf ~/.config/btop/ ", pver);
	system(cmd);
	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 200:
	snprintf(cmd, 192,
		"mkdir ~/.config/gtklock ; "
		"yay -S --noconfirm gtklock ; "
		"mv ~/.config/gtklock/style.css ~/.config/gtklock/style-v%.2f.css ; "	// gtklock exporting
		"cp -f %s/gtklock/style.css ~/.config/gtklock/style.css ", pver, inpath);
	system(cmd);
	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 210:
	snprintf(cmd, 512,
		"mkdir -p ~/.config/sway ; "
		"mkdir -p ~/.config/nvim ; "
		"yay -S --noconfirm sway ; "
		"mv ~/.config/nvim/init.lua ~/.config/nvim/init-oldv%.2f.lua ; "
		"cp -f nvim/init.lua ~/.config/nvim ; "
		"mv ~/.config/gtklock/style.css ~/.config/gtklock/style-v%.2f.css ; "
		"cp -f gtklock/style.css ~/.config/gtklock/style.css ; "
		"mv ~/.config/kitty/kitty.conf ~/.config/kitty/kitty-oldv%.2f.conf ; "
		"cp -f kitty/kitty.conf ~/.config/kitty/ ; "	// update kitty config
		, pver, pver, pver);
	system(cmd);
	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 220:
	snprintf(cmd, 512,
		"mv ~/.config/sway/config ~/.config/sway/config-oldv%.2f ; "
		"cp -f %s/sway/config ~/.config/sway/ ; "	// update sway config
		"cp -f %s/sway/config-default ~/.config/sway/ ; "
		"mkdir -p ~/.config/mpv/ ; "
		"mv ~/.config/mpv/mpv.conf ~/.config/mpv/mpv-oldv%.2f.conf ; "
		"cp -f %s/mpv/mpv.conf ~/.config/mpv/ ", pver, inpath, inpath, pver, inpath);
	system(cmd);
	__attribute__ ((fallthrough));
    case 230:
	snprintf(cmd, 1024,
		"yay -S --noconfirm nvim ; "
		"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-v%.2f.conf ; "
		"cp -f %s/hypr/hyprland.conf ~/.config/hypr/ ; "
		"cp -f %s/fuzzel/default-fuzzel.ini ~/.config/fuzzel/ ; "
		"cp -f %s/fuzzel/fuzzel.ini ~/.config/fuzzel/ ; "
		"cp -f %s/fuzzel/old-fuzzel.ini ~/.config/fuzzel/ ; "
		"mv ~/.config/fastfetch/config.jsonc ~/.config/fastfetch/config-v%.2f.jsonc ; "
		"mv ~/.zshrc ~/.zshrc-oldv%.2f ; "
		"cp -f %s/shell/zsh/.zshrc ~/ ; "
		"mv ~/.config/nvim/init.lua ~/.config/nvim/init-v%.2f.lua ; "	// nvim exporting
		"cp -f %s/nvim/init.lua ~/.config/nvim/init.lua ; "
		"cp -f %s/shell/bash/.bashrc ~/.bashrc-new ; "
		"cp -f %s/fastfetch/config.jsonc ~/.config/fastfetch/ "
		, pver, inpath, inpath, inpath, inpath, pver, pver, inpath, pver, inpath, inpath, inpath);
	system(cmd);
	goto end;
    case 240:
	printf("\nYou are running the latest version.\n");
	wait_for_timeout(2, 0);
	goto exit;

    default:
	printf("\nUnknown version\n");
	wait_for_timeout(2, 0);
	return 1;
    end:
	printf("Update completed!\n");
	goto exit;
    exit:
    ;
    }
    return 0;
}
