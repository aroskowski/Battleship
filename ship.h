//Anika Roskowski - partner Austin Strobel
#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship{
	public:
		Ship(int, int, int, std::string);//col, row, size, direction
		Ship(const Ship &);//if passing into function by value 
		~Ship(); //if using new

		int getShipLoc(); //1d vector for board start loccation = row*size + col
		int shipBeenHit(); //inc hits //calls isShipDead()
		bool isShipDead();

	private:
		int length;
		std::string direction;
		int col;
		int row;
		int location; //location = row*size + col
		int hits;

};
#endif
