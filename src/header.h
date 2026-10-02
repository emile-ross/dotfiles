#define _POSIX_C_SOURCE 200809L

#include "enums.h"
#include "macros.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int install_package(distro_type distro, const char *pkginstallname);
void pkg_cmd(const char *cmd_format, const char *pkg);

void file_archiving(const char *program_config_path, const char *config_file, const char *file_extention);
void file_exporting(const char *program_name, const char *text_config_name, const char *file_extention);
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

size_t string_size(void *buf_to_free[], bool terminate, const char *restrict format, ...);
int free_buffers(void *buffers_to_free[]);
void check_for_yay(void);
void configure_fastfetch(void);
void configure_oh_my_zsh(void);
void copyfiles(int fastfetch_conf_export);
void link_fastfetch_configs(void);

config_name detect_config_name(char *input);

/* time related */
	void yes_no_prompt(void);
	void countdown(int counter, int lines_to_skip);
	void wait_for_timeout(long quarters, long seconds);

	/* struct */
	extern struct timespec install_timer; 

/*  command line arguments */
	char *package_name(config_name config);
	void cli_arg_missing(char *first_command, char *type_of_missing_arg, char *user_flag_t);
	int parse_arguments(int num_cmd_arguments, char *cmd_arg_v[]);

	extern const int n_to_arg;
	extern char *description_arr[n_configs];

/* compare.c */
	bool cmp(const char *arg, const char *s_flag, const char *l_flag);
	bool scmp(const char *arg, const char *flag);

/* command line related
* Initialized in globals.c */
	extern char* help_flag_arg_text;
	extern char* pkgi_flag_arg_text;
	extern char* conf_inst_flag_arg_text;
	extern char* conf_info_flag_arg_text;
	extern bool verbose;
	void verbose_path_print(char *file_path, char *file_name);

/* data */

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
	extern char initial_path[64];
	extern char inpath[64];
	extern char config_path[256];
	char *get_initial_path(void);
	int get_os_name(void);
	extern distro_type parent_d;

	extern char full_update_opt; 
	float* get_version(void);

	int full_update(float version);


/* fuzzel functions */
	void fuzzel_config_importing(void);
	void apply_fuzzel_config(int config_choice_t);

/* errors */
	extern char errcode;
	int error_message(error_code_e err_code);


