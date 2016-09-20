#include <iostream>
#include "tokenizer.h"
using namespace std;

int main()
{
	// todo: add a welcome message with instructions
	// todo: initialize your linked list and stack

	string printCommand = "?";
	string quitCommand = "quit";
	string input;

	Tokenizer tokenizer;
	string token;

	while(true)
	{
		getline(cin, input);
		if(input == printCommand)
		{
			// todo: print all variables in the linked list
		}
		else if(input == quitCommand)
		{
			break;
		}
		else
		{
			tokenizer.tokenize(input);
			while(tokenizer.nextToken(token))
			{
				// todo: use token and evaluate the expression
				// cout << "string token" << token << endl; // prints full string over the loop no spaces
			}
			// todo: check the result of the expression and either print it out or store it in the linked list
		}
	}

	return 0;
}