#include "lv-engine/engine.h"

#ifdef LV_USE_STDIO
#include <stdio.h>
#endif

struct Lv lv;
void ui_drawPixel(LVPoint point, LVColor color);

int lvInit(){
    
    lv.version = makeVersion(1, 2, 0, 96);
    lv.system  = makeSystem();

    lv.ui.drawPixel = &ui_drawPixel;
    
#ifdef LV_USE_STDIO
    printf("lv engine version %d.%d.%d\n", lv.version.major, lv.version.minor, lv.version.path);
    printf("frame buffer size is %.1fkb\n", sizeof(lv.ui.screenBuffer) / 2.0 / 1024.0);
#endif

    return 0;
}

void ui_drawPixel(LVPoint point, LVColor color){
    
    int duo = (point.y * DRIVER_SCREEN_WIDTH + point.x) / 2;
 
    if (point.x % 2 == 0)  {
        lv.ui.screenBuffer[duo].a = color.value;
    } else {
        lv.ui.screenBuffer[duo].b = color.value;
    }
}