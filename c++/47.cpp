
#include <iostream>

using namespace std;

// abstract classes cannot be instantiated, but they can be inherited
class Entity {
    protected:
        int health;
        int attack;
    public:
        Entity() :
            health(10), attack(1) {
                cout << "Entity Constructor" << endl;
            };

        // virtual functions set to 0 prevent instances from existing
        virtual void setHealth(int health) = 0;
        virtual int getHealth() = 0;
        virtual void setAttack(int attack) = 0;
        virtual int getAttack() = 0;
        // another benefit is we now have forced any inherited classes to define the implementation of any virtual functions
};

class Player : public Entity {
    public:
        // an alternative approach to overriding super
//        Player() : Entity() {
//            this->health = 100;
//            this->attack = 10;
//        }
        // yet another approach
        Player() {
            this->health = 100;
            this->attack = 10;
        }
        void setHealth(int health) {
            this->health = health;
        }
        int getHealth() {
            return this->health;
        }
        void setAttack(int attack) {
            this->attack = attack;
        }
        int getAttack() {
            return this->attack;
        }
};

int main() {

    // this will fail
    //Entity e;

    // we can create an object if it has implemented all virtual methods
    Player p;
    cout << p.getHealth() << endl;

    return 0;
}

