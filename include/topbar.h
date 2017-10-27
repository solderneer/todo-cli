#ifndef TOPBAR_H
#define TOPBAR_H

void topbarInit(void);
WINDOW* create_newwin(int height, int weidth, int starty, int startx);
void destroy_win(WINDOW* local_win);

#endif /* TOPBAR_H */
