#ifndef RESOURCESET_H
#define RESOURCESET_H

#include <map>
#include <string>
#include <typeinfo>
#include <vector>
#include <string>

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

namespace logic {
    
    class resourceset {
    private:
        std::map<std::string, int> resourcecount = { {typeid(resources::diamond).name(), 0}, {typeid(resources::gold).name(), 0}, {typeid(resources::metal).name(), 0}, {typeid(resources::oil).name(), 0}};
        static std::vector<std::string> keys;
    public:
        template <class RESOURCETYPE> void set(int value) {
            resourcecount[std::string(typeid(RESOURCETYPE).name())] = value;
        }
        template <class RESOURCETYPE> int get() const {
            return ((resourceset *)this)->resourcecount[std::string(typeid(RESOURCETYPE).name())];
        }
        resourceset operator+(const resourceset &rs) const;
        resourceset &operator+=(const resourceset &rs);
        resourceset operator-(const resourceset &rs) const;
        resourceset &operator-=(const resourceset &rs);
        bool operator>(int v) const;
        bool operator>=(int v) const;
        bool operator<(int v) const;
        bool operator<=(int v) const;
        
        
        int operator+() const;
    };
    
}

#endif
