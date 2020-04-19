#include "lv-engine/engine.h"
#include <stdio.h>

// this is just a sandbox
void driver_draw_hline(uint32_t line, uint32_t* buffer, uint32_t size){
    
}

int main(){
    
    lvInit();

    printf("Running sandbox w/ lv-engine v%d.%d.%d\n", lv.version.major, lv.version.minor, lv.version.path);
    lv.ui.drawPixel(makePoint(1,0), makeColor(7));
    lv.ui.drawPixel(makePoint(0,0), makeColor(4));
    
    lv.system.update();
    lv.system.draw();

    return 0;
}