#ifndef LISTSTUDENTS_H
#define LISTSTUDENTS_H

#include <vector>
#include <string>

namespace commands {
    
    void liststudents(std::vector<std::string> &args);
    
    __attribute__((constructor(1001)))
    void init_liststudents();
    
}

#endif
