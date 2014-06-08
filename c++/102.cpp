
#include <iostream>
#include <string>

using namespace std;

class A {
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

class B {
};

int main() {

    // reinterpret cast is unique
    // it is the least safe casting type
    // may be useful during deserialization of complex data, such as after network transmission
    // it performs no checks, and can result in volatile data or improperly allocated space

    // these have no relation
    B *b;
    A *a;

    // we can cast, but dereferencing could be unsafe or invalid
    a = reinterpret_cast<A*>(b);

    return 0;
}

