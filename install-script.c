#include <stdio.h>
#include <stdlib.h>


int main() {
    // Check if yay is installed
    if (system("test -f /sbin/yay") == 0)
{
        printf("Yay is now installed, congrats!\n");
}
      else 
      {
        char YAY;
        printf("Yay is not installed, do you want to install it? (Y/n): ");
        scanf(" %c", &YAY);

        if (YAY == 'Y' || YAY == 'y')
        {
            // Check if makepkg is installed
            if (system("command -v makepkg > /dev/null") != 0)
            {
                printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
                system("sudo pacman -S --noconfirm base-devel");

                // Check if makepkg is available after installing base-devel


              // if makepkg is installed
              // clone + compile + install yay 
              // proceed with script
            }          
        }
  } 
