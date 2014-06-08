
// we can include our header file as the definition
// this file contains the implementation
#include "44.h"

// is this no-longer needed because of our header file?
//#include <iostream>


using namespace std;

// I can't continue defining a class here, so I guess header files are the place to put this
//class TestClass {
//    private:
//        int value;
//};

// we can now define the implementation, also note we can use "this->" instead of the class name
void TestClass::setValue(int value) {
    this->value = value;
}
int TestClass::getValue() {
    return TestClass::value;
}

int main() {

    TestClass test;

    test.setValue(200);
    cout << test.getValue() << endl;

    return 0;
}

