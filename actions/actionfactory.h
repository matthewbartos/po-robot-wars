#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include <vector>
#include <algorithm>

#include "robots/robot.h"
#include "actions/action.h"

#include "actions/build.h"
#include "actions/create.h"
#include "actions/mine.h"
#include "actions/move.h"
#include "actions/transfer.h"

namespace actions {
    
    class actionfactory {
    public:
        template <class ACTIONTYPE> static action* createaction(robots::robot *r) {
            action *result = new ACTIONTYPE;
            result->object = r;
            if (!result->robotiscapabletoperformthisaction()) {
                delete result;
                result = NULL;
            }
            return result;
        }
        
        static std::vector<action *> getallpossibleactions(robots::robot *r) {
            std::vector<action *> result;
            result.push_back(createaction<build>(r));
            result.push_back(createaction<create>(r));
            result.push_back(createaction<mine>(r));
            result.push_back(createaction<move>(r));
            result.push_back(createaction<transfer>(r));
            result.erase(std::remove_if(result.begin(), result.end(), [](action *a) {return a == NULL;}), result.end());
            return result;
        }
    };
    
}

#endif
