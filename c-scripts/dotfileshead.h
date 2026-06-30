#define HSETUP_DOT_H
#define _POSIX_C_SOURCE 200809L

#include "enums.h"
#include "macros.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <sys/stat.h>


void BASH(void);
void BPYT(bool archive_bl, bool pkginstall_bl);
void BTOP(bool archive_bl, bool pkginstall_bl);
void CAVA(bool archive_bl, bool pkginstall_bl);
void FAST(bool archive_bl, bool pkginstall_bl);
void FUZZ(bool archive_bl, bool pkginstall_bl);
void GTKL(bool archive_bl, bool pkginstall_bl);
void HYPR(bool archive_bl, bool pkginstall_bl);
void KITT(bool archive_bl, bool pkginstall_bl);
void MPVF(bool archive_bl, bool pkginstall_bl);
void NVIM(bool archive_bl, bool pkginstall_bl);
void SWAY(bool archive_bl, bool pkginstall_bl);
void WAYB(bool archive_bl, bool pkginstall_bl);
void ZSHH(bool archive_bl, float pver, bool pkginstall_bl);

int install_package(const char *pkg_type_distro, const char *pkginstallname);
void file_archiving(const char *program_config_path, const char *config_file, const char *file_extention);
void file_exporting(const char *program_name, const char *config_name, const char *file_extention);
void link_file(const char *source_path, const char *link_path);	/* link path is the target path */
void make_dir(const char *program_name);


/* initialise in functions.c */
	bool y_n(const char yes_no);
	long get_long(const char *message, const long lower_bound, const long upper_bound);
	void block(const bool prompt);
	void clear(void);
	void clearbuffer(void);
	void exec_cmd(const int buffer_size, const char *command_to_execute);
	void pre_startup(void);

void check_for_yay(void);
void configure_fastfetch(void);
void configure_oh_my_zsh(void);
void copyfiles(int fastfetch_conf_export);
void link_fastfetch_configs(void);
void full_config_install(bool ARCHIVE_BL, float previous_version_t, bool install_packages_t);
void full_install(bool archive_bl, bool full_install_bl);
void install_config_message(char *text);
void install_configs(unsigned int custom_package_install);
void install_menu(void);

config_name detect_config_name(char *input);

/* time related */
	void yes_no_prompt(void);
	void countdown(int counter, int lines_to_skip);
	void wait_for_timeout(long quarters, long seconds);

	/* struct */
	extern struct timespec install_timer; 

/*  command line arguments */
	char *package_name(config_name config);
	int config_fn_exec(config_name config_type, bool archive_bl, bool package_bl, float version);
	void argument_config_install(char *package_t, char archiving_t, char pkginstall_t);
	void cmd_arg_install(int num_cmd_arguments_t, char *cmd_arg_v_t[], char config_archive_t, char pkg_install_t);
	void cli_arg_missing(char *first_command, char *type_of_missing_arg, char *user_flag_t);
	int parse_arguments(int num_cmd_arguments, char *cmd_arg_v[]);

	extern const int n_to_arg;
	extern char *description_arr[n_configs];

/* command line related
* Initialized in globals.c */
	extern char* help_flag_arg_text;
	extern char* pkgi_flag_arg_text;
	extern char* conf_inst_flag_arg_text;
	extern char* conf_info_flag_arg_text;
	extern bool verbose;
	void verbose_path_print(char *file_path, char *file_name);

/* data */
	extern char *config_names[n_configs];
	extern char fastfetch_config_menu_text[menu_text_size];
	extern char kitty_config_menu_text[menu_text_size];
	extern char zshforhumans_config_menu_text[menu_text_size];

	/* fuzzel */
		extern char fuzzel_config_menu_text[menu_text_size];
		extern char fuzzel_view_config_text[menu_text_size];
		extern char fuzzel_edit_config_text[menu_text_size];
		extern char fuzzel_catppuccin_text[menu_text_size];

	extern char kitty_color_text[menu_text_size];
	extern char kitty_fonts_text[menu_text_size];

	extern char main_menu_title[128];
	extern char opt_one_text[MENU_TEXT_SIZE];
	extern char opt_the_text[MENU_TEXT_SIZE];
	extern char opt_for_text[MENU_TEXT_SIZE];
	extern char opt_fiv_text[MENU_TEXT_SIZE];
	extern char opt_exit_text[16];
	extern char *main_menu_text[NUM_ELEMENTS_MAIN_MENU];

/* needs to be global */
	extern char* theme_colour_text;
	extern float pver;
	extern int fastfetch_conf_export;
	extern const char *home;
	extern char full_install_opt; /* if the user wants to install everything set to Y */
	extern char archive_before_install;
	extern char *archiving_file_suffix_template;

/* main menu */
	extern const int max_menu_opt_n;
	extern bool fastfetch_config_apply;
	extern char distro[128];    /* distro string */
	extern char parent[128];    /* parent distro string (Ubuntu's Parent distro is Debian) */
	extern bool is_debian_bl;
	extern bool is_arch_bl;
	extern char initial_path[64];
	extern char inpath[64];
	extern char config_path[256];
	char *get_initial_path(void);
	int get_os_name(void);

	extern char full_update_opt; 
	float* get_version(void);

	int full_update(char ARCHIVE, float pver);


/* fuzzel functions */
	void fuzzel_config_importing(void);
	void apply_fuzzel_config(int config_choice_t);

/* errors */
	extern char errcode;
	int error_message(error_code_e err_code);
