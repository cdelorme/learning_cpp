
#include <iostream>
#include <string>

using namespace std;

// the template line has to exist before every separated class method (when separating header and implementation)

// class templates, similar to function templates, let us do some more crazy things
template<class T>
class Player {
    private:
        int health;
    public:
        Player() : health(100) {};
        T add(T a, T b) {
            cout << "Adding" << endl;
        }
        int getHealth() {
            return this->health;
        }
};

int main() {

    // now we have to specify the type for our player template
    Player <int> player;

    // sadly all definition of templates must be in the header file and cannot be part of the cpp file
    // therefore this example is moot (and I have no intention of testing it with a header file at the moment_
    //p.add(1, 2);

    // in general, templates allow flexibility at the cost of ambiguity
    // the ambiguity hurts both the compiler and possibly developers
    // generally I prefer explicit definitions

    return 0;
}

