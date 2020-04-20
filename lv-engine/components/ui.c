#include "lv-engine/components/ui.h"
#include "lv-engine/engine.h"

void drawPixel(LVPoint point, LVColor color){
    int duo = (point.y * DRIVER_SCREEN_WIDTH + point.x) / 2;
    if (point.x % 2 == 0) lv.ui.screenBuffer[duo].a = color.value;
    else lv.ui.screenBuffer[duo].b = color.value;
}

UI makeUI(){
    UI ui;
    ui.drawPixel = &drawPixel;
    
    LVDuoPixel blank;
    blank.a = 0;
    blank.b = 0;

    for(uint32_t i =0; i < SCREEN_BUFFER_SIZE; i++)
        ui.screenBuffer[i] = blank;
        
    return ui;
}

