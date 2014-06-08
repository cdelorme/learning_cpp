
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main() {

    // here is how to check if a map value exists
    map<string, string> files;

    files["128mb"] = "saveFile";

    // if we wanted to see if "128mb" existed in a map we would use find() with an iterator
    map<string, string>::iterator it = files.find("128mb");
    if (it != files.end()) {
        cout << "Found 128mb" << endl;
    }

    // short-hand approach:
    if (files.end() != files.find("128mb")) {
        cout << "Found 128mb" << endl;
    }

    return 0;
}

