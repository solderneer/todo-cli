#ifndef LEFTWIN_H
#define LEFTWIN_H

#include "config.h"

error_t leftwin_init(void);
error_t leftwin_destroy(void);
error_t leftwin_refresh(void);

// Test
void processTodoList(void);
#endif
