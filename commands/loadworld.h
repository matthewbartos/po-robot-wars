#ifndef LOADWORLD_H
#define LOADWORLD_H

#include <vector>
#include <string>

namespace commands {
    
    void loadworld(std::vector<std::string> &args);
    
    __attribute__((constructor(1001)))
    void init_loadworld();
    
}

#endif
