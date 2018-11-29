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

//Default constructor
Humans::Humans()
{
	name = "";
	alive = true;

	//Opens the animal info text file
	ifstream myFile;
	myFile.open("animalinfo.txt");
	string info[5];
	string line;

	int i = 0;
	//Reads each line in the text files and populats the animals array
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

//Algorithm - Splits a given string into multipal strings
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

//Sets the name of this human and marks them as alive
void Humans::SetName(string nameInput)
{
	name = nameInput;
	alive = true;
}

//Returns the name of the human
string Humans::GetName()
{
	return name;
}

//Returns if the player is alive
bool Humans::GetAlive()
{
	return alive;
}

//Sets the player as dead
void Humans::SetDead()
{
	alive = false;
}

//Returns a random number between the given min(inclusive) and max(inclusive)
int Humans::randomNumbers(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

//Algorithm - Rests for the amount of given while consuming food by the given amount
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

//Algorithm - Keeps asking the player if they wish to hunt untill a valid input is given
bool AskToHunt()
{
	bool stop = false;
	char charInput;

	//Untill there is a valid input
	while (stop == false)
	{
		cout << "Y / N" << endl;
		cin >> charInput;

		switch (charInput)
		{
		case 'Y':
		case 'y':
			stop = true;
			return true; //Yes the player wants to hunt
			break;
		case 'N':
		case 'n':
			stop = true;
			return false; //No the player does not want to hunt
			break;
		default:
			cout << "Please enter a valid input" << endl;
		}
	}
}

//Algorithm - Lets the player hunt for animals
//1. Checks the player ran into each animal one at a a time
//2. If the player ran into an animal then ask if they want to hunt it
//3. Check if the player has enouth bullets to hunt
//4. Ask the player to play a puzzel and award them food if they win
//5. Checks to see if the player ran into at least one animal
//6. Return an instance of the cart class with modified variables
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

	//If the hunt was unsiccessful
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

//Algorithm - Has the user guess a randomly genarated number with 3 attempts
//1. Creates a random number between 1 and 10
//2. Asks the user to guess the number up to 3 times
//3. Checks to make sure its a valid input
//4. Returns if the player managed to guess the input correctly
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

		//If the input was a number but did not fall withen the bounds of 1-10
		if (inputNum < 1 && badInput == false || inputNum > 10)
		{
			cout << "Please select a valid number" << endl;
			i--;
		}

		//If the user correctly guessed the number
		if (inputNum == randomNum)
		{
			cout << "You won!" << endl;
			return true;
		}
	}

	//If the palyer did not corretly gues the number after 3 tries
	if (inputNum != randomNum)
	{
		cout << "You lost" << endl;
		return false;
	}
}