#ifndef ANYROBOTACTION_H
#define ANYROBOTACTION_H

#include "actions/action.h"

namespace robots {
    class robot;
}

namespace actions {
    
    class anyrobotaction: public action {
    public:
        bool robotiscapabletoperformthisaction();
    };
}

#endif
