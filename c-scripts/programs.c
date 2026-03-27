#include "dotfileshead.h"

void BASH(void)
{
    char BRCNAME[12] = ".bashrc-new";
    // prompt to let the user know the bashrc isn't exported/replaced
    printf(UDRL_S"\nThe .bashrc file plays a very important role therefore, it was not replaced."STYLE_END);
    printf(UDRL_S"\nYou can find the new .bashrc file under the name %s\n"STYLE_END, BRCNAME);

    // export .bashrc
    
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

void BPYT(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[192];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
    	// archive bpytop config
    	snprintf(cmd, sizeof(cmd),
    		"mv ~/.config/bpytop/bpytop.conf "
    		"~/.config/bpytop/bpytop-oldv%.2f.conf", pver);
    	system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	install_package(parent, "bpytop"); // install bpytop package
    }
    // export bpytop config
    snprintf(cmd, sizeof(cmd),
	   "mkdir -p ~/.config/bpytop ; "
	   "cp -f %s/bpytop/bpytop.conf ~/.config/bpytop", inpath);
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
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	install_package(parent, "btop"); // install btop package
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
		"~/.config/cava/config-oldv%.2f", pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	install_package(parent, "cava"); // install cava package
    }
    // export cava config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/cava ; "
	    "cp -f %s/cava/config ~/.config/cava/ ", inpath);
    system(cmd);
}

void FAST(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[768];
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
	install_package(parent, "fastfetch"); // install fastfetch
    }
    // export fastfetch config
    snprintf(cmd, sizeof(cmd),
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
    char cmd[1024];
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
	install_package(parent, "fuzzel");
    }
    // export fuzzel appearance
    snprintf(cmd, 768,
            "mkdir -p ~/.config/fuzzel ; "
            "cp -f %s/fuzzel/old-fuzzel.ini ~/.config/fuzzel ; "
            "cp -f %s/fuzzel/default-fuzzel.ini ~/.config/fuzzel ; "
	    "cp -f ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/custom-edited-fuzzel.ini ; "
            "cp -f %s/fuzzel/fuzzel.ini ~/.config/fuzzel ; "
	    "mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-duplicated.ini ; "
	    "ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini ", inpath, inpath, inpath);
    system(cmd);  		
}
void GTKL(char ARCHIVE, float pver, char PKGINSTALL)
{
    char cmd[512];
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
	install_package(parent, "gtklock");
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
	char cmd[1536];
        snprintf(cmd, sizeof(cmd),
		"mv ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland-oldv%.2f.conf ; "
        	"mv ~/.config/hypr/hyprpaper.conf ~/.config/hypr/hyprpaper-oldv%.2f.conf ; "
        	"mv ~/.config/hypr/hyprlock.conf ~/.config/hypr/hyprlock-oldv%.2f.conf ; "
        	"mv ~/.config/hypr/hypridle.conf ~/.config/hypr/hypridle-oldv%.2f.conf", pver, pver, pver, pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install Hyprland packages
	install_package(parent, "hyprlock hypridle hyprpaper hyprland");
    }
    // export hyprland configs
    int mem_needed = snprintf(NULL, 0,
	    "mkdir -p ~/.config/hypr/assets ; "
    	    "cp -f %s/hypr/assets/lockscreen.png ~/.config/hypr/assets/ ; "
	    "cp -f %s/hypr/hyprland.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hypridle.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hyprlock.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hyprpaper.conf ~/.config/hypr",
	    inpath, inpath, inpath, inpath, inpath);

    char *cmd = malloc(mem_needed + 1); // allocate just enough memory for the buffer size

    snprintf(cmd, mem_needed + 1,
	    "mkdir -p ~/.config/hypr/assets ; "
    	    "cp -f %s/hypr/assets/lockscreen.png ~/.config/hypr/assets/ ; "
	    "cp -f %s/hypr/hyprland.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hypridle.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hyprlock.conf ~/.config/hypr ; "
    	    "cp -f %s/hypr/hyprpaper.conf ~/.config/hypr",
	    inpath, inpath, inpath, inpath, inpath);
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
    		"~/.config/kitty/kitty-oldv%.2f.conf", pver);
    	system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install kitty package
	//  the kitty terminal is most likely already installed on your system
	install_package(parent, "mpv");
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
	install_package(parent, "mpv");
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
	install_package(parent, "nvim lazygit");
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
    char cmd[256];
    if (ARCHIVE == 'Y' || ARCHIVE == 'y')
    {
        snprintf(cmd, 64,
    	    	"mv ~/.config/sway/config ~/.config/sway/config-oldv%.2f ", pver);
        system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	// install sway package -- a system update is strongly recommended 
	install_package(parent, "wlroots swaylock sway");
    }
    // export sway config
    snprintf(cmd, sizeof(cmd),
	    "mkdir -p ~/.config/sway ; "
	    "cp -f %s/sway/config ~/.config/sway/ ; "
    	    "cp -f %s/sway/config-default ~/.config/sway", inpath, inpath);
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
		"mv ~/.config/waybar/style.css ~/.config/waybar/style-oldv%.2f.css", pver, pver);
	system(cmd);
    }
    if ( PKGINSTALL == 'Y'|| PKGINSTALL == 'y')
    {
	install_package(parent, "waybar");
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
	install_package(parent, "zsh");
    }
    snprintf(cmd, 128, 
	    "cp -f %s/shell/zsh/.zshrc ~/ ", inpath);
    system(cmd);

    printf("Refer to the dotfiles configuration menu in order to configure zsh proprely (using zsh for humans)\n");
}

int install_package(char *pkg_type_distro, char *pkginstallname)
{
    char cmd[512];
    if (strcmp(pkg_type_distro, "arch") == 0)
    {
        snprintf(cmd, sizeof(cmd),
                "yay -S %s", pkginstallname);
        system(cmd);
    }
    else if (strcmp(pkg_type_distro, "debian") == 0)
    {
        snprintf(cmd, sizeof(cmd),
                "sudo apt install %s", pkginstallname);
        system(cmd);
    }
    else 
    {
    	printf("Your distribution is not supported.\n");
    	wait_for_timeout(0, 1);
    }

    return 0;
}

void configure_oh_my_zsh(void)
{
    // using curl to download a program is not a good practice 
    // but it's the recommended installation method
    system("if command -v curl >/dev/null 2>&1; then "
            "  sh -c \"$(curl -fsSL https://raw.githubusercontent.com/romkatv/zsh4humans/v5/install)\"; "
            "else "
            "  sh -c \"$(wget -O- https://raw.githubusercontent.com/romkatv/zsh4humans/v5/install)\"; " 
            "fi");
    clearbuffer();
    getchar(); // intended blocking behaviour
}
