#ifndef TOPBAR_H
#define TOPBAR_H

typedef enum{ERROR, SUCCESS} error_t;

error_t topbar_init(void);
error_t topbar_destroy(void);
error_t topbar_refresh(void);

#endif /* TOPBAR_H */
