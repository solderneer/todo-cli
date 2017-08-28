#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>
#include <vector>

#define version "1.0.0"

int main(void) {

    WINDOW * mainwin;
    int ch;
    int row, column, count;
    std::vector<char> char_array;

    /*  Initialize ncurses  */

    if ( (mainwin = initscr()) == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
    }

    raw();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, row, column);

    attrset(A_STANDOUT);
    printw("todo-cli version %s", version);
    attroff(A_STANDOUT);

    while(1)
    {
        count = 0;
        ch = getch();

        if(ch == 'q')
        {
            break;
        }
        else
        {
            char_array.push_back(ch);
            attrset(A_BOLD | A_BLINK);
            while(count <  char_array.size())
            {
                if((char_array.size()-1)%2 == 0)
                {
                    mvprintw(row/2, column/2 - (char_array.size()-1)/2, "%c", char_array[count]);
                }
                else
                {
                    mvprintw(row/2, column/2 + char_array.size(), "%c", char_array[count]);
                }
                count++;

            }
            attroff(A_BOLD | A_BLINK);
        }
        refresh();
        count++;
    }


    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}
