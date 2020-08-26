#include "display.h"
#include "engine.h"

using namespace lv;

void Display::clear() {
    for(half h = 0; h < lvk_display_h; h++) { 
        for(half w = 0; w < lvk_octaspixels_per_line; w++) {
            _framebuffer[h][w] = OctaPixel::zero();
        }
    }
}

void Display::refresh() {
    for(half i = 0; i < lvk_display_h; i++) {
        lvDriver_DrawHLine(i, (lv::OctaPixel*) &_framebuffer[i]);
    }
}

void Display::fillRect(octet color, octet x, octet y, octet w,  octet h) {
    for( int i = x; i < x + w; i++)
        for( int j = y; j < y + h; j++)
            setPixel(color, i, j);
}

void Display::setPixel(octet color, octet x, octet y) {
    switch(x%8) {
        case 0: _framebuffer[y%lvk_display_h][x/8].xa = color; return;
        case 1: _framebuffer[y%lvk_display_h][x/8].xb = color; return;
        case 2: _framebuffer[y%lvk_display_h][x/8].xc = color; return;
        case 3: _framebuffer[y%lvk_display_h][x/8].xd = color; return;
        case 4: _framebuffer[y%lvk_display_h][x/8].xe = color; return;
        case 5: _framebuffer[y%lvk_display_h][x/8].xf = color; return;
        case 6: _framebuffer[y%lvk_display_h][x/8].xg = color; return;
        case 7: _framebuffer[y%lvk_display_h][x/8].xh = color; return;
    }
}