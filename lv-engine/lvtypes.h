
#pragma once
#include "lv-game/lvk.h"

namespace lv {

    static unsigned char nil = 0;

    typedef unsigned char   octet; // 255
    typedef unsigned short   half; // 64k
    typedef unsigned int     word; // 4B
    
    typedef signed char      i8; // -127 / 127
    typedef short int       i16; // -21k / 21k
    typedef int             i32; //  -2B / 2B

    #pragma pack(1)
    typedef struct Point {
        i16 x, y;
        Point(i16 _x, i16 _y) : x(_x), y(_y) { };
    } Point;

    typedef struct Size {
        half w, h;
        Size(half _w, half _h) : w(_w), h(_h) { };
    } Size;

    typedef struct Region {
        Point origin;
        Size size;
        Region(i16 _x, i16 _y, half _w, half _h) : origin(_x, _y), size(_w, _h) { };
    } Region;
    
}