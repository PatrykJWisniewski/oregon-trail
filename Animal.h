// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#ifndef ANIMAL_H
#define ANIMAL_H
#include "Cart.h"
#include <string>
using namespace std;

class Animal
{
private:
	string name;
	int probility;
	int minFood;
	int maxFood;
	int bulletCost;

public:
	Animal();
	void SetName(string newV);
	void SetProb(int newV);
	void SetMin(int newV);
	void SetMax(int newV);
	void SetCost(int newV);
	string GetName();
	int GetProb();
	int GetMin();
	int GetMax();
	int GetCost();

};

#endif