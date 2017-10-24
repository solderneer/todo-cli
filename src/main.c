#include <ncurses.h>

int main()
{
    int ch;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    printw("Type any character to see it in bold\n");
    refresh();
    getch();
    endwin();

    return 0;
}
