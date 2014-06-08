
#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {

    // c++ 11 style arrays, which is new to c++ and not a c-style array
    array<string, 3> names;

    // the second value sets the size to 3
    cout << names.size() << endl;

    // we can use the traditional construct setters { 1, 2, 3 }
    // also standard setting of values
    names[0] = "Casey DeLorme";

    // it also has support for iterators if we would prefer

    return 0;
}

