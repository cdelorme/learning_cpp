
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string line("Whee worldly hi");
    string s;

    // we can use a function to copy string data instead of =
    s.assign(line);
    cout << s << endl;

    // we can use substring to grab parts of a string
    string s2 = line.substr(5, 7);
    cout << s2 << endl;

    return 0;
}

