
#include <iostream>

using namespace std;

int main() {

    // if we want to create a pointer and a reference we could use the dereference character
    int x = 10;
    int &y = x;

    // it will continue to reference my value
    x -= 2;
    cout << y << endl;

    // unlike a pointer, this dereferenced value has exactly the same memory address as the pointer
    // it is less flexible but consumes less memory (if that was your goal)

    return 0;
}

