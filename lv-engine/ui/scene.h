
#pragma once
#include "lvk.h"

// just don't "vtables". thanks.

typedef struct Scene {
    void (*onAwake)(void);
    void (*onEnter)(void);
    void (*onFrame)(void);
    void (*onExit)(void);
} Scene;

extern Scene scenesTable[lvk_scene_count];