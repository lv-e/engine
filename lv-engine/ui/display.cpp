#include "lv-engine/ui/display.h"
#include "lv-engine/engine.h"
#include <cstring>

#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace lv;

void Display::clear() {
#ifdef USE_OCTAPIXELS
    for(half h = 0; h < lvk_display_h; h++) { 
        for(half w = 0; w < lvk_octaspixels_per_line; w++) {
            _framebuffer[h][w] = OctaPixel::zero();
        }
    }
#else 
    memset(&_framebuffer, 0, lvk_display_h * lvk_display_w);
#endif
}

void Display::refresh() {
    for(half i = 0; i < lvk_display_h; i++) {
        #ifdef USE_OCTAPIXELS
        lvDriver_DrawHLine(i, (lv::OctaPixel*) &_framebuffer[i]);
        #else 
        lvDriver_DrawHLine(i, _framebuffer[i]);
        #endif
    }
}

octet Display::fps() {
    return lvDriver_CurrentFPS();
}

void Display::fillRect(Region region, octet color) {
    for( int i = region.origin.x; i < region.origin.x + region.size.w; i++)
        for( int j = region.origin.y; j < region.origin.y + region.size.h; j++)
            setPixel(Point(i, j), color);
}

void Display::setPixel(Point p, octet color) {
#ifdef USE_OCTAPIXELS
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
#else
    if (p.x > 0 && p.x < lvk_display_w && p.y > 0 && p.y < lvk_display_h)
        _framebuffer[p.y][p.x] = color;
#endif
}

#ifdef USE_OCTAPIXELS
void Display::blit(Region region, const OctaPixel *const  pixels) {
    
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

            if (color != 0) {
                switch(p.x % 8) {
                    case 0: _framebuffer[p.y % lvk_display_h][(p.x % lvk_display_w)/8].xa = color; break;
                    case 1: _framebuffer[p.y % lvk_display_h][(p.x % lvk_display_w)/8].xb = color; break;
                    case 2: _framebuffer[p.y % lvk_display_h][(p.x % lvk_display_w)/8].xc = color; break;
                    case 3: _framebuffer[p.y % lvk_display_h][(p.x % lvk_display_w)/8].xd = color; break;
                    case 4: _framebuffer[p.y % lvk_display_h][(p.x % lvk_display_w)/8].xe = color; break;
                    case 5: _framebuffer[p.y % lvk_display_h][(p.x % lvk_display_w)/8].xf = color; break;
                    case 6: _framebuffer[p.y % lvk_display_h][(p.x % lvk_display_w)/8].xg = color; break;
                    case 7: _framebuffer[p.y % lvk_display_h][(p.x % lvk_display_w)/8].xh = color; break;
                }
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
#else 
void Display::blit(Region region, const octet *const pixels) {

    // must have region and data to draw
    if(region.size.w < 1 || region.size.h < 1) return;
    if(pixels == 0) return;

    const word lineWidth    = region.size.w;
    const word lines        = region.size.h;
    const i32 firstLine    = region.origin.y;
    const i32 linePadding  = region.origin.x;

    // if x axis not even on screen, return
    if(linePadding > lvk_display_w) return;
    if(linePadding + lineWidth < 0) return;

    // do one memcpy per line
    for(word line = 0; line < lines; line++) {

        const word targetLine = firstLine + line;

        // check out of bounds
        if (targetLine > lvk_display_h) return;
        if (targetLine < 0) continue;

        if (linePadding >= 0) {
            memcpy(
                &_framebuffer[targetLine][linePadding],
                pixels + line * lineWidth,
                MIN(lineWidth, lvk_display_w - linePadding)
            );
        } else {
            memcpy(
                &_framebuffer[targetLine][0],
                pixels + (line * lineWidth) + (linePadding * -1),
                MIN(lineWidth, lvk_display_w + linePadding)
            );
        }
    }

}
#endif