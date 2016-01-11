#include "robots/warehouse.h"

#include "logic/resourceset.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"


using namespace robots;
using namespace logic;
using namespace resources;


resourceset warehouse::getcost() {
    resourceset cost;
    cost.set<oil>(-50);
    cost.set<metal>(-100);
    cost.set<gold>(75);
    return cost;
}