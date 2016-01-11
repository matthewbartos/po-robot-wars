#ifndef TRANSFER_H
#define TRANSFER_H

#include "robots/robot.h"

#include "actions/anyrobotaction.h"

#include "logic/resourceset.h"

namespace actions {
    
    class transfer: public anyrobotaction {
    protected:
        void executeaction();
    public:
        robots::robot *target;
        robots::robot *source;
        logic::resourceset totransfer;
        
        bool verifyparameters();
    };
    
}

#endif
