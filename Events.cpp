// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h> 
#include "Events.h"
using namespace std;

Events::Events(float M)
{
	if (randomNumbers(1,100) > 60)
	{
		misfortune = true;
	}
	else
	{
		misfortune = false;
	}

	//Calculates the probability of running into raiders
	float probability;
	probability = pow((M / 100) - 4, 2) + 72;
	probability = probability / (pow((M / 100) - 4, 2) + 12);
	probability--;
	probability = probability / 10;

	if (randomNumbers(1, 100) < probability*100)
	{
		attacked = true;
	}
	else
	{
		attacked = false;
	}
}

int Events::randomNumbers(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

Cart Events::Misfortune(Cart cart, Humans humans[], int dateNums[])
{
	int randomNum = randomNumbers(1, 3); //Calculates what kind of misfortune it will be
	bool stop = false;
	char input;

	//If the a player is going to get sick...
	if (randomNum == 1)
	{
		string diseases[6] = { "typhoid" , "cholera", "diarrhea", "measles", "dysentery", "fever" };

		int rand = randomNumbers(0, 4); //decides which of the 5 players will get sick
		cout << endl << "Oh no! " << humans[rand].GetName() << " has " << diseases[randomNumbers(0, 5)] << endl;
		
		//If the player has health kits...
		if (cart.GetHelathKits() > 0)
		{
			cout << "You used a medkit on " << humans[rand].GetName();
			//The player has a 50% chance of living
			if (randomNumbers(1, 100) > 50)
			{
				cout << " thankfully it looks like " << humans[rand].GetName() << " is going to be ok" << endl;
			}
			else
			{
				cout << " but unfortinaly " << humans[rand].GetName() << " didn't make it" << endl;
				humans[rand].SetDead();
			}
		}
		//If the player does not health kits...
		else
		{
			cout << "You don't have any medkits. What do you wish to do?" << endl;
			cout << "1. Rest" << endl;
			cout << "2. Press On!" << endl;

			//Player must choose a valid option
			while (stop == false)
			{
				cin >> input;

				switch (input)
				{
				case '1':
					//For each player in the game consume food
					for (int i = 0; i < 5; i++)
					{
						cart.SetFood(cart.GetFood() - humans[i].Rest(3, 3)); //Subtracts food from the players total for each human that is alive
					}
					cart.MoveDateForward(dateNums, 3);
					//The player has a 30% chance of living
					if (randomNumbers(1, 100) > 30)
					{
						cout << "Thankfully it looks like " << humans[rand].GetName() << " is going to be ok after resting for 3 days" << endl;
					}
					else
					{
						cout << "Unfortinaly after resting for 3 days " << humans[rand].GetName() << " didn't make it" << endl;
						humans[rand].SetDead();
					}
					stop = true;
					break;
				case '2':
					//The player has a 70% chance of living
					if (randomNumbers(1, 100) > 70)
					{
						cout << "Thankfully it looks like " << humans[rand].GetName() << " is going to be ok after all" << endl;
					}
					else
					{
						cout << "Unfortinaly after pressing on " << humans[rand].GetName() << " didn't make it" << endl;
						humans[rand].SetDead();
					}
					stop = true;
					break;
				default:
					cout << "Please enter a valid input" << endl;
				}
			}
		}
	}
	else if (randomNum == 2)
	{
		if (cart.GetOxen() > 0)
		{
			cart.SetOxen(cart.GetOxen() - 1);
			cout << endl << "Oh no! One of the oxen has died. You have " << cart.GetOxen() << " oxen left" << endl;
		}
	}
	else if (randomNum == 3)
	{
		cart.SetParts(cart.GetParts() - 1);
		cout << endl << "Oh no! One of your wheels broke." << endl;
	}

	return cart;
}

Cart Events::Raiders(Cart cart)
{
	bool stop = false;
	char input;

	cout << endl << "Riders Ahead! They look Hostile!" << endl;
	cout << "What do you wish to do?" << endl;
	cout << "1. Run" << endl;
	cout << "2. Attack" << endl;
	cout << "3. Surrender" << endl;

	//Player must choose a valid option
	while (stop == false)
	{
		cin >> input;

		switch (input)
		{
		case '1':
			cart.SetOxen(cart.GetOxen() - 1);
			cart.SetFood(cart.GetFood() - 10);
			//Checks to see that player has wagon parts so that his total dosen't go into the negatives when running away.
			if (cart.GetParts() > 0)
			{
				cart.SetParts(cart.GetParts() - 1);
				cout << "You escaped with your lives, but in the chaos you left behind 1 ox, 10 pounds of food, and a wagon part." << endl;
			}
			else
			{
				cout << "You escaped with your lives, but in the chaos you left behind 1 ox, and 10 pounds of food." << endl;
			}
			stop = true;
			break;

		case '2':
			cout << "You decided to fight the riders!" << endl;
			if (Puzzel() == true)
			{
				cart.SetFood(cart.GetFood() + 50);
				cart.SetAmmo(cart.GetAmmo() + 50);
				cout << "After fending off the riders you gained 50 pounds of food and 50 bullets!" << endl;
			}
			else
			{
				cart.SetAmmo(cart.GetAmmo() - 50);
				cart.SetMoney(cart.GetMoney()*.75);
				cout << "After losing too the riders you lost 50 bullets and quater of your cash." << endl;
			}
			stop = true;
			break;

		case '3':
			cart.SetMoney(cart.GetMoney()*.75);
			cout << "You surrendered a quater of your cash and contined on your way." << endl;
			stop = true;
			break;
		default:
			cout << "Please enter a valid input" << endl;
		}
	}

	return cart;
}

bool Events::GetMisfortune()
{
	return misfortune;
}

bool Events::GetAttacked()
{
	return attacked;
}

bool Events::Puzzel()
{
	int randomNum = randomNumbers(1, 10);
	string input;
	int inputNum = -1;
	bool badInput = false;

	for (int i = 0; i < 3; i++)
	{
		cout << "In order to win guess the corret number between 1 and 10. You have " << 3 - i << " tries left!" << endl;
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