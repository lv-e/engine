#pragma once
#include "lv-engine/lvtypes.h"

#define lvGamepads lv::GamePads::shared()
#define lvGamepad(N) lv::GamePads::shared().player(N)

namespace lv {

    typedef unsigned int ButtonState;
    typedef struct GamePad{
        ButtonState up, down, left, rigth;
        ButtonState x, y, a, b;
        ButtonState l, r;
        ButtonState start, select;
    } GamePad;

    class GamePads {
    
    public:

        static GamePads& shared(){
            static GamePads instance;
            return instance;
        }
     
        GamePad player(word playerID);
        void update(word playerID, GamePad pad);

        bool isReleased(ButtonState button);
        bool isUp(ButtonState button);
        bool isDown(ButtonState button);
        bool isPressed(ButtonState button);
        
    };
}