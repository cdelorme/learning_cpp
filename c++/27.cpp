
#include <iostream>

using namespace std;

int add(int x, int y) {
    return x + y;
}
int subtract(int x, int y) {
    return x - y;
}

int operation(int x, int y, int (*function) (int, int)) {
    return (*function)(x, y);
}

int main() {

    // now we can call it like this
    cout << operation(12, 5, add) << endl;
    cout << operation(12, 5, subtract) << endl;

    // we can also make references to a function via:
    int (*sub)(int, int) = subtract;

    // now I can pass that as my argument without the pointer character
    cout << operation(12, 5, sub) << endl;

    return 0;
}

