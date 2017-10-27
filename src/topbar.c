#include <ncurses.h>
#include "topbar.h"

WINDOW* topbar;
static int singleton = 0;

error_t topbar_init(void)
{
    if(singleton == 0)
    {
        init_pair(1, COLOR_BLACK, COLOR_WHITE);
        topbar = newwin(3, COLS, 0, 0);
        wattrset(topbar, A_STANDOUT);
        wprintw(topbar,"11:21                                                                ");
        wrefresh(topbar);

        singleton++;
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

error_t topbar_destroy(void)
{
    wrefresh(topbar);
    delwin(topbar);

    singleton--;
    return SUCCESS;
}






