
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

    // we can use dynamic casting to
    float f = 2.4f;

    // this will auto-convert
//    int i = f;
    // c-style cast
//    int i = (int)f;

    // for classes, that won't always work
    // in some cases we want a dynamic cast by reference (more type safe than static)
    Child c;
    Parent *p;

    // dynamic will check the class for compatibility, and reference is for pointer to data
    p = dynamic_cast<Parent*>(&c);

    // use dynamic when you want to convert something to a pointer or reference
    // of a class in a proper heirarchy, you cannot convert a parent to child, but you can child to parent

    return 0;
}

