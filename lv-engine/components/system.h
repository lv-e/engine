#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "lv-engine/typedefs.h"

typedef struct {
    void (*update)();
    void (*draw)();
} System;

System makeSystem();

#ifdef __cplusplus
}
#endif