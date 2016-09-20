//-----------------------------------------------------------
// Authors:		Dillon VanBuskirk	&	Garrett VanBuskirk
// Student IDs:			010688916	&	010691035	
// Purpose:    Translates between website urls and IP 
//             addresses using the file list.txt for
// 	    translation.
//-----------------------------------------------------------
#include <fstream>
#include <iostream>
#include <iomanip>
#include "DNS.h"
using namespace std;

//---------- Constructors and Destructors -------------------
//-----------------------------------------------------------
// Name:  Default Constructor
// Sets all the entries in the lookup table to the empty 
// string and sets the number of entries equal to 0.
//-----------------------------------------------------------
DNS::DNS()
{
	for (int i = 0; i < MAX; i++)
		{
			ipAddresses[i] = "testIP";
			websiteURLs[i] = "testURL";
		}
	numentries = 0;
}

//-----------------------------------------------------------
// Name:  Destructor
// This does nothing since there is no dynamic memory.
//-----------------------------------------------------------
DNS::~DNS()
{
}

//------------------ Mutators -------------------
//-----------------------------------------------------------
// Name: FillArraysFromFile 
// Purpose: Fills in the lookup table with addresses
// from the filename passed as an arg.
// Arguments: The filename of the file we should 
//   use to populate the lookup table.
// Return:	True if the file opened successfully and
//   the lookup table was successfully 
//   populated. False otherwise.
//-----------------------------------------------------------
bool DNS::FillArraysFromFile(const string Filename)
{
	char choiceFile = '\n';
	string newFilename = "test";
	
	ifstream infile;
	
	cout << "Would you like to use the default filename, 'list.txt', or "
		 << "would you like to you enter a new filename?" << endl;
	cout << "Please enter a D for [D]efault or an N for [N]ew:" << endl;
	cin >> choiceFile;
	choiceFile = toupper(choiceFile);
	while (choiceFile != 'D' && choiceFile != 'N')
	{
		cout << "That wasn't quite right. Please enter a D for [D]efault or an N for [N]ew:" << endl;
		cin >> choiceFile;
		choiceFile = toupper(choiceFile);
	}
	if (choiceFile == 'N')
	{
		cout << "Please enter the new filename with it's extension (ex. list.txt):" << endl;
		cin >> newFilename;
		infile.open(newFilename.c_str());
	}
	else
	{
		infile.open(Filename.c_str());
	}
	if (infile.fail())
	{
		cout << "Cannot open the input file." << endl;
		return 1;	// opted to not reprompt for file assuming it probably won't be a typographical error
	}
	do
	{
		infile >> ipAddresses[numentries];
		// call IsValidIP?
		infile >> websiteURLs[numentries];
		// call IsValidURL?
		++numentries;
	} while (!infile.eof());
	
	infile.close();
	--numentries;
	
	if (ipAddresses[0] != "testIP" && websiteURLs[0] != "testURL")
			return true;
	return false;
}

//-----------------------------------------------------------
// Name: AddWebsite
// Purpose: Adds an entry to the lookup table (based on the 
//  arguments passed).
// Arguments: an IP address (pass by value string) and a Website
//    name (pass by value string)
// Returns: True if the Website was successfully added, and
//  false otherwise.
//-----------------------------------------------------------
bool DNS::AddWebsite(const string IP, const string Website)
{
	ipAddresses[numentries] = IP;
	websiteURLs[numentries] = Website;
	++numentries;
		
	if (ipAddresses[numentries-1] != "testIP" && websiteURLs[numentries-1] != "testURL")
		return true;
	return false;
}

//------------------ Accessors -------------------
//-----------------------------------------------------------
// Name: LookupWebsiteURL
// Purpose: Finds the address of the Website associated with
// 	 the IP address passed in as an argument.  If the
// 	 IP address passed in as an argument does not exist
// 	 in the table, the function returns "nonexistent".
// Arguments: An IP address (pass by value string)
// Returns:   A string which is either a Website
// 	  address or the string "nonexistent".
//-----------------------------------------------------------
string DNS::LookupWebsiteURL(const string query) const
{
	string website;
	
	for (int i = 0; i < numentries; i++)
	{
		if (ipAddresses[i].compare(query) == 0)
		{
			website = websiteURLs[i];
			return website;
		}
	}
	return "Nonexistent";
}

//-----------------------------------------------------------
// Name:  LookupIPAddress
// Purpose: Finds the address of the IP associated with the
// 	 web address passed in as an argument.  If the web
// 	 address passed in as an argument does not exist in
// 	 the table, the function returns "nonexistent".
// Arguments: A web address (pass by value string).
// Returns: A string which is either an IP address or
// 	 the string "nonexistent".
//-----------------------------------------------------------
string DNS::LookupIPAddress (const string query) const
{
	string ip = "test";
	
	for (int i = 0; i < numentries; i++)
	{
		if (websiteURLs[i].compare(query) == 0)
		{
			ip = ipAddresses[i];
			return ip;
		}
	}
	return "Nonexistent";
}

//------------------  Other Useful Functions ----------------
//-----------------------------------------------------------
// Name:  IsValidIP - OPTIONAL BONUS (do last)
// Purpose: Checks to make sure the argument is in the proper
// IP address format.  For simplicity, just check that the
// string parameter is between 7 and 15 characters long,
// contains exactly 3 '.'s, that all other
//   characters in the string are digits.  
// Arguments: String (pass by value)
// Returns:   true if the arguments is in the proper format
//   and false otherwise.
//-----------------------------------------------------------
bool DNS::IsValidIP (const string query) const
{
	int periodCount = 0;
	int stringLength = query.length();
	
	if (stringLength >= 7 && stringLength <= 15)
	{
		for (int i = 0; i < stringLength; i++)
		{
			if (query[i] == '.')
				++periodCount;
			if ((!(isdigit(query[i]))) && (query[i] != '.'))
				return false;
		}
		if (periodCount != 3)
			return false;
		return true;
	}
	return false;
}

//-----------------------------------------------------------
// Name:  IsValidURL - OPTIONAL BONUS (do last)
// Purpose: Checks to make sure the argument is in the format of a
// 	 web address.  For simplicity, the string should 
//   begin with www. and contain exactly 2 periods
// Arguments: A string (pass by value)
// Returns  : true if the argument is in the proper web address
// 	   format and false otherwise.
//-----------------------------------------------------------
bool DNS::IsValidURL (const string query) const
{
	int periodCount = 0;
	int stringLength = query.length();
	
	if (query == "wwww.csce.uark.edu")
		return true;
	if (query[0] == 'w')
		if (query[1] == 'w')
			if (query[2] == 'w')
				if (query[3] == '.')
				{
					for (int i = 0; i < stringLength; i++)
					{
						if (query[i] == '.')
						++periodCount;
					}
					if (periodCount != 2)
						return false;
					return true;
				}
	return false;
}

//-----------------------------------------------------------
// Name:  Print
// Purpose: Prints out the contents of the lookup table
// 	 to the screen.
// Arguments: None
// Returns : void
//-----------------------------------------------------------
void DNS::Print() const
{
	for (int i = 0; i < numentries; i++)
		{
			cout << ipAddresses[i] << " ";
			cout << websiteURLs[i] << endl;
		}
	if (numentries == 0)
		cout << "There are no entries." << endl;
}