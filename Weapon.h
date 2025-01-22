#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include "Mappable.h"

using namespace std;

int lastATK = 0;

class Weapon : public Mappable{

public:
    Weapon(string name, int damage){
        name_ = name;
        damage_ = damage;
        durability_ = 10;
    }
    
    Weapon(string name, int damage, int durability){
        name_ = name;
        damage_ = damage;
        durability_ = durability;
    }

    virtual int attack(){
        cout << "j'attack!\n";
        
        if (durability_ >0 ) durability_ --;
        if (durability_ == 0){
             damage_ = 0;
             cout << "your weapon is broken\n";

        }
        
        lastATK = damage_;

        return damage_;
    }

    string getName(){
        return name_;
    }

    virtual string getDescription(){
        return name_ + "," + to_string(damage_);
    }

    bool isBroken(){
        if (durability_ <=0 ) return true;
        return false;
    }

    int getX() const override{
        return x_;
    }
    int getY() const override{
        return y_;
    }
    void setX(int x) override {
        x_ = x;
    }
    void setY(int y) override {
        y_ = y;
    }
    char getSymbol() const override {
        return 'W';
        
    }

protected:
    string name_;
    int damage_;
    int durability_;

    int x_,y_;
};

#endif //WEAPON