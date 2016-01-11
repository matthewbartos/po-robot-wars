#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "commands/setgameout.h"

#include "logic/game.h"

using namespace std;

using namespace commands;
using namespace logic;


void commands::setgameout(vector<string> &args) {
    if (args.size() < 2) {
        cout << "No output filename passed" << endl;
        return;
    }
    game::getgame().out = new ofstream(args[1].c_str());
    if (!*game::getgame().out) {
        cout << "No output filename passed" << endl;
    }
}

void commands::init_setgameout() {
    addcommand("setgameout", &commands::setgameout);
}
