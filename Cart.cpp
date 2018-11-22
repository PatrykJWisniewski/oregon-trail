// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Cart.h"
using namespace std;

Cart::Cart()
{
	money = 1200;
	oxen = 0;
	food = 0;
	ammo = 0;
	parts = 0;
	oxen = 0;
	healthKits = 0;
}

void Cart::SetMoney(float newMoney)
{
	money = newMoney;
}

float Cart::GetMoney()
{
	return money;
}

void Cart::SetOxen(int newOxen)
{
	oxen = newOxen;
}

int Cart::GetOxen()
{
	return oxen;
}

void Cart::SetFood(int newFood)
{
	food = newFood;
}
int Cart::GetFood()
{
	return food;
}

void Cart::SetAmmo(int newAmmo)
{
	ammo = newAmmo;
}

int Cart::GetAmmo()
{
	return ammo;
}

void Cart::SetParts(int newParts)
{
	parts = newParts;
}

int Cart::GetParts()
{
	return parts;
}

void Cart::SetHelathKits(int newHealthKits)
{
	healthKits = newHealthKits;
}

int Cart::GetHelathKits()
{
	return healthKits;
}