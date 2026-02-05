#include "dotfileshead.h"

void clear()
{
    printf("\033[2J\033[H");
}
//char ARCHIVE;
//char PKGINSTALL;
//
int main()
{
    int cust_conf_inst_opt;

    struct timespec install_timer;

    do
    {
    	char* temp_conf_installed = NULL;

    	scanf(" %i", &cust_conf_inst_opt);

    	switch (cust_conf_inst_opt)
    	{
    	    case 1:
    	        temp_conf_installed = (char*)(TEXT_C_BASH);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);

    		goto installmessage;
    		case 2:
    	        temp_conf_installed = (char*)(TEXT_C_BTOP);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    		case 3:
    	        temp_conf_installed = (char*)(TEXT_C_CAVA);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    	    
    		goto installmessage;
    		case 4:
    	        temp_conf_installed = (char*)(TEXT_C_FAST);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    
    		goto installmessage;
    		case 5:
    	        temp_conf_installed = (char*)(TEXT_C_FUZZ);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);

    		goto installmessage;
    		case 6:
    	        temp_conf_installed = (char*)(TEXT_C_GTKL);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    		case 7:
    	        temp_conf_installed = (char*)(TEXT_C_HYPR);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    		case 8:
    	        temp_conf_installed = (char*)(TEXT_C_KITT);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    		case 9:
    	        temp_conf_installed = (char*)(TEXT_C_MPVF);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    		case 10:
    	        temp_conf_installed = (char*)(TEXT_C_NVIM);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);

    		goto installmessage;
    		case 11:
    	        temp_conf_installed = (char*)(TEXT_C_SWAY);
    	        printf("\nInstalling %s \n", temp_conf_installed);

    	        printf(UDRL_S"\nInstalled %s successfully.\n"STYLE_END, temp_conf_installed);
    		    	
    		goto installmessage;
    		case 12:
    	        temp_conf_installed = (char*)(TEXT_C_WAYB);
    	        printf("\nInstalling %s \n", temp_conf_installed);

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

    	    install_timer.tv_sec = 5;
    	    install_timer.tv_nsec = 000000000L;
  
    	    nanosleep(&install_timer, NULL);
    return 0;
}
