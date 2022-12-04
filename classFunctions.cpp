#include "ship.h"
#include "board.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Board::getSize() {return size; }

void Board::emptyBoard(){
    for(int i = 0; i < 100; i++){
        board[i] = '-';
    }
}

void Board::placeShip(int xCord, int yCord, string direction){

}
