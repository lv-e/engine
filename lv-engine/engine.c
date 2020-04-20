#include "lv-engine/engine.h"

#ifdef LV_USE_STDIO
#include <stdio.h>
#endif

struct Lv lv;

void lvInit(){
    
    lv.version  = makeVersion(0, 0, 16, 96);
    lv.system   = makeSystem();
    lv.ui       = makeUI();

#ifdef LV_USE_STDIO
    printf("lv engine version %d.%d.%d\n", lv.version.major, lv.version.minor, lv.version.path);
    printf("frame buffer size is %.1fkb\n", sizeof(lv.ui.screenBuffer) / 2.0 / 1024.0);
#endif

    driver_LvReady();
}
