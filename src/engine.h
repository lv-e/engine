#include "typedefs.h"

struct Lv {
    Version version;
    UI ui;
    System system;
};

extern void driver_draw_hline(uint32_t line, uint32_t* buffer, uint32_t size);
extern struct Lv lv;

int lvInit();