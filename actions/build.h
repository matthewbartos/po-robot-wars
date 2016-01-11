#ifndef BUILD_H
#define BUILD_H

#include "actions/actioncapabler.h"
#include "robots/builder.h"

namespace actions {
    
    class build: public actioncapabler<robots::builder> {
    protected:
        void executeaction();
    public:
        bool verifyparameters();
    };
    
}

#endif
