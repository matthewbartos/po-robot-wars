#include "actions/transfer.h"
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

void transfer::executeaction() {
    if (!verifyparameters()) {
        return;
    }
    resourceset fuelneeds;
    fuelneeds.set<oil>(1);
    source->loadedresources -= totransfer;
    target->loadedresources += totransfer;
    source->loadedresources -= fuelneeds;
}

bool transfer::verifyparameters() {
    return action::verifyparameters() && ( source == object || target == object ) &&
            (source->loadedresources - totransfer >= 0) && 
            (+(target->loadedresources + totransfer) <= target->getmaxcapacity()) &&
            (source->myposition == target->myposition);
}