
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    map<string, int> stuff;

    // maps accept pairs
    pair<string, int> p;
    p.first = "key";
    p.second = 10;

    // a quicker alternative is to use the make_pair method which auto-detects the types
    p = make_pair("aKey", 12);

    // it can be added to a map via insert
    stuff.insert(p);
    cout << stuff["aKey"] << endl;

    // the fast way:
    stuff.insert(make_pair("key", 10));

    return 0;
}

