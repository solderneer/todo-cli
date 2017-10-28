#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "topbar.h"

WINDOW* topbar;
static int singleton = 0;

char* itoa (int value, char *result, int base);

error_t topbar_init(void)
{
    if(singleton == 0)
    {
        init_pair(1, COLOR_BLACK, COLOR_WHITE);
        topbar = newwin(3, COLS, 0, 0);
        wattrset(topbar, A_STANDOUT);

        char* width = (char* )malloc(sizeof(char) * (int)log10(COLS/2 - 3));
        char escape[50] = "%s %";
        itoa((COLS/2-3), width, 10);

        strcat(escape, width);
        strcat(escape, "s %");
        strcat(escape, width);
        strcat(escape, "s ");

        wprintw(topbar,escape," "," "," ");
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

char* itoa (int value, char *result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}






