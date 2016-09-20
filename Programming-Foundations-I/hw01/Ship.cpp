#include "Ship.h"
#include "Player.h"
#include <iostream>
using namespace std;

Ship::Ship(ShipType ship)
{
	row = 0;
	col = 0;
	orientation = ' ';
	
	switch (ship)
	{
		case Destroyer:
			shipname = Destroyer;
			size = 2;
			hp = size;
			break;
		case Cruiser:
			shipname = Cruiser;
			size = 3;
			hp = size;
			break;
		case Submarine:
			shipname = Submarine;
			size = 3;
			hp = size;
			break;
		case Battleship:
			shipname = Battleship;
			size = 4;
			hp = size;
			break;
		case Carrier:
			shipname = Carrier;
			size = 5;
			hp = size;
			break;
		default:
			cout << "Error initializing." << endl;
			break;
	}
}

int Ship::getHP() const
{
	return hp;
}

bool Ship::isSunk() const
{
	return (hp == 0);
}

void Ship::lowerHP()
{
	--hp;
}
