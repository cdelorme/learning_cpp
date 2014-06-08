
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
    // when main ends this is called to deallocate all special memory items, such as pointers and other objects
    cout << "Player has been deleted" << endl;
}

int main() {

    Player player;

    // we now see default values
    cout << player.getHealth() << endl;

    // We can also create one with alternative signature of parameters
    Player playerTwo(100, 50, 60, 76);

    // now it has our set values
    cout << playerTwo.getAttack() << endl;

    return 0;
}

