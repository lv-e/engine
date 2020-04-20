#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "lv-engine/typedefs.h"

/* LVColor
    is a four bits indexed color 
    so, 16 diferente colors at time */
typedef struct {
    char value:4;
} LVColor;

#define makeColor(C) (LVColor){C}

/* LVRGBColor
    will be a uint16 formated as R5G6B5 */
typedef struct {
    uint8_t r:5;
    uint8_t g:6;
    uint8_t b:5;
} LVRGBColor;

#define makeColorFromRGB(R, G, B) (LVRGBColor) {R >> 3, G >> 2, B >> 3}
#define RGB32FromColor(C) ((uint32_t) (C.r << 19 | C.g << 10 | C.b << 3))

typedef struct {
    unsigned char a:4;
    unsigned char b:4;
} LVDuoPixel;

/* LVRGBColor palette
    is based on PICO-8 amazing 16 color pallete */
static LVRGBColor palette[16] = {

    makeColorFromRGB(0,0,0),
    makeColorFromRGB(29,43,83),
    makeColorFromRGB(126,37,83),
    makeColorFromRGB(0,135,81),

    makeColorFromRGB(171,82,54),
    makeColorFromRGB(95,87,79),
    makeColorFromRGB(194,195,199),
    makeColorFromRGB(255,241,232),

    makeColorFromRGB(255,0,77),
    makeColorFromRGB(255,163,0),
    makeColorFromRGB(255,240,36),
    makeColorFromRGB(0,231,86),

    makeColorFromRGB(41,173,255),
    makeColorFromRGB(131,118,156),
    makeColorFromRGB(255,119,168),
    makeColorFromRGB(255,204,170)
    
};

#ifdef __cplusplus
}
#endif