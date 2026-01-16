#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CMD 512
int main()
{
  system("cd ~/.config/kitty");
  
  FILE *f = fopen("kitty.conf", "r");
  // print the commented lines with fonts to the terminal
  fclose(f);
  return 0;
}
