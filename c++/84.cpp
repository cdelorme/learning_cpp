
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

    // similar to a stack, but a fifo system
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    // so our for loop hits all keys
    int length = q.size();

    for (int i = 0; i < length; i++) {
        cout << q.front() << endl;
        q.pop();
    }

    // the key difference is font() vs top()
    // it also has a back() if you wanted to use it awkwardly

    return 0;
}

