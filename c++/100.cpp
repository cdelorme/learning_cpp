
#include <iostream>
#include <string>

using namespace std;

class Parent {
    protected:
        int x, y;
    public:
        void setPosition(int x, int y) {
            this->x = x;
            this->y = y;
        }
        void display() {
            cout << x << ", " << y << endl;
        }
};

class Child : public Parent {
};


int main() {

    // static cast is a c++ 11 style type-safe cast
    float f = 2.4f;
    int i = static_cast<int>(f);
    cout << i << endl;

    // this does not check like a dynamic cast prior to converting
    // however, it is by default converts the pointers to the desired class

    // for a class based example we have to use the pointer type
    Parent *p;
    Child *c;

    c = static_cast<Child*>(p);

    // because it does not do the checks it will be much faster than the original cast type
    // another huge benefit is when a class has same variables but not methods, and is not a child class
    // because we can still convert it!

    return 0;
}

