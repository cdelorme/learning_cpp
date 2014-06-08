
#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}
//int add(int a, int b, int c) {
//    return a + b + c;
//}
// we can set optional params by setting a default
int add(int a, int b, int c, int d = 0) {
    return a + b + c + d;
}

// methods are not just the name but the parameters, which creates a signature
// so we can have an "add" for doubles too:
double add (double a, double b) {
    cout << "Using double add" << endl;
    return a + b;
}

int main() {

    // function with parameters, and overloading (more params same method name)
    cout << add(12, 15) << endl;
    cout << add(12, 15, 5) << endl;
    cout << add(12, 15, 5, 7) << endl;

    // double addition
    cout << add(15.5, 12.7) << endl;

    return 0;
}

