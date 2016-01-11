#include <algorithm>

#include "actions/build.h"
#include "robots/robot.h"
#include "robots/warehouse.h"
#include "fields/field.h"
#include "logic/resourceset.h"
#include "logic/game.h"
#include "resources/oil.h"

using namespace robots;
using namespace actions;
using namespace resources;
using namespace logic;
using namespace fields;

void build::executeaction() {
    if (!verifyparameters()) {
        return;
    }
    robot *w = new warehouse();
    resourceset fuelneeds;
    fuelneeds.set<oil>(1);
    object->loadedresources -= w->getentirecost();
    object->loadedresources -= fuelneeds;
    w->team = object->team;
    w->myposition = object->myposition;
    object->myposition->rs.push_back(w);
    game::getgame().allrobots.push_back(w);
}

bool build::verifyparameters() {
    warehouse w;
    resourceset fuelneeds;
    fuelneeds.set<oil>(1);
    return (object->getloadedresources() - w.getentirecost() - fuelneeds >= 0) && 
            !any_of(object->myposition->rs.begin(), object->myposition->rs.end(), 
                    [](robot *r){ 
                        warehouse *ww = dynamic_cast<warehouse *>(r); 
                        return ww != NULL;
                    });
}