#include "dotfileshead.h"

void install_menu(void)
{
    clear();
    printf(BOLD_S "%s\n"STYLE_END, opt_one_text );
    printf("\nDo you want to backup your old dotfiles before proceeding? (Y/n)\n");
    clearbuffer();
    
    scanf(" %c", &archive_before_install);
    printf(ANSI_RED BOLD_S"\nWARNING\n"STYLE_END BOLD_S"This will install every config.\n"STYLE_END);
    printf(ITALICS_S"\nIn order to pick the configs you want, you need to use the custom configuration option\n"STYLE_END);
    clearbuffer();
    
    printf(BOLD_S"\nProceed with installation (Y/n)\n"STYLE_END); // prompt user for input
    scanf(" %c", &full_install_opt);
    if (full_install_opt == 'Y' || full_install_opt == 'y')
    {
        full_install(archive_before_install, 'y');
    }
}

void install_config_message(char *text)
{
    printf("\nInstalling %s \n", text);
}

void install_configs(int custom_package_install)  // the partial install script (configure which package or configuration to install)
{
    do
    {
	bool install_success = true;
	float pver = 0.0f; // assumes the user doesn't have the dotfiles
    	char* temp_conf_installed = NULL;

	clearbuffer();
	printf("Do you want to archive your old config?"BOLD_S"(Y/n)\n"STYLE_END);
	char ARCHIVE_T;
	scanf(" %c", &ARCHIVE_T);

	clearbuffer();
	printf("Do you want to install the package "BOLD_S"(Y/n)\n"STYLE_END);
	char PKGINSTALL_T;
	scanf(" %c", &PKGINSTALL_T);

    	switch (custom_package_install)
    	{
    	    case 1:
    	        temp_conf_installed = (char*)(TEXT_C_BASH);

		install_config_message(temp_conf_installed);
		BASH();
		clear();
		break;
    	    case 2:
    	        temp_conf_installed = (char*)(TEXT_C_BPYT);

		install_config_message(temp_conf_installed);
		BPYT(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 3:
    	        temp_conf_installed = (char*)(TEXT_C_BTOP);

		install_config_message(temp_conf_installed);
		BTOP(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
	    case 4:
    	        temp_conf_installed = (char*)(TEXT_C_CAVA);

		install_config_message(temp_conf_installed);
		CAVA(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 5:
    	        temp_conf_installed = (char*)(TEXT_C_FAST);

		install_config_message(temp_conf_installed);
		FAST(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 6:
    	        temp_conf_installed = (char*)(TEXT_C_FUZZ);

		install_config_message(temp_conf_installed);
		FUZZ(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 7:
    	        temp_conf_installed = (char*)(TEXT_C_GTKL);

		install_config_message(temp_conf_installed);
		GTKL(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 8:
    	        temp_conf_installed = (char*)(TEXT_C_HYPR);

		install_config_message(temp_conf_installed);
		HYPR(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 9:
    	        temp_conf_installed = (char*)(TEXT_C_KITT);

		install_config_message(temp_conf_installed);
		KITT(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 10:
    	        temp_conf_installed = (char*)(TEXT_C_MPVF);

		install_config_message(temp_conf_installed);
		MPVF(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 11:
    	        temp_conf_installed = (char*)(TEXT_C_NVIM);

		install_config_message(temp_conf_installed);
		NVIM(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 12:
    	        temp_conf_installed = (char*)(TEXT_C_SWAY);

		install_config_message(temp_conf_installed);
		SWAY(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 13:
    	        temp_conf_installed = (char*)(TEXT_C_WAYB);

		install_config_message(temp_conf_installed);
		WAYB(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    case 14:
    	        temp_conf_installed = (char*)(TEXT_C_ZSHH);

		install_config_message(temp_conf_installed);
		ZSHH(ARCHIVE_T, pver, PKGINSTALL_T);
		clear();
		break;
    	    default:
    		printf(ANSI_RED"\nInvalid character\n"STYLE_END);
		install_success = false;
		wait_for_timeout(2, 0);
		break;
    	}
	if (install_success)
	{
	    printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
	}
	wait_for_timeout(0, 1);
    }
    while(custom_package_install > 0 && custom_package_install < max_menu_opt_n);
}

void full_install(char install_ARCHIVE, char full_install_opt)
{
    if (full_install_opt == 'Y' || full_install_opt == 'y')
    {
	printf(BOLD_S"\nInstalling every configuration\n"STYLE_END);
	printf(BOLD_S"\nStarting in:\n"STYLE_END);
	
	countdown(3, 1);
	
	if (strcmp(parent, "arch") == 0)
	{
	    check_for_yay();
	}
	// actually install the dotfiles
	full_config_install(install_ARCHIVE, 0.0, 'Y');
    }
    else
    {
	int install_pkg_opt;
	do
	{
	    printf("\n[1] Install %s ", TEXT_C_BASH);
	    printf("\n[2] Install %s ", TEXT_C_BPYT);
	    printf("\n[3] Install %s ", TEXT_C_BTOP);
	    printf("\n[4] Install %s ", TEXT_C_CAVA);
	    printf("\n[5] Install %s ", TEXT_C_FAST);
	    printf("\n[6] Install %s ", TEXT_C_FUZZ);
	    printf("\n[7] Install %s ", TEXT_C_GTKL);
	    printf("\n[8] Install %s ", TEXT_C_HYPR);
	    printf("\n[9] Install %s ", TEXT_C_KITT);
	    printf("\n[10] Install %s ", TEXT_C_MPVF);
	    printf("\n[11] Install %s ", TEXT_C_NVIM);
	    printf("\n[12] Install %s ", TEXT_C_SWAY);
	    printf("\n[13] Install %s ", TEXT_C_WAYB);
	    printf("\n[14] Install %s ", TEXT_C_ZSHH);
	    
	    clearbuffer();
	    scanf(" %d", &install_pkg_opt);
	    install_configs(install_pkg_opt);
	}
	while (install_pkg_opt > 0);
    }
    printf(BOLD_S"\nInstallation completed!\n"STYLE_END);
}


void full_config_install(char choice_ARCHIVE_opt, float previous_version_t, char install_packages_t)
{
	// a list of all configs
	// this will execute all configuration entries
    BASH();
    BPYT(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    BTOP(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    CAVA(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    FAST(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    FUZZ(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    GTKL(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    HYPR(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    KITT(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    MPVF(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    NVIM(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    SWAY(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    WAYB(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
    ZSHH(choice_ARCHIVE_opt, previous_version_t, install_packages_t);
}
