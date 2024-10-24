#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

using namespace std;

class Weapon{

public:
    Weapon(string name, int damage){
        name_ = name;
        damage_ = damage;
    }

    virtual int attack(){
        cout << "j'attack!\n";
        return damage_;
    }

    string getDescription(){
        return name_ + "," + to_string(damage_);
    }

protected:
    string name_;
    int damage_;
};

#endif //WEAPON