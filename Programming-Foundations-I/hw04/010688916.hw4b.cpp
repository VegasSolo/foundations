// Author:		Dillon VanBuskirk
// ID:			010688916
// Title:		Homework 4b
// Started:		March 10, 2015
// Completed:	March 10, 2015

//---------------------------------------------------------------------------
// Purpose:  This program allows a user to calculate moving costs
//---------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

// City Options
const char KANSAS_CITY = 'K';
const char ANCHORAGE = 'A';
const char PANAMA_CITY = 'P';

// City Distances
const float KANSAS_CITY_DISTANCE = 236.7;
const float ANCHORAGE_DISTANCE = 3766.3;
const float PANAMA_CITY_DISTANCE = 818.7;

// Vehicle types
const char HYBRID = 'H';                
const char TRUCK = 'T';
const char CAR = 'C';
const char SUV = 'S';

// Vehicle MPG
const int HYBRID_MPG = 37;                
const int TRUCK_MPG = 20;
const int SUV_MPG = 23;
const int CAR_MPG = 30;

// AVG Gas Cost
const float GAS_COST = 3.12;

// AVG Speed in Miles Per Hour
const int AVG_SPEED = 70;

//---------------------------------------------------------------------------
// Name: GetVehicleType
// Parameters: None
// Returns: char; The type of vehicle selected
// Purpose: Display Vehicle Menu and get the user's input
//---------------------------------------------------------------------------
char GetVehicleType()
{
	char Vehicle = '\0';
	
	cout << "Enter H for Hybrid, C for Car, T for Truck or S for SUV." << endl;
	cout << "Which vehicle would you like to drive?" << endl;
	cin >> Vehicle;
	Vehicle = toupper(Vehicle);
	while (Vehicle != HYBRID && Vehicle != CAR && Vehicle != TRUCK && Vehicle != SUV)
	{
		cout << endl;
		cout << Vehicle << " is not a valid selection." << endl;
		cout << "Enter H for Hybrid, C for Car, T for Truck or S for SUV." << endl;
		cin >> Vehicle;
		Vehicle = toupper(Vehicle);
	}
	cout << endl;
	return Vehicle;
}

//---------------------------------------------------------------------------
// Name: GetGallonsNeeded
// Parameters: VehicleMPG, int; TravelDistance, float
// Returns: float; gallons of gas that will be used on the trip
// Purpose: Get the type of vehicle and the type of rental the user chose 
// NOTE:  Called by GetTotalGasCost
//---------------------------------------------------------------------------
float GetGallonsNeeded(int VehicleMPG, float TravelDistance)
{
	float needGallons = 0.0;
	
	needGallons = TravelDistance / (static_cast<float>(VehicleMPG));
	return needGallons;
}

//---------------------------------------------------------------------------
// Name: GetMPG
// Parameters: VehicleType, char;
// Returns: int; vehicles miles per gallons
// Purpose: Gets the vehicles miles per gallon
// NOTE:  Called by GetTotalGasCost
//---------------------------------------------------------------------------
int GetMPG(char VehicleType)
{
	int mpg = 0;
	
	if (VehicleType == HYBRID)
		mpg = HYBRID_MPG;
	else if (VehicleType == CAR)
		mpg = CAR_MPG;
	else if (VehicleType == TRUCK)
		mpg = TRUCK_MPG;
	else if (VehicleType == SUV)
		mpg = SUV_MPG;
	return mpg;
}

//---------------------------------------------------------------------------
// Name: GetGasCost
// Parameters: VehicleType, char, TravelDistance, float;
//             GallonsNeeded, float (reference parameter)
// Returns: float The total cost of gas to get to the destination
// Purpose: Calculates the Total Cost of Gas for the trip
// NOTE:  Calls GetGallonsNeeded and GetMPG (call before GetGallonsNeeded)
//---------------------------------------------------------------------------
float GetGasCost(char VehicleType, float TravelDistance, float &GallonsNeeded)
{
	float Cost = 0.0;
	int mpg = 0;
	
	mpg = GetMPG(VehicleType);
	GallonsNeeded = GetGallonsNeeded(mpg, TravelDistance);
	Cost = GallonsNeeded * GAS_COST;
	return Cost;
}

