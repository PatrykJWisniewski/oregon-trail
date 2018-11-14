// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 8

#ifndef HUMANS_H
#define HUMANS_H
#include <string>
using namespace std;

class Humans
{
private:
	string name;

public:
	Humans();
	void SetName(string nameInput);
	string GetName();
	void Rest();
	void Countine();
	void Hunt();
	void Puzzel();
};

#endif