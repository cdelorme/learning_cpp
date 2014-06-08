
#include <iostream>
#include <string>
#include <set>
#include <iterator>

using namespace std;

int main() {

    // a multi-set allows duplicates
    multiset<int> s;

    s.insert(1);
    s.insert(1);
    s.insert(10);
    s.insert(10);

    multiset<int>::iterator i;
    for (i = s.begin(); i != s.end(); i++) {
        cout << *i << endl;
    }

    // this (in my opinion) breaks the point of using a set

    return 0;
}

