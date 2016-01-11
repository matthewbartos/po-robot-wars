#include "actions/mine.h"

#include "robots/robot.h"
#include "fields/field.h"
#include "robots/warehouse.h"
#include "resources/oil.h"
#include "logic/game.h"
#include "logic/resourceset.h"

using namespace robots;
using namespace actions;
using namespace resources;
using namespace logic;
using namespace fields;

void mine::executeaction() {
    if (!verifyparameters()) {
        return;
    }
    resourceset fuelneeds;
    fuelneeds.set<oil>(1);
    object->loadedresources -= fuelneeds;
    resourceset product = object->myposition->produce(+object->loadedresources, object->getmaxcapacity());
    object->loadedresources += product;
}

bool mine::verifyparameters() {
    return action::verifyparameters() && (object->myposition->canmine(object));
}