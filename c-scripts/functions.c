#include "dotfileshead.h"

const int max_menu_opt_n = 12;

void clear()
{
    printf("\033[2J\033[H");
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

struct timespec install_timer;
int fastfetch_conf_export;

char initial_path[64];
char inpath[64];
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
	    //snprintf(err_solution_temp, sizeof(err_solution_temp), "NULL");
	    break;
	    
	case 207:
		snprintf(err_text_temp, sizeof(err_text_temp), "Unknown version");
	    snprintf(err_solution_temp, sizeof(err_solution_temp), "Try installing the dotfiles in order to fix the unknown version");snprintf(err_text_temp, sizeof(err_text_temp), "popen failed");
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
    // gets the current working directory
    snprintf(inpath, sizeof(inpath), "%s", get_initial_path());
}

void fuzzel_config_importing()
{
    // check if the configs were already downloaded 
    char path[512];
    char *home = getenv("HOME");
    snprintf(path, sizeof(path), "%s/.config/fuzzel/imported/fuzzel", home);

    struct stat st;
    char cmd[512];
    if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) 
    {
        printf("The fuzzel themes are already installed.\n");
    }
    else 
    {
    	snprintf(cmd, sizeof(cmd),
    	        "mkdir -p ~/.config/fuzzel/imported/ ; " 
    	        "cd ~/.config/fuzzel/imported/ ; "
    	        "git clone https://github.com/catppuccin/fuzzel.git");
    	system(cmd);
    }

    snprintf(cmd, sizeof(cmd),
	    "cd ~/.config/fuzzel/imported/fuzzel/themes");
    system(cmd);

    int theme_type_user_opt;

    char* theme_type_text;
    
    clear();
    printf(BOLD_S"Choose your fuzzel theme type\n"STYLE_END);
    
    printf(BOLD_S"[1]"STYLE_END" catppuccin-latte (light mode)\n");
    printf(BOLD_S"[2]"STYLE_END" catppuccin-frappe (grey)\n");
    printf(BOLD_S"[3]"STYLE_END" catppuccin-macchiato (dark)\n");
    printf(BOLD_S"[4]"STYLE_END" catppuccin-mocha (very dark)\n");
    
    while (getchar() != '\n'); // clear imput buffer
    scanf(" %d", &theme_type_user_opt);
    
    switch(theme_type_user_opt)
    {
	case 1:
    	    theme_type_text = "catppuccin-latte";
    	    goto endone;
    	case 2:
    	    theme_type_text = "catppuccin-frappe";
    	    goto endone;
    	case 3:
    	    theme_type_text = "catppuccin-macchiato";
    	    goto endone;
    	case 4:
    	    theme_type_text = "catppuccin-mocha";
    	    goto endone;
    	default:
    	    printf("Try again.\n");
    	    goto endone;
    	endone:
	;
    }
    // theme color
    printf(BOLD_S"Set the colour for your fuzzel config\n"STYLE_END);

    int theme_colour_user_opt;
    char colour_message_text[16] = "Use the colour";

    printf(BOLD_S"[1] "STYLE_END" %s "BOLD_S"blue"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[2] "STYLE_END" %s "BOLD_S"flamingo"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[3] "STYLE_END" %s "BOLD_S"green"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[4] "STYLE_END" %s "BOLD_S"lavender"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[5] "STYLE_END" %s "BOLD_S"maroon"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[6] "STYLE_END" %s "BOLD_S"mauve"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[7] "STYLE_END" %s "BOLD_S"peach"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[8] "STYLE_END" %s "BOLD_S"pink"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[9] "STYLE_END" %s "BOLD_S"red"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[10]"STYLE_END" %s "BOLD_S"rosewater"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[11]"STYLE_END" %s "BOLD_S"sapphire"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[12]"STYLE_END" %s "BOLD_S"sky"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[13]"STYLE_END" %s "BOLD_S"teal"STYLE_END"\n", colour_message_text);
    printf(BOLD_S"[14]"STYLE_END" %s "BOLD_S"yellow"STYLE_END"\n", colour_message_text);
    
    while (getchar() != '\n'); // clear imput buffer
    scanf(" %d", &theme_colour_user_opt);
    switch(theme_colour_user_opt)
    {
	case 1:
	    theme_colour_text = "blue";
	    break;
	case 2:
	    theme_colour_text = "flamingo";
	    break;
	case 3:
	    theme_colour_text = "green";
	    break;
	case 4:
	    theme_colour_text = "lavender";
	    break;
	case 5:
	    theme_colour_text = "maroon";
	    break;
	case 6:
	    theme_colour_text = "mauve";
	    break;
	case 7:
	    theme_colour_text = "peach";
	    break;
	case 8:
	    theme_colour_text = "pink";
	    break;
	case 9:
	    theme_colour_text = "red";
	    break;
	case 10:
	    theme_colour_text = "rosewater";
	    break;
	case 11:
	    theme_colour_text = "sapphire";
	    break;
	case 12:
	    theme_colour_text = "sky";
	    break;
	case 13:
	    theme_colour_text = "teal";
	    break;
	case 14:
	    theme_colour_text = "yellow";
	    break;
	default:
	    printf("Try again.\n");
    }
    char fuz_theme_path[256];
    snprintf(fuz_theme_path, sizeof(fuz_theme_path),
	    "%s/.config/fuzzel/imported/fuzzel/themes/%s/%s.ini", home, theme_type_text, theme_colour_text);
    
    snprintf(cmd, sizeof(cmd),
	    "mv -f %s/.config/fuzzel/fuzzel.ini %s/.config/fuzzel/before-link-fuzzel.ini ; "
	    "ln -sf %s %s/.config/fuzzel/fuzzel.ini", home, home, fuz_theme_path, home);
    system(cmd);
    fflush(stdout);
    
    char fuz_conf_path[64];
    snprintf(fuz_conf_path, sizeof(fuz_conf_path), "%s/.config/fuzzel/fuzzel.ini", home);
    
    if (lstat(fuz_conf_path, &st) == 0 && S_ISLNK(st.st_mode)) 
    {
        printf("Successfully applied Fuzzel theme\n");
        printf("Theme type:"BOLD_S UDRL_S" %s \n"STYLE_END, theme_type_text);
        printf("Theme colour:"BOLD_S UDRL_S" %s \n"STYLE_END, theme_colour_text);
	wait_for_timeout(0, 1);
    }
    else
    {
        error_message(103);
    }
}

