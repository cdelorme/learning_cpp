
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string test = "Hello World";

    // using a similar substr method we can replace text
    test.replace(6, 6, "Sekai");
    cout << test << endl;

    // we can use insert as well:
    test.insert(6, "entire ");
    cout << test << endl;

    return 0;
}

