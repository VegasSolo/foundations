#include <iostream>
#include "Ship.h"
#include "Player.h"
using namespace std;

int main()
{
	int row, col;
	char orientation;
	string choice; //nonsense choice in order to allow delay between switching of players
	const string p1 = "Player 1";
	const string p2 = "Player 2";
	string currentPlayer = p1;
	
	Player player1;
	Player player2;
		
	cout << "\n********************************************\n";
	cout << "********** Welcome to Battleship! **********\n";
	cout << "********************************************\n\n";
	cout << "This is a two-player game that prints out two \n"
		 << "10x10 boards. Please set your terminal to at \n"
		 << "least 24 height to see one full board. Thanks.\n\n";
	cout << "********************************************\n";
	cout << "We will first place both player's ships.\n";
	cout << "The ships will be placed at a starting location \n";
	cout << "and from there, they will always go down or to the right.\n";
	cout << "Player 1, are you ready to begin? ";
	cin >> choice;
	cout << endl;
	
	int count = 0;
	int dcount1 = 0;
	int rcount1 = 0;
	int scount1 = 0;
	int bcount1 = 0;
	int ccount1 = 0;
	int dcount2 = 0;
	int rcount2 = 0;
	int scount2 = 0;
	int bcount2 = 0;
	int ccount2 = 0;
	char shipChoice = ' ';

	while (count < 5)
	{
		if (currentPlayer == p1)
			cout << p1;
		if (currentPlayer == p2)
			cout << p2;
		cout << ", please enter the ship you would like to place: \n";
		if (dcount1 < 1)
			cout << "Enter D for [D]estroyer (size 2), ";
		if (rcount1 < 1)
			cout << "r for C[r]uiser (size 3), \n";
		if (scount1 < 1)
			cout << "S for [S]ubmarine (size 3), ";
		if (bcount1 < 1)
			cout << "B for [B]attleship (size 4), \n";
		if (ccount1 < 1)
			cout << "and C for [C]arrier (size 5):" << endl;
		cin >> shipChoice;
		shipChoice = toupper(shipChoice);
		if (currentPlayer == p1)
		{
			player1.print();
			switch (shipChoice)
			{
				case 'D':
					cout << "Player 1, please pick a starting row for the Destroyer (size 2) ship: ";
					cin >> row;
					cout << "Player 1, please pick a starting column for the Destroyer (size 2) ship: ";
					cin >> col;
					cout << "Player 1, please pick the orientation, [V]ertical or [H]orizontal, for the Destroyer (size 2) ship: ";
					cin >> orientation;
					player1.placeShip(Destroyer, row, col, orientation);
					player1.print();
					++dcount1;
					break;
				case 'R':
					cout << "Player 1, please pick a starting row for the Cruiser (size 3) ship: ";
					cin >> row;
					cout << "Player 1, please pick a starting column for the Cruiser (size 3) ship: ";
					cin >> col;
					cout << "Player 1, please pick the orientation, [V]ertical or [H]orizontal, for the Cruiser (size 3) ship: ";
					cin >> orientation;
					player1.placeShip(Cruiser, row, col, orientation);
					player1.print();
					++rcount1;
					break;
				case 'S':
					cout << "Player 1, please pick a starting row for the Submarine (size 3) ship: ";
					cin >> row;
					cout << "Player 1, please pick a starting column for the Submarine (size 3) ship: ";
					cin >> col;
					cout << "Player 1, please pick the orientation, [V]ertical or [H]orizontal, for the Submarine (size 3) ship: ";
					cin >> orientation;
					player1.placeShip(Submarine, row, col, orientation);
					player1.print();
					++scount1;
					break;
				case 'B':
					cout << "Player 1, please pick a starting row for the Battleship (size 4) ship: ";
					cin >> row;
					cout << "Player 1, please pick a starting column for the Battleship (size 4) ship: ";
					cin >> col;
					cout << "Player 1, please pick the orientation, [V]ertical or [H]orizontal, for the Battleship (size 4) ship: ";
					cin >> orientation;
					player1.placeShip(Battleship, row, col, orientation);
					player1.print();
					++bcount1;
					break;
				case 'C':
					cout << "Player 1, please pick a starting row for the Carrier (size 5) ship: ";
					cin >> row;
					cout << "Player 1, please pick a starting column for the Carrier (size 5) ship: ";
					cin >> col;
					cout << "Player 1, please pick the orientation, [V]ertical or [H]orizontal, for the Carrier (size 5) ship: ";
					cin >> orientation;
					player1.placeShip(Carrier, row, col, orientation);
					player1.print();
					++ccount1;
					break;
			}
			cout << "********************************************\n";
			cout << "Player 1, press 1 to clear the screen: ";
			cin >> choice;
			cout << string(50, '\n');
			currentPlayer = p2;
			cout << "Player 2, are you ready to begin? ";
			cin >> choice;
		}
		if (currentPlayer == p1)
			cout << p1;
		if (currentPlayer == p2)
			cout << p2;
		cout << ", please enter the ship you would like to place: \n";
		if (dcount2 < 1)
			cout << "Enter D for [D]estroyer (size 2), ";
		if (rcount2 < 1)
			cout << "r for C[r]uiser (size 3), \n";
		if (scount2 < 1)
			cout << "S for [S]ubmarine (size 3), ";
		if (bcount2 < 1)
			cout << "B for [B]attleship (size 4), \n";
		if (ccount2 < 1)
			cout << "and C for [C]arrier (size 5):" << endl;
		cin >> shipChoice;
		shipChoice = toupper(shipChoice);
		if (currentPlayer == p2)
		{
			player2.print();
			switch (shipChoice)
			{
				case 'D':
					cout << "Player 2, please pick a starting row for the Destroyer (size 2) ship: ";
					cin >> row;
					cout << "Player 2, please pick a starting column for the Destroyer (size 2) ship: ";
					cin >> col;
					cout << "Player 2, please pick the orientation, [V]ertical or [H]orizontal, for the Destroyer (size 2) ship: ";
					cin >> orientation;
					player2.placeShip(Destroyer, row, col, orientation);
					player2.print();
					++dcount2;
					break;
				case 'R':
					cout << "Player 2, please pick a starting row for the Cruiser (size 3) ship: ";
					cin >> row;
					cout << "Player 2, please pick a starting column for the Cruiser (size 3) ship: ";
					cin >> col;
					cout << "Player 2, please pick the orientation, [V]ertical or [H]orizontal, for the Cruiser (size 3) ship: ";
					cin >> orientation;
					player2.placeShip(Cruiser, row, col, orientation);
					player2.print();
					++rcount2;
					break;
				case 'S':
					cout << "Player 2, please pick a starting row for the Submarine (size 3) ship: ";
					cin >> row;
					cout << "Player 2, please pick a starting column for the Submarine (size 3) ship: ";
					cin >> col;
					cout << "Player 2, please pick the orientation, [V]ertical or [H]orizontal, for the Submarine (size 3) ship: ";
					cin >> orientation;
					player2.placeShip(Submarine, row, col, orientation);
					player2.print();
					++scount2;
					break;
				case 'B':
					cout << "Player 2, please pick a starting row for the Battleship (size 4) ship: ";
					cin >> row;
					cout << "Player 2, please pick a starting column for the Battleship (size 4) ship: ";
					cin >> col;
					cout << "Player 2, please pick the orientation, [V]ertical or [H]orizontal, for the Battleship (size 4) ship: ";
					cin >> orientation;
					player2.placeShip(Battleship, row, col, orientation);
					player2.print();
					++bcount2;
					break;
				case 'C':
					cout << "Player 2, please pick a starting row for the Carrier (size 5) ship: ";
					cin >> row;
					cout << "Player 2, please pick a starting column for the Carrier (size 5) ship: ";
					cin >> col;
					cout << "Player 2, please pick the orientation, [V]ertical or [H]orizontal, for the Carrier (size 5) ship: ";
					cin >> orientation;
					player2.placeShip(Carrier, row, col, orientation);
					player2.print();
					++ccount2;
					break;
			}
		cout << "********************************************\n";
		cout << "Player 2, press 1 to clear the screen: ";
		cin >> choice;
		cout << string(50, '\n');
		currentPlayer = p1;
		cout << "Player 1, are you ready to begin? ";
		cin >> choice;
		}
		++count;
	}
	
	cout << "********************************************\n";
	cout << "******************* Time *******************\n";
	cout << "******************** to ********************\n";
	cout << "****************** Shoot! ******************\n";
	cout << "********************************************\n";
	cout << "\nContinue? ";
	cin >> choice;
	currentPlayer = p1;
	cout << string(50, '\n');
	
	//Game begin
	bool valid = false;
	bool attackHit = false;
	bool gameover = false;

	while (!gameover)
	{
		// 1 - get input
		cout << currentPlayer << ": Time to attack!\n";
		cout << "Enter a row: ";
		cin >> row;
		cout << "Enter a column: ";
		cin >> col;

		// 2 - check input and make sure it is valid
		while (!valid)
		{
			while (((col-1) < 0) || ((col-1) >= 10))
			{
				cout << "Invalid selection! Enter another column between 1 and 10: ";
				cin >> col;
			}
			while (((row-1) < 0) || ((row-1) >= 10))
			{
				cout << "Invalid selection! Enter another row between 1 and 10: ";
				cin >> row;
			}
			if (currentPlayer == p1)
			{	
				valid = player1.isEmpty(row-1, col-1);
				if (!valid) 
				{
					cout << "You've already attacked there!\n";
					cout << "Enter a new row between 1 and 10: ";
					cin >> row;
					cout << "Enter a new column between 1 and 10: ";
					cin >> col;
				}
			}
			else if (currentPlayer == p2)
			{
				valid = player2.isEmpty(row-1, col-1);
				if (!valid) 
				{
					cout << "You've already attacked there!\n";
					cout << "Enter a new row between 1 and 10: ";
					cin >> row;
					cout << "Enter a new column between 1 and 10: ";
					cin >> col;
				}
			}			
		}
		--row;
		--col;
		// 3 - check if hit
		if (currentPlayer == p1)
		{
			attackHit = player2.isHit(row, col);
			player1.targetHit(attackHit, row, col);
			if (attackHit)
				cout << "\nIt's a hit!" << endl;
			else
				cout << "\nMiss!" << endl;
		}
		else if (currentPlayer == p2)
		{
			attackHit = player1.isHit(row, col);
			player2.targetHit(attackHit, row, col);
			if (attackHit)
				cout << "\nIt's a hit!" << endl;
			else
				cout << "\nMiss!" << endl;
		}

		// 4 - print currentPlayer's board
		if (currentPlayer == p1)
			player1.print();
		else if (currentPlayer == p2)
			player2.print();


		// 5 - check if player won
		if (currentPlayer == p1)
		{
			gameover = player2.isGameOver();
			if (gameover)
			{
				cout << p1 << " has won!\n";  
				return 0;
			}                                                             
		}
		else if (currentPlayer == p2)
		{
			gameover = player1.isGameOver();
			if (gameover)
			{
				cout << p2 << " has won!\n";
				return 0;
			}
		}
		
		// 6 - set player to the next player
		if (currentPlayer == p1)
		{
			currentPlayer = p2;
			cout << p1 << " press 1 to clear the screen: ";
			cin >> choice;
			cout << string(50, '\n');
			cout << currentPlayer << " its your turn. Are you ready? ";
			cin >> choice;
		}	
		else
		{
			currentPlayer = p1;
			cout << p2 << " press 1 to clear the screen: ";
			cin >> choice;
			cout << string(50, '\n');
			cout << currentPlayer << " its your turn. Are you ready? ";
			cin >> choice;
		}
		valid = false;
	}
	
	
	return 0;
}