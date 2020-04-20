#include "lv-engine/components/system.h"
#include "lv-engine/engine.h"

void update(){
    driver_GamePadState(0);
}

void draw(){
     
    uint32_t output[DRIVER_SCREEN_WIDTH];
    LVDuoPixel duo;

    int duoIndex; 
    int bufferIndex = 0;
    
    for (uint32_t y = 0; y < DRIVER_SCREEN_HEIGHT; y++, bufferIndex = 0) {
        for (uint32_t x = 0; x < DRIVER_SCREEN_WIDTH; x += 2) {

            duoIndex = (y * DRIVER_SCREEN_WIDTH + x) / 2;
            duo = lv.ui.screenBuffer[duoIndex];

            output[bufferIndex++] = RGB32FromColor(palette[duo.a]);
            output[bufferIndex++] = RGB32FromColor(palette[duo.b]);
        }
        
        driver_DrawHLine(y, (uint32_t*) &output, DRIVER_SCREEN_WIDTH);
    }
}

System makeSystem(){
    System system;
    system.draw = &draw;
    system.update = &update;
    return system;
}