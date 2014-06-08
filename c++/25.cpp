
#include <iostream>

using namespace std;

int main() {

    // arrays by default point to the first value when dereferenced:
    int test[] = { 1, 2, 3 };

    // arrays are already pointers, so we can use the pointer character to get the referenced value
    // arrays are allocated in sequence, so a pointer address +1 lets us access each value in sequence (much like [index+1])
    cout << *test << endl;
    cout << *test + 1 << endl;
    cout << *test + 2 << endl;

    return 0;
}

