#include <ncurses.h>
#include "topbar.h"

int main()
{
    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);

    height = 3;
    width = 10;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    printw("Press F1 to exit");
    refresh();
    topbarInit();
    getch();
    endwin();/* End curses mode		  */
    return 0;
}
