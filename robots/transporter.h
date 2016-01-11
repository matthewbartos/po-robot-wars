#ifndef TRANSPORTER_H
#define TRANSPORTER_H

#include "robots/robot.h"
#include "logic/resourceset.h"

namespace robots {
    
    class transporter: virtual public robot {
    public:
        static logic::resourceset getcost();
    };
    
}

#endif
