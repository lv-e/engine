#include "engine.h"
#include <stdio.h>

struct Lv lv;
void ui_drawPixel(LVPoint point, LVColor color);

int lvInit(){
    
    lv.version = makeVersion(1, 2, 0, 96);
    lv.system  = makeSystem();

    lv.ui.drawPixel = &ui_drawPixel;
    
    printf("lv engine version %d.%d.%d\n", lv.version.major, lv.version.minor, lv.version.path);
    printf("frame buffer size is %.1fkb\n", sizeof(lv.ui.screenBuffer) / 2.0 / 1024.0);

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