#include <stdio.h>
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
