#ifndef FIELDSFACTORY_H
#define FIELDSFACTORY_H

#include <map>
#include <string>
#include <utility>


#include "fields/field.h"

namespace fields {
    
    class fieldsfactory {
    private:
        std::map<char, field *(*)()> creators;
        template <typename FIELDTYPE> static field *create();
    public:
        fieldsfactory();
        field *producefield(std::string fieldinfo, std::pair<int, int> pos);
    };
    
    
    template <typename FIELDTYPE> field *fieldsfactory::create() {
            return new FIELDTYPE;
    }
}

#endif