//---------------------------------------------------------------------------
// Name: MainMenu
// Parameters: none
// Returns: none
// Purpose: Display some message about Spring Break coming up and needing
//            to choose a vehicle and destination.
//---------------------------------------------------------------------------
void MainMenu()
{
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Spring Break is coming up but you haven't started planning!" << endl;
	cout << "We're here to help you choose a vehicle and destination." << endl;
	cout << "Based on your vehicle type and destination we will calculate the number" << endl;
	cout << "of gallons needed to get there as well as how much it will cost." << endl;
	cout << "------------------------------------------------------------------------" << endl;
}

//---------------------------------------------------------------------------
// Name: GetHours
// Parameters: Distance, float;
// Returns: int, Hours it takes to get to the destination
// Purpose: Calculates the number of hours it take to get to the destination
//---------------------------------------------------------------------------
int GetHours(float Distance)
{
	int hours = 0;
	hours = Distance / AVG_SPEED;
	return hours;
}

//---------------------------------------------------------------------------
// Name: GetDestination
// Parameters: Destination, char (ref parameter); 
//             Distance, float (reference parameter)
// Returns: none
// Purpose: Fill in the user's destination choice and
//          the distance of the destination back to main
//---------------------------------------------------------------------------
void GetDestination(char &Destination, float &Distance)
{
	cout << "Enter K for Kansas City, P for Panama City Beach or A for Anchorage." << endl;
	cout << "Where would you like to go?" << endl;
	cin >> Destination;
	Destination = toupper(Destination);
	while (Destination != KANSAS_CITY && Destination != PANAMA_CITY && Destination != ANCHORAGE)
	{
		cout << endl;
		cout << Destination << " is not a valid selection." << endl;
		cout << "Enter K for Kansas City, P for Panama City Beach or A for Anchorage." << endl;
		cin >> Destination;
		Destination = toupper(Destination);
	}
	cout << endl;
	if (Destination == KANSAS_CITY)
		Distance = KANSAS_CITY_DISTANCE;
	else if (Destination == PANAMA_CITY)
		Distance = PANAMA_CITY_DISTANCE;
	else if (Destination == ANCHORAGE)
		Distance = ANCHORAGE_DISTANCE;	
}

//---------------------------------------------------------------------------
// Main program
//---------------------------------------------------------------------------
int main ()
{
   // Declarations
   char Destination;	// The destination chosen
   char VehicleType;        // The vehicle type you wish to drive from
   float Cost;              // The cost of your gas 
   float Distance; // The distance that will be travelled
   float GallonsNeeded;     // The number of gallons needed to get to the destination
   int Hours;		// How many hours it takes to get to the destination

   // print name and UAID
   cout << "#########################\n";
   cout << "### Dillon VanBuskirk ###\n";
   cout << "####### 010688916 #######\n";
   cout << "#########################\n\n";

   // Display MainMenu
   MainMenu();
   
   // Get Destination  
   GetDestination(Destination, Distance);

   // Get Vehicle Type
   VehicleType = GetVehicleType();   

   // Calculate the cost of Gas
   Cost = GetGasCost(VehicleType, Distance, GallonsNeeded); 


   // Calculate the time it takes to get there (rounded down because of int)
   Hours = GetHours(Distance);

   // Display the Cost of Gas, Gallons Needed, Vehicle Type, Destination
   // and travel time.
   cout << "You will need " << GallonsNeeded << " gallons which will cost you\n"
        << "$" << fixed << setprecision(2) << Cost << ".\n";
   cout << "It will take you about " << Hours << " hours to get to ";

   if(Destination == KANSAS_CITY)
      cout << "Kansas City in a ";
   else if(Destination == ANCHORAGE)
      cout << "Anchorage in a ";
   else
      cout << "Panama City Beach in a ";

   if(VehicleType == HYBRID)
      cout << "Hybrid.\n";
   else if(VehicleType == CAR)
      cout << "Car.\n";
   else if(VehicleType == TRUCK)
      cout << "Truck.\n";
   else
      cout << "SUV.\n";

   return 0;
}
