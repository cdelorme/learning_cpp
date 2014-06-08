
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    vector<int> numbers;

    // you can also reserve space in memory without actually adding to the size
    numbers.reserve(4);
    cout << numbers.size() << endl;

    // now we don't have to allocate memory later, which can be super if we know we will need a large amount of memory later

    return 0;
}

