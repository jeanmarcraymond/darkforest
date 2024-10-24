#ifndef SUPER_WEAPON_H
#define SUPER_WEAPON_H

#include <string>
#include "Weapon.h"

using namespace std;

class SuperWeapon : public Weapon{

    private:
        int doubler_;

    public: 
        SuperWeapon(string name, int damage) : Weapon(name, damage) {
            doubler_=1;
        }


        int attack() {

            int superDamage = doubler_ * damage_;
            doubler_ = doubler_ * 2;

            cout << "super j'attack damange!" << superDamage << "\n";

            return superDamage;
        }

};

#endif //SUPER_WEAPON_H