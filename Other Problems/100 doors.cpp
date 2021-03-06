// 100 doors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

vector <int> appendLoop(vector <int> doors, int door2door)
{
	for (int i = 0; i < doors.size();i = i+door2door)
	{
		if (doors[i] == 0)
		{
			doors[i] = doors[i] + 1;
			
		}
		else if (doors[i] == 1)
		{
			doors[i] = doors[i] - 1;
			
		}
	}
	return doors;
}

int main()
{
	string message;
	int doorNumber = 100;
	int doorValue = 0;
	int door2door = 1;
	vector <int> doors(doorNumber, doorValue);
	while (door2door < 100)
	{
		doors = appendLoop(doors, door2door);
		door2door = door2door + 1;
		
	}
	int mycount = count(doors.begin(), doors.end(), 1);
	cout << "The number of open doors are: " << mycount << endl;

	for (int i = 1; i < doors.size();i++)
	{
		if (doors[i] == 1)
		{
			cout << i << endl;
		}
	}
	cout << doors.size();
	cin >> message;
	cout << message << endl;
    return 0;
}

