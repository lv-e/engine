
#pragma once

#include "../lvk.h"
#include "../lvtypes.h"
#include "scene.h"

#define lvDirector lv::Director::shared()
#define NO_SCENE 254

namespace lv {

    class Director {
        
        public:

            static Director& shared(){
                static Director instance;
                return instance;
            }

            void update();
            void draw();

            void pause();
            bool isPaused();

            void resume();
            bool isRunning();

            void runScene(octet sceneID);
            
            Director();
            
        private:

            octet _currentScene;
            bool _running;
            word _frame;
    };
}