#ifndef BADFORMATEXCEPTION_H
#define BADFORMATEXCEPTION_H

#include <string>

namespace exceptions {
    
    class badformatexception {
    private:
        std::string message;
    public:
        badformatexception(std::string message);
        std::string getmessage();
    };
    
}

#endif 
