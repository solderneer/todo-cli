#include <ncurses.h>
#include "topbar.h"

WINDOW* topbar;
void topbar_init(void)
{
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    topbar = newwin(3, COLS, 0, 0);
    wattrset(topbar, A_STANDOUT);
    wprintw(topbar,"Hello World!");
    wrefresh(topbar);
}

void topbar_destroy(void)
{
    wrefresh(topbar);
    delwin(topbar);
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);
    wrefresh(local_win);

    return local_win;
}




