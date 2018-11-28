// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include "Results.h"
using namespace std;

//Default constructor
Results::Results()
{
	score = 0;
}

//Sets a players name		
void Results::SetName(string newS)
{
	name = newS;
}

//Sets a players distance travled
void Results::SetMiles(int newI)
{
	miles = newI;
}

//Sets a players remaining food
void Results::SetFood(int newI)
{
	food = newI;
}

//Sets a players remaining money
void Results::SetMoney(float newF)
{
	money = newF;
}

//Gets the players name
string Results::GetName()
{
	return name;
}

//Gets a players miles travled
int Results::GetMiles()
{
	return miles;
}

//Gets a players remaining food
int Results::GetFood()
{
	return food;
}

//Gets a players remaning money
float Results::GetMoney()
{
	return money;
}

//Gets a players overall score
float Results::GetScore()
{
	return score;
}

//Finds a players total score
void Results::FindScore()
{
	score = miles;

	//If the player beat the game then their score increases based on remaining food and money.
	if (miles == 2040)
	{
		score += money;
		score += food;
	}
}