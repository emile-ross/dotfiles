#include "dotfileshead.h"

int full_update(char ARCHIVE, float pver)
{
    int VAWSM = (int)(pver * 100);
    switch (VAWSM)
    {
	case 100:
    	    printf("\nUpdating from %d\n", VAWSM);

    	    install_package(parent, "cava fuzzel kitty fastfetch waybar");
    	    // do not break because we are also installing everything below
    	    __attribute__ ((fallthrough));
    	case 120:
    	case 130:
    	    install_package(parent, "hyprpaper btop");
    	    CAVA(ARCHIVE, VAWSM, 'N');
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case 140:
    	    BTOP(ARCHIVE, VAWSM, 'N');
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case 200:
    	    install_package(parent, "gtklock");
    	    KITT(ARCHIVE, VAWSM, 'N');
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case 210:
    	    install_package(parent, "sway");
    	    BASH();
    	    WAYB(ARCHIVE, VAWSM, 'N');
    	    NVIM(ARCHIVE, VAWSM, 'N');
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case 220:
    	    SWAY('Y', VAWSM, 'N');
    	    GTKL('Y', VAWSM, 'N');
    	    install_package(parent, "mpv swaylock");
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case 230:
    	    install_package(parent, "nvim");
    	    NVIM('Y', VAWSM, 'N');
    	    FUZZ('Y', VAWSM, 'N');
    	    MPVF('Y', VAWSM, 'N');
    	    FAST('Y', VAWSM, 'N');
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case 240:
    	    install_package(parent, "hyprland bpytop hyprlock");
    	    BPYT('Y', VAWSM, 'N');
    	    ZSHH('Y', VAWSM, 'N');
    	    HYPR('Y', VAWSM, 'N');

    	    printf("Update completed!\n");
    	    break;

    	case 250:
    	case 300:
    	    printf("\nYou are running the latest version.\n");
    	    wait_for_timeout(2, 0);
    	    break;

    	default:
    	    error_message(207);
    	    return 1;
    	}

    return 0;
}

float* update() 
{
    char *USERNAME = getenv("HOME");

    // error message if username can't be fetched 
    if (USERNAME == NULL) 
    {
	error_message(204);
        return NULL;
    }

    // create path to config
    char HYPRPATH[64];
    snprintf(HYPRPATH, sizeof(HYPRPATH), 
	    "%s/.config/hypr/hyprland.conf", USERNAME);
	    // set the hyprland path with username

    // open the file with HYPRPATH
    FILE *file = fopen(HYPRPATH, "r");
    
    // return error message when file isn't found
    if (file == NULL) 
    {
	error_message(205);
	// returns null if the file can't be opened/found
        return NULL;
    }
    static float VAWSM[32] = {0};

    char line[384];
    while (fgets(line, sizeof(line), file)) 
    {
        if (sscanf(line, "# AWSMVERSION: %31f[0-9.]", VAWSM) == 1) 
	{
            fclose(file);
            return VAWSM;
        }
    }
    fclose(file);
    return 0;
}
