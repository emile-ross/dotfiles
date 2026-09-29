#include "header.h"

void install_menu(void)
{
	clear();
	printf(BOLD_S "%s\n"STYLE_END, opt_one_text );
	printf("\nDo you want to backup your old dotfiles before proceeding? (Y/n)\n");
	clearbuffer();
	
	scanf(" %c", &archive_before_install);
	printf(ANSI_RED BOLD_S"\nWARNING\n"STYLE_END BOLD_S"This will install every config.\n"STYLE_END);
	printf(ITALICS_S"\nIn order to pick the configs you want, you need to use the custom configuration option\n"STYLE_END); /* italics might not work on all terminals */
	clearbuffer();
	
	printf(BOLD_S"\nProceed with installation (Y/n)\n"STYLE_END); /* prompt user for input */
	scanf(" %c", &full_install_opt);
	
	bool archive_bl = y_n(archive_before_install);
	bool full_install_bl = y_n(full_install_opt);
	if (full_install_bl)
	{
		full_install(archive_bl, true);
	}
	else
	{
		full_install(archive_bl, false);
		printf("Skipping full install\n");
	}
}

void install_config_message(char *text)
{
	printf("\nInstalling %s \n", text);
}

void full_install(bool archive_bl, bool full_install_bl)
{
	float previous_version = 0.0f; /* assumes the user doesn't have the dotfiles */
	if (full_install_bl)
	{
		printf(BOLD_S"\nInstalling every configuration\n"STYLE_END);
		printf(BOLD_S"\nStarting in:\n"STYLE_END);
		
		countdown(3, 1);
		
		if (parent_d == arch_linux)
		{
			check_for_yay();
		}
		/* proceed with the installation of the dotfiles */
		full_config_install(archive_bl, previous_version, true);
	}
	else
	{
		uint8_t install_pkg_opt = 255;
		do
		{
			/* loop through an array of config names in order to display them */
			for (int i = 1; i < n_configs; i++)
			{
				printf("\n[%d] Install %s ", i, config_names[i]);
			}
			/* cast from long to uint8_t is safe since there is already bounds checking
			 * within the get_long() function (we provide UINT8MAX as the upper bound) */
			install_pkg_opt = (uint8_t)get_long(" ", 0, UINT8MAX);
			/* install_configs(install_pkg_opt); TODO add custom packge installation (matching with a switch) */ 
		}
		while (install_pkg_opt > 0);
	}
	printf(BOLD_S"\nInstallation completed!\n"STYLE_END);
}


void full_config_install(bool ARCHIVE_BL, float previous_version_t, bool PKGINSTALL_BL)
{
	/* a list of all configs
	* this will execute all configuration entries */
	/* TODO add all package installs */
}

void check_for_yay(void)
{
	/* check if yay is present */
    	if (system("test -f /sbin/yay") == 0)
    	{
		printf("Yay already installed.\n");
    	}
    	else
    	{
		printf("Yay is not installed, do you want to install it? (Y/n): ");
    
		char YAY = '\0';
        	clearbuffer();
        	scanf(" %c", &YAY); /* asks the user if they wanna install yay (needed) */
		bool install_yay = y_n(YAY); /* convert the Y/n into a bool with the y_n() function */

		if (!install_yay)
		{
			error_message(YAY_INST_U);
			exit(1);
		}
		/* Check if makepkg is installed ( it is needed in order to compile yay ) */
		if (system("command -v makepkg > /dev/null") != 0)
		{
			printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
			exec_cmd(48, "sudo pacman -S --noconfirm base-devel");
		
			/* Check if makepkg is available after installing the base-devel package */
			if (system("command -v makepkg > /dev/null") != 0)
			{
				error_message(MAKEPKG_FAIL);
			}
			else
			{
				printf("Makepkg has been successfully installed!\n");
			}
		}
		else
		{
			printf("Makepkg is already installed.\n");
			exec_cmd(48, "sudo pacman -S --noconfirm base-devel"); /* update base-devel */
		}
		
		char cmd[256];
		snprintf(cmd, sizeof(cmd),
				"git clone https://aur.archlinux.org/yay.git ; "	/* download yay from aur */
				"cd yay ; "		
				"makepkg -si ; " /* build package from source */
				"cd ..");		
		system(cmd);
		printf("\nYay is installed, congrats!\n");
	}
}
