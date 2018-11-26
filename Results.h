// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#ifndef RESULTS_H
#define RESULTS_H
#include <string>
using namespace std;

class Results
{
private:
	string name;
	int miles;
	int food;
	float money;
	float score;

public:
	Results();
	void SetName(string newS);
	void SetMiles(int newI);
	void SetFood(int newI);
	void SetMoney(float newF);
	string GetName();
	int GetMiles();
	int GetFood();
	float GetMoney();
	float GetScore();
	void FindScore();
};

#endif