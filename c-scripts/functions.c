#include "dotfileshead.h"

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

int timer_quarters;
int timer_seconds;

char* theme_colour_text;
long int time_timer_quarters;
long int time_timer_seconds;

char ARCHIVE;
char PKGINSTALL;
int menu_one_i;
char full_install_opt; // if the user wants to install everything set to Y
char full_update_opt; 
int fuzzel_config_menu_choice;


struct timespec install_timer;
int fastfetch_conf_export;

char fuzzel_view_config_text[32] = "Preview Fuzzel appearance";
char fuzzel_edit_config_text[32] = "Edit Fuzzel config";
char fuzzel_catppuccin_text[32] = "Configure Catppuccin themes";


int error_message(int err_code)
{
    printf(ANSI_RED UDRL_S BOLD_S"Error\n"STYLE_END);
    printf(ANSI_RED BOLD_S"Error code: %d \n"STYLE_END, err_code);

    char err_text_temp[128];
    char err_solution_temp[128];
    
    switch (err_code)
    {
	case 2:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Exiting.. (invalid character)");
	    break;

	case 5:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Yay is needed for the installation");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Give the script permission to install Yay");
	    break;

	case 51:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Makepkg installation failed. Please check your system configuration.");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Helpful link: \"https://wiki.archlinux.org/title/Makepkg\"");
	    break;

	case 103:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Could not apply fuzzel theme");
	    break;

	case 204:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Can't find home directory");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Try running \"ls /home/\"\nif that doesn't do it \"useradd -m -d /home/[YOUR_USERNAME]/ -s /bin/bash -G sudo [YOUR_USERNAME]\"");
	    break;

	case 205:
	    snprintf(err_text_temp, sizeof(err_text_temp), "No such file or directory"); // for hyprland.conf (when looking for version # )
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Make sure you have installed the dotfiles");
	    break;

	case 909:
	    printf("This error should never display (in theory) \n");
	    break;
    }
    printf(ANSI_RED BOLD_S"%s \n"STYLE_END, err_text_temp);
    printf(ANSI_RED BOLD_S"%s \n"STYLE_END, err_solution_temp);
    printf("Press "UDRL_S"CTRL + C"STYLE_END BOLD_S" to exit\n"STYLE_END);
    printf("Press any key to continue\n");

    while (getchar() != '\n');  // clear imput buffer 
    getchar(); 
    return 0;
}

void wait_for_timeout(int timer_quarters, int timer_seconds)
{
    if (timer_quarters < 4)
    {
	time_timer_quarters = timer_quarters * 250000000;
	time_timer_seconds = timer_seconds;
    }
    else
    {
	time_timer_quarters = 0;
	time_timer_seconds = timer_seconds + 1;
    }

    install_timer.tv_nsec = time_timer_quarters;
    install_timer.tv_sec = time_timer_seconds;
    nanosleep(&install_timer, NULL);
}
