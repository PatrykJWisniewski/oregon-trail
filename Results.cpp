// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include "Results.h"
using namespace std;

Results::Results()
{
	score = 0;
}

void Results::SetName(string newS)
{
	name = newS;
}

void Results::SetMiles(int newI)
{
	miles = newI;
}

void Results::SetFood(int newI)
{
	food = newI;
}

void Results::SetMoney(float newF)
{
	money = newF;
}

string Results::GetName()
{
	return name;
}

int Results::GetMiles()
{
	return miles;
}

int Results::GetFood()
{
	return food;
}

float Results::GetMoney()
{
	return money;
}

float Results::GetScore()
{
	return score;
}

void Results::FindScore()
{
	score = miles;
	if (miles == 2040)
	{
		score += money;
		score += food;
	}
}