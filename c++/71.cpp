
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // we can also swap two strings
    string lineOne = "UPPER";
    string lineTwo = "lower";

    lineOne.swap(lineTwo);

    cout << lineOne << endl;

    return 0;
}

