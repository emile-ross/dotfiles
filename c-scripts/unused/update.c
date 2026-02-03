#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BOLD_S	"\e[1m" // defines BOLD_S as a keyword to make text bold
#define UDRL_S	"\e[4m" // defines BOLD_S as a keyword to make text bold
#define STYLE_END   	"\e[m" // resets the styling

float* update() 
{
    char *USERNAME = getenv("HOME");

    // error message if username can't be fetched 
    if (USERNAME == NULL) 
    {
        printf(BOLD_S UDRL_S"\nCan't find home directory\n"STYLE_END);
        return NULL;
    }

    // create path to config
    char HYPRPATH[256];
    snprintf(HYPRPATH, sizeof(HYPRPATH), 
	    "%s/.config/hypr/hyprland.conf", USERNAME);

    // open the file with HYPRPATH
    FILE *file = fopen(HYPRPATH, "r");
    
    // error checking 
    if (file == NULL) 
    {
	printf(BOLD_S UDRL_S"\nNo such file or directory\n"STYLE_END);
	// returns null if the file can't be opened/found
        return NULL;
    }
    static float VAWSM[32] = {0};

    char line[256];
    while (fgets(line, sizeof(line), file)) 
    {
        if (sscanf(line, "# AWSMVERSION: %31f[0-9.]", VAWSM) == 1) 
		{
            //printf("VAWSM: %s\n", VAWSM); // for troubleshooting purposes
            fclose(file);
            return VAWSM;
        }
    }

    fclose(file);
    return 0;
}

int main() 
{

    // check if the current version of dotfiles is correct
    float *version = update();
    char ACCURATEV;
    printf("\nYour current version is %.1f", *version);
    printf("\nDoes this seem correct? (Y/n)\n");
    scanf("%c", ACCURATEV);
    if (ACCURATEV == 'Y' || ACCURATEV == 'y')
    {
        char cmd[256];
        snprintf(cmd, sizeof(cmd),
        		"git clone https://github.com/imawsumm/dotfiles && " // download the repo
        		"gcc dotfiles/c-scripts/local-update.c -o dotfiles/lupdate && " // compile the update script
        		"./dotfiles/lupdate && ");
	system(cmd);
    	// add a prompt to ask if the user wants to remove the repo
    	char RM_REP;
	printf("\nWould you like to remove this repo? (Y/n)\n");
	scanf("%c", RM_REP);
	if (RM_REP == 'Y' || RM_REP == 'y')
	{
		system("rm -rf dotfiles/");
	}
	else
	{
		printf("\nDeletion skipped\n");
	}
    }
    else
    {
	    printf("\nUpdate canceled by user\n");
	    return 1;
    }
    printf(BOLD_S"\nUpdate completed successfully.\n"STYLE_END);
    printf("Make sure you check out the setup.c script for a future update!\n");
    return 0;
}
