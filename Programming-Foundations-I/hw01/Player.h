#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player
{
	public:
		Player();
		~Player();
		int playerGetHP(ShipType type) const;
		void placeShip(ShipType ship, int row, int col, char orientation); // FIX ??
		void print() const;
		bool isHit(int row, int col); // update shipGrid if hit
		void targetHit(bool hit, int row, int col); // update attackGrid w/ O or X
		bool isEmpty(int row, int col) const;
		bool isGameOver() const;
	private:
		Ship *destroyer;
		Ship *cruiser;
		Ship *submarine;
		Ship *battleship;
		Ship *carrier;
		char attackGrid[10][10];
		char shipGrid[10][10];
};

#endif