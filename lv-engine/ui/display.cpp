#include "lv-engine/ui/display.h"
#include "lv-engine/engine.h"

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

void Display::fillRect(Region region, octet color) {
    for( int i = region.origin.x; i < region.origin.x + region.size.w; i++)
        for( int j = region.origin.y; j < region.origin.y + region.size.h; j++)
            setPixel(Point(i, j), color);
}

void Display::setPixel(Point p, octet color) {

    switch(p.x%8) {
        case 0: _framebuffer[p.y%lvk_display_h][p.x/8].xa = color; return;
        case 1: _framebuffer[p.y%lvk_display_h][p.x/8].xb = color; return;
        case 2: _framebuffer[p.y%lvk_display_h][p.x/8].xc = color; return;
        case 3: _framebuffer[p.y%lvk_display_h][p.x/8].xd = color; return;
        case 4: _framebuffer[p.y%lvk_display_h][p.x/8].xe = color; return;
        case 5: _framebuffer[p.y%lvk_display_h][p.x/8].xf = color; return;
        case 6: _framebuffer[p.y%lvk_display_h][p.x/8].xg = color; return;
        case 7: _framebuffer[p.y%lvk_display_h][p.x/8].xh = color; return;
    }
}

void Display::blit(Region region, OctaPixel *pixels) {
    
    if(region.size.w == 0 || region.size.h == 0) return;
    if(pixels == 0) return;

    half pixelCount = region.size.w * region.size.h;
    half octas = (pixelCount + (8 - 1)) / 8;
    half cursor = 0;
    half buffer;
    half drawn = 0;
    Point p = region.origin;
    half lineStart = region.origin.x;
    half lineEnd = region.origin.x + region.size.w;
    OctaPixel octa;

    do {
        
        octa = *(pixels + cursor);
        buffer = 8;

        do {

            unsigned short color = 4;

            switch((8 - buffer) % 8) {
                case 0: color = octa.xa; break;
                case 1: color = octa.xb; break;
                case 2: color = octa.xc; break;
                case 3: color = octa.xd; break;
                case 4: color = octa.xe; break;
                case 5: color = octa.xf; break;
                case 6: color = octa.xg; break;
                case 7: color = octa.xh; break;
            }

            switch(p.x % 8) {
                case 0: _framebuffer[p.y % lvk_display_h][p.x/8].xa = color; break;
                case 1: _framebuffer[p.y % lvk_display_h][p.x/8].xb = color; break;
                case 2: _framebuffer[p.y % lvk_display_h][p.x/8].xc = color; break;
                case 3: _framebuffer[p.y % lvk_display_h][p.x/8].xd = color; break;
                case 4: _framebuffer[p.y % lvk_display_h][p.x/8].xe = color; break;
                case 5: _framebuffer[p.y % lvk_display_h][p.x/8].xf = color; break;
                case 6: _framebuffer[p.y % lvk_display_h][p.x/8].xg = color; break;
                case 7: _framebuffer[p.y % lvk_display_h][p.x/8].xh = color; break;
            }
            
            if (++drawn < pixelCount){
                if (p.x + 1 == lineEnd) {
                    p.x = lineStart;
                    p.y++;
                } else p.x++;
            } else return;

        } while (--buffer);

    } while( ++cursor < octas);
}