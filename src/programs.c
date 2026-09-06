#include "header.h"

void BASH(void)
{
	/* replace with ".bashrc" in order to replace the default bash config */
	char BRCNAME[12] = ".bashrc-new"; 

	/* prompt to let the user know the bashrc isn't exported/replaced */
	printf(UDRL_S"\nThe .bashrc file plays a very important role therefore, it was not replaced."STYLE_END);
	printf("\nYou can find the new .bashrc file under the new name %s\n", BRCNAME);
	
	/* calculate the sufficient amount of memory to the buffer */
	const char *command_format = "cp -f %s/shell/bash/.bashrc ~/%s";
	size_t mem_needed = string_size(NULL, true, command_format, inpath, BRCNAME);
	
	char *bash_cmd = malloc(mem_needed);
	if (bash_cmd == NULL)
		error_message(MALLOC_FAIL);
	/* execute the command with the according buffer size previously calculated (above) */
	snprintf(bash_cmd, (size_t)mem_needed, command_format, inpath, BRCNAME);
	system(bash_cmd);
	free(bash_cmd);
}

void BPYT(bool archive_bl, bool pkginstall_bl)
{
	char *pkg_name = "bpytop";
	if (archive_bl)
	{
		file_archiving(pkg_name, pkg_name, ".conf");
	}

	if (pkginstall_bl)
	{
		install_package(parent_d, pkg_name); /* install bpytop package */
	}
	/* export bpytop config */
	make_dir(pkg_name);
	file_exporting(pkg_name, pkg_name, ".conf");
}

void BTOP(bool archive_bl, bool pkginstall_bl)
{
	const char *package_name = "btop";
	const char *file_extention = ".conf";
	if (archive_bl)
	{
		file_archiving(package_name, package_name, file_extention);
	}
	if (pkginstall_bl)
	{
		install_package(parent_d, package_name); /* install btop package */
    	}
    	/* export btop config */
	make_dir(package_name);
	file_exporting(package_name, package_name, file_extention);
}

void CAVA(bool archive_bl, bool pkginstall_bl)
{
	const char *program_name = "cava";
	const char *program_config_path = "%s/%s";
	size_t program_path_size = string_size(NULL, true, program_config_path, config_path, program_name);
	
	char *program_path = malloc(program_path_size);
	snprintf(program_path, program_path_size, program_config_path, config_path, program_name);
	
	if (archive_bl)
	{
		file_archiving(program_name, "config", NULL);
	}
	
	if (pkginstall_bl)
	{
	    	install_package(parent_d, (const char*)program_name); /* install cava package */
	}
	
	/* export cava config */
	const char *dir_cmd = "mkdir -p %s ; cp -f %s/%s/config %s/ ";
	void *arr[2] = 
	{
		program_path,
		NULL
	};
	size_t mem_needed_cmd = string_size(arr, true, dir_cmd, program_path, inpath, program_name, program_path);
	
	char *safe_cmd = malloc(mem_needed_cmd);
	snprintf(safe_cmd, mem_needed_cmd, dir_cmd, program_path, inpath, program_name, program_path);
	free(program_path);

	if (verbose)
	{
		printf("%s\n", safe_cmd);
	}
	system(safe_cmd);
	free(safe_cmd);
}

