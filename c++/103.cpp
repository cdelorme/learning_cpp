
#include <iostream>
#include <string>

using namespace std;

void displayMessage(char *m) {
    cout << m << endl;
}

int main() {

    // constant cast is a way to manipulate a const
    const char *message = "Banana Hammock";

    // this will fail
    //displayMessage(message);

    // this creates duplicate data
    displayMessage((char*)message);

    // the correct approach that is type-safe is this
    displayMessage(const_cast<char*>(message));

    return 0;
}

