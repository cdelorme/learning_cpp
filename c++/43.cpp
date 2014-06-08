
#include <iostream>

using namespace std;

class OffensiveEntity {
    protected:
        int attack;
    public:
        OffensiveEntity():
            attack(10) {};
        int getAttack() {
            return OffensiveEntity::attack;
        }
        virtual void Attack() {
            cout << "Offensive Entity Attack: " << OffensiveEntity::attack << endl;
        }
};
class LivingEntity {
    protected:
        int health;
    public:
        LivingEntity() :
            health(100) {};
        void setHealth(int health) {
            LivingEntity::health = health;
        }
        int getHealth() {
            return LivingEntity::health;
        }
};

class Player : public OffensiveEntity, public LivingEntity {
    public:
        void Attack() {
            cout << "Player Attack: " << Player::attack << endl;
        }
};

int main() {

    Player player;

    // now we can have attack and health from separate entities
    cout << player.getHealth() << endl;
    cout << player.getAttack() << endl;


    return 0;
}

