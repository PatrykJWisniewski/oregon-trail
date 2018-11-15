// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 8

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Milestones.h"
using namespace std;

Milestones::Milestones()
{
	priceIncrease = 0;
	oxenCost = 40;
	foodCost = .5;
	ammoCost = 2;
	partCost = 10;
	medCost = 15;
}

void Milestones::PromptUser(int distance, int money)
{
	char input;
	bool stop = false;
	cout << "Would you like to visit the store?" << endl;

	while (stop == false)
	{
		cout << "Y / N" << endl;
		cin >> input;

		switch (input)
		{
		case 'Y':
		case 'y':
			stop = true;
			VisitStore(distance, money);
			break;
		case 'N':
		case 'n':
			stop = true;
			break;
		default:
			cout << "Please enter a valid input" << endl;
		}
	}
}

void Milestones::VisitStore(int distance, int money)
{
	if (distance == 0)
	{
		cout << endl << "Welcome to the Store!" << endl;
		cout <<	"YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE INITIALLY PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:" << endl;
		cout <<	"- OXEN.YOU CAN SPEND $100 - $200 ON YOUR TEAM.THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS" << endl;
		cout <<	"- FOOD.THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK" << endl;
		cout <<	"- BULLETS - $2 BUYS A BELT OF 20 BULLETS.YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD" << endl;
		cout <<	"- MISCELLANEOUS SUPPLIES.THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS" << endl;
		cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW." << endl;
		cout << "HOWEVER, ITEMS COST MORE AT THE FORTS.YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD." << endl;
		cout << endl << "Right now you have: $" << money << endl;
	}
}