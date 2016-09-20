// asdf

#include <iostream>
using namespace std;

int main()
{
	// ---- VARIABLES ----
	string name, team; 
	int numAttPass, numCompPass, numYdThrown, numTD, numInterception;
	float percComplete, percTD, percInterception, percAvgYDAttempt;
	float numQBR, numTemp;
 	
	// ----- READ & PROMPTS -----	
	cout << "Welcome to the QB Rating Caclulator!" << endl;	
	// read last name, team
	cout << "Enter your quarterback's name: ";
	cin >> name;
	cout << "Enter the team's name that they play for: ";
	cin >> team;
 	// print last name and team
	cout << "We will calculate the quarterback rating for " << name;
	cout << " who plays for the " << team << "." << endl;
	cout << endl;
  	// read attempted passes
	cout << "How many passes did the quarterback attempt?" << endl;
	cin >> numAttPass;
	// read completed passes
	cout << "How many of those passes did the quarterback complete?" << endl;
	cin >> numCompPass;
	// read num yards thrown
	cout << "How many yards did he throw for?" << endl;
	cin >> numYdThrown;
	// read num touchdowns
	cout << "How many touchdowns did he throw?" << endl;
	cin >> numTD;
	// read num interception
	cout << "How many interceptions did he throw?" << endl;
	cin >> numInterception;

	// ---- MATH ----
	numTemp = static_cast<float>(numAttPass); // used for all equations, floating it	
	// percent complete
	// subtract 30 from percentage, multiply result by .05. = point rating
	percComplete = (((numCompPass / numTemp) * 100) - 30) * .05;
	// avg yards per attempt
	// subtract 3 yards from yd per attempt, multiply result by .25
	percAvgYDAttempt = ((numYdThrown / numTemp)- 3) * .25;
	// percentage of td passes
	// multiply percentage by .2
	percTD = ((numTD / numTemp) * 100) * .2;
	// percentage of interception
	// multiply by .25 and subtract that number from 2.375
	percInterception = 2.375 - (((numInterception / numTemp) * 100) * .25);
	// sum of four above is qbr
	// divided by six, multiply by 100
	numQBR = ((percComplete + percAvgYDAttempt + percTD + percInterception) / 6) * 100;

	// ---- OUTPUT ----
	cout << "Your quarterback had a completion percentage rating of: " << percComplete << endl;
	cout << "Your quarterback had a yards per attempt rating of: " << percAvgYDAttempt << endl;
	cout << "Your quarterback had a touchdown percentage rating of: " << percTD << endl;
	cout << "Your quarterback had an interception rating of: " << percInterception << endl;
	cout << "The final QBR of your quarterback was: " << numQBR << endl;


  return 0;
}
