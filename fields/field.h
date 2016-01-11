#ifndef FIELD_H
#define FIELD_H

#include <map>
#include <vector>
#include <utility>

#include "logic/resourceset.h"

namespace actions {
    class action;
    class build;
    class create;
    class mine;
    class move;
    class transfer;
}

namespace robots {
    class robot;
}

namespace logic {
    class game;
}

namespace fields {
    
    class field {
    private:
        std::vector<robots::robot *> rs;
        std::pair<int, int> pos;
        static std::map<std::pair<int, int>, field *> *world;
    protected:
        virtual logic::resourceset produce(int currentload, int maxload);
        virtual void setcvalue(int cvalue) { }
    public:
        virtual ~field();
        const std::map<std::pair<int, int>, field *> getsurroundings(robots::robot *r) const;
        const std::vector<robots::robot *> getrobots(robots::robot *r) const;
        bool robotonfield(robots::robot *) const;
        
        virtual bool canmine(robots::robot *r);
        
        
        friend class fieldsfactory;
        friend class actions::build;
        friend class actions::create;
        friend class actions::mine;
        friend class actions::move;
        friend class actions::transfer;
        friend class logic::game;
    };
    
}

#endif