void FAST(bool archive_bl, bool pkginstall_bl)
{
	const char *program_name = "fastfetch";
	const char *program_config_path = "%s/%s";
	int temp_path_size = 1 + snprintf(NULL, 0, program_config_path, inpath, program_name);
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path, program_name);

	char *temp_path = malloc((size_t)temp_path_size);
	snprintf(temp_path, (size_t)temp_path_size, program_config_path, inpath, program_name);

	char *program_path = malloc((size_t)program_path_size);
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path, program_name);

    	if (archive_bl)
    	{
		file_archiving("fastfetch", "config", ".jsonc");
	}

	if (pkginstall_bl)
    	{
    	    	install_package(parent_d, "fastfetch"); /* install fastfetch */
    	}
	/* export fastfetch config */
	file_exporting("fastfetch", "config", ".conf");
	file_exporting("fastfetch", "config-other", ".conf");
	file_exporting("fastfetch", "config-default", ".conf");

	make_dir("fastfetch/assets");

	char *command_template = 
		"rm %s ; "
		"cp -f %s/assets/*.png %s/assets/ ; "
		"cp -f %s/config.jsonc %s/config-duplicated.jsonc";

    	size_t command_size = 1 + (size_t)snprintf(NULL, 0, command_template, program_path, temp_path, program_path, program_path, program_path);

	char *fastfetch_cmd = malloc(command_size);

    	snprintf(fastfetch_cmd, command_size, command_template, program_path, temp_path, program_path, program_path, program_path);
	free(program_path);
	free(temp_path);

    	system(fastfetch_cmd);
	if (verbose)
	{
		printf("%s \n\n ", fastfetch_cmd);
	}
	free(fastfetch_cmd);

}

void FUZZ(bool archive_bl, bool pkginstall_bl)
{
	const char *program_config_path = "%s/fuzzel";
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);

	char *program_path = malloc((size_t)program_path_size);
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);

    	if (archive_bl)
    	{
		file_archiving("fuzzel", "fuzzel", ".ini");
		file_archiving("fuzzel", "fuzzel-duplicated", ".ini");
		file_archiving("fuzzel", "old-fuzzel", ".ini");
	}
	if (pkginstall_bl)
    	{
		/* install fuzzel package */
		install_package(parent_d, "fuzzel");
	}
	/* export fuzzel appearance */
	file_exporting("fuzzel", "fuzzel", ".ini");
	file_exporting("fuzzel", "old-fuzzel", ".ini");
	file_exporting("fuzzel", "default-fuzzel", ".ini");

	link_file("~/.config/fuzzel/fuzzel-duplicated.ini", "~/.config/fuzzel/fuzzel.ini");

	make_dir("fuzzel");
	free(program_path);
}
void GTKL(bool archive_bl, bool pkginstall_bl)
{
	char *program_name = "gtklock";
	const char *program_config_path = "%s/gtklock";
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);

	char *program_path = malloc((size_t)program_path_size);
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);

    	if (archive_bl)
    	{
		file_archiving(program_name, "style", ".css");
	}
    	if (pkginstall_bl)
    	{
    	    	/* install gtklock package */
    	    	install_package(parent_d, program_name);
    	}
	/* export gtklock config */
	make_dir("gtklock/assets");
	file_exporting(program_name, "style", ".css");
	file_exporting(program_name, "lockscreen", ".jpg");

	free(program_path);
}

void HYPR(bool archive_bl, bool pkginstall_bl)
{
	char *file_extention = ".conf";
	char *config_file[5] = 
	{
		"hypridle",
		"hyprland",
		"hyprlock",
		"hyprpaper",
		NULL,
	};

	char *config_directory = "hypr";
	if (archive_bl)
	{
		for (int i = 0; config_file[i] != NULL; i++)
		{
			file_archiving(config_directory, config_file[i], file_extention);
		}
	}

	if (pkginstall_bl)
	{
		/* install Hyprland packages */
		for (int i = 0; config_file[i] != NULL; i++)
		{
			install_package(parent_d, config_file[i]);
		}
    	}
	/* export hyprland configs */
	for (int i = 0; config_file[i] != NULL; i++)
	{
		file_exporting(config_directory, config_file[i], file_extention);
	}

	char *assets_directory = "hypr/assets";
	make_dir(assets_directory);
	file_exporting(assets_directory, "lockscreen", ".png");
}

void KITT(bool archive_bl, bool pkginstall_bl)
{
	char *name = "kitty";
	if (archive_bl)
	{
		file_archiving(name, name, ".conf");
	}
	if (pkginstall_bl)
	{
		/* install kitty package
		 * the kitty terminal is most likely already installed on your system */
		install_package(parent_d, name);
	}
	/* export kitty config */
	file_exporting(name, "current-theme", ".conf");
	file_exporting(name, name, ".conf");
	make_dir(name);
}

