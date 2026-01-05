#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// for the system() function

int main(void) 
{
    FILE *f = fopen("hyprland.conf", "r");
    if (!f) return 1; // exit with errcode 1 if it fails
    char line[128]; // down from 512 bytes
    char VAWSM[16] = {0}; // only loads the actual version

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
            p += 12;
            while (isspace((unsigned char)*p)) p++;

            p[strcspn(p, "\r\n")] = 0; // strip newline
            strncpy(VAWSM, p, sizeof(VAWSM) - 1);
            break;
        }
    }

    fclose(f);

    if (VAWSM[0]) 
    {
        printf("VAWSM = %s\n", VAWSM);

    } 
    else 
    {
        printf("You need to install the dotfiles before updating them.\n");
    }
    system("cd ~ && git clone https://github.com/imawsumm/dotfiles && cd ~/c-scripts");
    system("gcc update.c -o localupdate && ./localupdate");
printf("\n If you encountered any issues, you can execute the install.c script and use the fixing option.\n");
    return 0;
}
