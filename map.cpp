#include <iostream>
#include <vector>
#include "getch.h"
#include "WimpyWeapon.h"
#include "Mappable.h"
#include <conio.h>
#include <fstream>

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 10;
const std::string FILE_NAME = "darkforest.dat";

void displayMap(const std::vector<std::string>& map, int coordX, int coordY, Mappable* m){
    system("clear");

    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x=0; x < MAP_WIDTH; x++){
            if(coordX == x && coordY == y){
                std::cout << 'X';
            }else if(m->getX() == x && m->getY() == y){
                std::cout << m->getSymbol();
            }else{
                std::cout << '.';
            }
        }
    std::cout << "\n";
    }
    
}

void saveGame(const std::vector<std::string>& map, int coordx, int coordy){
    std::ofstream outFile(FILE_NAME);

    outFile << MAP_HEIGHT << " " << MAP_WIDTH << "\n";
    outFile << coordx << " " << coordy << "\n";
    outFile << '\n';

    std::cout << "Game saved\n";

}

bool loadGame(std::vector<std::string>& map, int& coordx, int& coordy){
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

    ww.setX(3);
    ww.setY(3);

    std::vector<std::string> map(MAP_HEIGHT, std::string(MAP_WIDTH,'.'));
    char ch;

    loadGame(map, coordx, coordy);

    while(ch != 'x'){
        displayMap(map, coordx, coordy, &ww);
        ch = getch();
        switch (ch) {
            case 'w': if(coordy!=MAP_HEIGHT-MAP_HEIGHT){coordy --;} break;
            case 's': if(coordy!=MAP_HEIGHT-1){coordy ++;} break;
            case 'a': if(coordx!=MAP_WIDTH-MAP_WIDTH){coordx --;} break;
            case 'd': if(coordx!=MAP_WIDTH-1){coordx ++;} break;
            case 'x':
                std::cout << "Save Game (y/n)?:";

                if (getch() == 'y'){
                    saveGame(map, coordx, coordy);
                }
                break;
        }
    }
}

