#include "dotfileshead.h"

void BASH()
{
    char BRCNAME[12] = ".bashrc-new";
    // prompt to let the user know the bashrc isn't exported/replaced
    printf(UDRL_S"\nThe .bashrc file plays a very important role therefore, it was not replaced."STYLE_END);
    printf(UDRL_S"\nYou can find the new .bashrc file under the name %s\n"STYLE_END, BRCNAME);

    // export .bashrc
    //
    int mem_needed = snprintf(NULL, 0,
	    "cp -f %s/shell/bash/.bashrc ~/%s", 
	    inpath, BRCNAME);

char *cmd = malloc(mem_needed + 1);

    snprintf(cmd, mem_needed + 1,
             "cp -f %s/shell/bash/.bashrc ~/%s",
             inpath, BRCNAME);
    system(cmd);

    free(cmd);
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
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install btop package
        snprintf(cmd, 32,
		"yay -S --noconfirm btop");
	system(cmd);
    }
    // export btop config
    snprintf(cmd, sizeof(cmd),
	   "mkdir -p ~/.config/btop ; "
	   "cp -f %s/btop/btop.conf ~/.config/btop", inpath);
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
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install fuzzel package
        snprintf(cmd, 32,
		"yay -S --noconfirm cava");
	system(cmd);
    }
    // export cava config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/cava ; "
	    "cp -f %s/cava/config ~/.config/cava/ ", inpath);
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
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install fuzzel package
        snprintf(cmd, 32,
		"yay -S --noconfirm fastfetch");
	system(cmd);
    }
    // export fastfetch config
    snprintf(cmd, sizeof(cmd) + 128,
	    "rm ~/.config/fastfetch ; "
	    "mkdir -p ~/.config/fastfetch/assets ; "
	    "cp -f %s/fastfetch/assets/*.png ~/.config/fastfetch/assets ; "
	    "cp -f %s/fastfetch/config.jsonc ~/.config/fastfetch ; "
	    "cp -f ~/.config/fastfetch/config.jsonc ~/.config/fastfetch/config-duplicated.jsonc ; "
	    "cp -f %s/fastfetch/config-other.jsonc ~/.config/fastfetch ; "
	    "cp -f %s/fastfetch/config-default.jsonc ~/.config/fastfetch", inpath, inpath, inpath, inpath);
    system(cmd);
}
void FUZZ(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[512];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// backup fuzzel config
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/fuzzel/fuzzel-duplicated.ini "
		"~/.config/fuzzel/fuzzel-duplicated-oldv%.2f.ini ; "
		"mv ~/.config/fuzzel/old-fuzzel.ini "
		"~/.config/fuzzel/old-fuzzel-oldv%.2f.ini ; "
		"mv ~/.config/fuzzel/fuzzel.ini "
    		"~/.config/fuzzel/fuzzel-oldv%.2f.ini", pver, pver, pver);
    	system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install fuzzel package
        snprintf(cmd, 32,
		"yay -S --noconfirm fuzzel");
	system(cmd);
    }
    // export fuzzel appearance

    snprintf(cmd, sizeof(cmd),
            "mkdir -p ~/.config/fuzzel ; "
            "cp -f %s/fuzzel/old-fuzzel.ini ~/.config/fuzzel", inpath);
    system(cmd);  		
    
    snprintf(cmd, sizeof(cmd),
            "cp -f %s/fuzzel/default-fuzzel.ini ~/.config/fuzzel ; "
	    "cp -f ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/custom-edited-fuzzel.ini ; "
            "cp -f %s/fuzzel/fuzzel.ini ~/.config/fuzzel ; "
	    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-duplicated.ini ; "
	    "ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini ", inpath, inpath);
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
    		"~/.config/gtklock/style-oldv%.2f.css", 
    		pver);
    	system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install gtklock package
        snprintf(cmd, 32,
		"yay -S --noconfirm gtklock");
	system(cmd);
    }
    // export gtklock config
    snprintf(cmd, 384,
            "mkdir -p ~/.config/gtklock/assets ; "
            "cp -f %s/gtklock/style.css ~/.config/gtklock ; "
            "cp -f %s/gtklock/lockscreen.jpg ~/.config/gtklock/assets", inpath, inpath);
    system(cmd);
}

