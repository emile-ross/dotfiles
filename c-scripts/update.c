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
        // only check in comments 
        if (*p != '#')
            continue;
        p++; // skip anything after the #
        while (isspace((unsigned char)*p)) p++;
        if (strncmp(p, "AWSMVERSION:", 12) == 0) 
        {
            p += 12;
            while (isspace((unsigned char)*p)) p++;
            p[strcspn(p, "\r\n")] = 0;
            strncpy(VAWSM, p, sizeof(VAWSM) - 1);
            break;
        }
    }
    fclose(f);
    if (VAWSM[0]) 
    {
        printf("VAWSM = %s\n", VAWSM);
        // Only execute if version is exactly 1.0 (will be modified in newer versions
        if (strcmp(VAWSM, "1.0") == 0) 
        {
            system("cd ~/dotfiles/hypr && cp hyprland.conf ~/.config/hypr && cp hypridle.conf ~/.config/hypr && cp hyprpaper.conf ~/.config/hypr");
            system("cd ~/dotfiles/nvim && cp init.lua ~/.config/nvim");
            system("cd ~/dotfiles/waybar && cp style.css ~/.config/waybar && cp config.jsonc ~/.config/waybar");
            system("cd ~/dotfiles/fastfetch && cp config.jsonc ~/.config/fastfetch");
        } 
        else 
        {
            printf("Unsupported VAWSM version. No files were copied.\n");
        }
    } else {
        printf("You need to install the dotfiles before updating them.\n");
    }
    return 0;
}
