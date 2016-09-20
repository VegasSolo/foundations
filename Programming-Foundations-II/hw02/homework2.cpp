#include <iostream>
#include "matrix.h"
using namespace std;

void getShortest(Matrix &m, int r, int c, int &numGuards, string &path)
{
	// base case in Princess room
	if (r == m.getRows() -1 && c == m.getCols() -1)
	{
		numGuards += m[r][c];
	}
	// if at last row
	else if (r == m.getRows() - 1)
	{
		numGuards += m[r][c];
		path += "> ";
		getShortest(m, r, c+1, numGuards, path);
	}
	// if at last col
	else if (c == m.getRows() - 1)
	{
		numGuards += m[r][c];
		path += "v ";
		getShortest(m, r+1, c, numGuards, path);
	}
	// all other cases
	else
	{
		int rn = 0; // right num
		int dn = 0; // down num
		string rp = ""; // right path
		string dp = ""; // down path
		getShortest(m, r+1, c, dn, dp);
		getShortest(m, r, c+1, rn, rp);
		
		if (rn < dn)
		{
			numGuards += m[r][c] + rn;
			path += "> " + rp;
		}
		else
		{
			numGuards += m[r][c] + dn;
			path += "v " + dp;
		}
	}
}

void doit(Matrix &m)
{
	int shortestNum = 0;
	string shortestPath = "";
	getShortest(m, 0, 0, shortestNum, shortestPath);
	
	cout << shortestNum << endl;
	cout << shortestPath << endl;
}


int main(int argc, char **argv)
{
	Matrix m;
	
	if(argc < 2)
	{
		cout << "Please enter a filename when you call the program!\n";
		return 1;
	}
	
	if(!m.loadFile(argv[1]))
	{
		cout << "Invalid file!\n";
		return 1;
	}
	
	doit(m);
	
	return 0;
}
