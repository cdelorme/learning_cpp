
#include <iostream>

using namespace std;

int main() {

    // create a new integer type "i"
    typedef int i;

    // now we can alias the type int as "i"
    i x = 10;

    cout << x << endl;

    // useful for aliases and later on with templates

    return 0;
}

