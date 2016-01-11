#include <string>
#include <sstream>
#include <iostream>

#include "fields/fieldsfactory.h"
#include "fields/field.h"
#include "fields/resourcefield.h"

#include "resources/diamond.h"
#include "resources/gold.h"
#include "resources/metal.h"
#include "resources/oil.h"

#include "commands/test.h"

using namespace std;

using namespace fields;
using namespace resources;

fieldsfactory::fieldsfactory() {
    creators['F'] = &create<field>;
    creators['D'] = &create<resourcefield<diamond> >;
    creators['G'] = &create<resourcefield<gold> >;
    creators['M'] = &create<resourcefield<metal> >;
    creators['O'] = &create<resourcefield<oil> >;
}

field *fieldsfactory::producefield(string fieldinfo, pair<int, int> pos) {
    if (fieldinfo.size() == 0) {
        return NULL;
    }
    field *result = creators[fieldinfo[0]]();
    result->pos = pos;
    int cvalue;
    if (!(stringstream(fieldinfo.c_str() + 1) >> cvalue))
        return result;
    result->setcvalue(cvalue);
    return result;
}

void testproducefield() {
    fieldsfactory ff;
    cout << "Testing field production 1... ";
    field *f = ff.producefield("D100", {0, 0});
    resourcefield<diamond> *rfd;
    if (!(rfd = dynamic_cast<resourcefield<diamond> *>(f))) {
        cout << "FAILED" << endl;
        delete f;
        return;
    }
    if (rfd->cvalue != 100) {
        cout << "FAILED" << endl;
        delete f;
        return;
    }
    cout << "OK" << endl;
    delete f;
    cout << "Testing field production 2... ";
    f = ff.producefield("M", {0, 0});
    resourcefield<metal> *rfm;
    if (!(rfm = dynamic_cast<resourcefield<metal> *>(f))) {
        cout << "FAILED" << endl;
        delete f;
        return;
    }
    cout << "OK" << endl;
    delete f;
    return;
}

ADDTEST("producefield", testproducefield);
