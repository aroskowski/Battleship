#include "board.h"
#include "ship.h"
//#include "classFunctions.cpp"

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

void PrintBoard();
bool PlayerTurn(int);
int RandomNumber();

int main(){
	bool win = false;
	char play;
	int xPos, yPos;
	char inputX;
	string direction;
	int Turns = 0;

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
	
		//Setup board - place all ships. 
		//NEED TO FIX -- Hard coded to only one board!!!
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
		}
		while(!playBoard->placeShip(5, xPos, yPos, direction));
		
		//place ships until successful placement with random number generator
		while(!oppBoard->placeShip(5, RandomNumber(), RandomNumber(), "East")){
			printf("Hello!");
		}
		
		printf("\nYour board: \n");
		playBoard->PrintBoard();
		printf("\nOpponent's board: \n");
		oppBoard->PrintBoard();
		printf("\n");


		//Play the game! - Fire shots till there is a winner. 
		while(Turns < 100 || !win){
			printf("Turn: %i\n", Turns);
			
			if(PlayerTurn(Turns)){
				printf("Please select your target.\n\tEnter row character (A-J) and single digit column number (0-9): ");
				cin >> inputX >> yPos;
				xPos = inputX - 65;

				printf("The target cords are %i, %i.\n", xPos, yPos);
			
				oppBoard->shotFired(xPos, yPos);
				oppBoard->PrintBoard();
		
				printf("\t Finished Players Turn, starting opponents turn. \n");
			}
			//tried with else, else if, and just if: Nothing worked no idea why. pls explain
			if(!PlayerTurn(Turns)){
				int x, y;
				x = RandomNumber();
				y = RandomNumber();
				printf("The target cords are %i, %i.\n", x, y);

				playBoard->shotFired(x, y);
				playBoard->PrintBoard();
			}

			Turns++;
		}


		cout << endl;
		win = true; //exit case
	}

	delete playBoard;
	delete oppBoard;

	return 0;
}

bool PlayerTurn(int turn){
	while (turn < 100) {
		if (turn % 2 == 0){
			return true;
		}
	}
	return false;
	//cant return in a while loop since you may never enter the while loop
}

int RandomNumber(){
	srand((unsigned) time(NULL));
	return (rand() % 10);
}



