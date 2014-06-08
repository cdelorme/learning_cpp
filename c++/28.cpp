
#include <iostream>

using namespace std;

// you can also reduce the memory footprint by taking advantage of pointers in arithmatic
int add(void *x, void *y) {
    return *(int *)x + *(int *)y;
}

int main() {

    // define a value
    int n = 2;

    // call the method and pass dereferenced address
    cout << add(&n, &n) << endl;

    return 0;
}

