#include "board.h"
#include "ship.h"
//#include "classFunctions.cpp"

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintBoard();
bool PlayerTurn(int);

int main(){
	bool win = false;
	char play;
	int xPos, yPos;
	char inputX;
	string direction;

	Board *playBoard;
	playBoard = new Board();
	Board *oppBoard;
	oppBoard = new Board;

	printf("Would you like to play a game of battleship? (Type y or n): ");
	cin >> play;
	
	//playBoard->emptyBoard();
	//oppBoard->emptyBoard();
	cout << "Welcome to Battleship!" << endl << "The rules are simple: all entries should be lowercase and one character long" << endl;

	while(play == 'y' && !win){
		cout << endl << "Your board: " << endl;
		playBoard->emptyBoard(); //player's Board
		cout << endl << "Opponent's board: " << endl;
		oppBoard->emptyBoard(); //opponent's Board
		cout << endl;
		
		do{
			printf("Please place your Carrier (5 spaces long). \n\tEnter row charater (A-J), single digit column number (0-9), and direction (full word and capitalized, ex. \"North\"): "); 
			//scanf("%i %i", &xPos, &yPos);
			//cin >> direction;
			cin >> inputX >> yPos >> direction;
			xPos = inputX - 65;

			printf("the cords are %i, %i.", xPos, yPos);
			cout << "Facing the " << direction << endl;

			//playBoard->placeShip(5, xPos, yPos, direction);
			//playBoard->PrintBoard();
		}while(!playBoard->placeShip(5, xPos, yPos, direction));
		
		playBoard->PrintBoard();
		
		//Play the game!
		printf("Please select your target.\n\tEnter row character (A-J) and single digit column number (0-9)");
		cin >> inputX >> yPos;
		xPos = inputX - 65;

		printf("the target cords are %i, %i.", xPos, yPos);
		
		playBoard->shotFired(xPos, yPos);


		cout << endl;
		win = true; //exit case
	}

	//when I did ./battleship, I got a core dump, so I thought this would help...I was wrong
	delete playBoard;
	delete oppBoard;

	return 0;
}

/*
void PrintBoard(){
	vector<char> Board(100, 'O'); //temp board of all empty spaces !!!

	printf("   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |\n");
	printf("============================================\n");
	for(int i = 0; i < 10; i++){
		printf("%c  |", 65+i); //
		for(int j = 0; j < 10; j++){
			printf(" %c |", Board[10*i+j]);
			
			//   Here we will print our board map/vector
			//   - are we printing both sets of ships of just players?
		}
		printf("\n");
	}    
}*/

bool PlayerTurn(int turn){
	bool playerTurn = false;
	while (turn < 100) {
		//  int r = 0;
		//  int c = 0;
		//  int count = 0;
		//  char c1 = 't';

		if (turn % 2 == 0){
			playerTurn = true;
		}
	}
	return playerTurn;
	//cant return in a while loop since you may never enter the while loop
}

