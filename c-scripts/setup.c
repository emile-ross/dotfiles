#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOLD_S  "\e[1m" // defines BOLD_S as a keyword to make text bold
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_CYAN    "\x1b[36m"
#define STYLE_END   "\e[m" // resets the styling

float pver = 0.0f;

void clear();

char BTOP(char ARCHIVE);
char CAVA(char ARCHIVE);
char FAST(char ARCHIVE);
char FUZZ(char ARCHIVE);
char GTKL(char ARCHIVE);
char HYPR(char ARCHIVE);
char KITT(char ARCHIVE);
char NVIM(char ARCHIVE);
char WAYB(char ARCHIVE);

int main()
{
	clear();
	printf(BOLD_S ANSI_CYAN "\n Welcome to the setup utility for ImAwsumm's dotfiles \n" STYLE_END);
	printf(BOLD_S "\n [1] " STYLE_END "Install the dotfiles\n");

	printf(BOLD_S " [2] " STYLE_END "Fix the dotfiles\n");
	printf(BOLD_S " [3] " STYLE_END "Update your dotfiles\n");
	printf(BOLD_S " [4] " STYLE_END "Something else\n");
	printf(BOLD_S " [5] " STYLE_END "Exit\n");
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
			"mkdir -p ~/.config/nvim && cd ~/.config/nvim && "
			"cp -f dotfiles/nvim/init.lua ~/.config/nvim");
			//" cp -rf lua ~/.config/nvim && "
			//"cp -f lazy-lock.json ~/.config/nvim");
        system(cmd);
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
			"mkdir -p ~/.config/waybar && "
               		"cp -f dotfiles/waybar/style.css ~/.config/waybar && "
               		"cp -f dotfiles/waybar/config.jsonc ~/.config/waybar && ");
	system(cmd);
}



void clear()
{
	printf("\033[2J\033[H");
}
