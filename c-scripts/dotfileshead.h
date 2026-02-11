#define HSETUP_DOT_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BOLD_S  	"\e[1m" // defines BOLD_S as a keyword to make text bold
#define UDRL_S  	"\e[4m" // UDRL_S starts an underline style (does not work in kitty by default)
#define ITALICS_S 	"\e[3m"
#define SLOWBLINK_S 	"\e[5m"
#define FASTBLINK_S 	"\e[6m"
#define STRIKE_S 	"\e[9m"

void clear()
{
    printf("\033[2J\033[H");
}

#define ANSI_RED 	"\x1b[31m"
#define ANSI_GREEN 	"\x1b[32m"
#define ANSI_LGREEN 	"\x1b[92m"
#define ANSI_YELLOW 	"\x1b[33m"
#define ANSI_LYELLOW 	"\x1b[93m"
#define ANSI_BLUE    	"\x1b[34m"
#define ANSI_WHITE    	"\x1b[97m"
#define ANSI_GREY    	"\x1b[90m"
#define ANSI_CYAN    	"\x1b[36m"
#define ANSI_LCYAN    	"\x1b[96m"

#define STYLE_END   	"\e[m" // resets the styling

void BASH(char ARCHIVE, float pver, char PKGINSTALL);
void SWAY(char ARCHIVE, float pver, char PKGINSTALL);
void BTOP(char ARCHIVE, float pver, char PKGINSTALL);
void CAVA(char ARCHIVE, float pver, char PKGINSTALL);
void FAST(char ARCHIVE, float pver, char PKGINSTALL);
void FUZZ(char ARCHIVE, float pver, char PKGINSTALL);
void GTKL(char ARCHIVE, float pver, char PKGINSTALL);
void HYPR(char ARCHIVE, float pver, char PKGINSTALL);
void KITT(char ARCHIVE, float pver, char PKGINSTALL);
void MPVF(char ARCHIVE, float pver, char PKGINSTALL);
void NVIM(char ARCHIVE, float pver, char PKGINSTALL);
void WAYB(char ARCHIVE, float pver, char PKGINSTALL);

void full_install(char ARCHIVE, char full_install_opt);
int full_update(char ARCHIVE, float pver);

const int max_menu_opt_n = 12;

void install_configs(); // the partial install script (configure which package or configuration to install)
void copyfiles (int fastfetch_conf_export);

float* update();

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

int fastfetch_conf_export;

struct timespec install_timer;
char ARCHIVE;
char PKGINSTALL;

char full_install_opt; // if the user wants to install everything set to Y
char full_update_opt; 
