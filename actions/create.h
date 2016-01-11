#ifndef CREATE_H
#define CREATE_H

#include "actions/actioncapabler.h"
#include "robots/creator.h"

namespace actions {
    
    class create: public actioncapabler<robots::creator> {
    protected:
        void executeaction();
    public:
        robots::robot *created;
        bool verifyparameters();
    };
    
}

#endif
