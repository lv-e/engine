
#pragma once

#include "lv-game/lvk.h"
#include "lv-engine/lvtypes.h"
#include "lv-engine/ui/director.h"
#include "lv-engine/ui/scene.h"
#include "lv-engine/ui/display.h"
#include "lv-engine/ui/colors.h"

#include "lv-engine/io/gamepad.h"

// ----- driver promises:

extern "C" {

    #ifdef USE_OCTAPIXELS
    /* 
        will be called every horizontal line of frame buffer on draw
        size of stream = lvk_octaspixels_per_line
    */
    extern void lvDriver_DrawHLine(lv::half line, lv::OctaPixel* stream);
    #else 

    /* 
        will be called every horizontal line of framebuffer on draw
        size of stream = lvk_screen_w
    */
    extern void lvDriver_DrawHLine(lv::half line, lv::octet (&stream)[lvk_display_w]);
    #endif

    #if lvk_gamepads == true
    extern lv::octet lvDriver_CurrentFPS(void);
    #endif

    extern lv::GamePad lvDriver_GamePadState(lv::half player);
}