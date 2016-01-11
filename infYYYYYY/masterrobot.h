#ifndef MASTERROBOT_H
#define MASTERROBOT_H

#include <vector>

#include "logic/game.h"

#include "actions/action.h"

#include "robots/robot.h"
#include "robots/builder.h"
#include "robots/creator.h"
#include "robots/concreteminer.h"
#include "robots/transporter.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

// ropa    - 100  *0.1
// metal   - 200  *0.3
// diamond - 200  *0.4
// złoto   -   0  *1.0

namespace infYYYYYY {
    
    __attribute__((constructor(1001)))
    void init_masterrobot();
    
    class masterrobot: 
        virtual public robots::builder, 
        virtual public robots::creator, 
        virtual public robots::concreteminer<resources::diamond>,
        virtual public robots::concreteminer<resources::gold>,
        virtual public robots::concreteminer<resources::metal>,
        virtual public robots::concreteminer<resources::oil>,
        virtual public robots::transporter {
    public:
        virtual actions::action *performaction(const std::vector<actions::action *> &possibleactions);
       
    };
        
    
}

#endif
