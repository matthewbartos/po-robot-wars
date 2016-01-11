#ifndef EXIT_H
#define EXIT_H

#include <vector>
#include <string>

#include "logic/game.h"

namespace commands {
    
    void exit(std::vector<std::string> &args);
    
    __attribute__((constructor(1001)))
    void init_exit();
    
}

#endif
