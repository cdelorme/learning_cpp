
#include <iostream>

using namespace std;

int main() {

    // single quotes requires escape sequence and array designation
    char myChar[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };
    cout << myChar << endl;

    // alternative uses double quotes
    char newChar[] = "Hello World";
    cout << newChar << endl;

    // this will cause compiler errors, but it may still run
    //char anotherChar[12] = "Hello World!";
    //cout << anotherChar << endl;
    // you may end up with some problems

    return 0;
}

