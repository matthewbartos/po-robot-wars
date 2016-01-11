#include <typeinfo>
#include <string>
#include <limits>

#include "robots/robot.h"
#include "robots/builder.h"
#include "robots/concreteminer.h"
#include "robots/creator.h"
#include "robots/miner.h"
#include "robots/transporter.h"
#include "robots/warehouse.h"

#include "logic/resourceset.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

using namespace std;

using namespace robots;
using namespace logic;
using namespace resources;

resourceset robot::getcost() {
    resourceset cost;
    cost.set<oil>(50);
    cost.set<metal>(200);
    return cost;
}

int robot::getmaxcapacity() {
    warehouse *w = dynamic_cast<warehouse *>(this);
    transporter *t = dynamic_cast<transporter *>(this);
    if (w == NULL) {
        if (t == NULL) {
            return 200;
        } else {
            return 400;
        }
    } else {
        return std::numeric_limits<int>::max();
    }
}

resourceset robot::getentirecost() {
    resourceset entirecost;
    addcost<robot>(entirecost);
    addcost<builder>(entirecost);
    addcost<concreteminer<diamond> >(entirecost);
    addcost<concreteminer<gold> >(entirecost);
    addcost<concreteminer<metal> >(entirecost);
    addcost<concreteminer<oil> >(entirecost);
    addcost<creator>(entirecost);
    addcost<miner>(entirecost);
    addcost<transporter>(entirecost);
    addcost<warehouse>(entirecost);
    
    return entirecost;
}

const string robot::getteam() {
    return this->team;
}

const resourceset robot::getloadedresources() {
    return this->loadedresources;
}

