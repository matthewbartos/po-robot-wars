#ifndef TEST_H
#define TEST_H

#include <map>
#include <vector>
#include <string>

#define ADDTEST(testname, testfoo) \
    __attribute__((constructor(1001)))\
    void addtest_ ## testfoo () {\
        (*commands::tests)[testname] = &testfoo;\
    }

namespace commands {
    
    extern std::map<std::string, void (*)()> *tests;
    
    __attribute__((constructor(1000)))
    void init_tests();
    
    void test(std::vector<std::string> &args);
    
    __attribute__((constructor(1001)))
    void init_test();
}

#endif
