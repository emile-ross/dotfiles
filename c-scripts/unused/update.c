#include "dotfileshead.h"

int full_update(char ARCHIVE, float pver)
{
    int VAWSM = (int)(pver * 100);
    switch (VAWSM)
    {
    char cmd[2048];
    case 100:
	printf("\nUpdating from %d\n", VAWSM);

	install_package(parent, "cava fuzzel kitty fastfetch waybar");

	snprintf(cmd, 1024,
		"cp -f %s/kitty/kitty.conf ~/.config/kitty ; "
		"cp -f %s/kitty/current-theme.conf ~/.config/current-theme.conf ; "
		"cp -f %s/hypr/hypridle.conf ~/.config/hypr ; "
		"cp -f %s/hypr/hyprpaper.conf ~/.config/hypr ", inpath, inpath, inpath, inpath);
	system(cmd);
	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 120:
	snprintf(cmd, 512,
		"cp -f %s/fuzzel/fuzzel.ini ~/.config/fuzzel/ ; "
		"cp -f %s/fuzzel/old-fuzzel.ini ~/.config/fuzzel/ ; "
		"cp -f %s/waybar/style.css ~/.config/waybar ; "
		"cp -f %s/waybar/config.jsonc ~/.config/waybar", inpath, inpath, inpath, inpath);
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
	install_package(parent, "ttf-ubuntu-font-family btop ttf-ibmplex-mono-nerd");
	snprintf(cmd, 320,
		"ttf-blex-nerd-font-git ttf-victor-mono-nerd ttf-cascadia-mono-nerd ; "
		"cp -f kitty/current-theme.conf ~/.config/kitty/ ; "
		"mkdir -p ~/.config/cava/ ; "
		"rm ~/.config/cava/config ; "
		"cp -f %s/cava/config ~/.config/cava/ ", inpath);
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
	install_package(parent, "gtklock");
	snprintf(cmd, 24,
		"mkdir ~/.config/gtklock");
	system(cmd);

	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 210:
	install_package(parent, "sway");
	snprintf(cmd, sizeof(cmd),
		"mkdir -p ~/.config/sway ; "
		"mkdir -p ~/.config/nvim ; "
		"mv ~/.config/gtklock/style.css ~/.config/gtklock/style-v%.2f.css ; "
		"cp -f %s/gtklock/style.css ~/.config/gtklock/style.css ; "
		"cp -f %s/kitty/kitty.conf ~/.config/kitty/ ; "	// update kitty config
		"mv ~/.config/kitty/kitty.conf ~/.config/kitty/kitty-oldv%.2f.conf ; "
		, pver, inpath, inpath, pver);
	system(cmd);
	__attribute__ ((fallthrough));
	// do not break because we are also installing everything below
    case 220:
	snprintf(cmd, 512,
		"mkdir -p ~/.config/mpv/ ; "
		"mv ~/.config/sway/config ~/.config/sway/config-oldv%.2f ; "
		"cp -f %s/sway/config ~/.config/sway/ ; "	// update sway config
		"cp -f %s/sway/config-default ~/.config/sway/ ; "
		"mv ~/.config/mpv/mpv.conf ~/.config/mpv/mpv-oldv%.2f.conf ; "
		"cp -f %s/mpv/mpv.conf ~/.config/mpv/ ", pver, inpath, inpath, pver, inpath);
	system(cmd);
	__attribute__ ((fallthrough));
    case 230:
	install_package(parent, "nvim");
	snprintf(cmd, sizeof(cmd),
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
	install_package(parent, "bpytop");
	snprintf(cmd, sizeof(cmd),
		"cp -f %s/bpytop/bpytop.conf ~/.config/bpytop/ ", inpath);
	system(cmd);

	goto end;
    case 250:
    case 300:
	printf("\nYou are running the latest version.\n");
	wait_for_timeout(2, 0);
	break;

    default:
	error_message(207);
	return 1;
    end:
	printf("Update completed!\n");
	goto exit;
    exit:
    ;
    }
    return 0;
}

float* update() 
{
    char *USERNAME = getenv("HOME");

    // error message if username can't be fetched 
    if (USERNAME == NULL) 
    {
	error_message(204);
        return NULL;
    }

    // create path to config
    char HYPRPATH[64];
    snprintf(HYPRPATH, sizeof(HYPRPATH), 
	    "%s/.config/hypr/hyprland.conf", USERNAME);
	    // set the hyprland path with username

    // open the file with HYPRPATH
    FILE *file = fopen(HYPRPATH, "r");
    
    // return error message when file isn't found
    if (file == NULL) 
    {
	error_message(205);
	// returns null if the file can't be opened/found
        return NULL;
    }
    static float VAWSM[32] = {0};

    char line[384];
    while (fgets(line, sizeof(line), file)) 
    {
        if (sscanf(line, "# AWSMVERSION: %31f[0-9.]", VAWSM) == 1) 
	{
            fclose(file);
            return VAWSM;
        }
    }
    fclose(file);
    return 0;
}
