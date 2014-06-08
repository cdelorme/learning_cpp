
#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

int main() {

    forward_list<int> l;

    // you can only add elements to the front of a forward list
    l.push_front(2);

    cout << l.front() << endl;

    // like before we need an iterator to access in a loop

    return 0;
}

