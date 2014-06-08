
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

    // creating many instances with arrays
    Player players[4];

    // we can use the same array notation to set values to each
    Player morePlayers[4] = { 1, 2, 3, 4 };
    cout << morePlayers[0].getHealth() << endl;

    return 0;
}

