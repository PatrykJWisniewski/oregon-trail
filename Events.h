// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#ifndef EVENTS_H
#define EVENTS_H
#include <string>
#include "Cart.h"
#include "Humans.h"
using namespace std;

class Events
{
private:
	bool misfortune;
	bool attacked;

public:
	Events(float distance);
	int randomNumbers(int min, int max);
	Cart Misfortune(Cart cart, Humans humans[], int dateNums[]);
	Cart Raiders(Cart cart);
	bool GetMisfortune();
	bool GetAttacked();
	bool Puzzel();
};

#endif