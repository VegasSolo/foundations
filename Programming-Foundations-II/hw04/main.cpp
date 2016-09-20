#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include "tree.h"
#include "day.h"
using namespace std;

void sayWelcome();
void showHelp();
int convertTime(string t);
void doit(istream &fin);
void ignoreLines(istream &fin, int n);

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "Please enter a filename!\n";
		return 1;
	}

	ifstream fin("sunrise-sunset.txt");
	if(fin.fail())
	{
		cout << "Error reading file!\n";
		return 1;
	}

	ignoreLines(fin, 3);
	doit(fin);
	fin.close();

	return 0;
}

void sayWelcome()
{
	cout << "\nWelcome to Dillon's Sunrise/Sunset tool." << endl;
	cout << "Enter one of the following commands:" << endl;
	cout << "   sunrise before [time]" << endl;
	cout << "   sunrise after [time]" << endl;
	cout << "   sunrise between [start_time] [end_time]" << endl;
	cout << "   sunset before [time]" << endl;
	cout << "   sunset after [time]" << endl;
	cout << "   sunset between [start_time] [end_time]" << endl;
	cout << "   help" << endl;
	cout << "   all" << endl;
	cout << "   quit\n" << endl;
}

void showHelp()
{
	cout << "This program accepts times in both formats:" << endl;
	cout << "In military, (0700, 800, 1200, 1800) and in" << endl;
	cout << "standard, (7:00am, 12:00pm, 4:00pm, 12:00am)." << endl;
	cout << "This program also handles both sunrise and sunset." << endl;
}

int convertTime(string t)
{
	int n;
	string s;
	
	if (t.length() == 3 || t.length() == 4)
	{
		n = atoi(t.c_str());
	}
	else
	{
		if (t[1] == ':')
		{
			s.append(t,0,1);
			s.append(t,2,2);
		}
		else if (t[2] == ':')
		{
			s.append(t,0,2);
			s.append(t,3,2);
		}
		n = atoi(s.c_str());
		if (t[t.length()-2] == 'p')
			n += 1200;
	}
	return n;
}

void doit(istream &fin)
{
	BinaryTree Sunrise;
	BinaryTree Sunset;

	int year, month, date, sunrise, sunset;
	while(true)
	{
		fin >> year >> month >> date >> sunrise >> sunset;
		if(fin.eof())
		{
			break;
		}

		Sunrise.insert(sunrise, new Day(year, month, date, sunrise, sunset));
		Sunset.insert(sunset, new Day(year, month, date, sunrise, sunset));
	}

	sayWelcome();
	string input, inputNumConv;
	int inputNum, inputNum2, daysize;
	vector<Day *> days;
	
	while (true)
	{
		cin >> input;
		if (input == "sunrise")
		{
			cin >> input;
			if (input == "before")
			{
				cin >> input;
				inputNum = convertTime(input);
				days = Sunrise.searchBefore(inputNum);
				if (days.size() == 0)
					cout << "No dates found." << endl;
				else
				{
					daysize = days.size(); // done solely to get rid of warnings
					for (int i = 0; i < daysize; i++) // unsigned vs signed comparison warning ^
					{
						days[i]->print();
					}
				}
			}
			else if (input == "after")
			{
				cin >> input;
				inputNum = convertTime(input);
				days = Sunrise.searchAfter(inputNum);
				if (days.size() == 0)
					cout << "No dates found." << endl;
				else
				{
					daysize = days.size(); 
					for (int i = 0; i < daysize; i++)
					{
						days[i]->print();
					}
				}
			}
			else if (input == "between")
			{
				cin >> input;
				inputNum = convertTime(input);
				cin >> input;
				inputNum2 = convertTime(input);
				days = Sunrise.searchRange(inputNum, inputNum2);
				if (days.size() == 0)
					cout << "No dates found." << endl;
				else
				{
					daysize = days.size(); 
					for (int i = 0; i < daysize; i++)
					{
						days[i]->print();
					}
				}
			}
			else 
				cout << "Error! Incorrect input." << endl;
		}
		else if (input == "sunset")
		{
			cin >> input;
			if (input == "before")
			{
				cin >> input;
				inputNum = convertTime(input);
				days = Sunset.searchBefore(inputNum);
				if (days.size() == 0)
					cout << "No dates found." << endl;
				else
				{
					daysize = days.size(); 
					for (int i = 0; i < daysize; i++)
					{
						days[i]->print();
					}
				}
			}
			else if (input == "after")
			{
				cin >> input;
				inputNum = convertTime(input);
				days = Sunset.searchAfter(inputNum);
				if (days.size() == 0)
					cout << "No dates found." << endl;
				else
				{
					daysize = days.size(); 
					for (int i = 0; i < daysize; i++)
					{
						days[i]->print();
					}
				}
			}
			else if (input == "between")
			{
				cin >> input;
				inputNum = convertTime(input);
				cin >> input;
				inputNum2 = convertTime(input);
				days = Sunset.searchRange(inputNum, inputNum2);
				if (days.size() == 0)
					cout << "No dates found." << endl;
				else
				{
					daysize = days.size(); 
					for (int i = 0; i < daysize; i++)
					{
						days[i]->print();
					}
				}
			}
			else 
				cout << "Error! Incorrect input." << endl;
		}
		else if (input == "all")
		{
			Sunrise.print();
		}
		else if (input == "help")
		{
			showHelp();
		}
		else if (input == "quit")
		{
			break;
		}
		else
			cout << "Error! Incorrect input." << endl;
	}
}

void ignoreLines(istream &fin, int n)
{
	for(int i = 0; i < n; i++)
	{
		fin.ignore(255, '\n');
	}
}