#ifndef RESOURCEFIELD_H
#define RESOURCEFIELD_H

#include <algorithm>

#include "fields/field.h"
#include "robots/robot.h"
#include "robots/concreteminer.h"
#include "logic/resourceset.h"

void testproducefield();

namespace fields {
    
    template <class RESOURCETYPE> class resourcefield: public field {
    protected:
        int cvalue;
        logic::resourceset produce(int currentload, int maxload) {
            logic::resourceset result;
            int maxtoload = maxload - currentload;
            result.set<RESOURCETYPE>(std::min(std::max(cvalue, maxtoload), 100));
            cvalue -= result.get<RESOURCETYPE>();
            return result;
        }
        void setcvalue(int cvalue) {
            this->cvalue = cvalue;
        }
    public:
        bool canmine(robots::robot *r) {
            robots::concreteminer<RESOURCETYPE> *cm = dynamic_cast<robots::concreteminer<RESOURCETYPE> *>(r);
            return cm != NULL;
        }
        
        friend void ::testproducefield();
    };
    
}

#endif
