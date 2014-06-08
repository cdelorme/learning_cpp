
#include <iostream>

using namespace std;

class OffensiveEntity {
    protected:
        int attack;
    public:
        OffensiveEntity():
            attack(10) {};
        OffensiveEntity(int attack) :
            attack(attack) {};
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
        LivingEntity(int health) :
            health(health) {};
        void setHealth(int health) {
            LivingEntity::health = health;
        }
        int getHealth() {
            return LivingEntity::health;
        }
};

class Player : public OffensiveEntity, public LivingEntity {
    public:
        // with the other constructors we can now override defaults via:
        Player() :
            OffensiveEntity(60), LivingEntity(1000) {};
        void Attack() {
            cout << "Player Attack: " << Player::attack << endl;
        }
};

int main() {

    Player player;

    // now a player should have much more health and attack than standard entities
    cout << player.getHealth() << endl;
    cout << player.getAttack() << endl;

    return 0;
}

