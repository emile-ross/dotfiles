#include "dotfileshead.h"

int full_update(char ARCHIVE, float pver)
{
    check_for_yay();

    int VAWSM = (int)(pver * 100);
    bool install_pkg_yn = false;

    df_version prev_update_version = VAWSM;

    switch (prev_update_version)
    {
	case V_1:
    	    printf("\nUpdating from %f\n", pver);

    	    install_package(parent, "cava fuzzel kitty fastfetch waybar");
    	    // do not break because we are also installing everything below
    	    __attribute__ ((fallthrough));
    	case V_1_2:
    	case V_1_3:
    	    install_package(parent, "hyprpaper btop");
    	    CAVA(ARCHIVE, VAWSM, install_pkg_yn);
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case V_1_4:
    	    BTOP(ARCHIVE, VAWSM, install_pkg_yn);
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case V_2:
    	    install_package(parent, "gtklock");
    	    KITT(ARCHIVE, VAWSM, install_pkg_yn);
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case V_2_1:
    	    install_package(parent, "sway");
    	    WAYB(ARCHIVE, VAWSM, install_pkg_yn);
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case V_2_2:
    	    SWAY(ARCHIVE, VAWSM, install_pkg_yn);
    	    GTKL(ARCHIVE, VAWSM, install_pkg_yn);
    	    install_package(parent, "mpv swaylock");
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case V_2_3:
    	    install_package(parent, "nvim");
    	    NVIM(ARCHIVE, VAWSM, install_pkg_yn);
    	    FUZZ(ARCHIVE, VAWSM, install_pkg_yn);
    	    MPVF(ARCHIVE, VAWSM, install_pkg_yn);
    	    __attribute__ ((fallthrough));
    	    // do not break because we are also installing everything below
    	case V_2_4:
    	    install_package(parent, "hyprland bpytop hyprlock");
    	    BPYT(ARCHIVE, VAWSM, install_pkg_yn);
	    __attribute__ ((fallthrough));
	    // do not break because we are also installing everything below
    	case V_2_5:
    	case V_3:
	    BASH();
	    HYPR(ARCHIVE, VAWSM, install_pkg_yn);
	    ZSHH(ARCHIVE, VAWSM, install_pkg_yn);
	    printf("Update completed!\n");
	    break;

	case STABLE:
	    printf("\nYou are running the latest stableversion.\n");
    	    wait_for_timeout(SHORT_TIMER, 0); // let the user read the message
    	    break;

	case LATEST:
	    printf("You are using the latest versioin, it is ahead of the latest stable release\n");
	    break;

    	default:
    	    error_message(207);
	    break;
    	}

    return 0;
}

float* update(void) 
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
