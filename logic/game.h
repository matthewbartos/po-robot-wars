#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include <string>
#include <istream>
#include <ostream>
#include <utility>

void testloadworld();
int main();

namespace commands {
    void loadworld(std::vector<std::string> &);
    void setgameout(std::vector<std::string> &);
    void setplayer(std::vector<std::string> &);
    void rungame(std::vector<std::string> &);
}

namespace actions {
    class action;
    class build;
    class create;
    class mine;
    class move;
    class transfer;
}

namespace robots {
    class robot;
}

namespace fields {
    class field;
}

namespace logic {
    
    
    
    __attribute__((constructor(1000)))
    void init_masterrobots();
    
    __attribute__((constructor(1000)))
    void init_availablecommands();
    
    // Only one invokation per student is acceptable. The method should be 
    // invoked inside the method annotated with 
    // __attribute__((constructor(1001)))
    void addmasterrobot(std::string studentindex, robots::robot *masterrobot);
    
    void addcommand(std::string commandname, void (*commandfoo)(std::vector<std::string> &args));
    
    class game {
    private:
        static game thegame;
        std::vector<robots::robot *> allrobots;
        std::map<std::pair<int, int>, fields::field *> world;
        static std::map<std::string, robots::robot *> *masterrobots;
        static std::map<std::string, void (*)(std::vector<std::string> &args)> *availablecommands;
        robots::robot *currentrobot;
        
        std::vector<std::pair<int, int>> playersstartpostions;
        
        void loadworld(std::istream &s);
        void rungame();
        void runinteractive();
        
        std::ostream *out = NULL;
        
    public:
        friend class fields::field;
        friend class actions::build;
        friend class actions::create;
        friend class actions::mine;
        friend class actions::move;
        friend class actions::transfer;
        friend void logic::init_masterrobots();
        friend void logic::init_availablecommands();
        friend void logic::addmasterrobot(std::string studentindex, robots::robot *masterrobot);
        friend void logic::addcommand(std::string commandname, void (*commandfoo)(std::vector<std::string> &args));
        friend void ::testloadworld();
        friend void commands::loadworld(std::vector<std::string> &);
        friend void commands::setgameout(std::vector<std::string> &);
        friend void commands::setplayer(std::vector<std::string> &);
        friend void commands::rungame(std::vector<std::string> &);
        friend int ::main();
       
        static game &getgame();
        
        static void liststudents();
    };
    
}

#endif

