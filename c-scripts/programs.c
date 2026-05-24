#include "dotfileshead.h"

void BASH(void)
{
	/* replace with ".bashrc" in order to replace the default bash config */
	char BRCNAME[12] = ".bashrc-new"; 

	/* prompt to let the user know the bashrc isn't exported/replaced */
	printf(UDRL_S"\nThe .bashrc file plays a very important role therefore, it was not replaced."STYLE_END);
	printf(UDRL_S"\nYou can find the new .bashrc file under the new name %s\n"STYLE_END, BRCNAME);
	
	/* calculate the sufficient amount of memory to the buffer */
	const char *command_format = "cp -f %s/shell/bash/.bashrc ~/%s";
	int mem_needed = 1 + snprintf(NULL, 0, command_format, inpath, BRCNAME);
	
	char *cmd = malloc((size_t)mem_needed);
	/* execute the command with the according buffer size previously calculated (above) */
	snprintf(cmd, (size_t)mem_needed, command_format, inpath, BRCNAME);
	system(cmd);
	free(cmd);
}

void BPYT(bool archive_bl, bool pkginstall_bl)
{
	char *pkg_name = "bpytop";

	char cmd[192]; /* using malloc is now safer, it avoids truncation */
	if (archive_bl)
	{
		file_archiving(pkg_name, pkg_name, ".conf");
	}

	if (pkginstall_bl)
	{
		install_package(parent, "bpytop"); /* install bpytop package */
	}
	/* export bpytop config */
	snprintf(cmd, sizeof(cmd),
			"mkdir -p %s/bpytop ; "
			"cp -f %s/bpytop/bpytop.conf ~/.config/bpytop", config_path, inpath);
	system(cmd);
}

void BTOP(bool archive_bl, bool pkginstall_bl)
{
	const char *program_config_path = "%s/btop";
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);

	char *program_path = malloc((size_t)program_path_size);

	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);

	char cmd[128];
	if (archive_bl)
	{
		file_archiving("btop", "btop", ".conf");
    	}
    	if (pkginstall_bl)
    	{
		install_package(parent, "btop"); /* install btop package */
    	}
    	/* export btop config */
	snprintf(cmd, sizeof(cmd),
    	    		"mkdir -p %s/btop ; "
    	       		"cp -f %s/btop/btop.conf %s/btop", config_path, inpath, config_path);
    	system(cmd);
	free(program_path);
}

void CAVA(bool archive_bl, bool pkginstall_bl)
{
	const char *program_config_path = "%s/cava";
	const char *program_name = "cava";
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);
	
	char *program_path = malloc((size_t)program_path_size);
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);
	
	if (archive_bl)
	{
		file_archiving("cava", "config", NULL);
	}
	
	if (pkginstall_bl)
	{
	    	install_package(parent, (char*)program_name); /* install cava package */
	}
	
	/* export cava config */
	const char *dir_cmd = "mkdir -p %s ; cp -f %s/%s/config %s/ ";
	int mem_needed_cmd = 1 + snprintf(NULL, 0, dir_cmd, program_path, inpath, "cava", program_path);
	
	char safe_cmd[mem_needed_cmd];
	snprintf(safe_cmd, (size_t)mem_needed_cmd, dir_cmd, program_path, inpath, "cava", program_path);

	if (verbose)
	{
		printf("%s\n", safe_cmd);
	}
	free(program_path);
	system(safe_cmd);
}

