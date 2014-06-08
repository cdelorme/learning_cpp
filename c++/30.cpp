
#include <iostream>

using namespace std;

int main() {

    // we can also create a pointer to a pointer with dual asterisks
    int a = 10;
    int *b = &a;
    int **c = &b;

    cout << &a << endl;
    // pointers address
    cout << &b << endl;
    // pointers value (a's address)
    cout << b << endl;
    // value at final destination
    cout << *b << endl;
    // address of pointer to pointer (equal to b)
    cout << c << endl;
    // references memory address a
    cout << *c << endl;
    // still ends up at value of a
    cout << **c << endl;


    // both b and c have the same address, and all point at the memory address value of a

    return 0;
}

