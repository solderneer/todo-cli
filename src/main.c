#include <ncurses.h>
#include "topbar.h"

int main()
{
    int ch;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    topbarInit();
    while(1)
    {
        int input = getch();
        if(input == KEY_RESIZE)
        {
            //topbarResize();
            printw("boo");
        }
    }
    endwin();

    return 0;
}
