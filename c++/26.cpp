
#include <iostream>

using namespace std;

int main() {

    // arrays by default point to the first value when dereferenced:
    int test[] = { 1, 2, 3 };
    int *p = test;

    // now we can use the variable and ++ in a loop for example to quickly iterate all values
    cout << *p << endl;
    p++;
    cout << *p << endl;

    // we can also manipulate each value
    p++;
    *p = 25;
    cout << *p << endl;

    return 0;
}

