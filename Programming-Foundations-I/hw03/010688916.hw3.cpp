// Authors:		Dillon VanBuskirk	&	Garrett VanBuskirk
// IDs:			010688916			&	010691035
// Title:		Homework 3
// Started:		February 22, 2015
// Completed:	February 22, 2015

// This program reads in a message that will be encrypted or decrypted depending
// on user input. It will use a secret prime number key that will determine the 
// final message. The final message is outputted to the screen.

#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;


//------------------------------
// Name:       PrimeTest
// Purpose:    Test if passed number is prime
// Parameters: Pass by Value: Number - the value 
// Return:     int:  1 or 0 for true or false
//-------------------------------------------
int PrimeTest (int Number)
{
	if (Number == 1 || Number == 0)
		return 0;
	for (int i=2; i<=(sqrt(Number)); i++)
	{
		if (Number%i == 0)
			return 0;
	}
	return 1;
}


//------------------------------
// Name:       Encrypt
// Purpose:    Encrypt the character passed
// Parameters: Pass by Value: characters and the integer key
// Return:     char:  encrypted character
//-------------------------------------------
char Encrypt (char First, int Key, char New)
{
	New = 'A' + ((First - 'A') - Key%26 + 26) % 26;
	return New;
}


//------------------------------
// Name:       Decrypt
// Purpose:    Decrypt the character passed
// Parameters: Pass by Value: characters and the integer key 
// Return:     char:  decrypted character
//-------------------------------------------
char Decrypt (char First, int Key, char New)
{
	New = 'A' + ((First - 'A') + Key) % 26;
	return New;
}


//------------------------------
//---- ---  M  A  I  N  --- ----
//------------------------------
int main()
{
	// ---- VARIABLES ----
	char msgOne, msgTwo, msgThree, msgFour;
	string msgFull;
	int numSecretKey;
	char cryptEorD;
	char msgNewOne = 'a', msgNewTwo = 'a', msgNewThree = 'a', msgNewFour = 'a';
 	
	// ---- MESSAGE PROMPT, READ & ERROR CHECK ----
		// prompt and read message of 4 characters
		// error check for only alphabetical char [while]
		// inform invalid, prompt again
	while (!isalpha(msgOne) || !isalpha(msgTwo) || !isalpha(msgThree) || !isalpha(msgFour))
	{
		cout << "Please enter four alphabetical characters: ";
		cin >> msgFull;
		msgOne = msgFull.at(0);
		msgTwo = msgFull.at(1);
		msgThree = msgFull.at(2);
		msgFour = msgFull.at(3);
		//cin >> msgOne >> msgTwo >> msgThree >> msgFour;
		if (!isalpha(msgOne) || !isalpha(msgTwo) || !isalpha(msgThree) || !isalpha(msgFour))
			cout << "Incorrect input. Please try again." << endl;
	}
		// convert lower to upper    [toupper(msgOne)]
	msgOne = toupper(msgOne);
	msgTwo = toupper(msgTwo);
	msgThree = toupper(msgThree);
	msgFour = toupper(msgFour);
	
	// ---- SECRET KEY PRIME PROMPT, READ & ERROR CHECK ----
		// prompt and read secret key prime number
		// error check for prime, not 0 or 1, reprompt for prime number [do while and nested for]
	do
	{
		cout << "Please enter a prime number: ";
		cin >> numSecretKey;
		//for (int i = 2; i <= (numSecretKey/2); i++)
		//{
		//	if (numSecretKey % i == 0)
		//	{
		//	cout << "Are you stupid? That's not a prime number." << endl;
		//	break;
		//	}
		//}
		if (!PrimeTest(numSecretKey))
			cout << "That's not a prime number. Try again." << endl;
	} while (!PrimeTest(numSecretKey));
	
			
	// ---- ENCRYPT OR DECRYPT PROMPT, READ & ERROR CHECK ----
		// prompt and read single char, e or d
		// error check for only e or d [while]
	while (!(cryptEorD == 'e' || cryptEorD == 'E' || cryptEorD == 'd' || cryptEorD == 'D'))
	{
		cout << "Please choose whether you would like to (D)ecrypt or (E)ncrypt: ";
		cin >> cryptEorD;
		if (!(cryptEorD == 'e' || cryptEorD == 'E' || cryptEorD == 'd' || cryptEorD == 'D'))
			cout << "Incorrect input. Please enter an e/E or a d/D" << endl;
	}
	
	// ---- NEW MESSAGE MATH & OUTPUT ----
	// calculate new message
	cout << endl;
	cout << "We are going to ";
	if (cryptEorD == 'e' || cryptEorD == 'E')
	{
		msgNewOne = Encrypt(msgOne, numSecretKey, msgNewOne);
		msgNewTwo = Encrypt(msgTwo, numSecretKey, msgNewTwo);
		msgNewThree = Encrypt(msgThree, numSecretKey, msgNewThree);
		msgNewFour = Encrypt(msgFour, numSecretKey, msgNewFour);
		//msgNewOne = 'A' + ((msgOne - 'A') - numSecretKey%26 + 26) % 26;
		//msgNewTwo = 'A' + ((msgTwo - 'A') - numSecretKey%26 + 26) % 26;
		//msgNewThree = 'A' + ((msgThree - 'A') - numSecretKey%26 + 26) % 26;
		//msgNewFour = 'A' + ((msgFour - 'A') - numSecretKey%26 + 26) % 26;
		cout << "encrypt your message, ";
	}
	else
	{
		msgNewOne = Decrypt(msgOne, numSecretKey, msgNewOne);
		msgNewTwo = Decrypt(msgTwo, numSecretKey, msgNewTwo);
		msgNewThree = Decrypt(msgThree, numSecretKey, msgNewThree);
		msgNewFour = Decrypt(msgFour, numSecretKey, msgNewFour);
		//msgNewOne = 'A' + ((msgOne - 'A') + numSecretKey) % 26;
		//msgNewTwo = 'A' + ((msgTwo - 'A') + numSecretKey) % 26;
		//msgNewThree = 'A' + ((msgThree - 'A') + numSecretKey) % 26;
		//msgNewFour = 'A' + ((msgFour - 'A') + numSecretKey) % 26;
		cout << "decrypt your message, ";
	}
	cout << msgOne << msgTwo << msgThree << msgFour << ", using the secret key of " << numSecretKey << "." << endl;
	cout << endl;
	// output new message
	cout << "Your new message is " << msgNewOne << msgNewTwo << msgNewThree << msgNewFour << ". Thank you." << endl;
	cout << endl;
		
	return 0;
}
