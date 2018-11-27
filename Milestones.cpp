// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Milestones.h"
#include "Cart.h"
#include "Humans.h"
using namespace std;

Milestones::Milestones()
{
	name = "start";
	distance = 0;
	depth = 0;
	priceIncrease = 1;
	oxenCost = 40;
	foodCost = .5;
	ammoCost = 2;
	partCost = 20;
	medCost = 25;
}

Cart Milestones::PromptUser(int distance, Cart cart, Humans humans[])
{
	char input;
	bool stop = false;

	//If the player has reached a river
	if (depth > 0)
	{
		cout << "You have reached the " << name << endl;
		cout << "1. Cross the river" << endl;
		cout << "2. Rest" << endl;
		while (stop == false)
		{
			cin >> input;

			switch (input)
			{
			case '1':
				//If the depth of the river is greater then 3 feet...
				if (depth > 3)
				{
					//Charge the player 10$ per person
					for (int i = 0; i < 5; i++)
					{
						if (humans[i].GetAlive() == true)
						{
							cart.SetMoney(cart.GetMoney() - 10);
						}
					}

					cout << "You crossed the river by ferry paying $10 per person" << endl;
				}
				//If not then allow the player to cross without paying a fee
				else
				{
					cout << "The river proved shallow enouth to cross on your own so you pushed on with the cart in tow" << endl;
				}
				stop = true;
				return cart;
				break;
			case '2':
				//For each player in the game
				for (int i = 0; i < 5; i++)
				{
					cart.SetFood(cart.GetFood() - humans[i].Rest(1, 3)); //Subtracts food from the players total for each human that is alive
					if (cart.GetFood() <= 0)
					{
						return cart;
					}
				}
				break;
			default:
				cout << "Please enter a valid input" << endl;
			}
		}
	}
	else
	{
		//If the user is visting the store for the first time during the start of the game
		if (distance == 0)
		{
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
					return VisitStore(distance, cart);
					break;
				case 'N':
				case 'n':
					stop = true;
					return cart;
					break;
				default:
					cout << "Please enter a valid input" << endl;
				}
			}
		}
		//If the player has reached a fort
		else
		{
			cout << "You have reached " << name << endl;

			while (stop == false)
			{
				cout << "1. Visit the store" << endl;
				cout << "2. Rest" << endl;
				cout << "3. Continue" << endl;

				cin >> input;

				switch (input)
				{
				case '1':
					VisitStore(distance, cart);
					break;
				case '2':
					//For each player in the game
					for (int i = 0; i < 5; i++)
					{
						cart.SetFood(cart.GetFood() - humans[i].Rest(1, 3)); //Subtracts food from the players total for each human that is alive
						if (cart.GetFood() <= 0)
						{
							return cart;
						}
					}
					cout<< endl << "You rested for one day" << endl << endl;
					break;
				case '3':
					stop = true;
					cout << "You leave the fort ready to push onward" << endl;
				default:
					cout << "Please enter a valid input" << endl;
				}
			}
		}
		return cart;
	}
}

