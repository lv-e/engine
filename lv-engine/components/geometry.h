#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "lv-engine/typedefs.h"

typedef struct {
    int16_t x;
    int16_t y;
} LVPoint; 

typedef struct {
    uint16_t width;
    uint16_t height;
} LVSize;

LVPoint makePoint(int16_t x, int16_t y);
LVSize makeSize(uint16_t width, uint16_t height);

#ifdef __cplusplus
}
#endif