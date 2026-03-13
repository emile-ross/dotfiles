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
    	        temp_conf_installed = (char*)(TEXT_C_BPYT);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		BPYT(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 3:
    	        temp_conf_installed = (char*)(TEXT_C_BTOP);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		BTOP(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
	    case 4:
    	        temp_conf_installed = (char*)(TEXT_C_CAVA);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		CAVA(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 5:
    	        temp_conf_installed = (char*)(TEXT_C_FAST);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		FAST(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 6:
    	        temp_conf_installed = (char*)(TEXT_C_FUZZ);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		FUZZ(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 7:
    	        temp_conf_installed = (char*)(TEXT_C_GTKL);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		GTKL(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 8:
    	        temp_conf_installed = (char*)(TEXT_C_HYPR);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		HYPR(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 9:
    	        temp_conf_installed = (char*)(TEXT_C_KITT);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		KITT(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 10:
    	        temp_conf_installed = (char*)(TEXT_C_MPVF);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		MPVF(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 11:
    	        temp_conf_installed = (char*)(TEXT_C_NVIM);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		NVIM(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 12:
    	        temp_conf_installed = (char*)(TEXT_C_SWAY);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		SWAY(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    case 13:
    	        temp_conf_installed = (char*)(TEXT_C_WAYB);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		WAYB(ARCHIVE, pver, PKGINSTALL);
		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
		break;
    	    default:
    		    printf(ANSI_RED"\nInvalid character\n"STYLE_END);
		    wait_for_timeout(2, 0);
    	}
	printf(FASTBLINK_S ANSI_GREEN"Installed %s\n"STYLE_END, temp_conf_installed);
	wait_for_timeout(0, 1);
    }
    while(custom_package_install > 0 && custom_package_install < max_menu_opt_n);
}

void full_install(char install_ARCHIVE, char full_install_opt)
{
    if (full_install_opt == 'Y' || full_install_opt == 'y')
    {
	int timerinstall = 3;
	printf(BOLD_S"\nInstalling every configuration\n"STYLE_END);
	printf(BOLD_S"\nStarting in:\n"STYLE_END);
	
	for (int i = 0; i < 3; i++)
	{
	    printf("%d ", timerinstall);
	
	    for (int j = 0; j < 3; j++)
	    {
	        printf(".");
	        fflush(stdout);
	
		wait_for_timeout(1, 0);
	    }
	    for (int k = 0; k < 1; k++)
	    {
		printf("\n");
		wait_for_timeout(1, 0);
	    }
	    timerinstall--;
	}
	
	if (system("test -f /sbin/yay") == 0)
    	{
    	    printf("Yay already installed, congrats!\n");
    	}
    	else
    	{
    	    printf("Yay is not installed, do you want to install it? (Y/n): ");

    	    char YAY;
	    while (getchar() != '\n');  // clear imput buffer 
	    ;
    	    scanf(" %c", &YAY); // asks the user if they wanna install yay (needed)
    	    if (YAY == 'Y' || YAY == 'y')
    	    {
    	        // Check if makepkg is installed ( it is needed in order to compile yay )
    	        if (system("command -v makepkg > /dev/null") != 0)
    	        {
    	            printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
		    char cmd[128];
		    snprintf(cmd, sizeof(cmd),
			    "sudo pacman -S --noconfirm base-devel");
	    	    system(cmd);
    	            
    	            // Check if makepkg is available after installing the base-devel package
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
    	        }
	        // install yay \/
    	        char cmd[256];
    	        snprintf(cmd, sizeof(cmd),
			"sudo pacman -S --noconfirm base-devel ; "
			"git clone https://aur.archlinux.org/yay.git ; "	// download yay from aur
    	                "cd yay ; "						//
			"makepkg -si ; "					// build package from source
    	                "cd ..");						//
    	        system(cmd);
    	        printf("\nYay is installed, congrats!\n");
    	    }
    	    else
    	    {
	        error_message(5);
	    }
	}
	// actually install the dotfiles
	BASH();
	SWAY(install_ARCHIVE, 0.0, 'Y');
	BTOP(install_ARCHIVE, 0.0, 'Y');
	BPYT(install_ARCHIVE, 0.0, 'Y');
	CAVA(install_ARCHIVE, 0.0, 'Y');
	FAST(install_ARCHIVE, 0.0, 'Y');
	FUZZ(install_ARCHIVE, 0.0, 'Y');
	GTKL(install_ARCHIVE, 0.0, 'Y');
	HYPR(install_ARCHIVE, 0.0, 'Y');
	KITT(install_ARCHIVE, 0.0, 'Y');
	MPVF(install_ARCHIVE, 0.0, 'Y');
	NVIM(install_ARCHIVE, 0.0, 'Y');
	WAYB(install_ARCHIVE, 0.0, 'Y');
	ZSHH(install_ARCHIVE, 0.0, 'Y');
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
	    
	    while (getchar() != '\n');  // clear imput buffer 
	    scanf(" %d", &install_pkg_opt);
	    install_configs(install_pkg_opt);
	}
	while (install_pkg_opt > 0);
    }
    printf(BOLD_S"\nInstallation completed!\n"STYLE_END);
}
