#include <vector>
#include <algorithm>

#include "actions/create.h"
#include "robots/robot.h"
#include "fields/field.h"
#include "robots/warehouse.h"
#include "resources/oil.h"
#include "logic/game.h"

using namespace robots;
using namespace actions;
using namespace resources;
using namespace logic;
using namespace fields;

void create::executeaction() {
    if (!verifyparameters()) {
        return;
    }
    auto &rs = object->myposition->rs;
    auto wit = find_if(rs.begin(), rs.end(), [](robot *r){
                            warehouse *ww = dynamic_cast<warehouse *>(r);
                            return ww != NULL;
                        });
    
    resourceset fuelneeds;
    object->loadedresources -= fuelneeds;
    fuelneeds.set<oil>(1);
    warehouse *w = dynamic_cast<warehouse *>(*wit);
    w->loadedresources -= created->getentirecost();
    created->loadedresources.set<oil>(25);
    created->team = object->team;
    created->myposition = object->myposition;
    game::getgame().allrobots.push_back(created);
}

bool create::verifyparameters() {
    auto &rs = object->myposition->rs;
    auto wit = find_if(rs.begin(), rs.end(), [](robot *r){
                            warehouse *ww = dynamic_cast<warehouse *>(r);
                            return ww != NULL;
                        });
    
    if (wit == rs.end()) {
        return false;
    }
    warehouse *w = dynamic_cast<warehouse *>(*wit);
    return (w->loadedresources - created->getentirecost() >= 0) && action::verifyparameters();
}

