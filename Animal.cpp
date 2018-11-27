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

Animal::Animal()
{

}

void Animal::SetName(string newV)
{
	name = newV;
}

void Animal::SetProb(int newV)
{
	probility = newV;
}

void Animal::SetMin(int newV)
{
	minFood = newV;
}

void Animal::SetMax(int newV)
{
	maxFood = newV;
}

void Animal::SetCost(int newV)
{
	bulletCost = newV;
}

string Animal::GetName()
{
	return name;
}

int Animal::GetProb()
{
	return probility;
}

int Animal::GetMin()
{
	return minFood;
}

int Animal::GetMax()
{
	return maxFood;
}

int Animal::GetCost()
{
	return bulletCost;
}