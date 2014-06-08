
#include <iostream>
#include "48.h"

// the pramga once should prevent this from causing a problem
#include "48.h"

using namespace std;

// implementation
Player::Player() {
    this->health = 100;
}
int Player::getHealth() {
    return this->health;
}

int main() {

    Player player;
    cout << player.getHealth() << endl;

    return 0;
}

