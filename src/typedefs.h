#include <stdint.h>

#if !defined(DRIVER_SCREEN_WIDTH)
#define DRIVER_SCREEN_WIDTH 110
#endif

#if !defined(DRIVER_SCREEN_HEIGHT)
#define DRIVER_SCREEN_HEIGHT 88
#endif

#define SCREEN_SIZE (LVSize) {DRIVER_SCREEN_WIDTH, DRIVER_SCREEN_HEIGHT}
#define SCREEN_PIXELS (uint32_t) DRIVER_SCREEN_WIDTH * DRIVER_SCREEN_HEIGHT
#define SCREEN_BPP 4

#pragma once

// --- Numeric Conversions

inline int int_floor(double x){
  int i = (int)x;
  return i - ( i > x );
}

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
    char a:4;
    char b:4;
    char c:4;
    char d:4;
} LVQuadPixel;

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