#include "dotfileshead.h"

void install_configs(int custom_package_install)  // the partial install script (configure which package or configuration to install)
{
    do
    {
	float pver = 0.0f; // assumes the user doesn't have the dotfiles
    	char* temp_conf_installed = NULL;

	while (getchar() != '\n');  // clear imput buffer 
	printf("Do you want to archive your old config?"BOLD_S"(Y/n)\n"STYLE_END);
	scanf(" %c", &ARCHIVE);

	while (getchar() != '\n');  // clear imput buffer 
	printf("Do you want to install the package "BOLD_S"(Y/n)\n"STYLE_END);
	scanf(" %c", &PKGINSTALL);

    	switch (custom_package_install)
    	{
    	    case 1:
    	        temp_conf_installed = (char*)(TEXT_C_BASH);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		BASH();
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 2:
    	        temp_conf_installed = (char*)(TEXT_C_BTOP);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		BTOP(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 3:
    	        temp_conf_installed = (char*)(TEXT_C_CAVA);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		CAVA(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 4:
    	        temp_conf_installed = (char*)(TEXT_C_FAST);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		FAST(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 5:
    	        temp_conf_installed = (char*)(TEXT_C_FUZZ);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		FUZZ(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 6:
    	        temp_conf_installed = (char*)(TEXT_C_GTKL);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		GTKL(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 7:
    	        temp_conf_installed = (char*)(TEXT_C_HYPR);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		HYPR(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 8:
    	        temp_conf_installed = (char*)(TEXT_C_KITT);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		KITT(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 9:
    	        temp_conf_installed = (char*)(TEXT_C_MPVF);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		MPVF(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 10:
    	        temp_conf_installed = (char*)(TEXT_C_NVIM);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		NVIM(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 11:
    	        temp_conf_installed = (char*)(TEXT_C_SWAY);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		SWAY(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 12:
    	        temp_conf_installed = (char*)(TEXT_C_WAYB);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		WAYB(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 0:
    		goto exit;
    	    exit:
    	        break;
    	    default:
    		    printf(ANSI_RED"\nInvalid character\n"STYLE_END);
		    wait_for_timeout(2, 0);
    	        goto end;

    	    installmessage:
		    break;
    	    end:
		;

    	}
	printf(FASTBLINK_S ANSI_GREEN"Installed %s\n"STYLE_END, temp_conf_installed);
	wait_for_timeout(0, 1);
    }
    while(custom_package_install > 0 && custom_package_install < max_menu_opt_n);
}
