// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#ifndef HUMANS_H
#define HUMANS_H
#include <string>
using namespace std;

class Humans
{
private:
	string name;
	bool alive;
	int randomNum;

public:
	Humans();
	void SetName(string nameInput);
	string GetName();
	int Rest(int days);
	void Countine();
	void Hunt();
	void Puzzel();
};

#endif