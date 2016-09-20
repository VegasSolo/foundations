// Author:		Dillon VanBuskirk
// ID:			010688916
// Title:		Homework 5
// Started:		April 2, 2015
// Completed:	April 3, 2015 (barely 30 minutes after midnight - continued working next DAY
//								and added in randomization and others)

//---------------------------------------------------------------------------
// Program:  hw5.cpp
// Purpose:  This program simulates the board game called "Pay Day"
//---------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>

using namespace std;

const int ROWS = 4;
const int COLS = 6;
int ROLL_COUNT_1 = 0;  // counts for player 1 and 2 in order
int ROLL_COUNT_2 = 0;  // to determine the zero location of board when printing
int ROLL_COUNT = 3; // TOTAL roll count to determine which player's turn (default 3 so %2 is always 1)

//---------------------------------------------------------------------------
// Name: welcomeMessage
// Parameters: none
// Returns: none
// Purpose: This function displays a message to user explaining the game
//---------------------------------------------------------------------------
void welcomeMessage()
{
	cout << "Welcome to Payday! This is a game where you try to earn more money ";
	cout << "in a month than the other player. Each user will decide to roll the ";
	cout << "dice or pass their turn. The player will then move across the board. ";
	cout << "Certain events happen on the board when a player land on the ";
	cout << "corresponding letter. Once a player reaches the end of the month, ";
	cout << "their game is over." << endl;
}

//---------------------------------------------------------------------------
// Name: diceRoll
// Parameters: none
// Returns: int; value of roll
// Purpose: This function rolls the dice (1 - 6)
//---------------------------------------------------------------------------
int diceRoll()
{
    int roll = 0;
    roll = (rand() % 6) + 1;
    
    return roll;
}

//---------------------------------------------------------------------------
// Name: handleEvent
// Parameters: board; char array, pass by ref, game board 2D-array
//             event: char, pass by value, value of the location of the player
// Returns: double; value increase of the player's money
// Purpose: This function changes a player's money each roll and outputs event
//---------------------------------------------------------------------------
double handleEvent(const char board[ROWS][COLS], char event)
{
	double money = 0;
	int randEvent = 0;
	
	switch(event)
	{
		case 'G':
			randEvent = (rand() % 2) + 1;
			if (randEvent == 1)
			{
				cout << "Grandma sure does love you. She gave you $50" << endl;
				money = 50;
			}
			else
			{
				cout << "Grandma felt sorry for you. She gave you $120" << endl;
				money = 120;
			}
			break;
		case 'B':
			randEvent = (rand() % 2) + 1;
			if (randEvent == 1)
			{
				cout << "Time to pay the bills. You paid $850" << endl;
				money = -850;
			}
			else
			{
				cout << "Oh no! Your bills are overdue. You paid $850 plus $100 in fees" << endl;
				money = -950;
			}
			break;
		case 'P':
			randEvent = (rand() % 2) + 1;
			if (randEvent == 1)
			{
				cout << "It's pay day! You received $1000" << endl;
				money = 1000;
			}
			else
			{
				cout << "It's pay day and you worked holidays! You received $1250" << endl;
				money = 1250;
			}
			break;
		case 'F':
			randEvent = (rand() % 2) + 1;
			if (randEvent == 1)
			{
				cout << "Your dog needed some food. You had to pay $10" << endl;
				money = -10;
			}
			else
			{
				cout << "Your dog is fat and needed some food. You had to pay $20" << endl;
				money = -20;
			}
			break;
		case 'L':
			randEvent = (rand() % 2) + 1;
			if (randEvent == 1)
			{
				cout << "You won the Power Ball Lottery!! You received $150,000" << endl;
				money = 150000;
			}
			else
			{
				cout << "You won Mega Millions Lottery!!! You received $100,000" << endl;
				money = 100000;
			}

			break;
		case 'C':
			randEvent = (rand() % 2) + 1;
			if (randEvent == 1)
			{
				cout << "You were in a car wreck, ouch :(. You had $40,000 in repairs." << endl;
				money = -40000;
			}
			else
			{
				cout << "You were in a minor car wreck. You had $15,000 in repairs." << endl;
				money = -15000;
			}
			break;
	}
	return money;
}

