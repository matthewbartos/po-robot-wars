#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "logic/game.h"
#include "commands/test.h"

using namespace std;

using namespace commands;
using namespace logic;

map<string, void (*)()> *commands::tests;

void commands::init_tests() {
    tests = new map<string, void (*)()>;
}

void commands::test(vector<string> &args) {
    if (args.size() < 2) {
        cout << "No tests to run" << endl;
    }
    for (int i = 1; i < args.size(); i++) {
        if (!(*tests)[args[i]]) {
            cout << "No test method called " << args[i] << endl;
            continue;
        }
        (*tests)[args[i]]();
    }
}

void commands::init_test() {
    addcommand("test", &commands::test);
}

