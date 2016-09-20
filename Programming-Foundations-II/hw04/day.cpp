#include <iostream>
#include "day.h"
using namespace std;

Day::Day(int pyear, int pmonth, int pday, int psunrise, int psunset)
{
	year = pyear;
	month = pmonth;
	day = pday;
	sunrise = psunrise;
	sunset = psunset;
}

void Day::print() const
{
	cout << "Date:    " << year << "-" << month << "-" << day << endl;
	cout << "Sunrise: " << sunrise << endl;
	cout << "Sunset:  " << sunset << endl;
	cout << endl;
}