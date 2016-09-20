#ifndef SHIP_H
#define SHIP_H

enum ShipType
{
	Destroyer, Cruiser, Submarine, Battleship, Carrier
};

class Ship
{
	public:
		Ship(ShipType ship);
		int getHP() const; // return hp
		bool isSunk() const; // check hp = 0
		void lowerHP(); // lower ship hp by 1
	private:
		int size; // determined by shipname
		ShipType shipname; // enum shipname;
		int row;
		int col;
		char orientation; // v or h
		int hp; // determined by size
};

#endif