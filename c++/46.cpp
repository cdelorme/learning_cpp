
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
        Player() :
            OffensiveEntity(60), LivingEntity(1000) {};
        void Attack() {
            cout << "Player Attack: " << Player::attack << endl;
        }
};

// we can return a player instance
Player getPlayer() {
    return Player();
}

int main() {

    // we can get our player as a return value, treating it as its own type
    Player player = getPlayer();
    cout << player.getHealth() << endl;
    cout << player.getAttack() << endl;

    return 0;
}

