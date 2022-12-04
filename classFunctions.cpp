#include "ship.h"
#include "board.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Board::Board(int size = 10){
    Ship Five(5);
    Ship Four(4);
    Ship Three1(3);
    Ship Three2(3);
    Ship Two(2);
}
int Board::getSize() {return size; }

void Board::emptyBoard(){
    for(int i = 0; i < 100; i++){
        board[i] = '-';
    }
}

void Board::placeShip(Ship ship, int xCord, int yCord, string direction){
    int change = 0;
    int BoardLoc = yCord*10 + xCord;
    ship.placeShip(BoardLoc, direction);
    for (int i = ship.getShipLength(); i = 0; i--){
        if (direction == "North" || direction == "South"){
            change = 10;
            if (direction == "North") board[BoardLoc - change] = '*';
            if (direction == "South") board[BoardLoc + change] = '*';
        }
        if (direction == "East" || direction == "West"){
            change = 1;
            if (direction == "East") board[BoardLoc + change] = '*';
            if (direction == "West") board[BoardLoc - change] = '*';
        }
    }
    
}

void Board::shotFired(int BoardLoc){ 
    
}

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