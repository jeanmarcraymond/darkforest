#include <iostream>
#include <vector>
#include <cstdlib> // Needed for rand() and srand()
#include "Weapon.h"
#include "SuperWeapon.h"  //this is the coolest game ever
#include "WimpyWeapon.h"
using namespace std;

int health  = 100;
   
int random_in_range(int range){
       // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number in the range 1-2
    int random_num = rand() % range + 1;

    return random_num;
}

Weapon* search(){

    
    
    int rand = random_in_range(3);
    Weapon* weapon;

    if(rand == 1){
       weapon = new Weapon("sword",10);
       
    }
    else if(rand == 2){
       weapon = new SuperWeapon("Supersword",1);
    }
    else{
        weapon = new WimpyWeapon("WimpySword");
    }
    cout << "You found a "  << weapon->getDescription() << "!\n";
    return weapon;
}

void goIntoTheForest(Weapon* weapon){

    cout << "You encounter a goblin in the forest!\n";
    int goblinHealth = 120;

    if (weapon == nullptr){
        cout << "The goblin attacks you\n";
        health = 0;
    }
    else {

       string selection = "";

       while (selection != "2" && goblinHealth >0){

            cout << "[1] attack\n";
            cout << "[2] run away\n";

            cin >> selection;

            if ("1" == selection){
                goblinHealth = goblinHealth - (weapon->attack());
                cout << "you attack the goblin. The goblin is at " <<  goblinHealth <<  " health.\n";
            }

       }
    }

}


int main() {

    vector <Weapon*> inventory;
    string selection;
    

    while ("x" != selection){

        cout << "Select an action!\n";
        cout << "[1] to search around you\n";
        cout << "[2] to view inventory\n";
        cout << "[3] go into the forest\n";
        cout << "[4] remove broken weapons";
        cout << "[x] to exit\n";

        cin >> selection;

        if ("1" == selection){
            inventory.push_back(search());
        }
        else if("2" == selection){
            cout << "Your inventory contains:\n";
            for(int i=0; i < inventory.size() ; i++){
                cout << inventory[i]->getDescription() << "\n";
            }
        }
        
        else if("3" == selection){
            cout << "Please choose a weapon!\n";
            for(int i=0;i<inventory.size();i++){
                cout << "choose " << i << " for the " << inventory[i]->getName() << " weapon\n" ;
            }
            int chosenNum=0;
            cin >> chosenNum;
            cout << "you have chosen the " << inventory[chosenNum]->getName() << " weapon!\n";
                 
            Weapon *weapon = nullptr;

            if (inventory.size() > 0){
                weapon = inventory[chosenNum];
            }
            goIntoTheForest(weapon);
        }

        else if ("4" == selection){
            
cout << "Please choose a weapon to remove from your inventory(x to exit):\n";
for(int i=0;i<inventory.size();i++){
                listBrokenWeapons(inventory);
            }
            string R = "";
            int D = 0;
            cin >> D;

cout << "you have chosen the " << inventory[D]->getName() << " weapon to delete\n" << "Are you sure that you want to delete the " << inventory[D]->getName() << " weapon?\n";

cin >> R;

cout << "Now deleting the " << inventory[D]->getName() << " weapon\n";

inventory.remove(D);

        }

        
        if(health <= 0){
            cout << "you died!\n";
            break;
        }
    }

    cout << "goodbye\n";
    return 0;
}

