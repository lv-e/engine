
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

    /* 
        will be called every horizontal line of framebuffer on draw
        size of stream = lvk_screen_w
    */
    extern void lvDriver_DrawHLine(const lv::half line, const lv::octet (&stream)[lvk_display_w]);

    /* 
        will be called every frame on update
        num. of player = lvk_gamepads
    */
    extern lv::GamePad lvDriver_GamePadState(lv::half player);

    /* 
        when lvk_measuring == true
        will call every frame and then draw the fps side bar
    */
    #if lvk_measuring == true
    extern lv::octet lvDriver_CurrentFPS(void);
    #endif
}