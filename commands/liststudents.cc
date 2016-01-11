#include "commands/liststudents.h"

#include "logic/game.h"

using namespace logic;

void commands::liststudents(std::vector<std::string> &args) {
    game::liststudents();
}

void commands::init_liststudents() {
    addcommand("liststudents", &commands::liststudents);
}