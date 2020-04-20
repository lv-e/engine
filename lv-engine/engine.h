#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "lv-engine/driver-protocol.h"

#include "lv-engine/typedefs.h"
#include "lv-engine/components/color.h"
#include "lv-engine/components/geometry.h"
#include "lv-engine/components/system.h"
#include "lv-engine/components/ui.h"
#include "lv-engine/components/version.h"

struct Lv {
    Version version;
    System system;
    UI ui;
};

struct Lv lv;

/* lvInit
   will should be automaticaly be called by 
   main program, on editor's template */
void lvInit();

#ifdef __cplusplus
}
#endif