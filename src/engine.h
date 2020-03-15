#include "typedefs.h"

struct UI {
    LVQuadPixel screenBuffer[SCREEN_PIXELS/4];
    void (*drawPixel)(LVPoint point, LVColor color);
};

struct Lv {
    Version version;
    struct UI ui;
};

extern void (*driver_draw)();
extern struct Lv lv;

int lvInit();