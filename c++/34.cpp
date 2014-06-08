
#include <iostream>

using namespace std;

// classes and structs
// classes all types are private by default
// struct is from C and all types are public by default

// it is preferred to use `class`
class Player {
    private:
        // I always prefer protected, private has very little purpose in most code
        // sensible uses include dependencies of your system, such that if someone extends your code that
        // cannot modify values your system depends on somehow (still not exactly a good reason)
    protected:
        int health;
        int attackPower;
        int defense;
        int exp;
    public:
        // we can optionally separate constructor methods from the class to simplify reading later
        Player();// constructor
        ~Player();// destructor
        void setHealth(int h) {
            health = h;
        }
        int getHealth() {
            return health;
        }
        int takeDamage(int d) {
            health -= d;
            return health;
        }
};
Player::Player() {
}
Player::~Player() {
    // we can de-allocate anything here
}

int main() {

    Player player;

    // we can use get/set methods at creation
    player.setHealth(100);
    cout << player.getHealth() << endl;

    // we can now call it inline, modify health and return the new value
    cout << player.takeDamage(10) << endl;

    return 0;
}

