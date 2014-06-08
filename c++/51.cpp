
#include <iostream>
#include <string>

using namespace std;

// templates can even have multiple types specified
template<class T, class U>
T Add(T a, U b) {
    return a + b;
}

int main() {

    // this will now be accessible for anything
    cout << Add(1, 2) << endl;
    cout << Add(12.5, 17.6) << endl;

    // now we use a comma to specifty the types
    cout << Add<string, string>("A", "B") << endl;
    // some types cannot be added, like string and int

    // for similar types, the first value is the return type (as defined with `T Add`)
    cout << Add<int, double>(12, 13.5) << endl;

    return 0;
}

