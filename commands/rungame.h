#ifndef RUNGAME_H
#define RUNGAME_H

#include <vector>
#include <string>

#include "logic/game.h"

namespace commands {
    
    void rungame(std::vector<std::string> &args);
    
    __attribute__((constructor(1001)))
    void init_rungame();
    
}

#endif
