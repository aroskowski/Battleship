#ifndef BOARD_H
#define BOARD_H

#include "ship.h"

#include <vector>
#include <string>

class Board{
	public: 
		Board();
		Board(int); // default board size 10

		void PrintBoard();
		//member function used to print out each player's individual board
		int getSize(); //user defined board -- size varies num ships 
		void emptyBoard(); //initiallizes board to all open water
		void placeShip(Ship, int, int, std::string); //known size ship
				//give location ship start position, ship size and direction
				//error check invalid position on board and direction strings
		void shotFired(int); // locate user shot and check if hit/miss
				//error check invalid position or repeated position
				//call hitShip if ship sunk print a death message for ship
						//decriment numShips;
		
		//Ship getShips(int); // helper function to return ship location 
	//  Ship ship();
	//	Ship ship2();
	//	Ship ship3();
	//	Ship ship4();
	//	Ship ship5();

	private:
		int numShips; //starts at 5 when 
		int size;
		
		std::vector<char> board; //- is empty, * is ship, X is hit 
	//	std::vector<char>:: iterator itr; //know where we are in the map 

};
#endif
