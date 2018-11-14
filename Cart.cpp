// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 8

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Cart.h"
using namespace std;

Cart::Cart()
{
	money = 1000;
	food = 0;
	ammo = 0;
	parts = 0;
	oxen = 0;
	healthKits = 0;
}