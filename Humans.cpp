// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Humans.h"
#include "Cart.h"
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

bool Humans::GetAlive()
{
	return alive;
}

int Humans::randomNumbers(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

int Humans::Rest(int days, int food)
{
	if (alive == true)
	{
		return food * days;
	}
}

//Keeps asking the player if they wish to hunt untill a valid input is given
bool AskToHunt()
{
	bool stop = false;
	char charInput;

	while (stop == false)
	{
		cout << "Y / N" << endl;
		cin >> charInput;

		switch (charInput)
		{
		case 'Y':
		case 'y':
			stop = true;
			return true;
			break;
		case 'N':
		case 'n':
			stop = true;
			return false;
			break;
		default:
			cout << "Please enter a valid input" << endl;
		}
	}
}

Cart Humans::Hunt(Cart cart)
{
	//If the player encounters a rabbit
	if (randomNumbers(1, 100) > 50)
	{
		cout << "You encountered a rabbit. Would you like to hunt it?" << endl;
		//If the player choose to hunt
		if (AskToHunt() == true)
		{
			//If the player has less then 10 bullets
			if (cart.GetAmmo() < 10)
			{
				cout << "Due to your lack of bullets the hunt is unsuccessful." << endl;
			}
			else
			{
				//If the player beat the puzzel...
				if (Puzzel() == true)
				{
					//Add food and remove ammo
					cart.SetFood(cart.GetFood() + 2);
					cart.SetAmmo(cart.GetAmmo() - 10);
					cout << "The rabbit was worth 2 pounds of food, however it did take some ammo to kill." << endl;
				}
				//If the player failed the puzzel
				else
				{
					cout << "The hunt was unsuccessful." << endl;
				}
			}
		}
	}

	//If the player encounters a fox
	if (randomNumbers(1, 100) > 75)
	{
		cout << "You encountered a fox. Would you like to hunt it?" << endl;
		//If the player choose to hunt
		if (AskToHunt() == true)
		{
			//If the player has less then 10 bullets
			if (cart.GetAmmo() < 10)
			{
				cout << "Due to your lack of bullets the hunt is unsuccessful." << endl;
			}
			else
			{
				//If the player beat the puzzel...
				if (Puzzel() == true)
				{
					//Add food and remove ammo
					cart.SetFood(cart.GetFood() + 5);
					cart.SetAmmo(cart.GetAmmo() - 8);
					cout << "The fox was worth 5 pounds of food, however it did take some ammo to kill." << endl;
				}
				//If the player failed the puzzel
				else
				{
					cout << "The hunt was unsuccessful." << endl;
				}
			}
		}
	}

	//If the player encounters a deer
	if (randomNumbers(1, 100) > 85)
	{
		cout << "You encountered a deer. Would you like to hunt it?" << endl;
		//If the player choose to hunt
		if (AskToHunt() == true)
		{
			//If the player has less then 10 bullets
			if (cart.GetAmmo() < 10)
			{
				cout << "Due to your lack of bullets the hunt is unsuccessful." << endl;
			}
			else
			{
				//If the player beat the puzzel...
				if (Puzzel() == true)
				{
					//Add food and remove ammo
					randomNum = randomNumbers(30, 55); //Picks a random number for the animals food output
					cart.SetFood(cart.GetFood() + randomNum);
					cart.SetAmmo(cart.GetAmmo() - 5
);
					cout << "The deer was worth " << randomNum << " pounds of food, however it did take some ammo to kill." << endl;
				}
				//If the player failed the puzzel
				else
				{
					cout << "The hunt was unsuccessful." << endl;
				}
			}
		}
	}

	//If the player encounters a bear
	if (randomNumbers(1, 100) > 93)
	{
		cout << "You encountered a bear. Would you like to hunt it?" << endl;
		//If the player choose to hunt
		if (AskToHunt() == true)
		{
			//If the player has less then 10 bullets
			if (cart.GetAmmo() < 10)
			{
				cout << "Due to your lack of bullets the hunt is unsuccessful." << endl;
			}
			else
			{
				//If the player beat the puzzel...
				if (Puzzel() == true)
				{
					//Add food and remove ammo
					randomNum = randomNumbers(100, 350); //Picks a random number for the animals food output
					cart.SetFood(cart.GetFood() + randomNum);
					cart.SetAmmo(cart.GetAmmo() - 10);
					cout << "The bear was worth " << randomNum << " pounds of food, however it did take some ammo to kill." << endl;
				}
				//If the player failed the puzzel
				else
				{
					cout << "The hunt was unsuccessful." << endl;
				}
			}
		}
	}

	//If the player encounters a moose
	if (randomNumbers(1, 100) > 95)
	{
		cout << "You encountered a moose. Would you like to hunt it?" << endl;
		//If the player choose to hunt
		if (AskToHunt() == true)
		{
			//If the player has less then 10 bullets
			if (cart.GetAmmo() < 10)
			{
				cout << "Due to your lack of bullets the hunt is unsuccessful." << endl;
			}
			else
			{
				//If the player beat the puzzel...
				if (Puzzel() == true)
				{
					//Add food and remove ammo
					randomNum = randomNumbers(300, 600); //Picks a random number for the animals food output
					cart.SetFood(cart.GetFood() + randomNum);
					cart.SetAmmo(cart.GetAmmo() - 12);
					cout << "The moose was worth " << randomNum << " pounds of food, however it did take some ammo to kill." << endl;
				}
				//If the player failed the puzzel
				else
				{
					cout << "The hunt was unsuccessful." << endl;
				}
			}
		}
	}

	//If the player used more ammo then they had
	if (cart.GetAmmo() < 0)
	{
		cart.SetAmmo(0);
	}

	return cart;
}

bool Humans::Puzzel()
{
	int randomNum = randomNumbers(1, 10);
	string input;
	int inputNum = -1;
	bool badInput = false;

	for (int i = 0; i < 3; i++)
	{
		cout << "In order to win guess the corret number between 1 and 10. You have " << 3-i << " tries left!" << endl;
		cin >> input;

		//Checks to make sure the string can be converted to an int
		try
		{
			inputNum = stoi(input);
		}
		//Will tell the user to select a valid option this time
		catch (std::exception& e)
		{
			badInput = true;
			cout << "Please select a valid number" << endl;
			i--;
		}

		if (inputNum < 1 && badInput == false || inputNum > 10)
		{
			cout << "Please select a valid number" << endl;
			i--;
		}

		if (inputNum == randomNum)
		{
			cout << "You won!" << endl;
			return true;
		}
	}
}