
#include <iostream>
#include <string>
#include <queue>
#include <iterator>

using namespace std;

int main() {

    // this type of queue has a front and back functionality, very much the same as a list
    deque<string> names;

    // now we have push_back and push_front
    names.push_back("Jamie Smith");
    names.push_front("Casey DeLorme");

    // we can now use a normal for loop like before
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }

    // you can also use front and back
    cout << names.front() << endl;
    cout << names.back() << endl;

    // we also have a pop_back and pop_front
    names.pop_front();
    names.pop_back();
    cout << names.size() << endl;

    return 0;
}

