#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BOLD_S	"\e[1m" // defines BOLD_S as a keyword to make text bold
#define STYLE_END   	"\e[m" // resets the styling
int main(void) 
{
	FILE *f = fopen("hyprland.conf", "r");
	if (!f) return 1;
    	char line[96]; // down from 512 bytes
    	char VAWSM[8] = {0}; // only loads the actual version number
    	
    	while (fgets(line, sizeof(line), f)) 
    	{
    	    	char *p = line;
    	    	
    	    	// skip whitespace
    	    	while (isspace((unsigned char)*p)) p++;
    	    	
    	    	// only check comments
    	    	if (*p != '#')
    	    	    continue;
    	    	
    	    	p++; // skip '#'
    	    	while (isspace((unsigned char)*p)) p++;
    	    	
    	    	if (strncmp(p, "AWSMVERSION:", 12) == 0)
    	    	{
    	    	    	p += 12; // 12 bytes
    	    	    	while (isspace((unsigned char)*p)) p++;
    	    	
    	    	    	p[strcspn(p, "\r\n")] = 0; // strip newline
    	    	    	strncpy(VAWSM, p, sizeof(VAWSM) - 1);
    	    	    	break;
    	    	}
    }
    fclose(f);
							fflush(stdin);
    // check if the current version of dotfiles is correct
    char ACCURATEV;
    printf("\nYour current version is %s", VAWSM);
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
		break;
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
