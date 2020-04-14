
#include "typedefs.h"

struct Lv {
    Version version;
    System system;
    UI ui;
};

extern struct Lv lv;
int lvInit();

// driver related
extern void driver_draw_hline(uint32_t line, uint32_t* buffer, uint32_t size);
