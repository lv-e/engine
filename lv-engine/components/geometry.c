#include "lv-engine/components/geometry.h"
#include "lv-engine/engine.h"

LVPoint makePoint(int16_t x, int16_t y){
    return (LVPoint) {x, y};
}

LVSize makeSize(uint16_t width, uint16_t height){
    return (LVSize) {width, height};
}