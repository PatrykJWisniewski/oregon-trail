// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Cart.h"
using namespace std;

//Default constructor
Cart::Cart()
{
	money = 1200;
	oxen = 0;
	food = 0;
	ammo = 0;
	parts = 0;
	oxen = 0;
	healthKits = 0;
}

//Algorithm - Moves the date forward by the amount of given days
//1. Checks to see what month it its
//2. Moves date forward by the input of days
void Cart::MoveDateForward(int dateNums[], int days)
{
	switch (dateNums[1])
	{
	//If the month has 31 days
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
		//For each day passed
		for (int i = 0; i < days; i++)
		{
			dateNums[2]++;
			//If its the next month
			if (dateNums[2] == 32)
			{
				dateNums[1]++;
				dateNums[2] = 1;
			}
		}
		break;

	//If the month has 30 days
	case 4:
	case 6:
	case 9:
	case 11:
		//For each day passed
		for (int i = 0; i < days; i++)
		{
			dateNums[2]++;
			//If its the next month
			if (dateNums[2] == 31)
			{
				dateNums[1]++;
				dateNums[2] = 1;
			}
		}
		break;
	}
}

//Sets the amount of money the player has
void Cart::SetMoney(float newMoney)
{
	money = newMoney;
}

//Gets the amount of money the player has
float Cart::GetMoney()
{
	return money;
}

//Sets the amount of Oxen the player has
void Cart::SetOxen(int newOxen)
{
	oxen = newOxen;
}

//Returns the amount of oxen the player has 
int Cart::GetOxen()
{
	return oxen;
}

//Sets the amount of food the player has
void Cart::SetFood(int newFood)
{
	food = newFood;
}

//Returns the amount of food the player has
int Cart::GetFood()
{
	return food;
}

//Sets the amount of bullets the player has
void Cart::SetAmmo(int newAmmo)
{
	ammo = newAmmo;
}

//Returns the amount of bullets the player has
int Cart::GetAmmo()
{
	return ammo;
}

//Sets the amount of parts that the player has
void Cart::SetParts(int newParts)
{
	parts = newParts;
}

//Returns the amount of parts the player has
int Cart::GetParts()
{
	return parts;
}

//Sets the amount of health kits the player has
void Cart::SetHelathKits(int newHealthKits)
{
	healthKits = newHealthKits;
}

//Returns the amount of health kits the player has
int Cart::GetHelathKits()
{
	return healthKits;
}