
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // finally if we know an initial length we can set defaults
    vector< vector<int> > numbers(4, vector<int>());

    // now we can set a value
    numbers[0].push_back(25);
    cout << numbers[0][0] << endl;

    return 0;
}

