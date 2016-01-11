#include <string>

#include "badformatexception.h"


using namespace std;

using namespace exceptions;

badformatexception::badformatexception(string message) {
    this->message = message;
}

string badformatexception::getmessage() {
    return message;
}
