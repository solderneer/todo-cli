#include <ncurses.h>
#include "topbar.h"
#include "leftwin.h"

int main()
{
    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    refresh();
    topbar_init();
    leftwin_init();

    while(1)
    {
       topbar_refresh();
    }

    getch();
    topbar_destroy();
    endwin();/* End curses mode		  */
    return 0;
}
