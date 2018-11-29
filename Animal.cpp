// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Cart.h"
#include "Animal.h"
using namespace std;

//Default constructor.
Animal::Animal()
{
	name = "";
	probility = 0;
	minFood = 0;
	maxFood = 0;
	bulletCost = 0;
}

//Sets the name of this animal
void Animal::SetName(string newV)
{
	name = newV;
}

//Sets the probality of running into it
void Animal::SetProb(int newV)
{
	probility = newV;
}

//Sets the min amount of food it gives out
void Animal::SetMin(int newV)
{
	minFood = newV;
}

//Sets the max amount of food that it give out
void Animal::SetMax(int newV)
{
	maxFood = newV;
}

//Sets the amount of bullets needed to kill it
void Animal::SetCost(int newV)
{
	bulletCost = newV;
}

//Returns the name of the animal
string Animal::GetName()
{
	return name;
}

//Returns the probibility of the animal
int Animal::GetProb()
{
	return probility;
}

//Returns the min amount of food that the animal can drop
int Animal::GetMin()
{
	return minFood;
}

//Returns the max amount of food that the animal can drop
int Animal::GetMax()
{
	return maxFood;
}

//Returns the amount of bullets needed to kill the animal
int Animal::GetCost()
{
	return bulletCost;
}