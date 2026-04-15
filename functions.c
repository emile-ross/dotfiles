#include "dotfileshead.h"

void clear(void)
{
    // clears the screen
    printf("\033[2J\033[H");
}

void clearbuffer(void)
{
    // clears the imput buffer 
    while (getchar() != '\n');
}

void pre_startup(void)
{
    // gets the current working directory
    snprintf(inpath, sizeof(inpath), "%s", get_initial_path());
    get_os_name();

    if (strcmp(distro, "debian") == 0) 
    {
	//sets debian as the parent distro of (debian)
	snprintf(parent, sizeof(parent),
		"%s", distro);
    }
    else if (strcmp(distro, "arch") == 0) 
    {
	// sets arch as the parent distro of (arch)
	snprintf(parent, sizeof(parent),
		"%s", distro);
    }
    else
    {
	error_message(101);
    }
}

char *get_initial_path(void)
{
    chdir("dotfiles/");

    FILE *fp;
    
    fp = popen("pwd", "r");
    
    if (fp == NULL) 
    {
	error_message(206);
        return NULL;
    }
 
    if (fgets(initial_path, sizeof(initial_path), fp) == NULL)
    {
        pclose(fp);
        return NULL;
    }

    initial_path[strcspn(initial_path, "\n")] = '\0';

    pclose(fp);
    return initial_path;
}

void wait_for_timeout(int timer_quarters, int timer_seconds)
{
    if (timer_quarters < 4) // 4 quarters per second
    {
	time_timer_quarters = timer_quarters * 250000000;   // convert quarters to nanoseconds
	time_timer_seconds = timer_seconds;		    // set seconds
    }
    else
    {
	time_timer_quarters = 0;
	time_timer_seconds = timer_seconds + 1;	// adds 1 second if 4 >= quarters
    }

    install_timer.tv_nsec = time_timer_quarters;
    install_timer.tv_sec = time_timer_seconds;
    nanosleep(&install_timer, NULL);
}


int get_os_name(void)
{
    // open /etc/os-release
    FILE *fp = fopen("/etc/os-release", "r");

    // fallback to /usr/lib if /etc/os-release fails
    if (!fp) fp = fopen("/usr/lib/os-release", "r"); 
    // error checking
    if (!fp) error_message(52);

    char t_line[256];

    while (fgets(t_line, sizeof(t_line), fp)) 
    {
	// store the value after '=' in char val
        char *val = strchr(t_line, '=') + 1;

	// remove trailing newline
        val[strcspn(val, "\"\n")] = '\0'; 

        if (strncmp(t_line, "ID=", 3) == 0) strcpy(distro, val);	    // store the value in char distro
        else if (strncmp(t_line, "ID_LIKE=", 8) == 0) strcpy(parent, val);  // store the value in char parent
    }

    // close file
    fclose(fp);
    return 0;
}

void check_for_yay(void)
{
    // check if yay is present
    if (system("test -f /sbin/yay") == 0)
    {
	printf("Yay already installed.\n");
    }
    else
    {
        printf("Yay is not installed, do you want to install it? (Y/n): ");
    
        char YAY;
        clearbuffer();
        scanf(" %c", &YAY); // asks the user if they wanna install yay (needed)

        if (YAY == 'Y' || YAY == 'y')
        {
            // Check if makepkg is installed ( it is needed in order to compile yay )
            if (system("command -v makepkg > /dev/null") != 0)
            {
		printf("\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n");
		exec_cmd(48, "sudo pacman -S --noconfirm base-devel");
                 
                // Check if makepkg is available after installing the base-devel package
                if (system("command -v makepkg > /dev/null") != 0)
                {
		    error_message(51);
                }
                else
                {
		    printf("Makepkg has been successfully installed!\n");
                }
            }
            else
            {
		printf("Makepkg is already installed.\n");
		exec_cmd(48, "sudo pacman -S --noconfirm base-devel"); // update base-devel
            }
		char cmd[256];
		snprintf(cmd, sizeof(cmd),
			"git clone https://aur.archlinux.org/yay.git ; "	// download yay from aur
			"cd yay ; "						//
			"makepkg -si ; "					// build package from source
			"cd ..");						//
		system(cmd);
		printf("\nYay is installed, congrats!\n");
        }
        else
        {
            error_message(5);
        }
    }
}

void exec_cmd(int buffer_size, char *command_to_execute)
{
    // execute the command stored in command_to_execute
    // using system() while ensuring output doesn't exceed buffer_size
    char command_exec[buffer_size];
    snprintf(command_exec, sizeof(command_exec), "%s", command_to_execute);
    system(command_exec);   // execute command
}

void countdown(int counter, int lines_to_skip)
{
    // total_time is the total time the execution should last 
    // counter will be the variable used in the countdown 

    int total_time = counter;

    for (int i = 0; i < total_time; i++)
    {
        printf("%d ", counter);
    
	// prints a "." to the screen each quarter of a second
        for (int j = 0; j < 3; j++)
        {
            printf(".");
            fflush(stdout);
	    
	    wait_for_timeout(1, 0);
        }

	// prints one newline everytime this is executed
        for (int k = 0; k < lines_to_skip; k++)
        {
	    printf("\n");
        }
	wait_for_timeout(1, 0);
        counter--;
    }
}
