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
	PrintBoard();
}

void Board::placeShip(Ship ship, int xCord, int yCord, string direction){
	int change = 0;
	int BoardLoc = yCord*10 + xCord;
	//ship.placeShip(BoardLoc, direction);
	//for (int i = ship.getShipLength(); i = 0; i--){
	for (int i = 5; i > 0; i--){
		if (direction == "North" || direction == "South"){
			change = 10;
			printf("THINGS");
			//if (direction == "North") board[BoardLoc - change] = '*';
			//if (direction == "South") board[BoardLoc + change] = '*';
			if (direction == "North"){
				board[BoardLoc] = '*';
				BoardLoc -= change;
			}
			if (direction == "South"){
				board[BoardLoc] = '*';
				BoardLoc += change;
			}
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

void Board::PrintBoard(){
//	vector<char> Board(100, 'O'); //temp board of all empty spaces !!!

	printf("   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |\n");
	printf("============================================\n");
	for(int i = 0; i < 10; i++){
		printf("%c  |", 65+i); //
		for(int j = 0; j < 10; j++){
			//printf(" %c |", Board[10*i+j]);
			printf(" %c |", board[10*i+j]);	
			
			/*
			   Here we will print our board map/vector
			   - are we printing both sets of ships of just players?
			   */
		}
		printf("\n");
	}
}
