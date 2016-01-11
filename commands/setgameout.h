#ifndef SETGAMEOUT_H
#define SETGAMEOUT_H

#include <vector>
#include <string>

#include "logic/game.h"

namespace commands {
    
    void setgameout(std::vector<std::string> &args);
    
    __attribute__((constructor(1001)))
    void init_setgameout();
    
}

#endif
