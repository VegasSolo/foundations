//----------------------------------------------------
// Authors:		Dillon VanBuskirk	&	Garrett VanBuskirk
// Student IDs:			010688916	&	010691035	
// Purpose:    Translates between URLs and IP 
//             using arrays loaded from a file
//----------------------------------------------------

#include <iostream>
#include <string>
#include <cctype>
#include "DNS.h"

using namespace std;

const char EXIT = 'Q';
//const string FILENAME = "list.txt";

//----------------------------------------------------
// Purpose: Find out what the user wants to do.
// Arguments: None.
// Returns: A character which indicates the users choice.
//----------------------------------------------------
char getChoice()
{
	char choice = ' ';
	
	cout << "\nWelcome. Please follow instructions below.";
	do 
	{
        cout << "\n\nEnter 'F' to fill the lookup table from a file\n"
             << "      'A' to add an entry to the lookup table\n"
             << "      'U' to find a URL for a given IP address\n"
             << "      'I' to find an IP address for a given URL\n"
             << "      'P' to print the contents of the lookup table\n"
		     << "      'Q' to quit the program\n"
             << "Selection: ";
		cin >> choice;
		choice = toupper(choice);
	} while (choice != 'F' && choice != 'A' && choice != 'U' && choice != 'I' && choice != 'P' && choice != 'Q');
	return choice;
}

//----------------------------------------------------
// Purpose: Add an entry to the lookup table associated
// 	 with the argument.
// It prompts the user for the ip address and URL to add
// OPTION:  it checks that the ip address adn URL
// are valid before adding them to the table
// It calls the AddWebsite method with the user-provided
// strings.
// Argument: A DNS object (pass by reference)
// Returns: Void
//----------------------------------------------------
void AddWebsite(DNS &Dns)
{
	string ipAddress, webURL;
	
	cout << "This is the option to add a website to the table." << endl;
	cout << "Please enter the IP Address:" << endl;
	cin >> ipAddress;
	// call IsValidIP
	if (Dns.IsValidIP(ipAddress))
	{
		cout << "This IP Address is valid." << endl;
	}
	else 
	{
		while (!(Dns.IsValidIP(ipAddress)))
		{
			cout << "This IP Address is invalid. Please try again." << endl;
			cout << "An IP Address must be between 7 and 15 characters, contain exactly "
				 << "three periods and contain only digits and (3) periods." << endl;
			cin >> ipAddress;
		}			
	}
	cout << "Please enter the website URL:" << endl;
	cin >> webURL;
	// call IsValidURL
	if (Dns.IsValidURL(webURL))
	{
		cout << "This website URL is valid." << endl;
	}
	else 
	{
		while (!(Dns.IsValidURL(webURL)))
		{
			cout << "This website URL is invalid. Please try again." << endl;
			cout << "A website URL must begin with www. and contain exactly two periods" << endl;
			cin >> webURL;
		}			
	}
	
	if (Dns.AddWebsite(ipAddress, webURL))
		cout << "The website has been successfully added." << endl;
	else
		cout << "There was a problem adding the website." << endl;
}

int main()
{
	char choice;
	string userSearch;

	DNS Dns;
	
	choice = getChoice();
	while (choice != 'Q')
	{
		switch (choice)
		{
			case 'F':
				if (Dns.FillArraysFromFile("list.txt"))
					cout << "The file has been successfully read "
					<< "and arrays have been filled." << endl;
				else
					cout << "There was a problem reading and filling." << endl;
				break;
			case 'A':
				AddWebsite(Dns);
				break;
			case 'U':
				cout << "Please enter the IP Address for the website you want to find:" << endl;
				cin >> userSearch;
				cout << "/nThe website is ";
				cout << Dns.LookupWebsiteURL(userSearch) << endl;
				break;
			case 'I':
				cout << "Please enter the website for the IP Address you want to find:" << endl;
				cin >> userSearch;
				cout << "/nThe IP Address is ";
				cout << Dns.LookupIPAddress(userSearch) << endl;
				break;
			case 'P':
				Dns.Print();
				break;
		}
		cout << "\nYour request was completed. Would you like to continue?" << endl;
		cout << "Enter Q to [Q]uit or C to [C]ontinue" << endl;
		cin >> choice;
		choice = toupper(choice);
		if (choice != 'Q')
			choice = getChoice();
	}
	cout << "Goodbye." << endl;
	
	return 0;
}
