#include "dotfileshead.h"

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

void install_configs(unsigned int custom_package_install)  /* the partial install script (configure which package or configuration to install) */
{
	do
	{
		bool install_success = true;
		float pver = 0.0f; /* assumes the user doesn't have the dotfiles */
		char* temp_conf_installed = NULL;
		
		clearbuffer();
		printf("Do you want to archive your old config?"BOLD_S"(Y/n)\n"STYLE_END);
		char ARCHIVE_T;
		scanf(" %c", &ARCHIVE_T);
		bool archive_bl = y_n(ARCHIVE_T);
		
		clearbuffer();
		printf("Do you want to install the package "BOLD_S"(Y/n)\n"STYLE_END);
		char PKGINSTALL_T;
		scanf(" %c", &PKGINSTALL_T);
		bool pkginstall_bl = y_n(PKGINSTALL_T);
		
		config_name config_install_enum = custom_package_install;
		
		unsigned int package_name_index = custom_package_install;
		
		if (package_name_index < n_configs && package_name_index > 0)
		{
			temp_conf_installed = config_names[package_name_index];
		}
		else
		{
			error_message(CLI_UNKNOWN_PKG);
		}
		
		switch (config_install_enum)
		{
		case bash:
			install_config_message(temp_conf_installed);
			BASH();
			break;
		case bpyt:
			install_config_message(temp_conf_installed);
			BPYT(archive_bl, pkginstall_bl);
			break;
		case btop:
			install_config_message(temp_conf_installed);
			BTOP(archive_bl, pkginstall_bl);
			break;
		case cava:
			install_config_message(temp_conf_installed);
			CAVA(archive_bl, pkginstall_bl);
			break;
		case fast:
			install_config_message(temp_conf_installed);
			FAST(archive_bl, pkginstall_bl);
			break;
		case fuzz:
			install_config_message(temp_conf_installed);
			FUZZ(archive_bl, pkginstall_bl);
			break;
		case gtkl:
			install_config_message(temp_conf_installed);
			GTKL(archive_bl, pkginstall_bl);
			break;
		case hypr:
			install_config_message(temp_conf_installed);
			HYPR(archive_bl, pkginstall_bl);
			break;
		case kitt:
			install_config_message(temp_conf_installed);
			KITT(archive_bl, pkginstall_bl);
			break;
		case mpvf:
			install_config_message(temp_conf_installed);
			MPVF(archive_bl, pkginstall_bl);
			break;
		case nvim:
			install_config_message(temp_conf_installed);
			NVIM(archive_bl, pkginstall_bl);
			break;
		case sway:
			install_config_message(temp_conf_installed);
			SWAY(archive_bl, pkginstall_bl);
			break;
		case wayb:
			install_config_message(temp_conf_installed);
			WAYB(archive_bl, pkginstall_bl);
			break;
		case zshh:
			install_config_message(temp_conf_installed);
			ZSHH(archive_bl, pver, pkginstall_bl);
			break;
		default:
			printf(ANSI_RED"\nInvalid character\n"STYLE_END);
			install_success = false;
			wait_for_timeout(SHORT_TIMER, 0);
			break;
		}
		clear();
		if (install_success)
		{
			/* print success message if enabled */
			printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		}

		/* relatively short pause */
		wait_for_timeout(0, LONG_TIMER);
	}
    	while (custom_package_install > 0 && (int)custom_package_install < max_menu_opt_n);
}

void full_install(bool ARCHIVE_BL, bool full_install_bl)
{
	float previous_version = 0.0f; /* assumes the user doesn't have the dotfiles */
	if (full_install_bl)
	{
		printf(BOLD_S"\nInstalling every configuration\n"STYLE_END);
		printf(BOLD_S"\nStarting in:\n"STYLE_END);
		
		countdown(3, 1);
		
		if (strcmp(parent, "arch") == 0)
		{
			check_for_yay();
		}
		/* actually install the dotfiles */
		full_config_install(ARCHIVE_BL, previous_version, true);
	}
	else
	{
		unsigned int install_pkg_opt;
		do
		{
			/* this is awful
			* it could all be replaced by a single array with all of the text 
			* (would be significantly faster, better, more maintainable...) 
			*
			* this has now been fixed by looping through an array of strings */
			for (int i = 1; i < n_configs; i++)
			{
				printf("\n[%d] Install %s ", i, config_names[i]);
			}
			clearbuffer();
			scanf(" %d", &install_pkg_opt);
			install_configs(install_pkg_opt);
		}
		while (install_pkg_opt > 0);
	}
	printf(BOLD_S"\nInstallation completed!\n"STYLE_END);
}


void full_config_install(bool ARCHIVE_BL, float previous_version_t, bool PKGINSTALL_BL)
{
	/* a list of all configs
	* this will execute all configuration entries */
	BASH();
	BPYT(ARCHIVE_BL, PKGINSTALL_BL);
	BTOP(ARCHIVE_BL, PKGINSTALL_BL);
	CAVA(ARCHIVE_BL, PKGINSTALL_BL);
	FAST(ARCHIVE_BL, PKGINSTALL_BL);
	FUZZ(ARCHIVE_BL, PKGINSTALL_BL);
	GTKL(ARCHIVE_BL, PKGINSTALL_BL);
	HYPR(ARCHIVE_BL, PKGINSTALL_BL);
	KITT(ARCHIVE_BL, PKGINSTALL_BL);
	MPVF(ARCHIVE_BL, PKGINSTALL_BL);
	NVIM(ARCHIVE_BL, PKGINSTALL_BL);
	SWAY(ARCHIVE_BL, PKGINSTALL_BL);
	WAYB(ARCHIVE_BL, PKGINSTALL_BL);
	ZSHH(ARCHIVE_BL, previous_version_t, PKGINSTALL_BL);
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
    
		char YAY;
        	clearbuffer();
        	scanf(" %c", &YAY); /* asks the user if they wanna install yay (needed) */

			bool install_yay = y_n(YAY); /* convert the Y/n into a bool with the y_n() function */
        	if (install_yay)
        	{
			/* Check if makepkg is installed ( it is needed in order to compile yay ) */
			if (system("command -v makepkg > /dev/null") != 0)
			{
				printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
				exec_cmd(48, "sudo pacman -S --noconfirm base-devel");
 
				/* Check if makepkg is available after installing the base-devel package */
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
		else
        	{
			error_message(5);
		}
	}
}
