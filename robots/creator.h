#ifndef CREATOR_H
#define CREATOR_H

#include "robots/robot.h"
#include "logic/resourceset.h"

namespace robots {
    
    class creator: virtual public robot {
    public:
        static logic::resourceset getcost();
    };
    
}

#endif
