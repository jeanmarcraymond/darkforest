#include <iostream>
#include <vector>
#include "Weapon.h"
#include "WimpyWeapon.h"
#include "SuperWeapon.h"
#include "Mappable.h"
#include <conio.h>
#include <fstream>

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 10;
const std::string FILE_NAME = "darkforest.dat";

void displayMap( std::vector<Mappable*>& mappables, int coordX, int coordY){
    system("cls");
    int i=0;
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x=0; x < MAP_WIDTH; x++){
            if(coordX == x && coordY == y){
                std::cout << 'X';
                for(Mappable* m:mappables){
                    
                    if (m->getY() == coordY && m->getX() == coordX){
                     mappables.erase(mappables.begin() + i);//error
                     
                     
                    }
                    i++;
                }
            } 

            else{
                bool found=false;
                for(Mappable* m:mappables){
                    
                    if (m->getY() == y && m->getX() == x){
                     std::cout << m->getSymbol();   
                     found=true;
                    }
                }
                if (!found){
                std::cout << '.';
                }
            }
             
        }

    std::cout << "\n";
    }
    
}

void saveGame(int coordx, int coordy){
    std::ofstream outFile(FILE_NAME);

    outFile << MAP_HEIGHT << " " << MAP_WIDTH << "\n";
    outFile << coordx << " " << coordy << "\n";
    outFile << '\n';

    std::cout << "Game saved\n";

}

bool loadGame(int& coordx, int& coordy){
    std::ifstream inFile(FILE_NAME);
    if(!inFile){
      //  std::cerr << "Error loading " << FILE_NAME << "\n";
        return false;
    }

    int height, width; // read and throw away for now
    inFile >> height >> width;
    inFile >> coordx >> coordy;

    return true;

}

int main(){

    int coordx = 0, coordy = 0;
    WimpyWeapon ww("wimpy weapon");
    SuperWeapon sw("super weapon", 1);
    Weapon w("weapon", 1);

    std::vector<Mappable*> mappables={&ww, &sw, &w};
    

    char ch;

        ww.setX(3);
    ww.setY(3);
    sw.setX(2);
    sw.setY(7);
    w.setX(8);
    w.setY(6);
    loadGame(coordx, coordy);

    while(ch != 'x'){
        displayMap(mappables, coordx, coordy);
        ch = getch();
        switch (ch) {
            case 'w': if(coordy!=MAP_HEIGHT-MAP_HEIGHT){coordy --;} break;
            case 's': if(coordy!=MAP_HEIGHT-1){coordy ++;} break;
            case 'a': if(coordx!=MAP_WIDTH-MAP_WIDTH){coordx --;} break;
            case 'd': if(coordx!=MAP_WIDTH-1){coordx ++;} break;
            case 'x':
                std::cout << "Save Game (y/n)?:";

                if (getch() == 'y'){
                    saveGame(coordx, coordy);
                }
                break;
        }
    }
}

