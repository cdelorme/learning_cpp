
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string line("Whee");

    // you can also treat them as arrays
    cout << line[0] << endl;

    // similarly we have an at function as part of the string
    cout << line.at(0) << endl;

    return 0;
}

