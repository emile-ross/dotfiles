#include "dotfileshead.h"

const int max_menu_opt_n = 12;

void clear()
{
    // clears the screen
    printf("\033[2J\033[H");
}

void clearbuffer()
{
    // clears the imput buffer 
    while (getchar() != '\n');
}

char* TEXT_C_BASH = ".bashrc";
char* TEXT_C_SWAY = "Sway-WM configs";
char* TEXT_C_BPYT = "bpytop config";
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

char kitty_color_text[32] = "Change Kitty color scheme";
char kitty_fonts_text[32] = "Change Kitty fonts";

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

// the position of the first argument in a command
// example: ``./setup -i nvim``
// nvim is the 3rd argument
int n_to_arg = 3;

struct timespec install_timer;
int fastfetch_conf_export;

char distro[128] = "";
char parent[128] = "";

char initial_path[64];
char inpath[64];

void pre_startup()
{
    // gets the current working directory
    snprintf(inpath, sizeof(inpath), "%s", get_initial_path());
    get_os_name();

    if (strcmp(distro, "debian") == 0) 
    {
	//sets debian as the parent distro of (debian)
	snprintf(parent, sizeof(parent),
		"%s", distro);
    }
    else if (strcmp(distro, "arch") == 0) 
    {
	// sets arch as the parent distro of (arch)
	snprintf(parent, sizeof(parent),
		"%s", distro);
    }
}

char *get_initial_path()
{
    chdir("dotfiles/");

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

	case 6:
	    snprintf(err_text_temp, sizeof(err_text_temp), "This feature hasn't been implemented");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Try updating the dotfiles");
	    break;

	case 51:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Makepkg installation failed. Please check your system configuration.");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Helpful link: \"https://wiki.archlinux.org/title/Makepkg\"");
	    break;

	case 103:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Could not apply fuzzel theme");
	    break;

	case 104:
	    snprintf(err_text_temp, sizeof(err_text_temp), "Could not find kitty package"); // not in use
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
	    break;
	    
	case 207:
		snprintf(err_text_temp, sizeof(err_text_temp), "Unknown version");
		snprintf(err_solution_temp, sizeof(err_solution_temp), "Try installing the dotfiles in order to fix the unknown version");
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

    clearbuffer();
    getchar();  // blocking behaviour 
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


pkg_conf_name detect_config_name(char *input) 
{
    if (strcmp(input, "bash") == 0) return CONF_BASH;
    if (strcmp(input, "btop") == 0) return CONF_BTOP;
    if (strcmp(input, "bpytop") == 0) return CONF_BPYT;
    if (strcmp(input, "cava") == 0) return CONF_CAVA;
    if (strcmp(input, "fastfetch") == 0) return CONF_FAST;
    if (strcmp(input, "fuzzel") == 0) return CONF_FUZZ;
    if (strcmp(input, "gtklock") == 0) return CONF_GTKL;
    if (strcmp(input, "hyprland") == 0) return CONF_HYPR;
    if (strcmp(input, "kitty") == 0) return CONF_KITT;
    if (strcmp(input, "mpv") == 0) return CONF_MPVF;
    if (strcmp(input, "nvim") == 0) return CONF_NVIM;
    if (strcmp(input, "sway") == 0) return CONF_SWAY;
    if (strcmp(input, "waybar") == 0) return CONF_WAYB;
    if (strcmp(input, "zsh") == 0) return CONF_ZSHH;
    return CONF_UNKNOWN;
}

void config_description(char *package_t)
{
    switch (detect_config_name(package_t)) 
    {
        case CONF_BASH:
            printf("Bash, (Bourne Again SHell) is the default shell on most Linux distributions.\n");
            break;

        case CONF_BPYT:
            printf("bpytop is a system resource monitor.\n");
            break;

        case CONF_BTOP:
            printf("btop is a system resource monitor.\n");
            break;

        case CONF_CAVA:
            printf("Cava is a Cross-platform Audio Visualizer.\n");
            break;

        case CONF_FAST:
            printf("Fastfetch is a fast system information tool made in C.\n");
            break;

        case CONF_FUZZ:
            printf("Fuzzel is an App launcher and fuzzy finder based on rofi & dmenu.\n");
            break;

        case CONF_GTKL:
            printf("Gtklock is a GTK lockscreen for Wayland.\n");
            break;

        case CONF_HYPR:
            printf("Hyprland is a dynamic tiling window manager made for Wayland.\n");
            break;

	case CONF_KITT:
            printf("Kitty is a fast, GPU based terminal emulator.\n");
            break;

        case CONF_MPVF:
            printf("MPV is a cross-platform media player made for the command line.\n");
            break;

        case CONF_NVIM:
            printf("Neovim is a modern Vi-based text editor.\n");
            break;
 

        case CONF_WAYB:
            printf("Waybar is an highly customizable\n");
            break;

	case CONF_ZSHH:
            printf("Zsh (Z shell) is a command line interpreter focused on speed and efficiency.\n");
	    break;
        default:
            printf("Unknown program.\n");
    }
}

