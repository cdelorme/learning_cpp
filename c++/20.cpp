
#include <iostream>

using namespace std;

int main() {

    // acquire name
    char name[20];

    // this will use getline to get a fixed number of characters (fixing problems with spaces etc)
    cout << "Enter your full name (maximum of 20 spaces): ";
    cin.getline(name, 20);
    cout << "Hello " << name << endl;

    return 0;
}

