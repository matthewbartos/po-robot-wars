#ifndef MINE_H
#define MINE_H

#include "actions/actioncapabler.h"
#include "robots/miner.h"

namespace actions {
    
    class mine: public actioncapabler<robots::miner> {
    protected:
        void executeaction();
    public:
        bool verifyparameters();
    };
    
}

#endif
