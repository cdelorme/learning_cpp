
#include <iostream>

using namespace std;

int main() {

    // enums can store many values
    enum colors { black, blue, green, red, white, purple };

    // this gives us a new type "colors"
    // each constant within has an integer value starting with 0
    // we can set the integer value and the constants after will continue from that number
    // ex. if we set black to 52, blue will be 53, green will be 54, etc...

    // now we can set an integer to the constant value via:
    int color = black;

    // it will have the value of the retained constant
    cout << color << endl;

    // we can also us the enum as a type which limits what it a variable can be set to (enum constants, not int values)
    colors colorTwo = blue;
    cout << colorTwo << endl;

    return 0;
}

