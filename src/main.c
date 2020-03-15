#include "engine.h"
#include <stdio.h>

// this is just a sandbox

int main(){
    lvInit();
    lv.ui.drawPixel(makePoint(1,0), makeColor(7));
    printf("buffer: %d\n", lv.ui.screenBuffer[0].b);
    return 0;
}