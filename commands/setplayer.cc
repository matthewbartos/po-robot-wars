#include <iostream>
#include <vector>
#include <string>

#include "commands/setplayer.h"

#include "logic/game.h"

using namespace std;

using namespace logic;

void commands::setplayer(vector<string> &args) {
    if (args.size() < 2) {
        cout << "No playername(s) passed" << endl;
    }
    for (int i = 1; i < args.size(); i++) {
        auto it = game::getgame().masterrobots->find(args[i]);
        if (it == game::getgame().masterrobots->end()) {
            cout << "No player called " << args[i] << endl;
            continue;
        }
        cout << "Adding player " << it->first << endl;
        game::getgame().allrobots.push_back(it->second);
    }
}

void commands::init_setplayer() {
    addcommand("setplayer", &commands::setplayer);
}

