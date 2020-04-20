#include "lv-engine/components/version.h"
#include "lv-engine/engine.h"

Version makeVersion(uint8_t major, uint8_t minor, uint8_t path, uint8_t build){
    return (Version) {major, minor, path, build};
}