#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <string>

#include "logic/resourceset.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"
#include "logic/game.h"

namespace logic {
    class game;
}

namespace fields {
    class field;
}

namespace actions {
    class action;
    class build;
    class create;
    class mine;
    class move;
    class transfer;
}

namespace robots {
    
    class robot {
    private:
       std::string team;
       fields::field *myposition;
       logic::resourceset loadedresources;
       template <class ROBOTTYPE> void addcost(logic::resourceset &costtoaggregate) {
           ROBOTTYPE *rt = dynamic_cast<ROBOTTYPE *>(this);
           if (rt != NULL) {
               logic::resourceset temp = ROBOTTYPE::getcost();
               costtoaggregate.set<resources::diamond>(costtoaggregate.get<resources::diamond>() + temp.get<resources::diamond>());
               costtoaggregate.set<resources::gold   >(costtoaggregate.get<resources::gold   >() + temp.get<resources::gold   >());
               costtoaggregate.set<resources::metal  >(costtoaggregate.get<resources::metal  >() + temp.get<resources::metal  >());
               costtoaggregate.set<resources::oil    >(costtoaggregate.get<resources::oil    >() + temp.get<resources::oil    >());
           }
       }
    public:
       const fields::field &getmyposition();
       virtual actions::action *performaction(const std::vector<actions::action *> &possibleactions) {}
       
       static logic::resourceset getcost();
       
       int getmaxcapacity();
       logic::resourceset getentirecost();
       const std::string getteam();
       const logic::resourceset getloadedresources();
       
       friend class actions::build;
       friend class actions::create;
       friend class actions::mine;
       friend class actions::move;
       friend class actions::transfer;
       friend class logic::game;
       friend void logic::addmasterrobot(std::string studentindex, robots::robot *masterrobot);
    };
    
}

#endif