#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include <istream>

#include "logic/game.h"

#include "actions/actionfactory.h"
#include "actions/action.h"
#include "robots/robot.h"
#include "fields/fieldsfactory.h"
#include "fields/resourcefield.h"
#include "commands/test.h"
#include "exceptions/badformatexception.h"

#include "resources/metal.h"
#include "resources/gold.h"
#include "resources/oil.h"
#include "resources/diamond.h"

using namespace std;

using namespace logic;
using namespace robots;
using namespace exceptions;
using namespace fields;
using namespace resources;
using namespace actions;

map<string, robot *> *game::masterrobots;
map<string, void (*)(vector<string> &args)> *game::availablecommands;

game game::thegame;

void game::loadworld(istream &s) {
    string header;
    getline(s, header);
    if (header!="tournament1.0") {
        throw badformatexception("header unrecognisable");
    }
    int width, height;
    pair<int, int> playerpos;
    int playerscount;
    if (!(s >> width) || !(s >> height) || !(s >> playerscount)) {
        throw badformatexception("unreadable content");
    }
    while (playerscount-->0){
        if (!(s >> playerpos.first) || !(s >> playerpos.second)) {
            throw badformatexception("unreadable content");
        }
        playersstartpostions.push_back(playerpos);
    }
    string fielddefinition;
    fieldsfactory ff;
    world.clear();
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if (!(s >> fielddefinition))
                throw badformatexception("unreadable content");
            world[{i, j}] = ff.producefield(fielddefinition, {i, j});
        }
    }
    field::world = &world;
}

game &game::getgame() {
    return thegame;
}

vector<string> split(string s) { 
    stringstream ss(s);
    string buf;
    vector<string> result;
    while (!ss.eof()) {
        ss >> buf;
        if (buf != "") {
            result.push_back(buf);
        }
    }
    return result;
}

void game::runinteractive() {
    string commandtext;
    vector<string> commandwithargs;
    while (true) {
        cout << ">";
        getline(cin, commandtext);
        commandwithargs = std::move(split(commandtext));
        if (commandwithargs.size() == 0) {
            printf("No command passed\n");
            continue;
        }
        if ( (*availablecommands)[commandwithargs[0]])
            (*availablecommands)[commandwithargs[0]](commandwithargs);
        else
            printf("No command %s added to command map...\n", commandwithargs[0].c_str());
    }
}

void game::rungame() {
    if (playersstartpostions.size() != allrobots.size()) {
        cout << "Wrong robot starting spots..." << endl;
        return;
    }
    for (int i = 0; i < allrobots.size(); i++) {
        allrobots[i]->myposition = world[playersstartpostions[i]];
        world[playersstartpostions[i]]->rs.push_back(allrobots[i]);
        allrobots[i]->loadedresources.set<oil>(25);
    }
    
    
    int turns = 1000;
    for (int turn = 0 ; turn < turns; turn++) {
        int robotcountatstartofturn = allrobots.size();
        for (int robotidx = 0; robotidx < robotcountatstartofturn; robotidx++) {
            currentrobot = allrobots[robotidx];
            vector<action *> possibleactions = actionfactory::getallpossibleactions(allrobots[robotidx]);
            action *a = allrobots[robotidx]->performaction(possibleactions);
            if (a != NULL) {
                a->executeaction();
            }
        }
    }
    map<string, float> result;
    for (auto r: allrobots) {
        result[r->getteam()] += r->getloadedresources().get<oil>();
        result[r->getteam()] += r->getloadedresources().get<metal>();
        result[r->getteam()] += r->getloadedresources().get<gold>();
        result[r->getteam()] += r->getloadedresources().get<diamond>();
        result[r->getteam()] += r->getentirecost().get<oil>()*0.5;
        result[r->getteam()] += r->getentirecost().get<metal>()*0.5;
        result[r->getteam()] += r->getentirecost().get<gold>()*0.5;
        result[r->getteam()] += r->getentirecost().get<diamond>()*0.5;
    }
}

void game::liststudents() {
    for (auto student: *masterrobots) {
        cout << student.first << endl;
    }
}

void logic::init_masterrobots() {
    printf("Initializing master robots container... \n");
    game::masterrobots = new map<string, robot *>;
}

void logic::init_availablecommands() {
    printf("Initializing command map...\n");
    game::availablecommands = new map<string, void (*)(vector<string> &)>;
}

void logic::addmasterrobot(string studentindex, robot *masterrobot) {
    printf("Adding master robot of %s...\n", studentindex.c_str());
    (*game::masterrobots)[studentindex] = masterrobot;
    masterrobot->team = studentindex;
}

void logic::addcommand(string commandname, void (*commandfoo)(vector<string> &args)) {
    printf("Adding command %s...\n", commandname.c_str());
    (*game::availablecommands)[commandname] = commandfoo;
}

void testloadworld() {
    cout << "Load world test... ";
    stringstream ss;
    ss << "tournament1.0" << endl;
    ss << "6 5" << endl;
    ss << "2" << endl;
    ss << "2 2" << endl;
    ss << "3 2" << endl;
    ss << "F F F F F F" << endl;
    ss << "F M F F F F" << endl;
    ss << "F F F F F F" << endl;
    ss << "F F F F G100 F" << endl;
    ss << "F F F F F F" << endl;
    game g;
    try {
        g.loadworld(ss);
    } catch (badformatexception &ex) {
        cout << "FAILED" << endl;
    }
    if (!dynamic_cast<resourcefield<metal> *>(g.world[{1, 1}]))
        cout << "FAILED" << endl;
    cout << "OK" << endl;
    
}

ADDTEST("loadworld", testloadworld);

