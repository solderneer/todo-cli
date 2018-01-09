#include <curses.h>
#include <stdlib.h>
#include <menu.h>
#include <string.h>
#include <math.h>

#include "leftwin.h"
#include "config.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
// Global Variables
WINDOW* leftwin;
ITEM** my_items;
MENU* my_menu;
static int singleton = 0;
int n_choices, i, c;

char* options[] = {
                    "Add new item...",
                    "Choice 1",
                    "Choice 2",
                    "Choice 3",
                    "Choice 4",
                    "Exit",
                    (char* )NULL,
                };
// Private function declarations


error_t leftwin_init(void)
{
    if(singleton == 0)
    {
        leftwin = newwin(LINES, COLS/2, 1, 0);
        keypad(leftwin, TRUE);

        wattron(leftwin, A_STANDOUT);
        mvwvline(leftwin, 1, (COLS/2-2), '|', (LINES-3));
        wattroff(leftwin, A_STANDOUT);

        processTodoList();

        n_choices = ARRAY_SIZE(options);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i)
            my_items[i] = new_item(options[i], NULL);

        my_menu = new_menu((ITEM **)my_items);

        set_menu_win(my_menu, leftwin);
        set_menu_sub(my_menu, derwin(leftwin, LINES, (COLS/2-1), 1, 1));
        set_menu_mark(my_menu, "");

        post_menu(my_menu);
        wrefresh(leftwin);

        singleton++;
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

error_t leftwin_refresh(void)
{
    while((c = wgetch(leftwin)) != KEY_F(1))
    {
        switch(c)
        {
            case KEY_DOWN:
                menu_driver(my_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(my_menu, REQ_UP_ITEM);
                break;
        }

        wrefresh(leftwin);
    }

    return SUCCESS;
}

error_t leftwin_destroy(void)
{
    unpost_menu(my_menu);
    free_menu(my_menu);
    for(i = 0; i < n_choices; ++i)
        free_item(my_items[i]);

    wrefresh(leftwin);
    delwin(leftwin);

    singleton--;
    return SUCCESS;
}

void processTodoList(void)
{
    int i;
    char spacing[1] = " ";

    //printf("%lu", ARRAY_SIZE(options));
    for(i = 0; i < (ARRAY_SIZE(options)-1); i++)
    {
        int sizeofString = strlen(options[i]);
        int centerPadding = ((LINES/2 - 2) - sizeofString)/2;
        int m = 0;

        char* placeholder = (char* )malloc(sizeof(char) * (int)log10((LINES/2 - 2)));

        for(m = 0; m < centerPadding; m++)
        {
            strcat(placeholder, spacing);
        }

        strcat(placeholder, options[i]);
        m = 0;

        for(m = 0; m < centerPadding; m++)
        {
            strcat(placeholder, spacing);
        }

       wprintw(leftwin,"%s", placeholder);
    }
}

