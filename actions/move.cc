#include <cstdlib>
#include <algorithm>

#include "actions/move.h"
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

using namespace std;

void move::executeaction() {
    if (!verifyparameters()) {
        return;
    }
    auto prevpos = object->myposition;
    auto prevposcoords = prevpos->pos;
    auto newpos = (*prevpos->world)[{prevposcoords.first + delta.first, prevposcoords.second + delta.second}];
    prevpos->rs.erase(find(prevpos->rs.begin(), prevpos->rs.end(), object));
    object->myposition = newpos;
    newpos->rs.push_back(object);
    resourceset fuelneeds;
    fuelneeds.set<oil>(1);
    object->loadedresources -= fuelneeds;
}

bool move::verifyparameters() {
    int distance = abs(delta.first) + abs(delta.second);
    
    auto prevpos = object->myposition;
    auto prevposcoords = prevpos->pos;
    auto newpos = (*prevpos->world)[{prevposcoords.first + delta.first, prevposcoords.second + delta.second}];
    
    return action::verifyparameters() && (distance == 1) && newpos != NULL &&
           all_of(newpos->rs.begin(), newpos->rs.end(), [this](robot *r) {
               return this->object->team == r->team;
           });
}