void MPVF(bool archive_bl, bool pkginstall_bl)
{
	char *name = "mpv";
	if (archive_bl)
	{
		file_archiving(name, name, ".conf");
	}
	if (pkginstall_bl)
	{
		install_package(parent_d, name);
	}
	/* export mpv config with shaders */
	make_dir(name);	/* create directory before copying file */
	file_exporting(name, name, ".conf");
}

void NVIM(bool archive_bl, bool pkginstall_bl)
{
	char *name = "nvim";
	if (archive_bl)
	{
		/* both config files can be found in nvim/ */
		file_archiving(name, "init", ".lua");
		file_archiving(name, "dark-init", ".lua");

		file_archiving("nvim/lua/config", "lazy", ".lua");
		file_archiving(name, "lazy-lock", ".json");
	}
	if (pkginstall_bl)
	{
		/* install neovim (nvim) package 
		 * nvim is most likely already installed  */
		install_package(parent_d, "nvim lazygit");
	}
	make_dir(name);
	/* export nvim config */
	file_exporting(name, "init", ".lua");
}

void ROFI(bool archive_bl, bool pkginstall_bl)
{
	const char *package_name = "rofi";
	const char *file_extention = ".rasi";
	if (archive_bl)
	{
		file_archiving(package_name, package_name, file_extention);
	}
	if (pkginstall_bl)
	{
		install_package(parent_d, package_name); /* install rofi package */
	}
    	/* export btop config */
	make_dir(package_name);
	file_exporting(package_name, package_name, file_extention);
}

void SWAY(bool archive_bl, bool pkginstall_bl)
{
	/* sway window manager doesn't work without wlroots */
	char *name = "sway";
	if (archive_bl)
	{
		file_archiving(name, "config", NULL);
	}

	if (pkginstall_bl)
	{
		/* install sway package -- a system update is strongly recommended */
		install_package(parent_d, "wlroots swaylock sway swayidle");
	}
	/* export sway config */
	file_exporting(name, "config", NULL);
	file_exporting(name, "config-default", NULL);

	make_dir(name);
}

void WAYB(bool archive_bl, bool pkginstall_bl)
{
	char *name = "waybar";
	if (archive_bl)
	{
		/* archive waybar */
		file_archiving(name, "config", ".jsonc");
		file_archiving(name, "style", ".css");
	}
	if (pkginstall_bl)
	{
		install_package(parent_d, name);
	}

	/* export waybar config and appearance */
	file_exporting(name, "style", ".css");
	file_exporting(name, "config", ".jsonc");

	file_exporting(name, "old-style", ".css");
	file_exporting(name, "old-config", ".jsonc");

	make_dir(name);
}

void ZSHH(bool archive_bl, float fversion, bool pkginstall_bl)
{
	if (archive_bl)
	{
		/* archive old zsh config */
		char *archiving_template = "mv ~/.zshrc ~/.zshrc-old-v%.2f";
		int archiving_size = 1 + snprintf(NULL, 0, archiving_template, fversion);
		char *archive_command = malloc((size_t)archiving_size);
		snprintf(archive_command, (size_t)archiving_size, archiving_template, fversion);

		system(archive_command);
		free(archive_command); /* free after use */
		
		const char *new_path = "~/.zshrc-old-v%.2f";
		int path_size = 1 + snprintf(NULL, 0, new_path, fversion);
		char *new_f_path = malloc((size_t)path_size);
		snprintf(new_f_path, (size_t)path_size, new_path, fversion);
		
		/* archive the old zsh config by renaming the previous file */
		rename("~/.zshrc", new_f_path);
		free(new_f_path);
	}
	
	if (pkginstall_bl)
	{
		install_package(parent_d, "zsh");
	}

	const char *config_cmd_template = "cp -f %s/shell/zsh/.zshrc %s/ ";
	size_t mem_needed_cmd = 1 + (size_t)snprintf(NULL, 0, config_cmd_template, inpath, home);
	char *safe_cmd = malloc(mem_needed_cmd);

	snprintf(safe_cmd, (size_t)mem_needed_cmd, config_cmd_template, inpath, home);
	system(safe_cmd);
	free(safe_cmd);

	printf("Refer to the dotfiles configuration menu in order to configure zsh proprely (using zsh for humans)\n");
}


