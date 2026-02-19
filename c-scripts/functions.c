#include <stdio.h>
#include "dotfileshead.h"
#include <stdlib.h>
#include <time.h>

const int max_menu_opt_n = 12;

void clear()
{
    printf("\033[2J\033[H");
}

char* TEXT_C_BASH = ".bashrc";
char* TEXT_C_SWAY = "Sway-WM configs";
char* TEXT_C_BTOP = "btop config";
char* TEXT_C_CAVA = "cava config";
char* TEXT_C_FAST = "fastfetch configs";
char* TEXT_C_FUZZ = "fuzzel configs";
char* TEXT_C_GTKL = "gtklock config and style (appearance) ";
char* TEXT_C_HYPR = "Hyprland-WM config + Hypridle config";
char* TEXT_C_KITT = "kitty terminal";
char* TEXT_C_MPVF = "mpv config";
char* TEXT_C_NVIM = "neovim config with lazy";
char* TEXT_C_WAYB = "waybar config and style (appearance)";

char ARCHIVE;
char PKGINSTALL;
int menu_one_i;

char full_install_opt; // if the user wants to install everything set to Y
char full_update_opt; 

struct timespec install_timer;
int fastfetch_conf_export;

char fuzzel_view_config_text[32] = "Preview Fuzzel appearance";
char fuzzel_edit_config_text[32] = "Edit Fuzzel config";
char fuzzel_catppuccin_text[32] = "Configure Catppuccin themes";


int error_message(int err_code)
{
    printf(ANSI_RED BOLD_S"This is a bug\n"STYLE_END);
    printf(ANSI_RED BOLD_S"Error code: %d \n"STYLE_END, err_code);

    char err_text_temp[128];
    char err_solution_temp[128];
    
    switch (err_code)
    {
	case 51:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Makepkg installation failed. Please check your system configuration.");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Helpful link: \"https://wiki.archlinux.org/title/Makepkg\"");
	    break;
	case 103:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Could not apply fuzzel theme");
	    break;
	case 104:
	    printf("This error should never display (in theory) \n");
	    break;
    }
    printf(ANSI_RED BOLD_S"%s \n"STYLE_END, err_text_temp);
    printf(ANSI_RED BOLD_S"%s \n"STYLE_END, err_solution_temp);
    return 0;
}
