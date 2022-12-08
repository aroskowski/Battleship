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

bool Board::placeShip(Ship ship, int yCord, int xCord, string direction){
	int change = 0, count = 0;
	int BoardLoc = yCord*10 + xCord;
	int rowNum2;
	int rowNum1 = BoardLoc/10;
	//ship.placeShip(BoardLoc, direction);
	//for (int i = ship.getShipLength(); i = 0; i--){
	for (int i = 5; i > 0; i--){
		rowNum2 = BoardLoc/10;

		printf("Calculated Board Location is %i\n", BoardLoc);

		if(BoardLoc < 0 || BoardLoc > 99 ){
			printf("invalid ship placement. Choose another space. \n");
			return false;
		}
		if (direction == "North" || direction == "South"){
			change = 10;
			printf("change = 10\n");
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
			if( rowNum1 != rowNum2){
				printf("invalid board placement");
				return false;
			}
			change = 1;
			printf("change = 1\n");
			if (direction == "East"){
				printf("east boi\n");
				board[BoardLoc] = '*';
				BoardLoc += change;
			}
			if (direction == "West"){
				printf("WEST WORLD\n");
				board[BoardLoc] = '*';
				BoardLoc -= change;
			}
		}
		count++;
		if (BoardLoc < 0 || BoardLoc > 99){
			for (int j = 0; j < count; j++){
				board[BoardLoc] = '-';
				if (direction == "North"){
					change = 10;
					BoardLoc += change;
				} else if (direction == "South"){
					change = 10;
					BoardLoc -= change;
				} else if (direction == "East"){
					change = 1;
					BoardLoc -= change;
				} else if (direction == "West"){
					change = 1;
					BoardLoc += change;
				}
			}
		}
	}
	return true;

}

void Board::shotFired(int yPos, int xPos){
	int BoardLoc = yPos*10 + xPos;
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
