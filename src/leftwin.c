#include <curses.h>
#include <stdlib.h>

#include "leftwin.h"
#include "config.h"

// Global Variables
WINDOW* leftwin;
static int singleton = 0;
// Private function declarations

error_t leftwin_init(void)
{
    if(singleton == 0)
    {
        leftwin = newwin(LINES, COLS/2, 1, 0);
        box(leftwin, 0, 0);
        wrefresh(leftwin);

        singleton++;
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

error_t leftwin_destroy(void)
{
    wrefresh(leftwin);
    delwin(leftwin);

    singleton--;
    return SUCCESS;
}
