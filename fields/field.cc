#include <map>
#include <vector>
#include <algorithm>
#include <utility>

#include "logic/resourceset.h"
#include "fields/field.h"
#include "robots/robot.h"

using namespace std;

using namespace fields;
using namespace robots;
using namespace logic;

map<pair<int, int>, field *> *field::world;

bool field::canmine(robots::robot *r) {
    return false;
}

resourceset field::produce(int currentload, int maxload) {
    return resourceset();
}

const std::map<std::pair<int, int>, field *> field::getsurroundings(robots::robot *r) const {
    std::map<std::pair<int, int>, field *> result;
    if (robotonfield(r)) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                result[{i, j}] = (*world)[{pos.first + i, pos.second + j}];
            }
        }
    }
    return result;
}

const vector<robot *> field::getrobots(robot *r) const {
    bool containsrobot;
    for (int i = pos.first - 1; i <= pos.first + 1; i++) {
        for (int j = pos.second - 1; j <= pos.second + 1; j++) {
            if ((*world)[{i, j}] != NULL) {
                containsrobot |= (*world)[{i, j}]->robotonfield(r);
            }
        }
    }
    if (containsrobot && game::getgame().currentrobot 
                      && game::getgame().currentrobot->getteam() == r->getteam() ) {
        return vector<robot *>(this->rs.begin(), this->rs.end());
    } else {
        return vector<robot *>();
    }
}

bool field::robotonfield(robot *r) const {
    auto it = find(rs.begin(), rs.end(), r);
    return it != rs.end();
}

field::~field() {}