Cart Milestones::VisitStore(int distance, Cart cart)
{
	string input;
	int inputNum;
	float currentBill = 0;
	bool stop = false;

	cout << endl << "Welcome to the Store!" << endl;

	//If you are visiting the store at the start of the game
	if (distance == 0)
	{
		cout <<	"YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE INITIALLY PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:" << endl;
		cout <<	"- OXEN.YOU CAN SPEND $100 - $200 ON YOUR TEAM.THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS" << endl;
		cout <<	"- FOOD.THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK" << endl;
		cout <<	"- BULLETS - $2 BUYS A BELT OF 20 BULLETS.YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD" << endl;
		cout <<	"- MISCELLANEOUS SUPPLIES.THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS" << endl;
		cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW." << endl;
		cout << "HOWEVER, ITEMS COST MORE AT THE FORTS.YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD." << endl;
		cart.SetMoney(1000);
	}

	cout << endl << "Right now you have: $" << cart.GetMoney() << endl;

	//Will keep asking you what you want to buy untill the player exits the store
	while (stop == false)
	{
		cout << endl << "WHAT DO YOU WISH TO BUY?" << endl;
		cout << "1 : Oxen" << endl;
		cout << "2 : Food" << endl;
		cout << "3 : Bullets" << endl;
		cout << "4 : Wagon Parts" << endl;
		cout << "5 : Med Kits" << endl;
		cout << "6 : Exit Shop" << endl;

		cin >> input;

		inputNum = ConvertInput(input);

		switch (inputNum)
		{
			case 1:
				//If its the first store at the start of the game
				if (distance == 0)
				{
					cout << "Since this is your first time here you must spend between $100 and $200 on oxen to start your journey." << endl;
				}
				cout << "ITEM : Two Oxen(Yoke)" << endl;
				cout << "PRICE : $" << oxenCost*priceIncrease << endl;
				cout << "How many yoke's would you like to buy:" << endl;
				cin >> input;

				inputNum = ConvertInput(input);

				//If the player does not have enouth money
				if (currentBill + inputNum * (oxenCost*priceIncrease) > cart.GetMoney())
				{
					cout << "You do not have enouth cash to buy this" << endl;
					cout << "Current Bill: " << currentBill << endl;
					inputNum = -1;
				}

				//If there was a valid input
				if (inputNum > 0)
				{
					if (distance == 0 && cart.GetOxen() == 0 && inputNum * 40 < 100 || inputNum * 40 > 200)
					{
						cout << "You did not choose a valid amount of yokes" << endl;
						cout << "Current Bill: " << currentBill << endl;
					}
					else if (cart.GetOxen() + (inputNum * 2) > 9 && distance > 0)
					{
						cout << "You can not buy any more yokes" << endl;
						cout << "Current Bill: " << currentBill << endl;
					}
					else
					{
						cart.SetOxen(cart.GetOxen() + (inputNum * 2));
						currentBill += inputNum*(oxenCost*priceIncrease);
						cout << "Current Bill: " << currentBill << endl;
					}
				}
				break;

			case 2:
				//If its the first store at the start of the game
				if (distance == 0)
				{
					cout << "I recommend you get at least 200 lbs of food per person." << endl;
				}
				cout << "ITEM : A Pound of Food" << endl;
				cout << "PRICE : $" << foodCost * priceIncrease << endl;
				cout << "How many pounds would you like to buy:" << endl;
				cin >> input;

				inputNum = ConvertInput(input);

				//If the player does not have enouth money
				if (currentBill + inputNum * (foodCost*priceIncrease) > cart.GetMoney())
				{
					cout << "You do not have enouth cash to buy this" << endl;
					cout << "Current Bill: " << currentBill << endl;
					inputNum = -1;
				}

				//If there was a valid input
				if (inputNum > 0)
				{
					if ((cart.GetFood() + inputNum) > 1000)
					{
						cout << "You can not fit this much food on your cart" << endl;
						cout << "Current Bill: " << currentBill << endl;
					}
					else
					{
						cart.SetFood(cart.GetFood() + inputNum);
						currentBill += inputNum * (foodCost * priceIncrease);
						cout << "Current Bill: " << currentBill << endl;
					}
				}
				break;

			case 3:
				cout << "ITEM : A box with 20 Bullets" << endl;
				cout << "PRICE : $" << ammoCost * priceIncrease << endl;
				cout << "How many boxes would you like to buy:" << endl;
				cin >> input;

				inputNum = ConvertInput(input);

				//If the player does not have enouth money
				if (currentBill + inputNum * (ammoCost*priceIncrease) > cart.GetMoney())
				{
					cout << "You do not have enouth cash to buy this" << endl;
					cout << "Current Bill: " << currentBill << endl;
					inputNum = -1;
				}

				//If there was a valid input
				if (inputNum > 0)
				{
					cart.SetAmmo(cart.GetAmmo() + (inputNum*20));
					currentBill += inputNum * (ammoCost * priceIncrease);
					cout << "Current Bill: " << currentBill << endl;
				}
				break;

			case 4:
				cout << "ITEM : Wagon Part" << endl;
				cout << "PRICE : $" << partCost * priceIncrease << endl;
				cout << "How many parts would you like to buy:" << endl;
				cin >> input;

				inputNum = ConvertInput(input);

				//If the player does not have enouth money
				if (currentBill + inputNum * (partCost*priceIncrease) > cart.GetMoney())
				{
					cout << "You do not have enouth cash to buy this" << endl;
					cout << "Current Bill: " << currentBill << endl;
					inputNum = -1;
				}

				//If there was a valid input
				if (inputNum > 0)
				{
					cart.SetParts(cart.GetParts() + inputNum);
					currentBill += inputNum * (partCost * priceIncrease);
					cout << "Current Bill: " << currentBill << endl;
				}
				break;

			case 5:
				cout << "ITEM : Med Kit" << endl;
				cout << "PRICE : $" << medCost * priceIncrease << endl;
				cout << "How many boxes would you like to buy:" << endl;
				cin >> input;

				inputNum = ConvertInput(input);

				//If the player does not have enouth money
				if (currentBill + inputNum * (medCost*priceIncrease) > cart.GetMoney())
				{
					cout << "You do not have enouth cash to buy this" << endl;
					cout << "Current Bill: " << currentBill << endl;
					inputNum = -1;
				}

				//If there was a valid input
				if (inputNum > 0)
				{
					cart.SetHelathKits(cart.GetHelathKits() + inputNum);
					currentBill += inputNum * (medCost * priceIncrease);
					cout << "Current Bill: " << currentBill << endl;
				}
				break;

			case 6:
				cout << "Thanks for visting the store. Good luck out there." << endl;
				cart.SetMoney(cart.GetMoney() - currentBill);
				cout << "You have $" << cart.GetMoney() << " left" << endl;
				stop = true;
				break;

			default:
				cout << "Please select a valid option" << endl;
		}
	}

	return cart;
}

int Milestones::ConvertInput(string input)
{
	int inputNum;

	//Checks to make sure the string can be converted to an int
	try
	{
		inputNum = stoi(input);
	}
	//Will tell the user to select a valid option this time
	catch (std::exception& e)
	{
		inputNum = -1;
		cout << "Please select a valid option" << endl;
	}

	return inputNum;
}

void Milestones::SetPriceIncrease(float increase)
{
	priceIncrease = increase;
}

void Milestones::SetName(string newName)
{
	name = newName;
}

string Milestones::GetName()
{
	return name;
}

void Milestones::SetDistance(int newDistance)
{
	distance = newDistance;
}

int Milestones::GetDistance()
{
	return distance;
}

void Milestones::SetDepth(int newDepth)
{
	depth = newDepth;
}