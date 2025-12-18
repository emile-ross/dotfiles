#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    FILE *f = fopen("hyprland.conf", "r");
    if (!f) return 1; // exit with errcode 1 if it fails


// buffers to store strings in memory
    char line[512];
    char VAWSM[512] = {0}; 
    while (fgets(line, sizeof(line), f))
    {
        char *p = line;
        // skip whitespace (spaces / indenting)
        while (isspace((unsigned char)*p)) p++;
        // checks for comments only
        if (*p != '#')
            continue;
        p++;
      // skip '#'
        // Skip whitespace after '#'
        while (isspace((unsigned char)*p)) p++;
        // Match key
        if (strncmp(p, "AWSMVERSION:", 12) == 0) // 12 will need to be modified if the length of the string is modified
        {
            p += 12; // 12 because string is 12 chars
            while (isspace((unsigned char)*p)) p++;
            // skip newline
            p[strcspn(p, "\r\n")] = 0;
            strncpy(VAWSM, p, sizeof(VAWSM) - 1);
            break;
        }
    }
    fclose(f); // won't need it anymore
    if (strlen(VAWSM) > 0)
        printf("VAWSM = %s\n", VAWSM);
      // just prints the version we will work on that
    else
        printf("You need to install the dotfiles before updating them.\n");
    return 0;
}
