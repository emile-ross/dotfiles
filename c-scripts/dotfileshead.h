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
#define STRIKE_S 	"\e[9m"

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

#define STYLE_END	"\033[0m" // reset styling

void BASH();
void SWAY(char ARCHIVE, float pver, char PKGINSTALL);
void BTOP(char ARCHIVE, float pver, char PKGINSTALL);
void BPYT(char ARCHIVE, float pver, char PKGINSTALL);
void CAVA(char ARCHIVE, float pver, char PKGINSTALL);
void FAST(char ARCHIVE, float pver, char PKGINSTALL);
void FUZZ(char ARCHIVE, float pver, char PKGINSTALL);
void GTKL(char ARCHIVE, float pver, char PKGINSTALL);
void HYPR(char ARCHIVE, float pver, char PKGINSTALL);
void KITT(char ARCHIVE, float pver, char PKGINSTALL);
void MPVF(char ARCHIVE, float pver, char PKGINSTALL);
void NVIM(char ARCHIVE, float pver, char PKGINSTALL);
void WAYB(char ARCHIVE, float pver, char PKGINSTALL);
void ZSHH(char ARCHIVE, float pver, char PKGINSTALL);

void clear();
void clearbuffer();
void pre_startup();

// Mandatory global variables
extern char distro[128];
extern char parent[128];
extern char initial_path[64];
extern char inpath[64];

int install_package(char *pkg_type_distro, char *pkginstallname);
void full_install(char ARCHIVE, char full_install_opt);
void install_configs(int custom_package_install); // the partial install script (configure which package or configuration to install)
void copyfiles (int fastfetch_conf_export);
void check_for_yay();
void exec_cmd(int buffer_size, char *command_to_execute);
void link_fastfetch_configs();
void configure_oh_my_zsh();
void configure_fastfetch();


typedef enum 
{
    CONF_UNKNOWN,
    CONF_BASH,
    CONF_BTOP,
    CONF_BPYT,
    CONF_CAVA,
    CONF_FAST,
    CONF_FUZZ,
    CONF_GTKL,
    CONF_HYPR,
    CONF_KITT,
    CONF_MPVF,
    CONF_NVIM,
    CONF_SWAY,
    CONF_WAYB,
    CONF_ZSHH
} pkg_conf_name;

pkg_conf_name detect_config_name(char *input);

// time related
void countdown(int counter, int lines_to_skip);
void wait_for_timeout(int timer_quarters, int timer_seconds);
extern struct timespec install_timer;
extern int timer_quarters; // max is 4
extern int timer_seconds;

//  command line arguments
void config_description(char *package_t);
void argument_config_install(char *package_t);
void cmd_arg_install(int num_cmd_arguments_t, char *cmd_arg_v_t[]);
void cli_arg_missing(char *first_command, char *type_of_missing_arg, char *user_flag_t);
int parse_arguments(int num_cmd_arguments, char *cmd_arg_v[]);
extern int n_to_arg;

// data 
extern char* TEXT_C_BASH;
extern char* TEXT_C_BPYT;
extern char* TEXT_C_BTOP;
extern char* TEXT_C_CAVA;
extern char* TEXT_C_FAST;
extern char* TEXT_C_FUZZ;
extern char* TEXT_C_GTKL;
extern char* TEXT_C_HYPR;
extern char* TEXT_C_KITT;
extern char* TEXT_C_MPVF;
extern char* TEXT_C_NVIM;
extern char* TEXT_C_SWAY;
extern char* TEXT_C_WAYB;
extern char* TEXT_C_ZSHH;

extern char fastfetch_config_menu_text[32];
extern char kitty_config_menu_text[32];
extern char fuzzel_config_menu_text[32];
extern char zshforhumans_config_menu_text[32];

extern char main_menu_text[128];
extern char opt_one_text[128];
extern char opt_the_text[128];
extern char opt_for_text[128];
extern char opt_fiv_text[128];
extern char opt_exit_text[16];

extern char kitty_color_text[32];
extern char kitty_fonts_text[32];

// needs to be global
extern char* theme_colour_text;
extern float pver;
extern int fastfetch_conf_export;
extern const char *home;
extern char full_install_opt; // if the user wants to install everything set to Y
extern char archive_before_install;
extern int menu_one_i;
extern const int max_menu_opt_n;
char *get_initial_path();
int get_os_name();

extern char full_update_opt; 
float* update();
int full_update(char ARCHIVE, float pver);


// fuzzel 
void fuzzel_config_importing();
extern int fuzzel_config_menu_choice;
void apply_fuzzel_config(int config_choice_t);
extern char fuzzel_view_config_text[32];
extern char fuzzel_edit_config_text[32];
extern char fuzzel_catppuccin_text[32];

// errors
extern char errcode;
int error_message(int err_code);