void FAST(bool archive_bl, bool pkginstall_bl)
{
	const char *program_config_path = "%s/fastfetch";
	int temp_path_size = 1 + snprintf(NULL, 0, program_config_path, inpath);
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);

	char *temp_path = malloc((size_t)temp_path_size);
	snprintf(temp_path, (size_t)temp_path_size, program_config_path, inpath);

	char *program_path = malloc((size_t)program_path_size);
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);

	char cmd[768];
    	if (archive_bl)
    	{
		file_archiving("fastfetch", "config", ".jsonc");
	}

	if (pkginstall_bl)
    	{
    	    	install_package(parent, "fastfetch"); /* install fastfetch */
    	}
	/* export fastfetch config */
    	snprintf(cmd, sizeof(cmd),
			"rm %s ; "
			"mkdir -p %s/assets ; "
			"cp -f %s/assets/*.png %s/assets/ ; "
			"cp -f %s/config.jsonc %s/ ; "
			"cp -f %s/config.jsonc %s/config-duplicated.jsonc ; "
			"cp -f %s/config-other.jsonc %s/ ; "
			"cp -f %s/config-default.jsonc %s/"
			, program_path, program_path, temp_path, program_path, temp_path, program_path, temp_path, program_path, temp_path, program_path, temp_path, program_path);
    	system(cmd);
	printf("%s \n\n ", cmd);
	free(program_path);
	free(temp_path);
}
void FUZZ(bool archive_bl, bool pkginstall_bl)
{
	const char *program_config_path = "%s/fuzzel";
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);

	char *program_path = malloc((size_t)program_path_size);

	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);

	char cmd[1024];
    	if (archive_bl)
    	{
		file_archiving("fuzzel", "fuzzel", ".ini");
		file_archiving("fuzzel", "fuzzel-duplicated", ".ini");
		file_archiving("fuzzel", "old-fuzzel", ".ini");
	}
	if (pkginstall_bl)
    	{
		/* install fuzzel package */
		install_package(parent, "fuzzel");
	}
	/* export fuzzel appearance */
	int mem_needed_cmd = 1 + snprintf(NULL, 0, 
			"mkdir -p ~/.config/fuzzel ; "
			"cp -f %s/fuzzel/old-fuzzel.ini ~/.config/fuzzel ; "
			"cp -f %s/fuzzel/default-fuzzel.ini ~/.config/fuzzel ; "
			"cp -f ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/custom-edited-fuzzel.ini ; "
			"cp -f %s/fuzzel/fuzzel.ini ~/.config/fuzzel ; "
			"mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-duplicated.ini ; "
			"ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini ", inpath, inpath, inpath);

	snprintf(cmd, (size_t)mem_needed_cmd,
			"mkdir -p ~/.config/fuzzel ; "
			"cp -f %s/fuzzel/old-fuzzel.ini ~/.config/fuzzel ; "
			"cp -f %s/fuzzel/default-fuzzel.ini ~/.config/fuzzel ; "
			"cp -f ~/.config/fuzzel/default-fuzzel.ini ~/.config/fuzzel/custom-edited-fuzzel.ini ; "
			"cp -f %s/fuzzel/fuzzel.ini ~/.config/fuzzel ; "
			"mv ~/.config/fuzzel/fuzzel.ini ~/.config/fuzzel/fuzzel-duplicated.ini ; "
			"ln -sf ~/.config/fuzzel/fuzzel-duplicated.ini ~/.config/fuzzel/fuzzel.ini ", inpath, inpath, inpath);
	system(cmd);  		
	free(program_path);
}
void GTKL(bool archive_bl, bool pkginstall_bl)
{
	const char *program_config_path = "%s/gtklock";
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);
	char *program_path = malloc((size_t)program_path_size);
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);

	char cmd[512];
    	if (archive_bl)
    	{
		file_archiving("gtklock", "style", ".css");
	}
    	if (pkginstall_bl)
    	{
    	    	/* install gtklock package */
    	    	install_package(parent, "gtklock");
    	}
	/* export gtklock config */
    	system("mkdir -p ~/.config/gtklock/assets");

	file_exporting("gtklock", "style", ".css");
	file_exporting("gtklock", "lockscreen", ".jpg");

	free(program_path);
}

void HYPR(bool archive_bl, bool pkginstall_bl)
{
	char *config_file[5] = 
	{
		"hypridle",
		"hyprland",
		"hyprlock",
		"hyprpaper",
		NULL,
	};

	if (archive_bl)
	{
		for (int i = 0; config_file[i] != NULL; i++)
		{
			file_archiving("hypr", config_file[i], ".conf");
		}
	}

	if (pkginstall_bl)
	{
		/* install Hyprland packages */
		install_package(parent, "hyprlock hypridle hyprpaper hyprland");
    	}
	/* export hyprland configs */
	for (int i = 0; config_file[i] != NULL; i++)
	{
		file_exporting("hypr", config_file[i], ".conf");
	}

	char cmd[384];
	snprintf(cmd, sizeof(cmd), "mkdir -p %s/.config/hypr/assets", home);
	system(cmd);

	file_exporting("hypr/assets", "lockscreen", ".png");
}
void KITT(bool archive_bl, bool pkginstall_bl)
{
	if (archive_bl)
	{
		file_archiving("kitty", "kitty", ".conf");
	}
	if (pkginstall_bl)
	{
		/* install kitty package
		 * the kitty terminal is most likely already installed on your system */
		install_package(parent, "kitty");
	}
	/* export kitty config */
	file_exporting("kitty", "current-theme", ".conf");
	file_exporting("kitty", "kitty", ".conf");
	char cmd[32];
	snprintf(cmd, sizeof(cmd), "mkdir ~/.config/kitty");
	system(cmd);
}

