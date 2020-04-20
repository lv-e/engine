#pragma once
#ifdef __cplusplus
extern "C" {
#endif

// 8/16/32bits Integers definitions
#if !defined(LV_PRIMITIVES)
#define LV_PRIMITIVES

typedef signed char int8_t;
typedef short int   int16_t;
typedef int         int32_t;

typedef unsigned char       uint8_t;
typedef unsigned short int  uint16_t;
typedef unsigned int        uint32_t;

#endif

#if !defined(DRIVER_SCREEN_WIDTH)
#define DRIVER_SCREEN_WIDTH ((const uint32_t) 220)
#endif

#if !defined(DRIVER_SCREEN_HEIGHT)
#define DRIVER_SCREEN_HEIGHT ((const uint32_t) 176)
#endif

#define SCREEN_SIZE (const LVSize) {DRIVER_SCREEN_WIDTH, DRIVER_SCREEN_HEIGHT}
#define SCREEN_PIXELS (uint32_t) DRIVER_SCREEN_WIDTH * DRIVER_SCREEN_HEIGHT
#define SCREEN_BUFFER_SIZE (uint32_t) SCREEN_PIXELS/2

#ifdef __cplusplus
}
#endif