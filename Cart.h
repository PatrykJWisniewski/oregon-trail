// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#ifndef CART_H
#define CART_H
#include <string>
using namespace std;

class Cart
{
private:
	float money;
	int oxen;
	int food;
	int ammo;
	int parts;
	int healthKits;

public:
	Cart();
	void SetMoney(float newMoney);
	float GetMoney();
	void SetOxen(int newOxen);
	int GetOxen();
	void SetFood(int newFood);
	int GetFood();
	void SetAmmo(int newAmmo);
	int GetAmmo();
	void SetParts(int newParts);
	int GetParts();
	void SetHelathKits(int newHealthKits);
	int GetHelathKits();
};

#endif