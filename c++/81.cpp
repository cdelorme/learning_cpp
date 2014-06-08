
#include <iostream>
#include <stack>

using namespace std;

int main() {

    // this is aka a lifo system
    stack<int> numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);

    // this for loop will not get all items, because size() gets called and changes per iteration (important to note)
    for (int i = 0; i <= numbers.size(); i++) {
        cout << numbers.top() << endl;
        numbers.pop();
    }

    return 0;
}