//---------------------------------------------------------------------------
// Name: printBoard
// Parameters: board; char array, pass by ref, game board 2D-array
//             playerNumCol & Row; int, pass by value, location of player 1 & 2
// Returns: none
// Purpose: This function prints the board
//---------------------------------------------------------------------------
void printBoard(const char board[ROWS][COLS], 
                const int playerOneRow, const int playerOneCol, 
                const int playerTwoRow, const int playerTwoCol)
{
    cout << "\n+---+---+---+---+---+---+\n";
    for (int r = 0; r < ROWS; r++)
    {
        cout << "| ";
        for (int c = 0; c < COLS; c++)
        {
            if ((playerOneCol == c && playerOneRow == r) || (playerTwoCol == c && playerTwoRow == r))
			{
				if ((playerOneCol == playerTwoCol && playerOneRow == playerTwoRow) && (ROLL_COUNT_1 > 0 && ROLL_COUNT_2 > 0))
					cout << "3 | ";
				else if ((playerOneCol == c && playerOneRow == r) && (ROLL_COUNT_1 > 0))
					cout << "1 | ";
				else if ((playerTwoCol == c && playerTwoRow == r) && (ROLL_COUNT_2 > 0))
					cout << "2 | ";
				else if (ROLL_COUNT_1 == 0 || ROLL_COUNT_2 == 0)
					cout << board[r][c] << " | ";
			}
			else
			{
				cout << board[r][c];
				cout << " | ";
			}       
        }
        cout << "\n+---+---+---+---+---+---+\n";
    }
}

//---------------------------------------------------------------------------
// Name: randomBoard
// Parameters: board; char array, pass by ref, game board 2D-array
// Returns: none
// Purpose: This function randomizes the board with weighted values
//---------------------------------------------------------------------------
void randomBoard(char board[ROWS][COLS])
{
	int randSpot = 0;
	for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
			randSpot = (rand() % 17) + 1;
			switch (randSpot)
			{
				case 1:
				case 7:
				case 12:
					board[r][c] = 'G'; //  3/17 chance for grandma
					break;
				case 2:
				case 8:
				case 13:
				case 15:
					board[r][c] = 'B'; //  4/17 chance for bill
					break;
				case 3:
				case 9:
				case 14:
				case 16:
				case 17:
					board[r][c] = 'P'; //  5/17 chance for payday
					break;
				case 4:
				case 10:
					board[r][c] = 'F'; //  2/17 chance for feeding dog
					break;
				case 5:
					board[r][c] = 'L'; //  1/17 chance for lottery
					break;
				case 6:
				case 11:
					board[r][c] = 'C'; //  2/17 chance for car wreck
					break;
			}
        }
    }
}

//---------------------------------------------------------------------------
// Name: initBoard
// Parameters: board; char array, pass by ref, game board 2D-array
// Returns: none
// Purpose: This function initializes the game board and prompts for randomization
//---------------------------------------------------------------------------
void initBoard(char board[ROWS][COLS])
{
	char randomGame;

	board[0][0] = 'B';
	board[0][1] = 'C';
	board[0][2] = 'G';
	board[0][3] = 'P';
	board[0][4] = 'L';
	board[0][5] = 'C';
	board[1][0] = 'F';
	board[1][1] = 'F';
	board[1][2] = 'P';
	board[1][3] = 'B';
	board[1][4] = 'B';
	board[1][5] = 'L';
	board[2][0] = 'F';
	board[2][1] = 'G';
	board[2][2] = 'F';
	board[2][3] = 'B';
	board[2][4] = 'C';
	board[2][5] = 'P';
	board[3][0] = 'P';
	board[3][1] = 'F';
	board[3][2] = 'F';
	board[3][3] = 'P';
	board[3][4] = 'L';
	board[3][5] = 'G';
	
	cout << endl;
	cout << "Would you like to randomize the game board?" << endl;
	cout << "Enter R for [r]andomization or S for [s]tandard board:" << endl;
	cin >> randomGame;
	randomGame = toupper(randomGame);
	while (randomGame != 'R' && randomGame != 'S')
	{
		cout << "Sorry, that didn't quite work." << endl;
		cout << "Please enter R for randomization or S for standard board:" << endl;
		cin >> randomGame;
		randomGame = toupper(randomGame);
	}
	if (randomGame == 'R')
	{
		randomBoard(board);
		cout << "The board has been randomized." << endl;
	}
}

