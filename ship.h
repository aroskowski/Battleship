#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship{
	public:
		Ship(int);//size
		//Ship(const Ship &){} 
		//if passing into function by value 
		~Ship(){} //if using new

        void placeShip(int, std::string);
        int getShipLength(){
			return length;
		}
		int getShipLoc(int, int, std::string); //1d vector for board start loccation = row*size + col
		void shipBeenHit(); //inc hits //calls isShipDead()
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
