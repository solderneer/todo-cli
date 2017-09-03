#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[])
{
    WINDOW *my_win;
    int startx, starty, width, height, row, column, speed;
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);

    height = 4;
    width = 10;
    speed = 2;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    printw("Press F1 to exit");
    refresh();
    my_win = create_newwin(height, width, starty, startx);
    getmaxyx(stdscr, row, column);

    while((ch = getch()) != 'q')
    {
        switch(ch)
        {
            case KEY_LEFT:
                if(startx <= 0)
                    break;
                destroy_win(my_win);
                startx -= speed;
                my_win = create_newwin(height, width, starty, startx);
                break;
            case KEY_RIGHT:
                if((startx+width) == column)
                    break;
                destroy_win(my_win);
                startx += speed;
                my_win = create_newwin(height, width, starty, startx);
                break;
            case KEY_UP:
                if(starty <= 0)
                    break;
                destroy_win(my_win);
                starty -= speed;
                my_win = create_newwin(height, width, starty,startx);
                break;
            case KEY_DOWN:
                if((starty+height) == row)
                    break;
                destroy_win(my_win);
                starty += speed;
                my_win = create_newwin(height, width, starty,startx);
                break;
        }
    }
    endwin();
    return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    wborder(local_win,'|','|','-','-','+','+','+','+');
    wrefresh(local_win);

    return local_win;
}

void destroy_win(WINDOW *local_win)
{
    wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(local_win);
    delwin(local_win);
}
