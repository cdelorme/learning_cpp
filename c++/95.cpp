
#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator>

using namespace std;

int main() {

    // unordered sets are not in order
    unordered_set<int> n;
    unordered_set<int>::iterator i;

    // unordered_multiset is also available

    n.insert(1);
    n.insert(14);
    n.insert(10);

    for (i = n.begin(); i != n.end(); i++) {
        cout << *i << endl;
    }

    // notice the order comes out randomly

    return 0;
}

