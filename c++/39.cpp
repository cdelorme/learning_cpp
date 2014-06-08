
#include <iostream>

using namespace std;

class Player {
    protected:
        int health;
        int attackPower;
        int defense;
        int exp;
    public:
        // we can override and set default values inline, reducing external code
        Player():
            health(100), defense(10), attackPower(10), exp(0) {};
        Player(int health):
            health(health) { cout << "Overload 2" << endl; };
        Player(int health, int attack, int defense, int exp) :
            health(health), attackPower(attack), defense(defense), exp(exp) {};
        ~Player();

        // proper scope aka "Player::" allows duplicate values as params
        void setHealth(int health) {
            Player::health = health;
        }
        int getHealth() {
            return Player::health;
        }
        int takeDamage(int damage) {
            Player::health -= damage;
            return Player::health;
        }
        int getAttack() {
            return Player::attackPower;
        }
};
Player::~Player() {
}

int main() {

    // now with pointers!
    Player playerOne, *playerTwo;

    // now we can access reference
    playerTwo = &playerOne;

    // modify health from default for demo
    playerOne.setHealth(200);

    // pointers do not allow the dot-operator, now we need to use a pointer symbol
    cout << playerTwo->getHealth() << endl;

    return 0;
}

