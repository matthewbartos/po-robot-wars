#include "robots/miner.h"
#include "logic/resourceset.h"

// oil 0.2 gold 1.0 diamond 0.8 metal 0.5

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

using namespace robots;
using namespace logic;
using namespace resources;

resourceset miner::getcost() {
    resourceset cost;
    cost.set<metal>(200);
    return cost;
}
    
template <> resourceset miner::getconcreteminercost<diamond>() {
    resourceset cost;
    cost.set<diamond>(200);
    cost.set<gold>(200);
    return cost;
}

template <> resourceset miner::getconcreteminercost<gold>() {
    resourceset cost;
    cost.set<gold>(400);
    return cost;
}

template <> resourceset miner::getconcreteminercost<metal>() {
    resourceset cost;
    cost.set<metal>(200);
    cost.set<gold>(200);
    return cost;
}

template <> resourceset miner::getconcreteminercost<oil>() {
    resourceset cost;
    cost.set<oil>(200);
    cost.set<gold>(200);
    return cost;
}

