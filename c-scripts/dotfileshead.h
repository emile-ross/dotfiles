#define HSETUP_DOT_H
#define _POSIX_C_SOURCE 200809L

#include "enums.h"
#include "macros.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include <unistd.h>
#include <sys/stat.h>


void BASH(void);
void SWAY(bool archive_bl, float pver, bool pkginstall_bl);
void BTOP(bool archive_bl, float pver, bool pkginstall_bl);
void BPYT(bool archive_bl, float pver, bool pkginstall_bl);
void CAVA(bool archive_bl, float pver, bool pkginstall_bl);
void FAST(bool archive_bl, float pver, bool pkginstall_bl);
void FUZZ(bool archive_bl, float pver, bool pkginstall_bl);
void GTKL(bool archive_bl, float pver, bool pkginstall_bl);
void HYPR(bool archive_bl, float pver, bool pkginstall_bl);
void KITT(bool archive_bl, float pver, bool pkginstall_bl);
void MPVF(bool archive_bl, float pver, bool pkginstall_bl);
void NVIM(bool archive_bl, float pver, bool pkginstall_bl);
void WAYB(bool archive_bl, float pver, bool pkginstall_bl);
void ZSHH(bool archive_bl, float pver, bool pkginstall_bl);


void clear(void);
void clearbuffer(void);
void pre_startup(void);
bool yn(char yn);


int install_package(char *pkg_type_distro, char *pkginstallname);
void install_menu(void);
void full_install(bool ARCHIVE_BL, bool full_install_bl);
void full_config_install(bool ARCHIVE_BL, float previous_version_t, bool install_packages_t);
void install_configs(unsigned int custom_package_install);
void copyfiles(int fastfetch_conf_export);
void check_for_yay(void);
void exec_cmd(int buffer_size, char *command_to_execute);
void link_fastfetch_configs(void);
void configure_oh_my_zsh(void);
void configure_fastfetch(void);

config_name detect_config_name(char *input);

// time related
void countdown(int counter, int lines_to_skip);
void wait_for_timeout(int timer_quarters, int timer_seconds);
extern struct timespec install_timer;
extern int timer_quarters; // max is 4
extern int timer_seconds;
extern long int time_timer_quarters;
extern long int time_timer_seconds;

//  command line arguments
void config_description(char *package_t);
void argument_config_install(char *package_t, char archiving_t, char pkginstall_t);
void cmd_arg_install(int num_cmd_arguments_t, char *cmd_arg_v_t[], char config_archive_t, char pkg_install_t);
void cli_arg_missing(char *first_command, char *type_of_missing_arg, char *user_flag_t);
int parse_arguments(int num_cmd_arguments, char *cmd_arg_v[]);
extern const int n_to_arg;

// data 
extern char* TEXT_C_BASH;   /* will be replaced by an array */
extern char* TEXT_C_BPYT;   /* will be replaced by an array */
extern char* TEXT_C_BTOP;   /* will be replaced by an array */
extern char* TEXT_C_CAVA;   /* will be replaced by an array */
extern char* TEXT_C_FAST;   /* will be replaced by an array */
extern char* TEXT_C_FUZZ;   /* will be replaced by an array */
extern char* TEXT_C_GTKL;   /* will be replaced by an array */
extern char* TEXT_C_HYPR;   /* will be replaced by an array */
extern char* TEXT_C_KITT;   /* will be replaced by an array */
extern char* TEXT_C_MPVF;   /* will be replaced by an array */
extern char* TEXT_C_NVIM;   /* will be replaced by an array */
extern char* TEXT_C_SWAY;   /* will be replaced by an array */
extern char* TEXT_C_WAYB;   /* will be replaced by an array */
extern char* TEXT_C_ZSHH;   /* will be replaced by an array */

// command line related
// Initialized in globals.c
extern char* help_flag_arg_text;
extern char* pkgi_flag_arg_text;
extern char* conf_inst_flag_arg_text;
extern char* conf_info_flag_arg_text;

extern char fastfetch_config_menu_text[32];
extern char kitty_config_menu_text[32];
extern char fuzzel_config_menu_text[32];
extern char zshforhumans_config_menu_text[32];

extern char main_menu_text[128];
extern char opt_one_text[MENU_TEXT_SIZE];
extern char opt_the_text[MENU_TEXT_SIZE];
extern char opt_for_text[MENU_TEXT_SIZE];
extern char opt_fiv_text[MENU_TEXT_SIZE];
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

// main menu
extern int menu_one_i;
extern const int max_menu_opt_n;
extern bool fastfetch_config_apply;
extern char distro[128];    /* distro string */
extern char parent[128];    /* parent distro string (Ubuntu's Parent distro is Debian) */
extern char initial_path[64];
extern char inpath[64];
char *get_initial_path(void);
int get_os_name(void);

extern char full_update_opt; 
float* update(void);
int full_update(char ARCHIVE, float pver);


// fuzzel 
void fuzzel_config_importing(void);
extern int fuzzel_config_menu_choice;
void apply_fuzzel_config(int config_choice_t);
extern char fuzzel_view_config_text[32];
extern char fuzzel_edit_config_text[32];
extern char fuzzel_catppuccin_text[32];


// errors
extern char errcode;
int error_message(int err_code);
