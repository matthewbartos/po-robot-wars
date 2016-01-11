#include "actions/action.h"
#include "robots/robot.h"

#include "logic/resourceset.h"

#include "resources/oil.h"

using namespace actions;
using namespace robots;

using namespace logic;

using namespace resources;

void action::setobject(robot *object) {
    this->object = object;
}

bool action::verifyparameters() {
    resourceset gasneed;
    gasneed.set<oil>(1);
    return object->getloadedresources() - gasneed >= 0;
}

