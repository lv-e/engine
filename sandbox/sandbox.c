#include "lv-engine/engine.h"
#include <stdio.h>

// this is just a sandbox
void driver_LvReady(){
    printf("- driver_LvReady called\n");
}

uint32_t driver_GamePadState(uint32_t player){
    printf("- driver_GamePadState called\n");
    return 0;
}

void driver_DrawHLine(uint32_t line, uint32_t* buffer, uint32_t size) {
    printf("- driver_DrawHLine(%d) called\n", line);
}

int main(){
    
    lvInit();

    printf("Running sandbox w/ lv-engine v%d.%d.%d\n", lv.version.major, lv.version.minor, lv.version.path);

    lv.ui.drawPixel(makePoint(1,0), makeColor(1));
    lv.ui.drawPixel(makePoint(0,1), makeColor(1));
    lv.ui.drawPixel(makePoint(0,0), makeColor(2));
    lv.ui.drawPixel(makePoint(1,1), makeColor(2));
    
    lv.system.update();
    lv.system.draw();

    return 0;
}