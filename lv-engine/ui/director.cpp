#include "lv-engine/ui/director.h"
#include "lv-engine/ui/display.h"
#include "lv-engine/ui/scene.h"

using namespace lv;

Scene scenesTable[lvk_scene_count];

Director::Director() {
    _currentScene = NO_SCENE;
}

void Director::update(){
    if (isRunning()) {
        _frame++;
        (scenesTable[_currentScene].onFrame)();
    }
}

void Director::draw(){
    if (isRunning()) lvDisplay.refresh();
}

void Director::runScene(octet sceneID){
    _currentScene = sceneID; _frame = 0;
    (scenesTable[_currentScene].onAwake)();
    (scenesTable[_currentScene].onEnter)();
    _running = true;
}

// pausing and resuming routines
void Director::pause() { _running = false; }
bool Director::isPaused() { return _running == false || _currentScene == NO_SCENE; }
void Director::resume() { _running = true; }
bool Director::isRunning() { return _running && _currentScene != NO_SCENE; }