#include "robots/builder.h"
#include "logic/resourceset.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

using namespace robots;
using namespace logic;
using namespace resources;

resourceset builder::getcost() {
    resourceset cost;
    cost.set<metal>(200);
    return cost;
}
