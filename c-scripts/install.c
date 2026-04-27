#include "dotfileshead.h"

void install_menu(void)
{
    clear();
    printf(BOLD_S "%s\n"STYLE_END, opt_one_text );
    printf("\nDo you want to backup your old dotfiles before proceeding? (Y/n)\n");
    clearbuffer();
    
    scanf(" %c", &archive_before_install);
    printf(ANSI_RED BOLD_S"\nWARNING\n"STYLE_END BOLD_S"This will install every config.\n"STYLE_END);
    printf(ITALICS_S"\nIn order to pick the configs you want, you need to use the custom configuration option\n"STYLE_END); // italics might not work on all terminals
    clearbuffer();
    
    printf(BOLD_S"\nProceed with installation (Y/n)\n"STYLE_END); // prompt user for input
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

void install_configs(unsigned int custom_package_install)  // the partial install script (configure which package or configuration to install)
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

	config_name config_install_enum = custom_package_install;

	unsigned int package_name_index = custom_package_install;

	if (package_name_index < n_configs && package_name_index > 0)
	{
	    temp_conf_installed = config_names[package_name_index];
	}
	else
	{
	    error_message(CLI_UNKNOWN_PKG); // probably malicious
	}

    	switch (config_install_enum)
    	{
    	    case bash:
		install_config_message(temp_conf_installed);
		BASH();
		break;
    	    case bpyt:
		install_config_message(temp_conf_installed);
		BPYT(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case btop:
		install_config_message(temp_conf_installed);
		BTOP(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
	    case cava:
		install_config_message(temp_conf_installed);
		CAVA(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case fast:
		install_config_message(temp_conf_installed);
		FAST(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case fuzz:
		install_config_message(temp_conf_installed);
		FUZZ(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case gtkl:
		install_config_message(temp_conf_installed);
		GTKL(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case hypr:
		install_config_message(temp_conf_installed);
		HYPR(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case kitt:
		install_config_message(temp_conf_installed);
		KITT(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case mpvf:
		install_config_message(temp_conf_installed);
		MPVF(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case nvim:
		install_config_message(temp_conf_installed);
		NVIM(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case sway:
		install_config_message(temp_conf_installed);
		SWAY(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case wayb:
		install_config_message(temp_conf_installed);
		WAYB(ARCHIVE_T, pver, PKGINSTALL_T);
		break;
    	    case zshh:
		install_config_message(temp_conf_installed);
		ZSHH(ARCHIVE_T, pver, PKGINSTALL_T);
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
	    printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
	}
	wait_for_timeout(0, 1);
    }
    while (custom_package_install > 0 && (int)custom_package_install < max_menu_opt_n);
}

void full_install(bool ARCHIVE_BL, bool full_install_bl)
{
    if (full_install_bl)
    {
	printf(BOLD_S"\nInstalling every configuration\n"STYLE_END);
	printf(BOLD_S"\nStarting in:\n"STYLE_END);
	
	countdown(3, 1);
	
	if (strcmp(parent, "arch") == 0)
	{
	    check_for_yay();
	}
	// actually install the dotfiles
	full_config_install(ARCHIVE_BL, 0.0, true);
    }
    else
    {
	unsigned int install_pkg_opt;
	do
	{
	    // this is awful
	    // it could all be replaced by a single array with all of the text 
	    // (would be significantly faster, better, more maintainable...)
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


void full_config_install(bool ARCHIVE_BL, float previous_version_t, bool install_packages_t)
{
    // a list of all configs
    // this will execute all configuration entries
    BASH();
    BPYT(ARCHIVE_BL, previous_version_t, install_packages_t);
    BTOP(ARCHIVE_BL, previous_version_t, install_packages_t);
    CAVA(ARCHIVE_BL, previous_version_t, install_packages_t);
    FAST(ARCHIVE_BL, previous_version_t, install_packages_t);
    FUZZ(ARCHIVE_BL, previous_version_t, install_packages_t);
    GTKL(ARCHIVE_BL, previous_version_t, install_packages_t);
    HYPR(ARCHIVE_BL, previous_version_t, install_packages_t);
    KITT(ARCHIVE_BL, previous_version_t, install_packages_t);
    MPVF(ARCHIVE_BL, previous_version_t, install_packages_t);
    NVIM(ARCHIVE_BL, previous_version_t, install_packages_t);
    SWAY(ARCHIVE_BL, previous_version_t, install_packages_t);
    WAYB(ARCHIVE_BL, previous_version_t, install_packages_t);
    ZSHH(ARCHIVE_BL, previous_version_t, install_packages_t);
}
