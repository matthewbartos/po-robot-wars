#include <typeinfo>
#include <vector>
#include <string>

#include "logic/resourceset.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

using namespace std;

using namespace logic;
using namespace resources;

vector<string> resourceset::keys = {typeid(diamond).name(), typeid(gold).name(), typeid(metal).name(), typeid(oil).name()};

resourceset resourceset::operator+(const resourceset &rs) const {
    resourceset result;
    for (auto resource: resourcecount) {
        result.resourcecount[resource.first] = resource.second;
    }
    for (auto resource: rs.resourcecount) {
        result.resourcecount[resource.first] += resource.second;
    }
    return result;
}

resourceset &resourceset::operator+=(const resourceset &rs) {
    *this = *this + rs;
    return *this;
}

resourceset resourceset::operator-(const resourceset &rs) const {
    resourceset result;
    for (auto resource: resourcecount) {
        result.resourcecount[resource.first] = resource.second;
    }
    for (auto resource: rs.resourcecount) {
        result.resourcecount[resource.first] -= resource.second;
    }
    return result;
}

resourceset &resourceset::operator-=(const resourceset &rs) {
    *this = *this - rs;
    return *this;
}


bool resourceset::operator>(int v) const {
    for (auto resource: keys) {
        if (((resourceset *)this)->resourcecount[resource] <= v) {
            return false;
        }
    }
    return true;
}

bool resourceset::operator>=(int v) const {
    for (auto resource: keys) {
        if (((resourceset *)this)->resourcecount[resource] < v) {
            return false;
        }
    }
    return true;
}

bool resourceset::operator<(int v) const {
    for (auto resource: keys) {
        if (((resourceset *)this)->resourcecount[resource] >= v) {
            return false;
        }
    }
    return true;
}

bool resourceset::operator<=(int v) const {
    for (auto resource: keys) {
        if (((resourceset *)this)->resourcecount[resource] > v) {
            return false;
        }
    }
    return true;
}

int resourceset::operator+() const{
    int sum = 0;
    for (auto resource: keys) {
        sum+=((resourceset *)this)->resourcecount[resource];
    }
    return sum;
}

