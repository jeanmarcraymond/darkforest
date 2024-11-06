#ifndef WIMPY_WEAPON_H
#define WIMPY_WEAPON_H

#include <string>
#include "Weapon.h"

using namespace std;

class WimpyWeapon : public Weapon{


    public: 
        WimpyWeapon(string name) : Weapon(name, 1) {
    
        }


        int attack() {

            cout << "wimpy j'attack damange!" << damage_ << "\n";

            return damage_;
        }

};

#endif //SUPER_WEAPON_H