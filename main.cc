#include <iostream>

using namespace std;

#include "robots/robot.h"
#include "robots/builder.h"
#include "robots/concreteminer.h"
#include "robots/creator.h"
#include "robots/miner.h"
#include "robots/transporter.h"

#include "logic/resourceset.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

#include "logic/game.h"

using namespace std;

using namespace robots;
using namespace logic;
using namespace resources;


int main() {
    cout << "Running main loop of the program..." << endl;
    game::getgame().runinteractive();
}