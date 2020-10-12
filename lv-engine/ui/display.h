
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

            void refresh();
            octet fps();

            void clear(const octet color = 0);            
            void fillRect(const Region region, const octet color);
            void setPixel(const Point p, const octet color);

        #ifdef USE_OCTAPIXELS
            void blit(Region region, const OctaPixel *const pixels);
        #else
            // blit does alpha, transfer don't
            void blit(const Region region, const octet *const pixels);
            void transfer(const Region region, const octet *const pixels);
        #endif

        private:

        #ifdef USE_OCTAPIXELS
            // # Octas consume a lot of CPU, but less memory
            // for 130px at 5bpp -> 650 bits
            // each octa can carry 8px -> (130 + 8 - 1) / 8 = 17 OctaPixels per line
            // total: 17*5*130 = 11KB of frame buffer
            OctaPixel _framebuffer[lvk_display_h][lvk_octaspixels_per_line];

        #else
            // # 1 byte per pixel can use DMA, so it's faster
            // for 130px square at 8bpp -> 16.9KB
            // each octa can carry 8px -> (650 + 8 - 1) / 8 = 82 OctaPixels per line
            octet _framebuffer[lvk_display_h][lvk_display_w];

        #endif
    };

}