#ifndef TOPBAR_H
#define TOPBAR_H

typedef enum{ERROR, SUCCESS} error_t;

error_t topbar_init(void);
error_t topbar_destroy(void);
WINDOW* create_newwin(int height, int weidth, int starty, int startx);

#endif /* TOPBAR_H */
