
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
        void Attack() {
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

    Player player;

    // we can create an entity to map to our player, because our player is an entity
    Entity *entity = &player;

    // unless `Attack()` is defined on entity, this would not work
    entity->Attack();

    // this will spit out difference information
    player.Attack();

    return 0;
}

