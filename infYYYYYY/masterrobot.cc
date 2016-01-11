#include <vector>
#include <algorithm>
#include <iostream>

#include "actions/action.h"
#include "actions/move.h"

#include "logic/game.h"

#include "infYYYYYY/masterrobot.h"

using namespace std;

using namespace actions;
using namespace logic;

using namespace infYYYYYY;

action *masterrobot::performaction(const vector<action *> &possibleactions) {
    actions::move *moveaction = NULL;
    cout << "Robot infYYYYYY" << endl;
    for (auto currentaction: possibleactions) {
        if (dynamic_cast<actions::move *>(currentaction)) {
            moveaction = dynamic_cast<actions::move *>(currentaction);
        }
    }
    if (moveaction) {
        moveaction->delta = {1, 0};
        if (moveaction->verifyparameters())
            return moveaction;
    }
    return NULL;
}

void infYYYYYY::init_masterrobot() {
    addmasterrobot("infYYYYYY", new masterrobot);
}
