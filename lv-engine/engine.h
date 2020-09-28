
#pragma once

#include "lv-game/lvk.h"
#include "lv-engine/lvtypes.h"
#include "lv-engine/ui/director.h"
#include "lv-engine/ui/scene.h"
#include "lv-engine/ui/display.h"
#include "lv-engine/ui/colors.h"

// ----- driver promises:

extern "C" {
    /* 
        will be called every horizontal line of frame buffer on draw
        size of stream = lvk_octaspixels_per_line
    */

    #ifdef USE_OCTAPIXELS
    extern void lvDriver_DrawHLine(lv::half line, lv::OctaPixel* stream);
    #else 
    extern void lvDriver_DrawHLine(lv::half line, lv::octet (&stream)[lvk_display_w]);
    #endif
}