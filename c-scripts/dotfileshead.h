#define HSETUP_DOT_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOLD_S  	"\e[1m" // defines BOLD_S as a keyword to make text bold
#define UDRL_S  	"\e[4m" // UDRL_S starts an underline style (does not work in kitty by default)
#define ITALICS_S 	"\e[3m"
#define SLOWBLINK_S 	"\e[5m"
#define FASTBLINK_S 	"\e[6m"
#define STRIKE_S 	"\e[9m"


#define ANSI_RED 	"\x1b[31m"
#define ANSI_GREEN 	"\x1b[32m"
#define ANSI_LGREEN 	"\x1b[92m"
#define ANSI_YELLOW 	"\x1b[33m"
#define ANSI_LYELLOW 	"\x1b[93m"
#define ANSI_BLUE    	"\x1b[34m"
#define ANSI_WHITE    	"\x1b[97m"
#define ANSI_GREY    	"\x1b[90m"
#define ANSI_CYAN    	"\x1b[36m"
#define ANSI_LCYAN    	"\x1b[96m"

#define STYLE_END   	"\e[m" // resets the styling


void BASH(char ARCHIVE, float pver, char PKGINSTALL);
void SWAY(char ARCHIVE, float pver, char PKGINSTALL);
void BTOP(char ARCHIVE, float pver, char PKGINSTALL);
void CAVA(char ARCHIVE, float pver, char PKGINSTALL);
void FAST(char ARCHIVE, float pver, char PKGINSTALL);
void FUZZ(char ARCHIVE, float pver, char PKGINSTALL);
void GTKL(char ARCHIVE, float pver, char PKGINSTALL);
void HYPR(char ARCHIVE, float pver, char PKGINSTALL);
void KITT(char ARCHIVE, float pver, char PKGINSTALL);
void MPVF(char ARCHIVE, float pver, char PKGINSTALL);
void NVIM(char ARCHIVE, float pver, char PKGINSTALL);
void WAYB(char ARCHIVE, float pver, char PKGINSTALL);

void full_install(char ARCHIVE, char full_install_opt);
int full_update(char ARCHIVE, float pver);

void install_configs(float pver); // the partial install script (configure which package or configuration to install)

float* update();
