/*

  CURHELLO.C
  ==========
  (c) Copyright Paul Griffiths 1999
  Email: mail@paulgriffiths.net

  "Hello, world!", ncurses style.

*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>


int main(void) {

    WINDOW * mainwin;
    int ch;
    
    /*  Initialize ncurses  */

    if ( (mainwin = initscr()) == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
    }

    raw();
    noecho();
    keypad(stdscr, TRUE);

    printw("Type any character to see it in bold\n");
    while(1)
    {
        ch = getch();

        if(ch == KEY_F(1))
        {
            break;
        }
        else
        {
            attrset(A_BOLD);
            printw("%c", ch);
            attroff(A_BOLD);
        }
        refresh();
    }


    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}