void configure_oh_my_zsh(void)
{
	/* using curl to download a program is not a good practice
	 * but it's the recommended installation method */
	system("if command -v curl >/dev/null 2>&1; then "
			"  sh -c \"$(curl -fsSL https://raw.githubusercontent.com/romkatv/zsh4humans/v5/install)\"; "
			"else "
			"  sh -c \"$(wget -O- https://raw.githubusercontent.com/romkatv/zsh4humans/v5/install)\"; " 
			"fi");
	clearbuffer();
	block(true);
}

void file_archiving(const char *program_config_path, const char *config_file, const char *file_extention)
{
	/* initialize the template for the program config path 
	 * this will represent the full path to the config including the config name
	 * example: /home/admin/.config/nvim */
	const char *program_config_path_template = "%s/%s";

	bool extention_bl = true;
	if (file_extention == NULL)
	{
		extention_bl = false;
	}

	/* calculate the size of all strings */
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path_template, config_path, program_config_path);

	char *program_path = malloc((unsigned)program_path_size);
	if (!program_path) return;
	snprintf(program_path, (unsigned)program_path_size, program_config_path_template, config_path, program_config_path);

	int file_suffix_size = 1 + snprintf(NULL, 0, archiving_file_suffix_template, pver);
	char *file_suffix = malloc((unsigned)file_suffix_size); /* allocate memory to the file_suffix */
	if (!file_suffix) return; /* exit if the malloc call fails */
	snprintf(file_suffix, (unsigned)file_suffix_size, archiving_file_suffix_template, pver);

	/* calculate the config_file size */
	int config_file_size = 1 + snprintf(NULL, 0, "%s", config_file);
	char config_file_temp[config_file_size];
	snprintf(config_file_temp, (size_t)config_file_size, "%s", config_file);

	int destination_file_size = 1;
	if (extention_bl)
	{
		destination_file_size += snprintf(NULL, 0, "%s/%s%s%s", program_path, config_file, file_suffix, file_extention);
	}
	else
	{
		destination_file_size += snprintf(NULL, 0, "%s/%s%s", program_path, config_file, file_suffix);
	}

	char *destination_file = malloc((size_t)destination_file_size);
	if (!destination_file) return;

	char *src_file;
	if (extention_bl)
	{
		snprintf(destination_file, (size_t)destination_file_size, "%s/%s%s%s", program_path, config_file, file_suffix, file_extention);
		free(file_suffix); /* not used by the src_file */

		int src_file_size = 1 + snprintf(NULL, 0, "%s/%s%s", program_path, config_file, file_extention);
		src_file = malloc((size_t)src_file_size);

		if (!src_file) return;
		snprintf(src_file, (size_t)src_file_size, "%s/%s%s", program_path, config_file, file_extention);
	}
	else
	{
		snprintf(destination_file, (size_t)destination_file_size, "%s/%s%s", program_path, config_file, file_suffix);
		free(file_suffix); /* not used by the src_file */

		void *arr[2] = { program_path, NULL };
		size_t src_file_size = string_size(arr, false, "%s/%s", program_path, config_file);
		src_file = malloc(src_file_size);

		if (!src_file) return;
		snprintf(src_file, src_file_size, "%s/%s", program_path, config_file);
	}
	free(program_path);


	/* print the destination and source file paths */
	if (verbose)
	{
		printf("source file path:%s\ndestination file path: %s\n", src_file, destination_file);
	}

	rename(src_file, destination_file);
	free(src_file);
	free(destination_file);
}
