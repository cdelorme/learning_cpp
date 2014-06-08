
#include <iostream>

using namespace std;

int main() {

    // acquire name
    char name[20];

    cout << "Enter you name: ";

    // this may work, but...
    cin >> name;

    // it won't include spaces
    cout << "Hello " << name << endl;

    return 0;
}

