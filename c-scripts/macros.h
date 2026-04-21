// text styles
#define BOLD_S  	"\x1B[1m" // defines BOLD_S as a keyword to make text bold
#define UDRL_S  	"\x1B[4m" // UDRL_S starts an underline style (does not work in kitty by default)
#define ITALICS_S 	"\x1B[3m"
#define STRIKE_S 	"\x1B[9m"

// colors
#define ANSI_RED 	"\x1b[31m"
#define ANSI_GREEN 	"\x1b[32m"  // same as LGREEN on many terminals
#define ANSI_LGREEN 	"\x1b[92m"  // same as GREEN on many terminals
#define ANSI_YELLOW 	"\x1b[33m"
#define ANSI_LYELLOW 	"\x1b[93m"
#define ANSI_BLUE    	"\x1b[34m"
#define ANSI_WHITE    	"\x1b[97m"
#define ANSI_GREY    	"\x1b[90m"
#define ANSI_CYAN    	"\x1b[36m"
#define ANSI_LCYAN    	"\x1b[96m"

// reset styling
#define STYLE_END	"\x1B[0m"

// user input macro definitions
// These are the values users must input in order to perform certain actions
#define INPUT_BACK_VALUE 0
#define INPUT_EXIT_VALUE 0

#define KEY_MAIN_MENU_CONFIGURE 3

#define MENU_TEXT_SIZE (128)
#define SHORT_TIMER 2
