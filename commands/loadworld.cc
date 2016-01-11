#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "commands/loadworld.h"
#include "logic/game.h"
#include "exceptions/badformatexception.h"

using namespace std;

using namespace logic;
using namespace exceptions;

void commands::loadworld(vector<string> &args) {
    if (args.size() < 2) {
        cout << "File name not passed" << endl;
        return;
    }
    ifstream f(args[1].c_str());
    if (!f)  {
        cout << "File " << args[1] << " does not exist" << endl;
        return;
    }
    try {
        game::thegame.loadworld(f);
    } catch (badformatexception &ex) {
        cout << "Problem while reading file: " << ex.getmessage() << endl;
    }
    f.close();
}

void commands::init_loadworld() {
    addcommand("loadworld", &commands::loadworld);
}

