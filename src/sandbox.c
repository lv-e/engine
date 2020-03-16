#include "engine.h"
#include <stdio.h>

// this is just a sandbox

void driver_draw_hline(uint32_t line, uint32_t* buffer, uint32_t size){
    printf("draw called for line: %d\n", line);
}

int main(){
    
    lvInit();
    
    lv.ui.drawPixel(makePoint(1,0), makeColor(7));
    lv.ui.drawPixel(makePoint(0,0), makeColor(4));
    
    lv.system.draw();

    return 0;
}