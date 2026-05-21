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

void CAVA(bool archive_bl, float pver, bool pkginstall_bl)
{
	const char *program_config_path = "%s/cava";
	const char *program_name = "cava";
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);
	
	char *program_path = malloc((size_t)program_path_size);
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);
	
	if (archive_bl)
	{
		/* backup cava config */
	    	const char *out_config_name = "%s/config-oldv%.2f";
	    	const char *in_config_path = "%s/%s/config";
	
	    	int mem_out_size = 1 + snprintf(NULL, 0, out_config_name, program_path, pver);
	    	int mem_path_size = 1 + snprintf(NULL, 0, in_config_path, program_path);
	    	char *out_config_temp = malloc((size_t)mem_out_size);
	    	char *config_path_temp = malloc((size_t)mem_path_size);
	
	    	snprintf(out_config_temp, (size_t)mem_out_size, program_path, pver);
	
	    	strcpy(out_config_temp, program_path);
	    	strcat(out_config_temp, out_config_name);
	
	    	rename(config_path_temp, out_config_temp);
	    	free(out_config_temp);
	    	free(config_path_temp);
	}
	
	if (pkginstall_bl)
	{
	    	install_package(parent, (char*)program_name); /* install cava package */
	}
	
	/* export cava config */
	const char *dir_cmd = "mkdir -p %s ; cp -f %s/%s/config %s/ ";
	int mem_needed_cmd = 1 + snprintf(NULL, 0, dir_cmd, program_path, inpath, program_path, program_path);
	
	char safe_cmd[mem_needed_cmd];
	snprintf(safe_cmd, (size_t)mem_needed_cmd, dir_cmd, program_path, inpath, program_path, program_path);
	
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
    	snprintf(cmd, 384,
			"mkdir -p ~/.config/gtklock/assets ; "
			"cp -f %s/gtklock/style.css ~/.config/gtklock ; "
			"cp -f %s/gtklock/lockscreen.jpg ~/.config/gtklock/assets", inpath, inpath);
    	system(cmd);
	free(program_path);
}

void HYPR(bool archive_bl, bool pkginstall_bl)
{
	const char *program_config_path = "%s/hypr";
	int temp_path_size = 1 + snprintf(NULL, 0, program_config_path, inpath);
	int program_path_size = 1 + snprintf(NULL, 0, program_config_path, config_path);

	char *temp_path = malloc((size_t)temp_path_size);
	snprintf(temp_path, (size_t)temp_path_size, program_config_path, inpath);

	char *program_path = malloc((size_t)program_path_size);
	snprintf(program_path, (size_t)program_path_size, program_config_path, config_path);

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
		for (int i = 0; i < 5; i++)
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
	int mem_needed = 1 + snprintf(NULL, 0,
			"mkdir -p %s/assets ; "
			"cp -f %s/hypr/assets/lockscreen.png %s/assets/ ; "
			"cp -f %s/hypr/hyprland.conf %s ; "
			"cp -f %s/hypr/hypridle.conf %s ; "
			"cp -f %s/hypr/hyprlock.conf %s ; "
			"cp -f %s/hypr/hyprpaper.conf %s",
			program_path, inpath, program_path, inpath, program_path, inpath, program_path, inpath, program_path, inpath, program_path);

	char *cmd = malloc((size_t)mem_needed); /* allocate just enough memory for the buffer size */
	snprintf(cmd, (size_t)mem_needed,
			"mkdir -p %s/assets ; "
			"cp -f %s/assets/lockscreen.png %s/assets/ ; "
			"cp -f %s/hyprland.conf %s ; "
			"cp -f %s/hypridle.conf %s ; "
			"cp -f %s/hyprlock.conf %s ; "
			"cp -f %s/hyprpaper.conf %s",
			program_path, temp_path, program_path, temp_path, program_path, temp_path, program_path, temp_path, program_path, temp_path, program_path);
	system(cmd);
    	free(cmd);
	free(temp_path);
	free(program_path);
}
void KITT(bool archive_bl, bool pkginstall_bl)
{
	char cmd[256];
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
	snprintf(cmd, sizeof(cmd),
			"mkdir ~/.config/kitty ; "
			"cp -f %s/kitty/current-theme.conf ~/.config/kitty ; "
			"cp -f %s/kitty/kitty.conf ~/.config/kitty", inpath, inpath);
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
	snprintf(cmd, 192,
			"mkdir -p ~/.config/mpv/ ; "
			"cp -f %s/mpv/mpv.conf ~/.config/mpv ", inpath);
	system(cmd);
}

void NVIM(bool archive_bl, bool pkginstall_bl)
{

	char cmd[256];
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
	
	/* export nvim config */
	snprintf(cmd, sizeof(cmd),
			"mkdir -p ~/.config/nvim ; "
			"cp -f %s/nvim/init.lua ~/.config/nvim", inpath);
	system(cmd);
}

void SWAY(bool archive_bl, float pver, bool pkginstall_bl)
{
	/* sway window manager doesn't work without wlroots */
	char cmd[256];
	if (archive_bl)
	{
		snprintf(cmd, 64,
				"mv ~/.config/sway/config ~/.config/sway/config-oldv%.2f ", pver);
		system(cmd);
	}
	if (pkginstall_bl)
	{
		/* install sway package -- a system update is strongly recommended */
		install_package(parent, "wlroots swaylock sway swayidle");
	}
	/* export sway config */
	snprintf(cmd, sizeof(cmd),
			"mkdir -p ~/.config/sway ; "
			"cp -f %s/sway/config ~/.config/sway/ ; "
			"cp -f %s/sway/config-default ~/.config/sway", inpath, inpath);
	system(cmd);
}

void WAYB(bool archive_bl, float pver, bool pkginstall_bl)
{
	const char *path = "~/.config/waybar/";
	char cmd[256];
	if (archive_bl)
	{
		/* archive waybar */
		snprintf(cmd, sizeof(cmd),
				"mv %sconfig.jsonc ~/.config/waybar/config-oldv%.2f.jsonc ; "
				"mv %sstyle.css ~/.config/waybar/style-oldv%.2f.css", path, pver, path, pver);
		system(cmd);
	}
	if (pkginstall_bl)
	{
		install_package(parent, "waybar");
	}
	/* export waybar config and appearance */
	snprintf(cmd, sizeof(cmd),
			"mkdir -p %s ; "
			"cp -f %s/waybar/style.css %s ; "
			"cp -f %s/waybar/config.jsonc %s", path, inpath, path, inpath, path);
	system(cmd);
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

	int destination_file_size = 1 + snprintf(NULL, 0, "%s/%s%s%s", program_path, config_file, file_suffix, file_extention);

	char *destination_file = malloc((size_t)destination_file_size);
	if (!destination_file) return;
	snprintf(destination_file, (size_t)destination_file_size, "%s/%s%s%s", program_path, config_file, file_suffix, file_extention);
	free(file_suffix); /* not used by the src_file */

	int src_file_size = 1 + snprintf(NULL, 0, "%s/%s%s", program_path, config_file, file_extention);
	char *src_file = malloc((size_t)src_file_size);
	if (!src_file) return;
	snprintf(src_file, (size_t)src_file_size, "%s/%s%s", program_path, config_file, file_extention);

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
