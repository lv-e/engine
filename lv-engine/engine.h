
#pragma once

#include "lvk.h"
#include "lvtypes.h"
#include "ui/director.h"
#include "ui/scene.h"
#include "ui/display.h"
#include "ui/colors.h"

// ----- driver promises:
extern "C" {
    /* 
        will be called every horizontal line of frame buffer on draw
        size of stream = lvk_octaspixels_per_line
    */
    extern void lvDriver_DrawHLine(lv::half line, lv::OctaPixel* stream);
}