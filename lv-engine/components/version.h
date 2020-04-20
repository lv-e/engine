#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "lv-engine/typedefs.h"

typedef struct {
    uint8_t major;
    uint8_t minor;
    uint8_t path;
    uint8_t build;
} Version;

Version makeVersion(uint8_t major, uint8_t minor, uint8_t path, uint8_t build);

#ifdef __cplusplus
}
#endif