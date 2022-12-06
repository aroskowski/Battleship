#include "ship.h"
#include "board.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Board::Board(){
    size = 10;
    Ship ship = Ship(5); //ship of size 5
}

//Board::Board(int size=10){}

int Board::getSize() {
    return size; 
}

void Board::emptyBoard(){
    for(int i = 0; i < 100; i++){
        board.push_back('-');
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
    if(board[BoardLoc] == '*'){
        board[BoardLoc] = 'X';
        
    } else if (board[BoardLoc] == '-'){
        board[BoardLoc] = 'O';
        
    }
}

