// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#ifndef HUMANS_H
#define HUMANS_H
#include "Cart.h"
#include "Animal.h"
#include <string>
using namespace std;

class Humans
{
private:
	string name;
	bool alive;
	int randomNum;
	Animal animals[5];

public:
	Humans();
	int split(string str, char c, string array[], int size);
	void SetName(string nameInput);
	string GetName();
	bool GetAlive();
	void SetDead();
	int randomNumbers(int min, int max);
	int Rest(int days, int food);
	Cart Hunt(Cart cart);
	bool Puzzel();
};

#endif