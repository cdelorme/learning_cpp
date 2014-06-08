
#include <iostream>
#include <string>

using namespace std;

// templates allow you to simplify repeated code
// such as operations that are the same regardless of type
// with templates we can create a generic type that fits all scenarios

// we can create a generic type "T"
template<class T>
T Add(T a, T b) {
    return a + b;
}

int main() {

    // this will now be accessible for anything
    cout << Add(1, 2) << endl;
    cout << Add(12.5, 17.6) << endl;

    // to speed up the compilers job we can specify the type
    cout << Add<int>(2, 3) << endl;

    // it may also be required for some data types
    cout << Add<string>("A", "B") << endl;

    return 0;
}

