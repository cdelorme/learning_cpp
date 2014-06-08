
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    map<string, float> s;

    s["casey"] = 4.0;
    s["john"] = 3.8;

    // super shorthand "ranged for loop" (aka foreach)
    for (auto &i : s) {
        i.second = 10;
    }

    // if we don't provide the iterator as a reference, it won't change the original, it creates a copy
    cout << s["casey"] << endl;

    return 0;
}

