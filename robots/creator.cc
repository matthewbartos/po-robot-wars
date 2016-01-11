#include "robots/creator.h"
#include "logic/resourceset.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

using namespace robots;
using namespace logic;
using namespace resources;

resourceset creator::getcost() {
    resourceset cost;
    cost.set<diamond>(200);
    return cost;
}