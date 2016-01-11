#ifndef MOVE_H
#define MOVE_H

#include <utility>

#include "actions/anyrobotaction.h"

namespace actions {
    
    class move: public anyrobotaction {
    protected:
        void executeaction();
    public:
        std::pair<int, int> delta;
        
        bool verifyparameters();
    };
}

#endif
