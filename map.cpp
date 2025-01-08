#include <iostream>
#include <vector>
#include "getch.h"
#include <conio.h>


const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 10;

void displayMap(const std::vector<std::string>& map, int coordX, int coordY){
    system("cls");

    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x=0; x < MAP_WIDTH; x++){
            if(coordX == x && coordY == y){
                std::cout << 'X';
            }else{
                std::cout << map[y][x];
            }
        }
    std::cout << "\n";
    }
    
}

int main(){

    int coordx = 0, coordy = 0;

    std::vector<std::string> map(MAP_HEIGHT, std::string(MAP_WIDTH,'.'));
   
    while(true){
        displayMap(map, coordx, coordy);
        char ch = getch();
        switch (ch) {
            case 'w': if(coordy!=MAP_HEIGHT-MAP_HEIGHT){coordy --;} break;
            case 's': if(coordy!=MAP_HEIGHT-1){coordy ++;} break;
            case 'a': if(coordx!=MAP_WIDTH-MAP_WIDTH){coordx --;} break;
            case 'd': if(coordx!=MAP_WIDTH-1){coordx ++;} break;
        }
    }
}

