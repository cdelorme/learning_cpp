
#include <iostream>

using namespace std;

class Entity {
    protected:
        int health;
    public:
        Entity():
            health(100) {};
        void setHealth(int health) {
            Entity::health = health;
        }
        int getHealth() {
            return Entity::health;
        }
};

class Player : public Entity {
    // inherits health
};
class Enemy : public Entity {
    // inherits health
};

int main() {

    Player test;
    cout << test.getHealth() << endl;

    return 0;
}

