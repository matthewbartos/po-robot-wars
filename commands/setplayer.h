#ifndef SETPLAYER_H
#define SETPLAYER_H

#include <vector>
#include <string>

#include "logic/game.h"

namespace commands {
    
    void setplayer(std::vector<std::string> &args);
    
    __attribute__((constructor(1001)))
    void init_setplayer();
    
}

#endif
