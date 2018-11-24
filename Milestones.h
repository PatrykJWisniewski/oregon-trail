// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#ifndef MILESTONES_H
#define MILESTONES_H
#include <string>
#include "Cart.h"
#include "Humans.h"
using namespace std;

class Milestones
{
private:
	string name;
	int depth;
	int distance;
	float priceIncrease;
	float oxenCost;
	float foodCost;
	float ammoCost;
	float partCost;
	float medCost;

public:
	Milestones();
	Cart PromptUser(int distance, Cart cart, Humans humans[]);
	Cart VisitStore(int distance, Cart cart);
	int ConvertInput(string input);
	void SetPriceIncrease(float increase);
	void SetName(string newName);
	string GetName();
	void SetDistance(int newDistance);
	int GetDistance();
	void SetDepth(int newDepth);
};

#endif