#ifndef CONCRETEMINER_H
#define CONCRETEMINER_H

#include "robots/miner.h"
#include "logic/resourceset.h"

namespace robots {
    
    template <class RESOURCETYPE> class concreteminer: virtual public miner {
    public:
        static logic::resourceset getcost() {
            return miner::getconcreteminercost<RESOURCETYPE>();
        }
    };
    
}

#endif
