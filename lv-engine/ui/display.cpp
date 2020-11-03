#include "lv-engine/ui/display.h"
#include "lv-engine/engine.h"
#include <cstring>

#ifndef lvrMIN
#define lvrMIN(a,b) ((a)<(b)?(a):(b))
#endif

#ifndef lvrMAX
#define lvrMAX(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef lvrCLAMP
#define lvrCLAMP(value,min,max) ((value)<(min)?(min):((value)>(max)?(max):(value)))
#endif

using namespace lv;

void Display::clear(const octet color) {
#ifdef USE_OCTAPIXELS
    for(half h = 0; h < lvk_display_h; h++) { 
        for(half w = 0; w < lvk_octaspixels_per_line; w++) {
            _framebuffer[h][w] = OctaPixel::zero();
        }
    }
#else 
    memset(&_framebuffer, color, lvk_display_h * lvk_display_w);
#endif
}

#if lvk_measuring == true
static octet fpsLog[lvk_display_h - 4] = {0};
octet Display::fps() {
    return lvDriver_CurrentFPS();
}
#endif

void Display::refresh() {

    #if lvk_measuring == true
    for(word y = 2; y < lvk_display_h - 4;  y++)
        fillRect(Region(lvk_display_w - 10, y, 8, 1), fpsLog[y-2]);
    #endif

    for(half i = 0; i < lvk_display_h; i++) {
        #ifdef USE_OCTAPIXELS
        lvDriver_DrawHLine(i, (lv::OctaPixel*) &_framebuffer[i]);
        #else 
        lvDriver_DrawHLine(i, _framebuffer[i]);
        #endif
    }

    #if lvk_measuring == true
    
    const word frame = lvDirector.frame();
    word fps = lvDriver_CurrentFPS();
    if (lvk_60hz) fps /= 2;

    fpsLog[frame%(lvk_display_h-4)] = fps < 25 ? 28 : fps - 12;
    fpsLog[(frame+1)%(lvk_display_h-4)] = 21;
    
    #endif
}

void Display::fillRect(const Region region, const octet color) {

    if(region.size.w < 1 || region.size.h < 1) return;

    const i32 sx   = lvrMAX(0, region.origin.x);
    const i32 ex   = lvrMIN(lvk_display_w, region.origin.x + region.size.w) - sx;
    const i32 sy   = lvrMAX(0, region.origin.y);
    const i32 ey   = lvrMIN(lvk_display_h, region.origin.y + region.size.h);

    for(register word y = sy; y < ey; y++) memset(&_framebuffer[y][sx], color, ex);
}

void Display::setPixel(const Point p, const octet color) {
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

void Display::blit(const Region src, const Point dst, const octet *const pixels, const Size bufferSize){

    /*
    
    xxxxxxxx     -------
    xxxoooxx     -------
    xxxoooxx     -ooo---
    xxxxxxxx     -ooo---- 
    
    size = 8,8
    src = 3,1, 3,2
    dst = 1,2

    */

    // must have a valid region, position and data to draw
    if(src.size.w < 1 || src.size.h < 1) return;
    if(dst.x > lvk_display_w || dst.y > lvk_display_h) return;
    if(dst.x + src.size.w < 0 || dst.y + src.size.h < 0) return;
    if(pixels == 0) return;

    const word reads = src.size.w;
    const word jumps = bufferSize.w - reads;
    register word cursor = (src.origin.y * bufferSize.w) + src.origin.x;
    register word color = 0;
    const i32 yEnd = lvrMIN(dst.y + src.size.h, lvk_display_h);
    const i32 xEnd = dst.x + reads;
    
    for(register int ly = dst.y; ly < yEnd; ly++){
        for(register int lx = dst.x; lx < xEnd; lx++, cursor++){
            if (lx >= lvk_display_w || lx < 0) continue;
            color = *(pixels + (cursor - 1));
            if (!color) continue;
            _framebuffer[ly][lx] = color;
        }

        cursor += jumps;
    }

}

void Display::blit(const Region region, const octet *const pixels) {
    blit(  
        Region(0,0,region.size.w, region.size.h),
        Point(region.origin.x,region.origin.y),
        pixels, region.size
    );
}

void Display::transfer(const Region region, const octet *const pixels) {

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
    if (linePadding >= 0) {

        for(register word line = 0; line < lines; line++) {

            // check out of bounds
            const word targetLine = firstLine + line;
            if (targetLine > lvk_display_h) return;
            if (targetLine < 0) continue;

            memcpy(
                &_framebuffer[targetLine][linePadding],
                pixels + line * lineWidth,
                lvrMIN(lineWidth, lvk_display_w - linePadding)
            );
        }

    } else {

        for(register word line = 0; line < lines; line++) {

            // check out of bounds
            const word targetLine = firstLine + line;
            if (targetLine > lvk_display_h) return;
            if (targetLine < 0) continue;

            memcpy(
                &_framebuffer[targetLine][0],
                pixels + (line * lineWidth) + (linePadding * -1),
                lvrMIN(lineWidth, lvk_display_w + linePadding)
            );
        }
    }
}
#endif