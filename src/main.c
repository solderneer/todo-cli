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
    start_color();

    refresh();
    topbar_init();

    while(1)
    {
       topbar_refresh();
    }

    getch();
    topbar_destroy();
    endwin();/* End curses mode		  */
    return 0;
}
