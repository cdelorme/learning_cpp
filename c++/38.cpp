
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

    // We can get even more explicit via:
    Player players[4] = { Player(100), Player(20), Player(60, 1000, 60, 75), Player(10) };
    cout << players[0].getHealth() << endl;
    cout << players[3].getAttack() << endl;
    cout << players[2].getAttack() << endl;

    // notice because our second override never sets attack, etc, we may see a random value with the second output, which is whatever was at the memory address when we allocated it

    return 0;
}

