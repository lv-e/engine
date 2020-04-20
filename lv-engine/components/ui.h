#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "lv-engine/typedefs.h"
#include "lv-engine/components/color.h"
#include "lv-engine/components/geometry.h"

typedef struct {
    LVDuoPixel screenBuffer[SCREEN_BUFFER_SIZE];
    void (*drawPixel)(LVPoint point, LVColor color);
} UI;

UI makeUI();

#ifdef __cplusplus
}
#endif