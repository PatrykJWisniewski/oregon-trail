// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 8

#ifndef MILESTONES_H
#define MILESTONES_H
#include <string>
using namespace std;

class Milestones
{
private:
	float priceIncrease;
	float oxenCost;
	float foodCost;
	float ammoCost;
	float partCost;
	float medCost;

public:
	Milestones();
	void PromptUser(int distance, int money);
	void VisitStore(int distance, int money);
};

#endif