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
#include "Animal.h"
using namespace std;

Humans::Humans()
{
	name = "";
	alive = true;

	ifstream myFile;
	myFile.open("animalinfo.txt");
	string info[5];
	string line;

	int i = 0;
	while (getline(myFile, line))
	{
		split(line, ' ', info, 5);
		animals[i].SetName(info[0]);
		animals[i].SetProb(stoi(info[1]));
		animals[i].SetMin(stoi(info[2]));
		animals[i].SetMax(stoi(info[3]));
		animals[i].SetCost(stoi(info[4]));
		i++;
	}
}

int Humans::split(string str, char c, string array[], int size)
{
	if (str.length() == 0) {
		return 0;
	}
	string word = "";
	int count = 0;
	str = str + c;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
		{
			if (word.length() == 0)
				continue;
			array[count++] = word;
			word = "";
		}
		else {
			word = word + str[i];
		}
	}
	return count;
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

void Humans::SetDead()
{
	alive = false;
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
	else
	{
		return 0;
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
	bool nothingFound = true;

	//Checks if the user encountered each type of animal
	for (int i = 0; i < 5; i++)
	{
		//If the player encounters an animal
		if (randomNumbers(1, 100) > animals[i].GetProb())
		{
			cout << "You encountered a " << animals[i].GetName() << " . Would you like to hunt it?" << endl;
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
						randomNum = randomNumbers(animals[i].GetMin(), animals[i].GetMax()); //Picks a random number for the animals food output
						cart.SetFood(cart.GetFood() + randomNum);
						cart.SetAmmo(cart.GetAmmo() - animals[i].GetCost());
						cout << "The  " << animals[i].GetName() << "  was worth " << randomNum << " pounds of food, however it did take some ammo to kill." << endl;
					}
					//If the player failed the puzzel
					else
					{
						cout << "The hunt was unsuccessful." << endl;
					}
				}
			}

			nothingFound = false;
		}
	}

	if (nothingFound == true)
	{
		cout << "The hunt was unsuccessful." << endl;
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

	if (inputNum != randomNum)
	{
		cout << "You lost" << endl;
		return false;
	}
}