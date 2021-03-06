// Langstrase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
using namespace std;

int ofAKind(vector <int> diceVector)
{
	int score;
	bool stopCheck = false;
	int kindCheck = 2;
	int multiplier = 1;
	while (stopCheck == false)
	{
		for (int i = 0; i < kindCheck; i++)
		{
			if (diceVector[i] == diceVector[i + kindCheck])
			{

				if (kindCheck > 2)
				{
					multiplier = multiplier * 2;
				}
				kindCheck = kindCheck + 1;
				continue;
			}
			else
			{
				if (kindCheck > 1)
				{
					if (diceVector[i] == 1)
					{
						score = 1000 * diceVector[i] * multiplier;
					}
					else
					{
						score = 100 * diceVector[i] * multiplier;
					}
				}
				stopCheck = true;
			}

		}
	}
	if (score != 0)
	{
		cout << "You rolled multiple of the same die! You earned " << score << " points! " << endl;
	}
	return score;

}

int twoThrees(vector <int> diceVector)
{
	int score = 0;
	for (int i = 0; i < diceVector.size(); i++)
	{
		if (diceVector[i] == diceVector[i + 2])
		{
			if (diceVector[i] == 1)
			{
				score = 1000 * diceVector[i] + score;
			}
			else
			{
				score = 100 * diceVector[i] + score;
			}

			if (diceVector[2] == diceVector[5])
			{

				if (diceVector[2] == 1)
				{
					score = 1000 * diceVector[2] + score;
				}
				else
				{
					score = 100 * diceVector[2] + score;
				}
			}
		}
	}
	return score;
}

int diceScore(vector <int> diceVector)
{	
	int multiScore;
	int score = 0;
	int diceCount;



	for (int i = 0;i < diceVector.size();i++)
	{
		if (diceVector[i] == 5)
		{
			score = score + diceVector[i] * 10;
		}
		else if (diceVector[i] == 1)
		{
			score = score + diceVector[i] * 100;
		}

	}
	return score;
}

vector <int> diceShake(int diceAmount, vector <int> rollResult)
{
	srand(time(NULL));
	for (int i = 0; i < diceAmount;i++)
	{
		int diceValue = rand() % diceAmount+1;
		rollResult.push_back(diceValue);
	}

	return rollResult;
}

int diceCheckAuto(vector <int> rollResult)
{
	int result = 0;
	vector <int> langstrasse{1, 2, 3, 4, 5, 6};
	sort(rollResult.begin(), rollResult.end());

	if ((rollResult[0] == rollResult[1]) && (rollResult[2] == rollResult[3]) && (rollResult[4] == rollResult[5]))
	{
		cout << "Congratulations! You rolled three sets of pairs! You gain 1000 points and you get to roll the dice again" << endl;
		result = 1000;
	}

	if (includes(rollResult.begin(), rollResult.end(),
		langstrasse.begin(), langstrasse.end()))
	{
		cout << "LANGSTRASSE!!! You gain 1500 points and you get to roll the dice again!" << endl;
		result = 1500;
	}
	return result;
}

vector<char> keptToVector(int diceKept) 
{
	stringstream ss;
	ss << diceKept;
	string ssDice = ss.str();
	vector<char> diceReturn(ssDice.begin(), ssDice.end());
	return diceReturn;
}

int diceRoll()
{
	int score = 0;
	int diceAmount = 6;
	bool canRoll = true;
	int diceKept;
	vector <int> diceVector;
	bool selectionSuccess = false;

	vector <int> rollResult;
	while (canRoll == true)
	{
		if (score != 0)
		{
			cout << "You currently have " << score << " points." << endl;
		}

		cout << "You roll the dice..." << endl;
		rollResult = diceShake(diceAmount, rollResult);
		cout << "With " << diceAmount << " die, you rolled: " << endl;
		sort(rollResult.begin(), rollResult.end());
		for (int i = 0; i < diceAmount;i++)
		{
			cout << rollResult[i] << ", ";
		}
		if (diceAmount == 6)
		{
			if (diceCheckAuto(rollResult) != 0)
			{
				selectionSuccess = true;
			}
		}
		vector <int> testNumbers{1, 5};
		if (!(includes(rollResult.begin(), rollResult.end(),
			testNumbers.begin(), testNumbers.end())))
		{
			cout << "no dice" << endl;
			diceVector.clear();
			canRoll = false;
		}
		while (selectionSuccess == false)
		{
			cout << "Please enter which dice you would like to hold on to: ";
			cin >> diceKept;

			int modulo = 10;
			int divide = 1;
			for (int i = rollResult.size(); i > 0 ;i--)
			{

				int digit = diceKept / divide % modulo;
				diceVector.push_back(digit);
				divide = divide * 10;

			}

			sort(diceVector.begin(), diceVector.end());
			int diceCount;
			for (int i = 0; i < diceVector.size();i++)
			{
				diceCount = count(rollResult.begin(), rollResult.end(), diceVector[i]);
				cout << diceCount << "sets of " << diceVector[i] << endl;
			}



			if (!(includes(rollResult.begin(), rollResult.end(),
				diceVector.begin(), diceVector.end())))
			{
				cout << "You selected dice incorrectly, please try again with the format (115) if you found two ones and a five... " << endl;
				diceVector.clear();
			}
			else
			{
				cout << "You selected correctly" << endl;
				diceAmount = diceAmount - 1;
				rollResult.clear();
				diceVector.clear();
				//run score function
				selectionSuccess = true;
			}
		}

	}

	return score;
}

int main()
{
	srand(time(NULL));
	diceRoll();
	


    return 0;
}

