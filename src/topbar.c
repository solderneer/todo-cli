#include <ncurses.h>
#include "topbar.h"

// Global declarations go here
WINDOW* topbarWin;

// Function definitions
void topbarInit(void)
{
    int term_width, term_height;
    //getmaxyz(stdscr, term_width, term_height);
    topbarWin = newwin(10, COLS, 0, 0);
    box(topbarWin, '+', '-');
    refresh();

}

void topbarResize()
{
    wresize(topbarWin, 3, COLS);
    wrefresh(topbarWin);
}

