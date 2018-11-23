// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Humans.h"
using namespace std;

Humans::Humans()
{
	name = "";
	alive = true;
}

void Humans::SetName(string nameInput)
{
	name = nameInput;
	alive = true;
}

string Humans::GetName()
{
	return name;
}

int Humans::randomNumbers(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

int Humans::Rest(int days)
{
	if (alive == true)
	{
		return 3 * days;
	}
}

void Humans::Hunt()
{
	bool rabbit = false;
	bool fox = false;
	bool deer = false;
	bool bear = false;
	bool moose = false;

	if (randomNumbers(1, 100) > 50)
	{
		rabbit = true;
		cout << "R" << endl;
	}
	if (randomNumbers(1, 100) > 75)
	{
		fox = true;
		cout << "F" << endl;
	}
	if (randomNumbers(1, 100) > 85)
	{
		deer = true;
		cout << "D" << endl;
	}
	if (randomNumbers(1, 100) > 93)
	{
		bear = true;
		cout << "B" << endl;
	}
	if (randomNumbers(1, 100) > 95)
	{
		moose = true;
		cout << "M" << endl;
	}
}