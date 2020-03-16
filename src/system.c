#include "engine.h"
#include <stdio.h>

void draw();
void update();

System makeSystem(){
    System system;
    system.draw = &draw;
    system.update = &update;
    return system;
}

void update(){

}

void draw(){
     
    uint32_t output[DRIVER_SCREEN_WIDTH];
    LVDuoPixel duo;

    int duoIndex; 
    int bufferIndex = 0;
    
    for (uint32_t y = 0; y < 1; y++, bufferIndex = 0) {
        for (uint32_t x = 0; x < DRIVER_SCREEN_WIDTH; x += 2) {

            duoIndex = (y * DRIVER_SCREEN_WIDTH + x) / 2;
            duo = lv.ui.screenBuffer[duoIndex];

            output[bufferIndex++] = RGB32FromColor(palette[duo.a]);
            output[bufferIndex++] = RGB32FromColor(palette[duo.b]);
        }
        
        driver_draw_hline(y, (uint32_t*) &output, DRIVER_SCREEN_WIDTH);
    }
}


