
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string line("Whee");

    // we can use the C built-in strlen to get the length
    // However, the preferred method is .length
    cout << line.length() << endl;

    return 0;
}

