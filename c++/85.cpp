
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

    // so we have stacks for lifo, queue for fifo
    // there is also a priority queue which hits the highest value first

    // imagine a turn based system where decision order is less important than character speed
    priority_queue<int> q;

    q.push(10);
    q.push(40);
    q.push(5);

    // let's grab the size to iterate all items
    int length = q.size();

    for (int i = 0; i < length; i++) {
        cout << q.top() << endl;
        q.pop();
    }

    // this one has top, like the stack

    return 0;
}

