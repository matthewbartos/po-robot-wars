#include <vector>
#include <string>

#include "commands/rungame.h"
#include "logic/game.h"

using namespace std;
using namespace logic;

void commands::rungame(vector<string> &args) {
    game::getgame().rungame();
}

void commands::init_rungame() {
    addcommand("rungame", &commands::rungame);
}
