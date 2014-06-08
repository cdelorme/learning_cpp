
#include <iostream>

using namespace std;

class Entity {
    protected:
        int attack;
    public:
        Entity():
            attack(10) {};
        int getAttack() {
            return Entity::attack;
        }
        virtual void Attack() {
            cout << "Entity Attack: " << Entity::attack << endl;
        }
};

class Player : public Entity {
    public:
        void Attack() {
            cout << "Player Attack: " << Player::attack << endl;
        }
};
class Enemy : public Entity {
};

int main() {

    // we can also do this
    Entity *entity = new Player;

    // since we named Attack as a virtual function, it will look at the derived or "originating" class instead
    entity->Attack();

    // this is incredibly powerful, when we have to supply a Player as an Entity to simplify parameters in a function elsewhere

    return 0;
}

