// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 8

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Milestones.h"
#include "Events.h"
#include "Humans.h"
#include "Cart.h"
using namespace std;

int main()
{
	Cart CART;
	Humans HUMANS[5];
	Milestones MILESTONES[20];
	int year;
	int month;
	int day;
	int distanceTravled;
	string nameInput;

	cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847." << endl;
	cout << "YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6 MONTHS --- IF YOU MAKE IT ALIVE." << endl << endl;

	cout << "Before you begin your jorney we would like to document some basic information about you and your family." << endl;
	cout << "If you could be so kind as to please tell us your name." << endl;

	cin >> nameInput;
	HUMANS[0].SetName(nameInput);

	cout << endl << "Thank you kindly. Now if we could please tell us the names of your fellow travalers." << endl;

	for (int i = 1; i < 5; i++)
	{
		cin >> nameInput;
		HUMANS[i].SetName(nameInput);
	}

	cout << endl << "You, ";
	for (int j = 1; j < 5; j++)
	{
		if (j == 4)
		{
			cout << "and ";
			cout << HUMANS[j].GetName();
		}
		else
		{
			cout << HUMANS[j].GetName() << ", ";
		}
	}

	cout << endl << "Once you recorded your information you headed off the store in order to start your jorney" << endl;
	cin >> year;
	
}