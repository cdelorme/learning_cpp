
#include <iostream>

using namespace std;

class Player {
    protected:
        int health;
        int attackPower;
        int defense;
        int exp;
    public:
        Player();
        // alternative constructo with auto-setters
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
Player::Player() {
    Player::health = 100;
    Player::attackPower = 10;
    Player::defense = 10;
    Player::exp = 0;
}
Player::~Player() {
    // we can de-allocate anything here
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

