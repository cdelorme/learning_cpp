
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    // maps give us key/value pairing
    map<string, int> stuff;

    // we can easily set values
    stuff["banana"] = 3;

    // then we can access it the same way
    cout << stuff["banana"] << endl;

    // this is excellent for duplicate item handling
    // for example if we wanted to identify files by size
    // we store a vector of strings to the file, by the size as the map key
    // then we can easily compare only hashes of files with the same size to check for duplicates!

    return 0;
}