//---------------------------------------------------------------------------
// Name: playTurn
// Parameters: board; char array, pass by ref, game board 2D-array
//             playerNumCol & Row; int, pass by ref, location of player 1 & 2
//			   pNumMoney; double, pass by ref, value of player's money
// Returns: none
// Purpose: This function handles the turns and player movement. This
//			function calls diceRoll and handleEvent
//---------------------------------------------------------------------------
void playTurn(const char board[ROWS][COLS], 
                int& playerOneRow, int& playerOneCol, 
                int& playerTwoRow, int& playerTwoCol,
				double& p1Money, double& p2Money)
{
	char choice;
	int move;
	char event;
	
	cout << "Player 1 has $" << p1Money << endl;
	cout << "Player 2 has $" << p2Money << endl;
	cout << endl;
	if (ROLL_COUNT % 2 == 1)
	{
		cout << "Player 1, type an R to roll or P to pass this turn: ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'R' && choice != 'P')
		{
			cout << "Sorry, that didn't quite work." << endl;
			cout << "Please enter R to roll or P to pass: " << endl;
			cin >> choice;
			choice = toupper(choice);
		}
		if (choice == 'R')
		{
			move = diceRoll();
			cout << endl;
			cout << "Player 1 rolled a " << move << endl;
			playerOneCol += move;
			if ((playerOneCol <= 6 && playerOneRow <= 4) || (playerTwoCol <= 6 && playerTwoRow <= 4))
			{
				if (playerOneCol > 5 && playerOneRow < 3)
				{
					++playerOneRow;
					playerOneCol -= 6;
				}
				if (playerOneCol >= 6 && playerOneRow >= 3)
				{
					playerOneRow = 6;
					playerOneRow = 4;
				}
				event = board[playerOneRow][playerOneCol];
				p1Money += handleEvent(board, event);
				++ROLL_COUNT_1;
			}
			if (playerOneCol >= 6 && playerOneRow >=3)
			{
				playerOneCol = 6;
				playerOneRow = 4;
				cout << "Player 1 has reached the end. Player 2 still has one turn remaining" << endl;
			}
		}
		else if (choice == 'P')
			cout << "Player 1 has passed." << endl;
	}
		
	else if (ROLL_COUNT % 2 == 0)
	{
		cout << "Player 2, type an R to roll or P to pass this turn: ";
		cin >> choice;
		choice = toupper(choice);
		while (choice != 'R' && choice != 'P')
		{
			cout << "Sorry, that didn't quite work." << endl;
			cout << "Please enter R to roll or P to pass: " << endl;
			cin >> choice;
			choice = toupper(choice);
		}
		if (choice == 'R')
		{
			move = diceRoll();
			cout << endl;
			cout << "Player 2 rolled a " << move << endl;
			playerTwoCol += move;
			if ((playerOneCol <= 6 && playerOneRow <= 4) || (playerTwoCol <= 6 && playerTwoRow <= 4))
			{
				if (playerTwoCol > 5 && playerTwoRow < 3)
				{
					++playerTwoRow;
					playerTwoCol -= 6;
				}
				if (playerTwoCol >= 6 && playerTwoRow >= 3)
				{
					playerTwoRow = 6;
					playerTwoRow = 4;
				}
				event = board[playerTwoRow][playerTwoCol];
				p2Money += handleEvent(board, event);
				++ROLL_COUNT_2;
			}
			if (playerTwoCol >= 6 && playerTwoRow >= 3)
			{
				playerTwoCol = 6;
				playerTwoRow = 4;
				playerOneRow = 7;
				playerOneRow = 5;
				cout << "The game is over" << endl;
			}
		}
		else if (choice == 'P')
			cout << "Player 2 has passed." << endl;
	}
	
	
}

//---------------------------------------------------------------------------
// Name: displayWinner
// Parameters: pNumMoney; double, pass by ref, value of player's money
// Returns: none
// Purpose: This function displays total money for each player and displays a
//			victory message for the winner
//---------------------------------------------------------------------------
void displayWinner(double p1Money, double p2Money)
{
	cout << endl;
	cout << "The final totals are: " << endl;
	cout << "Player 1 = $" << p1Money << endl;
	cout << "Player 2 = $" << p2Money << endl;
	cout << endl;
	if (p1Money > p2Money)
		cout << "The winner is Player 1" << endl;
	else
		cout << "The winner is Player 2" << endl;
}


//---------------------------------------------------------------------------
// Name: main
//---------------------------------------------------------------------------
int main()
{
    char board[ROWS][COLS];
    int p1Row, p1Col, p2Row, p2Col;  // The players' current locations
	double p1Money, p2Money;

    // Seed the random number generator for diceRoll and resetBoard
    srand(time(NULL));
    
    // initialize the board
	welcomeMessage();
	initBoard(board);
	
    // set some values for testing
    p1Row = 0;
    p1Col = -1;
    p2Row = 0;
    p2Col = -1;
	p1Money = 0;
	p2Money = 0;
	
    while ((p1Col < 6 && p1Row < 4) || (p2Col < 6 && p2Row < 4))
	{
		printBoard(board, p1Row, p1Col, p2Row, p2Col);
		playTurn(board, p1Row, p1Col, p2Row, p2Col, p1Money, p2Money);
		++ROLL_COUNT;
	}
    	
	// print winner
	displayWinner(p1Money, p2Money);

    return 0;
}
