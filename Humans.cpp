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

int Humans::Rest(int days)
{
	if (alive == true)
	{
		return 3 * days;
	}
}