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
    getch();
    endwin();

    return 0;
}
