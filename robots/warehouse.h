#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "robots/robot.h"
#include "logic/resourceset.h"

namespace robots {
    
    class warehouse: public robot {
    public:
       static logic::resourceset getcost();
    };
    
}

#endif
