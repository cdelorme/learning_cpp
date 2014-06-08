
#include <iostream>

using namespace std;

int main() {

    // add two numbers of invariable types
    int t1 = 12;
    float t2 = 11.5;

    // by default it will convert to the best data type to retain it (eg int + float = float)
    cout << t1 + t2;
    cout << endl;

    // you can force convert the float to an int, but you will loose the decimal value
    cout << t1 + (int) t2;
    cout << endl;

    return 0;
}

