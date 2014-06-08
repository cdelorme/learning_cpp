
#include <iostream>

using namespace std;

void damage(int &health) {
    health -= 10;
}

int main() {

    int health = 100;

    // we can pass variables by reference so they are changed within a function
    damage(health);

    // print changed value
    cout << "Health After Damage: " << health << endl;

    return 0;
}

