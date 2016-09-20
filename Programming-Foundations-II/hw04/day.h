#ifndef DAY_H
#define DAY_H

class Day
{
	public:
		Day(int pyear, int pmonth, int pday, int psunrise, int psunset);
		void print() const;
	private:
		int year, month, day, sunrise, sunset;
};

#endif