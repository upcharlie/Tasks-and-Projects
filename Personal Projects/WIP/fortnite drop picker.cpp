// fortnite drop picker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int rangeCompare(int rangeX, int rangeY)
{
	int rangeReturn;
	if (rangeX > rangeY)
	{
		rangeReturn = rangeX;
	}
	else
	{
		rangeReturn = rangeY;
	}
	return rangeReturn;
}

string busInput()
{
	string start;
	cout << "Please enter the starting point of the bus: " << endl;
	cin >> start;

	string finish;
	cout << "Now please enter the end grid location of the bus" << endl;
	cin >> finish;

	
	vector<char> startDrop(start.begin(), start.end());

	
	vector<char> endDrop(finish.begin(), finish.end());

	startDrop[0] = (int)startDrop[0] - 87;
	endDrop[0] = (int)endDrop[0] - 87;

	int rangeX = startDrop[0] - endDrop[0];
	int rangeY = startDrop[1] - endDrop[1];

	vector <int> returnVec;

	for (int i = 0; i != rangeCompare(rangeX, rangeY);i++)
	{
		returnVec.push_back()
	}
}

string gridTrack()
{

}

int main()
{

	busInput();
	string fortniteMap[10][10] =
	{
		"", "Junk Junction", "", "", "", "","", "", "", "",
		"", "Haunted Hills", "", "", "", "","", "Risky Reels", "", "",
		"", "", "Pleasant Park", "", "", "Lazy Links","", "", "Wailing Woods", "",
		"", "", "", "", "", "","Tomato Town", "", "", "",
		"Snobby Shores", "", "", "Tilted Towers", "", "Dusty Divot","", "", "", "Lonely Lodge",
		"", "", "", "", "", "","", "Retail Row", "", "",
		"", "", "Greasy Grove", "Shifty Shafts", "", "","Salty Springs", "", "", "",
		"", "", "", "", "", "","", "", "Paradise Palms", "",
		"", "", "", "Flush Factory", "", "","", "", "", "",
		"", "", "", "", "", "","", "", "", "",

	};

    return 0;
}