int get_os_name()
{
    // open /etc/os-release
    FILE *fp = fopen("/etc/os-release", "r");

    // fallback to /usr/lib if /etc/ fails
    if (!fp) fp = fopen("/usr/lib/os-release", "r"); 
    // error checking
    if (!fp) error_message(52);

    char t_line[256];

    while (fgets(t_line, sizeof(t_line), fp)) 
    {
	// store the value after '=' in char val
        char *val = strchr(t_line, '=') + 1;

	// remove trailing newline
        val[strcspn(val, "\"\n")] = '\0'; 

        if (strncmp(t_line, "ID=", 3) == 0) strcpy(distro, val);	    // store the value in char distro
        else if (strncmp(t_line, "ID_LIKE=", 8) == 0) strcpy(parent, val);  // store the value in char parent
    }

    // close file since it won't be used anymore
    fclose(fp);
    return 0;
}

void check_for_yay()
{
    if (system("test -f /sbin/yay") == 0)
    {
	printf("Yay already installed.\n");
    }
    else
    {
        printf("Yay is not installed, do you want to install it? (Y/n): ");
    
        char YAY;
        clearbuffer();
        scanf(" %c", &YAY); // asks the user if they wanna install yay (needed)
        if (YAY == 'Y' || YAY == 'y')
        {
            // Check if makepkg is installed ( it is needed in order to compile yay )
            if (system("command -v makepkg > /dev/null") != 0)
            {
		printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
		exec_cmd(48, "sudo pacman -S --noconfirm base-devel");
                 
                // Check if makepkg is available after installing the base-devel package
                if (system("command -v makepkg > /dev/null") != 0)
                {
		    error_message(51);
                }
                else
                {
		    printf("Makepkg has been successfully installed!\n");
                }
            }
            else
            {
		printf("Makepkg is already installed.\n");
		exec_cmd(48, "sudo pacman -S --noconfirm base-devel"); // update base-devel
            }
		char cmd[256];
		snprintf(cmd, sizeof(cmd),
			"git clone https://aur.archlinux.org/yay.git ; "	// download yay from aur
			"cd yay ; "						//
			"makepkg -si ; "					// build package from source
			"cd ..");						//
		system(cmd);
		printf("\nYay is installed, congrats!\n");
        }
        else
        {
            error_message(5);
        }
    }
}

void exec_cmd(int buffer_size, char *command_to_execute)
{
    char command_exec[buffer_size];
    snprintf(command_exec, sizeof(command_exec), "%s", command_to_execute);
    system(command_exec);
}

void countdown(int counter)
{
    int total_time = counter;

    for (int i = 0; i < total_time; i++)
    {
        printf("%d ", counter);
    
        for (int j = 0; j < 3; j++)
        {
            printf(".");
            fflush(stdout);
    
    	wait_for_timeout(1, 0);
        }
        for (int k = 0; k < 1; k++)
        {
	    printf("\n");
	    wait_for_timeout(1, 0);
        }
        counter--;
    }
}
void argument_config_install(char *package_t)
{
    switch (detect_config_name(package_t)) 
    {
        case CONF_BASH:
            break;

        case CONF_BPYT:
            break;

        case CONF_BTOP:
            break;

        case CONF_CAVA:
            break;

        case CONF_FAST:
            break;

        case CONF_FUZZ:
            break;

        case CONF_GTKL:
            break;

        case CONF_HYPR:
            break;

	case CONF_KITT:
            break;

        case CONF_MPVF:
            break;

        case CONF_NVIM:
            break;
 
        case CONF_WAYB:
            break;

	case CONF_ZSHH:
	    break;

        default:
	    break;
    }
}
