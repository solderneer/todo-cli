#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>
#include <vector>

#include "display.h"

void DisplayInit(WINDOW* mainwin)
{
    if((mainwin = initscr()) == NULL)
    {
        fprintf(stderr, "Error initialising ncurses\n");
        exit(EXIT_FAILURE);
    }

    raw();
    noecho();
    keypad(stdscr, TRUE);

}

void DisplayEnd(WINDOW* mainwin)
{
    delwin(mainwin);
    endwin();
    refresh();
}
