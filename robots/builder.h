#ifndef BUILDER_H
#define BUILDER_H

#include "robots/robot.h"
#include "logic/resourceset.h"

namespace robots {
    
    class builder: virtual public robot {
    public:
        static logic::resourceset getcost();
    };
    
}

#endif
