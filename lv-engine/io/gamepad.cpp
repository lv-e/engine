#include "lv-engine/io/gamepad.h"
#include <stddef.h>
 #include <limits.h>

#define B_RELEASED  0
#define B_DOWN      1
#define B_UP        UINT_MAX - 1

using namespace lv;

static GamePad pads[lvk_gamepads];

GamePad GamePads::player(word playerID) {
    if (playerID < lvk_gamepads) return pads[playerID];
    else return (GamePad) {0};
}

ButtonState transition(ButtonState oldValue, ButtonState newValue) {
    if (oldValue == B_RELEASED && newValue == B_RELEASED) return B_RELEASED;
    switch (newValue){
        case B_RELEASED:
            switch (oldValue){
                case B_RELEASED: return B_RELEASED;
                case B_UP: return B_RELEASED;
                default: return B_UP;
            }
        default:
            switch (oldValue){
                case B_RELEASED: return B_DOWN;
                case B_UP: return B_DOWN;
                case B_DOWN: return B_DOWN + 1;
                default: return oldValue + 1;
            }
    }
}

void GamePads::update(word playerID, GamePad pad){
    if (playerID < lvk_gamepads) {
        
        pads[playerID].up = transition(pads[playerID].up, pad.up);
        pads[playerID].down = transition(pads[playerID].down, pad.down);
        pads[playerID].left = transition(pads[playerID].left, pad.left);
        pads[playerID].rigth = transition(pads[playerID].rigth, pad.rigth);

        pads[playerID].a = transition(pads[playerID].a, pad.a);
        pads[playerID].b = transition(pads[playerID].b, pad.b);
        pads[playerID].x = transition(pads[playerID].x, pad.x);
        pads[playerID].y = transition(pads[playerID].y, pad.y);

        pads[playerID].l = transition(pads[playerID].l, pad.l);
        pads[playerID].r = transition(pads[playerID].r, pad.r);

        pads[playerID].start = transition(pads[playerID].start, pad.start);
        pads[playerID].select = transition(pads[playerID].select, pad.select);

    }
}

bool GamePads::isReleased(ButtonState button){
    return button == B_RELEASED;
}

bool GamePads::isDown(ButtonState button){
    return button == B_DOWN;
}

bool GamePads::isPressed(ButtonState button){
    return button > B_DOWN && button < B_UP;
}

bool GamePads::isUp(ButtonState button){
    return button == B_UP;
}