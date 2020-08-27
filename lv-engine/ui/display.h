
#pragma once

#include "lv-game/lvk.h"
#include "lv-engine/lvtypes.h"
#include "lv-engine/ui/colors.h"

#define lvDisplay lv::Display::shared()

namespace lv {

    class Display {
        
        public:

            static Display& shared(){
                static Display instance;
                return instance;
            }

            void clear();
            void refresh();
            
            void fillRect(octet color, octet x, octet y, octet w,  octet h);
            void setPixel(octet color, octet x, octet y);

        private:
            // for 130px at 5bpp -> 650 bits
            // each octa can carry 8px -> (650 + 8 - 1) / 8 = 82 OctaPixels per line
            OctaPixel _framebuffer[lvk_display_h][lvk_octaspixels_per_line];
    };

}