void HYPR(char ARCHIVE, float pver, char PKGINSTALL)
{
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive hyprland configs
	char cmd[256];
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-oldv%.2f.conf ; "
        	"mv ~/.config/hypr/hyprpaper.conf ~/.config/hypr/hyprpaper-oldv%.2f.conf ; "
        	"mv ~/.config/hypr/hypridle.conf ~/.config/hypr/hypridle-oldv%.2f.conf", pver, pver, pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install Hyprland packages
	char cmd[256];
        snprintf(cmd, 48,
		"yay -S --noconfirm hypridle hyprpaper hyprland");
	system(cmd);
    }
    // export hyprland configs
    int mem_needed = snprintf(NULL, 0,
	    "mkdir -p ~/.config/hypr ; "
	    "cp -f %s/hypr/hyprland.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hypridle.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hyprpaper.conf ~/.config/hypr", inpath, inpath, inpath);

    char *cmd = malloc(mem_needed + 1);

    snprintf(cmd, mem_needed + 1,
	    "mkdir -p ~/.config/hypr ; "
	    "cp -f %s/hypr/hyprland.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hypridle.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hyprpaper.conf ~/.config/hypr", inpath, inpath, inpath);
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
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install kitty package
	//  the kitty terminal is most likely already installed on your system
        snprintf(cmd, 32,
		"yay -S --noconfirm kitty");
	system(cmd);
    }
    // export kitty config
    snprintf(cmd, sizeof(cmd),
	    "mkdir ~/.config/kitty ; "
	    "cp -f %s/kitty/current-theme.conf ~/.config/kitty ; "
	    "cp -f %s/kitty/kitty.conf ~/.config/kitty", inpath, inpath);
    system(cmd);
}

void MPVF(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive mpv config
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/mpv/mpv.conf ~/.config/mpv/mpv-oldv%.2f.conf ", pver);
	system(cmd);
	printf(BOLD_S"\nThe old "UDRL_S"mpv"STYLE_END BOLD_S" config was archived\n"STYLE_END);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
        snprintf(cmd, 32,
		"yay -S --noconfirm mpv");
	system(cmd);

	printf(BOLD_S"\nMPV was installed!\n"STYLE_END);
    }
    // export mpv config with shaders
    snprintf(cmd, 128,
	    "mkdir -p ~/.config/mpv/ ; "
            "cp -f %s/mpv/mpv.conf ~/.config/mpv ", inpath);
    system(cmd);
}

void NVIM(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        snprintf(cmd, sizeof(cmd),
    	    	"mv ~/.config/nvim/init.lua ~/.config/nvim/init-oldv%.2f.lua ; "
    	    	"mv ~/.config/nvim/lua/config/lazy.lua ~/.config/nvim/lua/config/lazy-oldv%.2f.lua ; "
    	    	"mv ~/.config/nvim/lazy-lock.json ~/.config/nvim/lazy-lock-oldv%.2f.json",
    	    	pver, pver, pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install neovim (nvim) package
	// nvim is most likely already installed 
        snprintf(cmd, 32,
		"yay -S --noconfirm nvim lazygit");
	system(cmd);
    }

    // export nvim config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/nvim ; "
    	    "cp -f %s/nvim/init.lua ~/.config/nvim", inpath);
    system(cmd);
}

void SWAY(char ARCHIVE, float pver, char PKGINSTALL)
{
    // sway window manager doesn't work without wlroots
    char cmd[128];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        snprintf(cmd, sizeof(cmd),
    	    	"mv ~/.config/sway/config ~/.config/sway/config-oldv%.2f ",
		pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install sway package
        snprintf(cmd, 48,
		"yay -S --noconfirm wlroots swaylock sway");
	system(cmd);
	// a system update is strongly recommended 
    }
    // export sway config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/sway ; "
    	    "cp -f %s/sway/config ~/.config/sway", inpath);
    system(cmd);
}

void WAYB(char ARCHIVE, float pver, char PKGINSTALL)
{
    
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive waybar
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/waybar/config.jsonc ~/.config/waybar/config-oldv%.2f.jsonc ; "
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
	    "mkdir -p ~/.config/waybar ; "
	    "cp -f %s/waybar/style.css ~/.config/waybar ; "
            "cp -f %s/waybar/config.jsonc ~/.config/waybar", inpath, inpath);
    system(cmd);
}

void ZSHH(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[128];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive old zsh config
        snprintf(cmd, sizeof(cmd),
		"mv ~/.zshrc ~/.zshrc-old-v%.2f", pver);
	system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
        snprintf(cmd, 24,
		"yay -S --noconfirm zsh");
	system(cmd);
    }
    // export waybar config and appearance
    snprintf(cmd, 96,
	    "cp -f %s/shell/zsh/.zshrc ~/ ", inpath);
    system(cmd);

    printf("Refer to the dotfiles configuration menu in order to configure zsh proprely (using zsh for humans)\n");
}
