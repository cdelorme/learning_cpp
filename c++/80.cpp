
#include <iostream>
#include <stack>

using namespace std;

int main() {

    // stacks are similar to vectors, but serve a different purpose
    stack<int> numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);

    // we cannot access a stack via array index
    //cout << stack[0] << endl;// this will fail
    // the point of a stack is to get the highest item in the stack

    // you can either get the top element without modifying the stack (if you needed to access it many times
    cout << numbers.top() << endl;

    // when we are done we can pop the element off
    numbers.pop();
    cout << numbers.top() << endl;

    return 0;
}

