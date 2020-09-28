#pragma once 

#include "lv-engine/lvtypes.h"
#include "lv-game/lvk.h"

namespace lv {

#ifdef USE_OCTAPIXELS    
    /*
    OctaPixel
    is a five bits indexed color, 40 bits into 5 bytes pack
    so, 31 + transparency unique colors at runtime
    indexed will then be mapped to 16bits//24bits RGB
    */

    #pragma pack(1)
    struct OctaPixel{
        unsigned short xa:5; //  0 bit  // 1 byte  ( 8)
        unsigned short xb:5; // 10 bits // 2 bytes (16)
        unsigned short xc:5; // 15 bits // 2 bytes (16)
        unsigned short xd:5; // 20 bits // 3 bytes (24)
        unsigned short xe:5; // 25 bits // 4 bytes (32)
        unsigned short xf:5; // 30 bits // 4 bytes (32)
        unsigned short xg:5; // 35 bits // 5 bytes (40)
        unsigned short xh:5; // 40 bits // 5 bytes (40)

        static OctaPixel zero() {
            static OctaPixel z;
            z.xa = 0; z.xb = 0; z.xc = 0;
            z.xd = 0; z.xe = 0; z.xf = 0;
            z.xg = 0; z.xh = 0;
            return z;
        }

        static OctaPixel withColor(octet c) {
            static OctaPixel z;
            z.xa = c; z.xb = c; z.xc = c;
            z.xd = c; z.xe = c; z.xf = c;
            z.xg = c; z.xh = c;
            return z;
        }
    };
#endif
    
}
