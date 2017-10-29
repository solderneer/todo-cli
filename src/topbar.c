#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "topbar.h"

// Global Variables
WINDOW* topbar;
static int singleton = 0;

// Function Prototypes
char* itoa (int value, char *result, int base);
void get24hTime(char* returnTime);
void getDayDate(char* dayDate);
void calculateSpacing(char* escape);

error_t topbar_init(void)
{
    if(singleton == 0)
    {
        init_pair(1, COLOR_BLACK, COLOR_WHITE);
        topbar = newwin(3, COLS, 0, 0);
        wattrset(topbar, A_STANDOUT);

        char escape[50];
        char currentTime[20];
        char dayDate[20];

        get24hTime(currentTime);
        getDayDate(dayDate);
        calculateSpacing(escape);
        calculateSpacing(escape);

        wprintw(topbar, escape, currentTime,"todocli 2.4.2 ", dayDate);
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

error_t topbar_refresh(void)
{
        char escape[50];
        char currentTime[20];
        char dayDate[20];

        get24hTime(currentTime);
        getDayDate(dayDate);
        calculateSpacing(escape);

        mvwprintw(topbar,0,0, escape, currentTime,"todocli 2.4.2 ", dayDate);
        wrefresh(topbar);

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

void get24hTime(char* returnTime)
{
    // TODO: Haven't implemented check to prevent overflow
    time_t now  = time(NULL);
    strftime(returnTime, 20, "%r", localtime(&now));
}

void getDayDate(char* dayDate)
{
    // TODO: Haven't implemented check to prevent overflow
    time_t now = time(NULL);
    strftime(dayDate, 20, "%a, %b %d", localtime(&now));
}

void calculateSpacing(char* escape)
{
    char* width = (char* )malloc(sizeof(char) * (int)log10((COLS-14)/2));
    itoa(((COLS-14)/2), width, 10);

    memset(&escape[0], 0, sizeof(escape));
    strcat(escape, "%s %");
    strcat(escape, width);
    strcat(escape, "s %");
    strcat(escape, width);
    strcat(escape, "s ");

    free(width);
}
