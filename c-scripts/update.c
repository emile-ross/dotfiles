#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    FILE *f = fopen("hyprland.conf", "r");
    if (!f) return 1; // exit with errcode 1 if it fails

  
// buffers
    char line[512]; 
    char VAWSM[512] = {0};
    while (fgets(line, sizeof(line), f))
    {
        char *p = line;
        // Skip leading whitespace
        while (isspace((unsigned char)*p)) p++;
    
        if (strncmp(p, "AWSMVERSION:", 12) == 0) 
        {
            p += 12;
            p[strcspn(p, "\r\n")] = 0;
            strncpy(VAWSM, sizeof(VAWSM));
            break;
        }
    }
    fclose(f);
    if (VAWSM[0])
        printf("VAWSM = %s\n", VAWSM);
      // just prints the version we will work on that
    else
        printf("You need to install the dotfiles before updating them.\n");
    return 0;
}
