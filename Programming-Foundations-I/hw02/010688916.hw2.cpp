// Author:     Dillon VanBuskirk
// ID:         010688916
// Title:	   Homework 2
// Started:    February 9, 2015
// Completed:  February 9, 2015

// Description of program

#include <iostream>
using namespace std;

int main()
{
	// ---- VARIABLES ----
	string nameQB, nameRB, nameWR, team; 
	int numAttPass, numCompPass, numYdThrown, numQBTD, numInterception;
	int numReception, numWRYd, numWRTD, numWRFumble;
	int numRushAtt, numRBYd, numRBTD, numRBFumble;
	float percComplete, percTD, percInterception, percAvgYdAttempt;
	float percWRYd, percRBYd;
	float numQBR;
 	
	// ---- QB READ & PROMPTS ----
	cout << endl;
	cout << "Welcome to the Football Statistics Calculator!" << endl;
	cout << "This is a program that can calculate and compare statistics about a ";
	cout << "Quarterback, Running Back and a Wide Receiver." << endl;
	// read team name and QB's last name
	cout << "Enter the team's name for which these players play: ";
	cin >> team;
	cout << "Enter the Quarterback's last name: ";
	cin >> nameQB;
 	// print last name
	cout << endl;
	cout << "We will calculate the quarterback rating for " << nameQB;
	cout << "." << endl;
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
	cin >> numQBTD;
	// read num interception
	cout << "How many interceptions did he throw?" << endl;
	cin >> numInterception;

	// ---- QB MATH ----
	// percent complete
	// subtract 30 from percentage, multiply result by .05. = point rating
	percComplete = ((((static_cast<float>(numCompPass)) / numAttPass) * 100) - 30) * .05;
	if (percComplete > 2.375)
		percComplete = 2.375;
	else if (percComplete < 0)
		percComplete = 0;
	// avg yards per attempt
	// subtract 3 yards from yd per attempt, multiply result by .25
	percAvgYdAttempt = ((((static_cast<float>(numYdThrown)) / numAttPass)- 3) * .25;
	if (percAvgYdAttempt > 2.375)
		percAvgYdAttempt = 2.375;
	else if (percAvgYdAttempt < 0)
		percAvgYdAttempt = 0;
	// percentage of td passes
	// multiply percentage by .2
	percTD = ((((static_cast<float>(numQBTD)) / numAttPass) * 100) * .2;
	if (percTD > 2.375)
		percTD = 2.375;
	// percentage of interception
	// multiply by .25 and subtract that number from 2.375
	percInterception = 2.375 - (((((static_cast<float>(numInterception)) / numAttPass) * 100) * .25);
	if (percInterception < 0)
		percInterception = 0;
	// sum of four above is qbr
	// divided by six, multiply by 100
	numQBR = ((percComplete + percAvgYdAttempt + percTD + percInterception) / 6) * 100;

	// ---- QB OUTPUT ----
	cout << "Your quarterback had a completion percentage rating of: " << percComplete << endl;
	cout << "Your quarterback had a yards per attempt rating of: " << percAvgYdAttemptAttempt << endl;
	cout << "Your quarterback had a touchdown percentage rating of: " << percTD << endl;
	cout << "Your quarterback had an interception rating of: " << percInterception << endl;
	cout << "The QBR of your quarterback was: " << numQBR << endl;

	// ---- WR READ & PROMPTS ----
	cout << endl;
	cout << "Enter the Wide Receiver's last name: ";
	cin >> nameWR;
	cout << "We will calculate some Wide Receiver statistics for " << nameWR;
	cout << "." << endl;
	cout << "How many receptions did he have?" << endl;
	cin >> numReception;
	cout << "How many yards did he earn?" << endl;
	cin >> numWRYd;
	cout << "How many TDs did he have?" << endl;
	cin >> numWRTD;
	cout << "How many fumbles did he have?" << endl;
	cin >> numWRFumble;
	
	// ---- WR MATH ----
	percWRYd = (static_cast<float>(numReception)) / numWRYd;
	
	// ---- WR OUTPUT ----
	cout << endl;
	cout << nameWR << "'s average yards per catch is: " << percWRYd << endl;
	
	// ---- RB READ & PROMPTS ----
	cout << endl;
	cout << "Enter the Running Back's last name: ";
	cin >> nameRB;
	cout << "We will calculate some Running Back statistics for " << nameRB;
	cout << "." << endl;
	cout << "How many rushing attempts did he have?" << endl;
	cin >> numRushAtt;
	cout << "How many yards did he earn?" << endl;
	cin >> numRBYd;
	cout << "How many TDs did he have?" << endl;
	cin >> numRBTD;
	cout << "How many fumbles did he have?" << endl;
	cin >> numRBFumble;
	
	// ---- RB MATH ----
	percRBYd = (static_cast<float>(numRushAtt)) / numRBYd;
	
	// ---- RB OUTPUT ----
	cout << endl;
	cout << nameRB << "'s average yards per rush is: " << percRBYd << endl;
	
	// ---- FINAL ----
	// ---- COMPARISON MATH ----
	if (
	
	// ---- COMPARISON OUTPUT ----
	cout << endl;
	cout << "The player with the most turnovers is: " << numMostTurnover;
	cout << "The player with the highest yards per attempt is: " << numMostYdAtt;
	cout << "The player with the most TDs is: " << numMostTD;
	cout << endl;
	cout << "Go " << team << " go!" << endl;
	
  return 0;
}
