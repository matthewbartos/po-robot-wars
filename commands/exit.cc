#include <cstdlib>
#include <cstdio>
#include "commands/exit.h"

using namespace logic;

void commands::exit(std::vector<std::string> &args) {
    printf("Exiting...\n");
    ::exit(0);
}

void commands::init_exit() {
    addcommand("exit", &commands::exit);
}