void MPVF(bool archive_bl, bool pkginstall_bl)
{
	char cmd[256];
	if (archive_bl)
	{
		file_archiving("mpv", "mpv", ".conf");
	}
	if (pkginstall_bl)
	{
		install_package(parent, "mpv");
	}
	/* export mpv config with shaders */
	system("mkdir -p ~/.config/mpv/"); /* create directory before copying file */
	file_exporting("mpv", "mpv", ".conf");
}

void NVIM(bool archive_bl, bool pkginstall_bl)
{
	if (archive_bl)
	{
		file_archiving("nvim", "init", ".lua");
		file_archiving("nvim/lua/config", "lazy", ".lua");
		file_archiving("nvim", "lazy-lock", ".json");
	}
	if (pkginstall_bl)
	{
		/* install neovim (nvim) package 
		 * nvim is most likely already installed  */
		install_package(parent, "nvim lazygit");
	}
	system("mkdir -p ~/.config/nvim");
	/* export nvim config */
	file_exporting("nvim", "init", ".lua");
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
		install_package(parent, "wlroots swaylock sway swayidle");
	}
	/* export sway config */
	file_exporting(name, "config", NULL);
	file_exporting(name, "config-default", NULL);

	system("mkdir -p ~/.config/sway");
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
		install_package(parent, name);
	}

	/* export waybar config and appearance */
	file_exporting(name, "style", ".css");
	file_exporting(name, "config", ".jsonc");

	system("mkdir -p ~/.config/waybar/");
}

void ZSHH(bool archive_bl, float pver, bool pkginstall_bl)
{
	char cmd[128];
	if (archive_bl)
	{
		/* archive old zsh config */
		char *archiving_template = "mv ~/.zshrc ~/.zshrc-old-v%.2f";
		int archiving_size = snprintf(NULL, 0, archiving_template, pver);
		snprintf(cmd, (size_t)archiving_size, archiving_template, pver);
		system(cmd);
		
		char *new_f_path = NULL;
		const char *new_path = "~/.zshrc-old-v%.2f";
		int path_size = 1 + snprintf(NULL, 0, new_path, pver);
		snprintf(new_f_path, (size_t)path_size, new_path, pver);
		
		/* archive the old zsh config by renaming the previous file */
		rename("~/.zshrc", new_f_path);
	}
	
	if (pkginstall_bl)
	{
		install_package(parent, "zsh");
	}

	const char *copy_config_cmd = "cp -f %s/shell/zsh/.zshrc %s/ ";
	int mem_needed_cmd = 1 + snprintf(NULL, 0, copy_config_cmd, inpath, home);
	char safe_cmd[mem_needed_cmd];
	snprintf(safe_cmd, (size_t)mem_needed_cmd, copy_config_cmd, inpath, home);
	system(safe_cmd);

	printf("Refer to the dotfiles configuration menu in order to configure zsh proprely (using zsh for humans)\n");
}

