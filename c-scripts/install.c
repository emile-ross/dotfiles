#include "dotfileshead.h"

void clear()
{
    printf("\033[2J\033[H");
}

void install_configs()  // the partial install script (configure which package or configuration to install)
{
    int cust_conf_inst_opt;
    struct timespec install_timer;

    do
    {
	char ARCHIVE;
	char PKGINSTALL;
	float pver = 0.0f; // assumes the user doesn't have the dotfiles

	printf(BOLD_S" [1] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_BASH);
	printf(BOLD_S" [2] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_SWAY);
	printf(BOLD_S" [3] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_BTOP);
	printf(BOLD_S" [4] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_CAVA);
	printf(BOLD_S" [5] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_FAST);
	printf(BOLD_S" [6] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_FUZZ);
	printf(BOLD_S" [7] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_GTKL);
	printf(BOLD_S" [8] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_HYPR);
	printf(BOLD_S" [9] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_KITT);
	printf(BOLD_S" [10] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_MPVF);
	printf(BOLD_S" [11] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_NVIM);
	printf(BOLD_S" [12] "STYLE_END"Install "BOLD_S"%s\n"STYLE_END, TEXT_C_WAYB);
	printf(BOLD_S"\n [0] Exit \n"STYLE_END);

    	char* temp_conf_installed = NULL;

    	scanf(" %i", &cust_conf_inst_opt);

    	switch (cust_conf_inst_opt)
    	{
    	    case 1:
    	        temp_conf_installed = (char*)(TEXT_C_BASH);

		printf("Do you want to archive your dotfiles "BOLD_S"(Y/n)\n"STYLE_END);
		scanf(" %c", &ARCHIVE);

		printf("Do you want to install the package "BOLD_S"(Y/n)\n"STYLE_END);
		scanf(" %c", &PKGINSTALL);

    	        printf("\nInstalling %s \n", temp_conf_installed);
		BASH(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);

    		goto installmessage;
    	    case 2:
    	        temp_conf_installed = (char*)(TEXT_C_BTOP);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		BTOP(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    	    case 3:
    	        temp_conf_installed = (char*)(TEXT_C_CAVA);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		CAVA(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    	    
    		goto installmessage;
    	    case 4:
    	        temp_conf_installed = (char*)(TEXT_C_FAST);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		FAST(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    
    		goto installmessage;
    	    case 5:
    	        temp_conf_installed = (char*)(TEXT_C_FUZZ);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		FUZZ(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);

    		goto installmessage;
    	    case 6:
    	        temp_conf_installed = (char*)(TEXT_C_GTKL);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		GTKL(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    	    case 7:
    	        temp_conf_installed = (char*)(TEXT_C_HYPR);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		HYPR(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    	    case 8:
    	        temp_conf_installed = (char*)(TEXT_C_KITT);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		KITT(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    	    case 9:
    	        temp_conf_installed = (char*)(TEXT_C_MPVF);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		MPVF(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    	    case 10:
    	        temp_conf_installed = (char*)(TEXT_C_NVIM);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		NVIM(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);

    		goto installmessage;
    	    case 11:
    	        temp_conf_installed = (char*)(TEXT_C_SWAY);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		SWAY(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    	    case 12:
    	        temp_conf_installed = (char*)(TEXT_C_WAYB);
    	        printf("\nInstalling %s \n", temp_conf_installed);
		WAYB(ARCHIVE, pver, PKGINSTALL);

		clear();
    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		
    		goto installmessage;
    	    case 0:
    		
    		goto exit;
    	    exit:
    	        break;
		
    	    default:
    		    printf(ANSI_RED"\nInvalid character\n"STYLE_END);
    	        goto end;

    	    installmessage:
		    printf(FASTBLINK_S ANSI_GREEN"Installed %s\n"STYLE_END, temp_conf_installed);

    	    end:
    	}
    }
    while(cust_conf_inst_opt > 0 && cust_conf_inst_opt < max_menu_opt_n);
}
