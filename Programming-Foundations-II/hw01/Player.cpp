#include "Ship.h"
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	for (int row = 0; row < 10; row++)
	{
		for(int col = 0; col < 10; col++)
		{
			attackGrid[row][col] = ' ';
		}
	}
	for (int row = 0; row < 10; row++)
	{
		for(int col = 0; col < 10; col++)
		{
			shipGrid[row][col] = ' ';
		}
	}
	destroyer = new Ship(Destroyer);
	cruiser = new Ship(Cruiser);
	submarine = new Ship(Submarine);
	battleship = new Ship(Battleship);
	carrier = new Ship(Carrier);
}

Player::~Player()
{
	delete destroyer;
	delete cruiser;
	delete submarine;
	delete battleship;
	delete carrier;
}

int Player::playerGetHP(ShipType type) const
{
    switch(type)
    {
		case Destroyer:
			return destroyer->getHP();
			break;
		case Cruiser:
			return cruiser->getHP();
			break;
		case Submarine:
			return submarine->getHP();
			break;
		case Battleship:
            return battleship->getHP();
            break;
        case Carrier:
            return carrier->getHP();
            break;
    }
    return 0;
}

void Player::placeShip(ShipType ship, int row, int col, char orientation)
{
	// *** Error Checking ***
	orientation = toupper(orientation);
	while (orientation != 'V' && orientation != 'H')
	{
		cout << "Incorrect orientation. Please enter [V]ertical or [H]orizontal: ";
		cin >> orientation;
		orientation = toupper(orientation);
	}
	switch(ship)
    {
		case Destroyer:
			if (orientation == 'V')
			{
				while (col < 1 || col >= 11)
				{
					cout << "Incorrect column number. Please enter a number between 1 and 10: ";
					cin >> col;
				}
				while ((row < 1 || row >= 10) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row][col-1]) != ' '))
				{
					cout << "Incorrect row number or space is in use. Please enter a number between 1 and 9: ";
					cin >> row;
					if (shipGrid[row-1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 9: ";
						cin >> row;
					}
					else if (shipGrid[row][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 9: ";
						cin >> row;
					}
				}
			}
			else if (orientation == 'H')
			{
				while (row < 1 || row >= 11)
				{
					cout << "Incorrect row number. Please enter a number between 1 and 10: ";
					cin >> row;
				}
				while ((col < 1 || col >= 10) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row-1][col]) != ' '))
				{
					cout << "Incorrect column number or space is in use. Please enter a number between 1 and 9: ";
					cin >> col;
					if (shipGrid[row-1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 9: ";
						cin >> col;
					}
					else if (shipGrid[row-1][col] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 9: ";
						cin >> col;
					}
				}
			}
			// *** Place Ship ***
			--row;
			--col;
			if (orientation == 'V')
			{
				shipGrid[row][col] = 'D';
				shipGrid[row+1][col] = 'D';
			}
			else if (orientation == 'H')
			{
				shipGrid[row][col] = 'D';
				shipGrid[row][col+1] = 'D';
			}
			break;
			
		case Cruiser:
			if (orientation == 'V')
			{
				while (col < 1 || col >= 11)
				{
					cout << "Incorrect column number. Please enter a number between 1 and 10: ";
					cin >> col;
				}
				while ((row < 1 || row >= 9) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row][col-1]) != ' ') || ((shipGrid[row+1][col-1]) != ' '))
				{
					cout << "Incorrect row number or space is in use. Please enter a number between 1 and 8: ";
					cin >> row;
					if (shipGrid[row-1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> row;
					}
					else if (shipGrid[row][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> row;
					}
					else if (shipGrid[row+1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> row;
					}
				}
			}
			else if (orientation == 'H')
			{
				while (row < 1 || row >= 11)
				{
					cout << "Incorrect row number. Please enter a number between 1 and 10: ";
					cin >> row;
				}
				while ((col < 1 || col >= 9) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row-1][col]) != ' ') || ((shipGrid[row-1][col+1]) != ' '))
				{
					cout << "Incorrect column number or space is in use. Please enter a number between 1 and 8: ";
					cin >> col;
					if (shipGrid[row-1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> col;
					}
					else if (shipGrid[row-1][col] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> col;
					}
					else if (shipGrid[row-1][col+1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> col;
					}
				}
			}
			// *** Place Ship ***
			--row;
			--col;
			if (orientation == 'V')
			{
				shipGrid[row][col] = 'r';
				shipGrid[row+1][col] = 'r';
				shipGrid[row+2][col] = 'r';
			}
			else if (orientation == 'H')
			{
				shipGrid[row][col] = 'r';
				shipGrid[row][col+1] = 'r';
				shipGrid[row][col+2] = 'r';
			}
			break;
			
		case Submarine:
			if (orientation == 'V')
			{
				while (col < 1 || col >= 11)
				{
					cout << "Incorrect column number. Please enter a number between 1 and 10: ";
					cin >> col;
				}
				while ((row < 1 || row >= 9) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row][col-1]) != ' ') || ((shipGrid[row+1][col-1]) != ' '))
				{
					cout << "Incorrect row number or space is in use. Please enter a number between 1 and 8: ";
					cin >> row;
					if (shipGrid[row-1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> row;
					}
					else if (shipGrid[row][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> row;
					}
					else if (shipGrid[row+1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> row;
					}
				}
			}
			else if (orientation == 'H')
			{
				while (row < 1 || row >= 11)
				{
					cout << "Incorrect row number. Please enter a number between 1 and 10: ";
					cin >> row;
				}
				while ((col < 1 || col >= 9) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row-1][col]) != ' ') || ((shipGrid[row-1][col+1]) != ' '))
				{
					cout << "Incorrect column number or space is in use. Please enter a number between 1 and 8: ";
					cin >> col;
					if (shipGrid[row-1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> col;
					}
					else if (shipGrid[row-1][col] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> col;
					}
					else if (shipGrid[row-1][col+1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 8: ";
						cin >> col;
					}
				}
			}
			// *** Place Ship ***
			--row;
			--col;
			if (orientation == 'V')
			{
				shipGrid[row][col] = 'S';
				shipGrid[row+1][col] = 'S';
				shipGrid[row+2][col] = 'S';
			}
			else if (orientation == 'H')
			{
				shipGrid[row][col] = 'S';
				shipGrid[row][col+1] = 'S';
				shipGrid[row][col+2] = 'S';
			}
			break;
			
		case Battleship:
			if (orientation == 'V')
			{
				while (col < 1 || col >= 11)
				{
					cout << "Incorrect column number. Please enter a number between 1 and 10: ";
					cin >> col;
				}
				while ((row < 1 || row >= 8) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row][col-1]) != ' ') || ((shipGrid[row+1][col-1]) != ' ') || 
					  ((shipGrid[row+2][col-1]) != ' '))
				{
					cout << "Incorrect row number or space is in use. Please enter a number between 1 and 7: ";
					cin >> row;
					if (shipGrid[row-1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 7: ";
						cin >> row;
					}
					else if (shipGrid[row][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 7: ";
						cin >> row;
					}
					else if (shipGrid[row+1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 7: ";
						cin >> row;
					}
					else if (shipGrid[row+2][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 7: ";
						cin >> row;
					}
				}
			}
			else if (orientation == 'H')
			{
				while (row < 1 || row >= 11)
				{
					cout << "Incorrect row number. Please enter a number between 1 and 10: ";
					cin >> row;
				}
				while ((col < 1 || col >= 8) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row-1][col]) != ' ') || ((shipGrid[row-1][col+1]) != ' ') || 
					  ((shipGrid[row-1][col+2]) != ' '))
				{
					cout << "Incorrect column number or space is in use. Please enter a number between 1 and 7: ";
					cin >> col;
					if (shipGrid[row-1][col-1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 7: ";
						cin >> col;
					}
					else if (shipGrid[row-1][col] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 7: ";
						cin >> col;
					}
					else if (shipGrid[row-1][col+1] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 7: ";
						cin >> col;
					}
					else if (shipGrid[row-1][col+2] != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 7: ";
						cin >> col;
					}
				}
			}
			// *** Place Ship ***
			--row;
			--col;
			if (orientation == 'V')
			{
				shipGrid[row][col] = 'B';
				shipGrid[row+1][col] = 'B';
				shipGrid[row+2][col] = 'B';
				shipGrid[row+3][col] = 'B';
			}
			else if (orientation == 'H')
			{
				shipGrid[row][col] = 'B';
				shipGrid[row][col+1] = 'B';
				shipGrid[row][col+2] = 'B';
				shipGrid[row][col+3] = 'B';
			}
			break;
			
        case Carrier:
			if (orientation == 'V')
			{
				while (col < 1 || col >= 11)
				{
					cout << "Incorrect column number. Please enter a number between 1 and 10: ";
					cin >> col;
				}
				while ((row < 1 || row >= 7) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row][col-1]) != ' ') || ((shipGrid[row+1][col-1]) != ' ') || 
					  ((shipGrid[row+2][col-1]) != ' ') || ((shipGrid[row+2][col-1]) != ' '))
				{
					cout << "Incorrect row number or space is in use. Please enter a number between 1 and 6: ";
					cin >> row;
					if ((shipGrid[row-1][col-1]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> row;
					}
					else if ((shipGrid[row][col-1]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> row;
					}
					else if ((shipGrid[row+1][col-1]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> row;
					}
					else if ((shipGrid[row+2][col-1]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> row;
					}
					else if ((shipGrid[row+3][col-1]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> row;
					}
				}
			}
			else if (orientation == 'H')
			{
				while (row < 1 || row >= 11)
				{
					cout << "Incorrect row number. Please enter a number between 1 and 10: ";
					cin >> row;
				}
				while ((col < 1 || col >= 7) || ((shipGrid[row-1][col-1]) != ' ') || 
				      ((shipGrid[row-1][col]) != ' ') || ((shipGrid[row-1][col+1]) != ' ') || 
					  ((shipGrid[row-1][col+2]) != ' ') || ((shipGrid[row-1][col+3]) != ' '))
				{
					cout << "Incorrect column number or space is in use. Please enter a number between 1 and 6: ";
					cin >> col;
					if ((shipGrid[row-1][col-1]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> col;
					}
					else if ((shipGrid[row-1][col]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> col;
					}
					else if ((shipGrid[row-1][col+1]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> col;
					}
					else if ((shipGrid[row-1][col+2]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> col;
					}
					else if ((shipGrid[row-1][col+3]) != ' ')
					{
						cout << "That space is already in use. Please enter a different number between 1 and 6: ";
						cin >> col;
					}
				}
			}
			// *** Place Ship ***
			--row;
			--col;
			if (orientation == 'V')
			{
				shipGrid[row][col] = 'C';
				shipGrid[row+1][col] = 'C';
				shipGrid[row+2][col] = 'C';
				shipGrid[row+3][col] = 'C';
				shipGrid[row+4][col] = 'C';
			}
			else if (orientation == 'H')
			{
				shipGrid[row][col] = 'C';
				shipGrid[row][col+1] = 'C';
				shipGrid[row][col+2] = 'C';
				shipGrid[row][col+3] = 'C';
				shipGrid[row][col+4] = 'C';
			}
			break;
			
    }
}

void Player::print() const // FIX to print numbers and letters on board
{
	cout << "                 Attack Board" << endl;
	cout << "     1   2   3   4   5   6   7   8   9   10\n";
	for(int row = 0; row < 10; row++)
	{
		cout << "   +---+---+---+---+---+---+---+---+---+---+\n";
		if (row+1 < 10)
			cout << row+1 << "  ";
		else
			cout << row+1 << " ";
		for(int col = 0; col < 10; col++)
		{
			cout << "| " << attackGrid[row][col] << " ";
		}
		cout << "|\n";
	}
	cout << "   +---+---+---+---+---+---+---+---+---+---+\n";

	cout << "                 Your Board" << endl;
	cout << "     1   2   3   4   5   6   7   8   9   10\n";
	for(int row = 0; row < 10; row++)
	{
		cout << "   +---+---+---+---+---+---+---+---+---+---+\n";
		if (row+1 < 10)
			cout << row+1 << "  ";
		else
			cout << row+1 << " ";
		for(int col = 0; col < 10; col++)
		{
			cout << "| " << shipGrid[row][col] << " ";
		}
		cout << "|\n";
	}
	cout << "   +---+---+---+---+---+---+---+---+---+---+\n";
}
		
bool Player::isHit(int row, int col) // lower health if hit & then update shipGrid
{
	if ((shipGrid[row][col]) != ' ')
	{
		switch ((shipGrid[row][col]))
		{
			case 'D':
				destroyer->lowerHP();
				if (destroyer->isSunk())
					cout << "The destroyer was sunk!\n";
				break;
			case 'r':
				cruiser->lowerHP();
				if (cruiser->isSunk())
					cout << "The cruiser was sunk!\n";
				break;
			case 'S':
				submarine->lowerHP();
				if (submarine->isSunk())
					cout << "The submarine was sunk!\n";
				break;
			case 'B':
				battleship->lowerHP();
				if (battleship->isSunk())
					cout << "The battleship was sunk!\n";
				break;
			case 'C':
				carrier->lowerHP();
				if (carrier->isSunk())
					cout << "The carrier was sunk!\n";
				break;
		}
		shipGrid[row][col] = 'X';
		return true;
	}
	else
		return false;
}
		
void Player::targetHit(bool hit, int row, int col) // // update attackGrid w/ O or X
{
	if (hit == true)
		attackGrid[row][col] = 'X';
	else 
		attackGrid[row][col] = 'O';
}

bool Player::isEmpty(int row, int col) const
{
	if (attackGrid[row][col] == 'O')
		return false;
	if (attackGrid[row][col] == 'X')
		return false;
	if (attackGrid[row][col] == ' ')
		return true;
	return false;
	//return ((attackGrid[row][col]) == ' '); 
}

bool Player::isGameOver() const
{
	bool win = false;
	win = destroyer->isSunk();
	if (win)
	{
		win = cruiser->isSunk();
		if (win)
		{
			win = submarine->isSunk();
			if (win)
			{
				win = battleship->isSunk();
				if (win)
				{
					win = carrier->isSunk();
					return win;
				}
					
			}
				
		}
			
	}
	return false;
}
		