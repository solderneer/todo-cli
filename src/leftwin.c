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
        wattron(leftwin, A_STANDOUT);
        // wborder(leftwin, '\0', ' ', '\0', '\0', '\0', '\0', '\0', '\0');
        mvwvline(leftwin, 1, (COLS/2-2), '|', (LINES-3));
        wattroff(leftwin, A_STANDOUT);
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
