
#include <iostream>

using namespace std;


// you can overload operators to define alternative types when adding or subtracting for basic operations
// this is exceptionally useful for data-only classes

class Player {
    private:
        int health;
    public:
        Player() :
            health(100) {}
        int getHealth() {
            return this->health;
        }
        void operator+(Player p) {
//            this->health += p.getHealth();
            cout << "Add" << endl;
        }
        void operator++() {
            cout << "prefix" << endl;
        }
        void operator++(int p) {
            cout << "postfix" << endl;
        }
        void operator+=(Player p) {
            cout << "+=" << endl;
            this->health += p.getHealth();
        }
};


int main() {

    // what happens if we add two players?
    Player p1, p2;

    // if we have a viable override, this will run whatever is inside of that
    p1 + p2;

    // we can also override prefix ++
    ++p1;

    // postfix requires integer argument
    p1++;

    // also +=
    p1 += p2;

    // an example of the results of += which adds p2 health:
    cout << p1.getHealth() << endl;

    return 0;
}