void full_install(char ARCHIVE, char full_install_opt)
{
    if (full_install_opt == 'Y' || full_install_opt == 'y')
    {
	int timerinstall = 3;
	printf(BOLD_S"\nInstalling every configuration\n"STYLE_END);
	printf(BOLD_S"\nStarting in:\n"STYLE_END);
	
	for (int i = 0; i < 3; i++)
	{
	    printf("%d ", timerinstall);
	
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
	    timerinstall--;
	}
	
	if (system("test -f /sbin/yay") == 0)
    	{
    	    printf("Yay already installed, congrats!\n");
    	}
    	else
    	{
    	    printf("Yay is not installed, do you want to install it? (Y/n): ");

    	    char YAY;
	    while (getchar() != '\n');  // clear imput buffer 
	    ;
    	    scanf(" %c", &YAY); // asks the user if they wanna install yay (needed)
    	    if (YAY == 'Y' || YAY == 'y')
    	    {
    	        // Check if makepkg is installed ( it is needed in order to compile yay )
    	        if (system("command -v makepkg > /dev/null") != 0)
    	        {
    	            printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
		    char cmd[128];
		    snprintf(cmd, sizeof(cmd),
			    "sudo pacman -S --noconfirm base-devel");
	    	    system(cmd);
    	            
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
    	        }
	        // install yay \/
    	        char cmd[256];
    	        snprintf(cmd, sizeof(cmd),
			"sudo pacman -S --noconfirm base-devel ; "
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
	// actually install the dotfiles
	BASH();
	SWAY(ARCHIVE, 0.0, 'Y');
	BTOP(ARCHIVE, 0.0, 'Y');
	BPYT(ARCHIVE, 0.0, 'Y');
	CAVA(ARCHIVE, 0.0, 'Y');
	FAST(ARCHIVE, 0.0, 'Y');
	FUZZ(ARCHIVE, 0.0, 'Y');
	GTKL(ARCHIVE, 0.0, 'Y');
	HYPR(ARCHIVE, 0.0, 'Y');
	KITT(ARCHIVE, 0.0, 'Y');
	MPVF(ARCHIVE, 0.0, 'Y');
	NVIM(ARCHIVE, 0.0, 'Y');
	WAYB(ARCHIVE, 0.0, 'Y');
	ZSHH(ARCHIVE, 0.0, 'Y');
    }
    else
    {
	int install_pkg_opt;
	do
	{
	    printf("\n[1] Install %s ", TEXT_C_BASH);
	    printf("\n[2] Install %s ", TEXT_C_BPYT);
	    printf("\n[3] Install %s ", TEXT_C_BTOP);
	    printf("\n[4] Install %s ", TEXT_C_CAVA);
	    printf("\n[5] Install %s ", TEXT_C_FAST);
	    printf("\n[6] Install %s ", TEXT_C_FUZZ);
	    printf("\n[7] Install %s ", TEXT_C_GTKL);
	    printf("\n[8] Install %s ", TEXT_C_HYPR);
	    printf("\n[9] Install %s ", TEXT_C_KITT);
	    printf("\n[10] Install %s ", TEXT_C_MPVF);
	    printf("\n[11] Install %s ", TEXT_C_NVIM);
	    printf("\n[12] Install %s ", TEXT_C_SWAY);
	    printf("\n[13] Install %s ", TEXT_C_WAYB);
	    printf("\n[14] Install %s ", TEXT_C_ZSHH);
	    
	    while (getchar() != '\n');  // clear imput buffer 
	    scanf(" %d", &install_pkg_opt);
	    install_configs(install_pkg_opt);
	}
	while (install_pkg_opt > 0);
    }
    printf(BOLD_S"\nInstallation completed!\n"STYLE_END);
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

        case CONF_NVIM:
            printf("Neovim is a modern Vi-based text editor.\n");
            break;

	case CONF_ZSHH:
            printf("Zsh (Z shell) is a command line interpreter focused on speed and efficiency.\n");
	    break;
        default:
            printf("Unknown program.\n");
    }
}
