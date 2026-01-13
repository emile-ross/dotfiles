#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

float pver = 0.0f;
char HYPRI;
void BTOP(char ARCHIVE);
void CAVA(char ARCHIVE);
void FAST(char ARCHIVE);
void FUZZ(char ARCHIVE);
void GTKL(char ARCHIVE);
void HYPR(char ARCHIVE);
void KITT(char ARCHIVE);
void NVIM(char ARCHIVE);
void WAYB(char ARCHIVE);

void view_item() 
{
    printw("\nInstalling...\n");
    refresh();
    getch();
}

void add_item() 
{
    printw("\nAdding item...\n");
    refresh();
    getch(); // Wait for user input
}
void delete_item() 
{
    printw("\nDeleting item...\n");
    refresh();
    getch(); // Wait for user input
}

int main() 
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    const char *menu[] = 
    {
        "View Item",
        "Add Item",
        "Delete Item",
        "Exit"
    };
    int n_options = sizeof(menu) / sizeof(menu[0]);
    int highlight = 0;
    int choice;

    while (1) 
    {
        clear();
        for (int i = 0; i < n_options; ++i) 
        {
            if (i == highlight) 
                attron(A_REVERSE);
            mvprintw(i + 1, 1, menu[i]);
            if (i == highlight) 
                attroff(A_REVERSE);
        }
        refresh();
        choice = getch();

        switch (choice) 
        {
            case KEY_UP:
                highlight = (highlight == 0) ? n_options - 1 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == n_options - 1) ? 0 : highlight + 1;
                break;
            case 10: // Enter key
                if (highlight == 0) 
                {
                    view_item(); // Action for "View Item"
                } 
                else if (highlight == 1) 
                {
			system("fastfetch");
                } 
                else if (highlight == 2) 
                {
                    delete_item(); // Action for "Delete Item"
                } 
                else if (highlight == 3) 
                {
                    endwin();
                    return 0; // Exit
                }
                break;
        }
    }

    endwin();
    return 0;
}
