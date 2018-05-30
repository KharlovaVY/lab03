//
// Created by u211-06 on 19.04.2018.
//
#include <cassert>
#include "Temperature.h"
using namespace std;
int
main() {
    Temperature Temp;
    istringstream iss("10K");
    iss >> Temp;
    assert(Temp.value == 10);
    assert(Temp.scale == 'K');

    istringstream cel("0C");
    cel >> Temp;
    assert(Temp.value == 0);
    assert(Temp.scale == 'C');

    istringstream far("-43F");
    far >> Temp;
    assert(Temp.value == -43);
    assert(Temp.scale == 'F');

    istringstream chk("10A");
    chk>>Temp;
    assert(chk.fail()==true);

    istringstream mns("-10K");
    mns>>Temp;
    assert(mns.fail()==true);
}
