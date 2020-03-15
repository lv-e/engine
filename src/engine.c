#include "engine.h"
#include <stdio.h>

struct Lv lv;
void ui_drawPixel(LVPoint point, LVColor color);

int lvInit(){
    
    lv.version = makeVersion(1, 2, 0, 96);
    lv.ui.drawPixel = &ui_drawPixel;
    
    printf("lv engine version %d.%d.%d\n", lv.version.major, lv.version.minor, lv.version.path);
    printf("frame buffer size is %.1fkb\n", sizeof(lv.ui.screenBuffer) / 2.0 / 1024.0);
    
    return 0;
}

void ui_drawPixel(LVPoint point, LVColor color){
    
    int linearLocation = point.y * SCREEN_SIZE.width + point.x;
    int quad = linearLocation / 4;

    LVQuadPixel q = lv.ui.screenBuffer[quad];
    switch (point.x % 4){
        case 0: q.a = color.value; break;
        case 1: q.b = color.value; break;
        case 2: q.c = color.value; break;
        case 3: q.d = color.value; break;
    }

    lv.ui.screenBuffer[quad] = q;
}