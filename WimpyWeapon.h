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
            Weapon::attack(); 

            cout << "wimpy j'attack damange!" << damage_ << "\n";

            return damage_;
        }
        char getSymbol() const override {
            return 'w';
        
        }

};

#endif //SUPER_WEAPON_H