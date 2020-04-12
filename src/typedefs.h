#include <stdint.h>

#if !defined(DRIVER_SCREEN_WIDTH)
#define DRIVER_SCREEN_WIDTH ((const uint32_t) 220)
#endif

#if !defined(DRIVER_SCREEN_HEIGHT)
#define DRIVER_SCREEN_HEIGHT ((const uint32_t) 176)
#endif

#define SCREEN_SIZE (const LVSize) {DRIVER_SCREEN_WIDTH, DRIVER_SCREEN_HEIGHT}
#define SCREEN_PIXELS (uint32_t) DRIVER_SCREEN_WIDTH * DRIVER_SCREEN_HEIGHT
#define SCREEN_BUFFER_SIZE (uint32_t) SCREEN_PIXELS/2

#pragma once

// --- Versioning

typedef struct {
    uint8_t major;
    uint8_t minor;
    uint8_t path;
    uint8_t build;
} Version;

static Version makeVersion(uint8_t major, uint8_t minor, uint8_t path, uint8_t build){
    return (Version) {major, minor, path, build};
}

// --- Colors

/* four pixels of indexed colors */

typedef struct {
    char value:4;
} LVColor;

#define makeColor(C) (LVColor){C}

typedef struct {
    uint8_t r:5;
    uint8_t g:6;
    uint8_t b:5;
} RGBScaledColor;

#define makeColorFromRGB(R, G, B) (RGBScaledColor) {R >> 3, G >> 2, B >> 3}
#define RGB32FromColor(C) ((uint32_t) (C.r << 19 | C.g << 10 | C.b << 3))

typedef struct {
    unsigned char a:4;
    unsigned char b:4;
} LVDuoPixel;

static RGBScaledColor palette[16] = {

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

// --- Geometry

typedef struct {
    int16_t x;
    int16_t y;
} LVPoint; 

static LVPoint makePoint(int16_t x, int16_t y){
    return (LVPoint) {x, y};
}

typedef struct {
    uint16_t width;
    uint16_t height;
} LVSize;

static LVSize makeSize(int16_t width, int16_t height){
    return (LVSize) {width, height};
}

// --- UI 

typedef struct {
    LVDuoPixel screenBuffer[SCREEN_BUFFER_SIZE];
    void (*drawPixel)(LVPoint point, LVColor color);
} UI;

typedef struct {
    void (*update)();
    void (*draw)();
} System;

System makeSystem();
