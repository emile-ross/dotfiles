#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) 
{
    FILE *f = fopen("hyprland.conf", "r");
    if (!f) return 1;
    char line[128]; // down from 512 bytes
    char VAWSM[16] = {0}; // only loads the actual version number

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

    // check if the current version of dotfiles is correct
    char ACCURATEV;
    printf("\nYour current version is %s", VAWSM);
    printf("\nDoes this seem correct? (Y/n)\n");
    scanf("%c", ACCURATEV);
    if (ACCURATEV == 'Y' || ACCURATEV == 'y')
    {
        char cmd[256];
        snprintf(cmd, sizeof(cmd),
       "cd ~ && " 
        "git clone https://github.com/imawsumm/dotfiles && " // download the repo
        "cd dotfiles/c-scripts && "
        "gcc local-update.c -o lupdate && " // compile the update script
        "./lupdate && 
        "cd .. && "
        "cd ..");
    system(cmd);
    // add a prompt to ask if the user wants to remove the repo
    char RM_REP;
            printf("\nWould you like to remove this repo? (Y/n)"\n);
            scanf("%c", RM_REP);
    }
    else
    {
    return 1;
    }
    printf("\nUpdate completed.\n");
  return 0;
}
