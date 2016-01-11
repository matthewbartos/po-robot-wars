#ifndef MINER_H
#define MINER_H

#include "robots/robot.h"
#include "logic/resourceset.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

namespace robots {
    
    class miner: virtual public robot {
    public:
        static logic::resourceset getcost();
        
        template <class RESOURCETYPE> static logic::resourceset getconcreteminercost() {
            return logic::resourceset();
        }
        
    };
    
    template <> logic::resourceset miner::getconcreteminercost<resources::diamond>();
    template <> logic::resourceset miner::getconcreteminercost<resources::gold>();
    template <> logic::resourceset miner::getconcreteminercost<resources::metal>();
    template <> logic::resourceset miner::getconcreteminercost<resources::oil>();
    
}

#endif
