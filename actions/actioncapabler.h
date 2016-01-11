#ifndef ACTIONCAPABLER_H
#define ACTIONCAPABLER_H

#include <cstdlib>
#include <typeinfo>
#include "actions/action.h"

namespace actions {
    
    template <typename ROBOTTYPE>
    class actioncapabler: public action {
    public:
        bool robotiscapabletoperformthisaction();
    };
    
    template <typename ROBOTTYPE>
    bool actioncapabler<ROBOTTYPE>::robotiscapabletoperformthisaction() {
        ROBOTTYPE *rt = dynamic_cast<ROBOTTYPE *>(object);
        return rt != NULL;
    }
    
}

#endif
