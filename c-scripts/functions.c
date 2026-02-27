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
char* TEXT_C_ZSHH = "zsh config (.zshrc)";

char fuzzel_view_config_text[32] = "Preview Fuzzel appearance";
char fuzzel_edit_config_text[32] = "Edit Fuzzel config";
char fuzzel_catppuccin_text[32] = "Configure Catppuccin themes";

char fastfetch_config_menu_text[32] = "Customize fastfetch";
char kitty_config_menu_text[32] = "Customize kitty";
char fuzzel_config_menu_text[32] = "Customize fuzzel";
char zshforhumans_config_menu_text[32] = "Set up zsh";

char main_menu_text[128] = "Welcome to the setup utility for ImAwsumm's dotfiles";
char opt_one_text[128] = "Install the dotfiles";
char opt_the_text[128] = "Update your dotfiles";
char opt_for_text[128] = "Custom configuration menu";
char opt_fiv_text[128] = "Something else";
char opt_exit_text[16] = "Exit";

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
float pver;

struct timespec install_timer;
int fastfetch_conf_export;

char initial_path[64];
char inpath[64];
char *get_initial_path()
{
    char cd_init[16];
    snprintf(cd_init, sizeof(cd_init), // this should fail. User is supposed to be at dotfiles/
	    "cd dotfiles/");
    system(cd_init);

    FILE *fp;
    
    fp = popen("pwd", "r");
    
    if (fp == NULL) 
    {
	error_message(206);
        return NULL;
    }
 
    if (fgets(initial_path, sizeof(initial_path), fp) == NULL)
    {
        pclose(fp);
        return NULL;
    }

    initial_path[strcspn(initial_path, "\n")] = '\0';

    pclose(fp);
    return initial_path;
}

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

	case 104:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Could not find kitty package");
	    break;

	case 204:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Can't find home directory");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Try running \"ls /home/\"\nif that doesn't do it \"useradd -m -d /home/[YOUR_USERNAME]/ -s /bin/bash -G sudo [YOUR_USERNAME]\"");
	    break;

	case 205:
	    snprintf(err_text_temp, sizeof(err_text_temp), "No such file or directory"); // for hyprland.conf (when looking for version # )
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Make sure you have installed the dotfiles");
	    break;

	case 206:
	    snprintf(err_text_temp, sizeof(err_text_temp), "popen failed");
	    //snprintf(err_solution_temp, sizeof(err_solution_temp), "NULL");
	    break;

	case 909:
	    printf("This error should never display (in theory) \n");
	    break;
		
	default:
		snprintf(err_text_temp, sizeof(err_text_temp), "This error code isn't known");
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

void pre_startup()
{
    snprintf(inpath, sizeof(inpath), "%s", get_initial_path());
}
