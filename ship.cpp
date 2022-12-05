#include "ship.h"
#include <string>

using namespace std;

Ship::Ship(int size){
    length = size;
}

void Ship::placeShip(int BoardLoc, string direction){
    location = BoardLoc;
}

int Ship::getShipLoc(int xCord, int yCord, string direction){
    int BoardLoc = yCord*10 + xCord;
    return BoardLoc;
}
 
void Ship::shipBeenHit(){
    hits++;
    isShipDead();
}

bool Ship::isShipDead(){
    if(hits == length) return true;
    return false;
}