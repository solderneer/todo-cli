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
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

    refresh();
    topbar_init();
    leftwin_init();

    leftwin_refresh();

    getch();
    topbar_destroy();
    leftwin_destroy();
    endwin();/* End curses mode		  */
    return 0;
}
