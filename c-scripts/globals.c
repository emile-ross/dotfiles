#include "dotfileshead.h"


// Text available globally

char *config_names[num_packages] = 
{
    "Unknown Package",
    ".bashrc",
    "Sway-WM config",
    "bpytop config",
    "btop config",
    "cava config",
    "fastfetch configs",
    "fuzzel configs",
    "gtklock config and style (appearance) ",
    "Hyprland-WM config + Hypridle config",
    "kitty terminal configs",
    "mpv config",
    "neovim config with lazy",
    "waybar config and style (appearance)",
    "zsh config (.zshrc)",
};

    char* TEXT_C_BASH = ".bashrc";
    char* TEXT_C_SWAY = "Sway-WM config";
    char* TEXT_C_BPYT = "bpytop config";
    char* TEXT_C_BTOP = "btop config";
    char* TEXT_C_CAVA = "cava config";
    char* TEXT_C_FAST = "fastfetch configs";
    char* TEXT_C_FUZZ = "fuzzel configs";
    char* TEXT_C_GTKL = "gtklock config and style (appearance) ";
    char* TEXT_C_HYPR = "Hyprland-WM config + Hypridle config";
    char* TEXT_C_KITT = "kitty terminal configs";
    char* TEXT_C_MPVF = "mpv config";
    char* TEXT_C_NVIM = "neovim config with lazy";
    char* TEXT_C_WAYB = "waybar config and style (appearance)";
    char* TEXT_C_ZSHH = "zsh config (.zshrc)";
    
    char* help_flag_arg_text = "--help";	// flag for the help menu
    char* pkgi_flag_arg_text = "-p";	// flag to install a package
    char* conf_inst_flag_arg_text = "-c";	// flag to install a config
    char* conf_info_flag_arg_text = "-i";	// flag to install a package
    
    char fuzzel_view_config_text[32] = "Preview Fuzzel appearance";
    char fuzzel_edit_config_text[32] = "Edit Fuzzel config";
    char fuzzel_catppuccin_text[32] = "Configure Catppuccin themes";
    char fastfetch_config_menu_text[32] = "Customize fastfetch";
    char kitty_config_menu_text[32] = "Customize kitty";
    char fuzzel_config_menu_text[32] = "Customize fuzzel";
    char zshforhumans_config_menu_text[32] = "Set up zsh";
    
    char kitty_color_text[32] = "Change Kitty color scheme";
    char kitty_fonts_text[32] = "Change Kitty fonts";
    
    char main_menu_title[128] = "Welcome to the setup utility for ImAwsumm's dotfiles";
    char opt_one_text[128] = "Install the dotfiles";
    char opt_the_text[128] = "Update your dotfiles";
    char opt_for_text[128] = "Custom configuration menu";
    char opt_fiv_text[128] = "Something else";
    char opt_exit_text[16] = "Exit";
    char opt_back_text[16] = "Back";

char *main_menu_text[NUM_ELEMENTS_MAIN_MENU] = 
{
    "Install the dotfiles",
    "Update your dotfiles",
    "Custom configuration menu",
    "Something else",
};


    char *description_arr[n_configs] =
    {
	"Unknown config",
	"Bash, (Bourne Again SHell) is the default shell on most Linux distributions.",
	"bpytop is a system resource monitor.",
	"Btop is a system resource monitor.",
	"Cava is a Cross-platform Audio Visualizer.",
	"Fastfetch is a fast system information tool made in C.",
	"Fuzzel is an App launcher and fuzzy finder based on rofi & dmenu.",
	"Gtklock is a GTK lockscreen for Wayland.",
	"Hyprland is a dynamic tiling window manager made for Wayland.",
	"Kitty is a fast, GPU based terminal emulator.",
	"MPV is a cross-platform media player made for the command line.",
	"Neovim is a modern Vi-based text editor.",
	"Sway is a tiling window manager based on i3 (Written in C).",
	"Waybar is an highly customizable",
	"Zsh (Z shell) is a command line interpreter focused on speed and efficiency.",
    };
    
// Global variables

    const int max_menu_opt_n = 14;

    // the position of the first argument in a command
    // example: ``./setup -i nvim``
    // nvim is the 3rd argument
    const int n_to_arg = 3;

    struct timespec install_timer;
    int timer_quarters;
    int timer_seconds;
    long int time_timer_quarters;
    long int time_timer_seconds;
    
    char ARCHIVE;
    char PKGINSTALL;
    int menu_one_i;
    char full_install_opt; // if the user wants to install everything set to Y
    char archive_before_install;
    char full_update_opt; 
    int fuzzel_config_menu_choice;
    char* theme_colour_text;
    float pver;
    
    int fastfetch_conf_export;
    bool fastfetch_config_apply;
    
    // Distribution global variable
    // it is used when installing packages with the right package manager
    char distro[128] = "";
    char parent[128] = "";
    
    char initial_path[64];
    char inpath[64];
