#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Board{
	public: 
		Board(int = 10); // default board size 10
		
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

	private:
		int numShips; //starts at 5 when 
		int size;
		
		std::vector<char> board; //- is empty, * is ship, X is hit 
		std::vector<char>:: iterator itr; //know where we are in the map 

};
#endif