int install_package(char *pkg_type_distro, char *pkginstallname)
{
	if (strcmp(pkg_type_distro, "arch") == 0)
	{
		int cmd_size = 1 + snprintf(NULL , 0, "yay -S %s", pkginstallname);
		char cmd_arch[cmd_size];
		snprintf(cmd_arch, (size_t)cmd_size,
				"yay -S %s", pkginstallname);
		system(cmd_arch);
	}
	else if (strcmp(pkg_type_distro, "debian") == 0)
	{
		int cmd_size = 1 + snprintf(NULL, 0, "sudo apt install %s", pkginstallname);
		char cmd_deb[cmd_size];
		snprintf(cmd_deb, (size_t)cmd_size,
				"sudo apt install %s", pkginstallname);
		system(cmd_deb);
	}
	else 
	{
		printf("Your distribution is not supported.\n");
		wait_for_timeout(SHORT_TIMER, 1);
	}
	
	return 0;
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

void file_archiving(char *program_name, char *config_file, char *file_extention)
{
	/* initialize the template for the program config path 
	 * this will represent the full path to the config including the config name
	 * example: /home/admin/.config/nvim */
	char *program_config_path = "%s/%s";

	bool extention_bl = true;
	if (file_extention == NULL)
	{
		extention_bl = false;
	}

	/* calculate the size of all strings */
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path, program_name);

	char *program_path = malloc((size_t)program_path_size);
	if (!program_path) return;
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path, program_name);

	int file_suffix_size = 1 + snprintf(NULL, 0, archiving_file_suffix_template, pver);
	char *file_suffix = malloc((size_t)file_suffix_size); /* allocate memory to the file_suffix */
	if (!file_suffix) return; /* exit if the malloc call fails */
	snprintf(file_suffix, (size_t)file_suffix_size, archiving_file_suffix_template, pver);

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

		int src_file_size = 1 + snprintf(NULL, 0, "%s/%s%s", program_path, config_file, file_extention);
		src_file = malloc((size_t)src_file_size);
		if (!src_file) return;
		snprintf(src_file, (size_t)src_file_size, "%s/%s%s", program_path, config_file, file_extention);
	}
	else
	{
		snprintf(destination_file, (size_t)destination_file_size, "%s/%s%s", program_path, config_file, file_suffix);

		int src_file_size = 1 + snprintf(NULL, 0, "%s/%s", program_path, config_file);
		src_file = malloc((size_t)src_file_size);
		if (!src_file) return;
		snprintf(src_file, (size_t)src_file_size, "%s/%s", program_path, config_file);
	}

	free(file_suffix); /* not used by the src_file */

	/* print the destination and source file paths */
	if (verbose)
	{
		printf("source file path:%s\ndestination file path: %s\n", src_file, destination_file);
	}

	rename(src_file, destination_file);
	free(src_file);
	free(destination_file);
	free(program_path);
}

void file_exporting(char *program_name, char *config_name, char *file_extention)
{
	char *dest_file_path_template = "%s/%s/%s";

	int file_path_size = 1;

	int config_file_name_size = 1;


	if (file_extention == NULL)
	{
		config_file_name_size += snprintf(NULL, 0, "%s", config_name);
	}
	else
	{
		config_file_name_size += snprintf(NULL, 0, "%s%s", config_name, file_extention);
	}

	char *config_file_name = malloc((size_t)config_file_name_size);

	if (file_extention == NULL)
	{
		snprintf(config_file_name, (size_t)config_file_name_size, "%s", config_name);
	}
	else
	{
		snprintf(config_file_name, (size_t)config_file_name_size, "%s%s", config_name, file_extention);
	}

	file_path_size += config_file_name_size;
	file_path_size += snprintf(NULL, 0, dest_file_path_template, config_path, program_name, config_name);

	char *dest_file_path = malloc((size_t)file_path_size); /* allocate memory */
	snprintf(dest_file_path, (size_t)file_path_size, dest_file_path_template, config_path, program_name, config_file_name); /* write to memory/buffer */

	char *source_path_template = "%s/%s/%s";
	int source_path_size = 1 + snprintf(NULL, 0, source_path_template, inpath, program_name, config_file_name);

	char *source_path = malloc((size_t)source_path_size);	/* allocate memory */

	snprintf(source_path, (size_t)source_path_size, source_path_template, inpath, program_name, config_file_name);
	free(config_file_name);

	int exporting_cmd_size = 1;

	/* the 2 spaces are intentional, the command expects 2 arguments separated by a space */
	char *exporting_cmd_template = "cp -f %s %s";
	exporting_cmd_size += snprintf(NULL, 0, "%s", exporting_cmd_template); 
	exporting_cmd_size += file_path_size;
	exporting_cmd_size += source_path_size;

	char *exporting_cmd = malloc((size_t)exporting_cmd_size); /* allocate memory */
	snprintf(exporting_cmd, (size_t)exporting_cmd_size, exporting_cmd_template, source_path, dest_file_path);

	if (verbose)
	{
		printf("%s\n", dest_file_path);
		printf("%s\n", source_path);
		printf("%s\n", exporting_cmd);
	}
	
	system(exporting_cmd); /* execute final command */

	free(exporting_cmd);
	free(dest_file_path);
	free(source_path);
}
