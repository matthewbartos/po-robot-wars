#include <vector>
#include <algorithm>
#include <iostream>

#include "actions/action.h"
#include "actions/mine.h"
#include "actions/move.h"
#include "actions/create.h"

#include "fields/resourcefield.h"

#include "resources/oil.h"

#include "logic/game.h"

#include "infXXXXXX/masterrobot.h"

using namespace std;

using namespace actions;
using namespace logic;
using namespace resources;
using namespace fields;

using namespace infXXXXXX;

action *masterrobot::performaction(const vector<action *> &possibleactions) {
    /*
    actions::move *moveaction = NULL;
    for (auto currentaction: possibleactions) {
        if (dynamic_cast<actions::move *>(currentaction)) {
            moveaction = dynamic_cast<actions::move *>(currentaction);
        }
    }
    if (moveaction) {
        moveaction->delta = {-1, 0};
        if (moveaction->verifyparameters())
            return moveaction;
    }
    return NULL;
    
    auto it = find_if(possibleactions.begin(), possibleactions.end(), [](action *a) {
        return dynamic_cast<actions::mine *>(a) != NULL;
    });
    if (dynamic_cast<const resourcefield<oil>*>(&getmyposition())) {
        
    }
    
    auto mineaction = dynamic_cast<actions::mine *>(*it);
    
    if (mineaction->verifyparameters()) {
        return mineaction;
    }
    */
    auto mr = new masterrobot;
    cout << "Robot infXXXXXX" << endl;
    auto it = find_if(possibleactions.begin(), possibleactions.end(), [](action *a) {
        return dynamic_cast<actions::create *>(a) != NULL;
    });
    auto createaction = dynamic_cast<actions::create *>(*it);
    createaction->created = mr;
    if (it == possibleactions.end()) {
        return NULL;
    }
    if (!createaction->verifyparameters()) {
        return NULL;
    }
    return createaction;
}

void infXXXXXX::init_masterrobot() {
    addmasterrobot("infXXXXXX", new masterrobot);
}
