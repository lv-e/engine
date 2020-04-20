#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "lv-engine/typedefs.h"

/* driver_LvReady 
   will be called by main just when program start 
   after lv struct initialization */
extern void driver_LvReady();

/* driver_gamepad_state
   will be called before every update on a scene */
extern uint32_t driver_GamePadState(uint32_t player);

/* driver_draw_hline 
   will be called every horizontal line of frame buffer on draw*/
extern void driver_DrawHLine(uint32_t line, uint32_t* buffer, uint32_t size);

#ifdef __cplusplus
}
#endif