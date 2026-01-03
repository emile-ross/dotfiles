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
            p += 12;
            while (isspace((unsigned char)*p)) p++;

            p[strcspn(p, "\r\n")] = 0; // strip newline
            strncpy(VAWSM, p, sizeof(VAWSM) - 1);
            break;
        }
    }
    fclose(f);

    system("cd ~ && git clone https://github.com/imawsumm/dotfiles && cd dotfiles/c-scripts");
    system("gcc local-update.c -o lupdate && ./lupdate");
  
  return 0;
}
