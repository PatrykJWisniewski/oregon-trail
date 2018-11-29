// Patryk Wisniewski: CS1300 Fall 2018
// Recitation: 103 - Tetsumichi Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/patrykw/csci1300-patryk
// Project 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "Milestones.h"
#include "Events.h"
#include "Humans.h"
#include "Cart.h"
#include "Results.h"
using namespace std;

//Algorithm - Splits a given string into multipal strings
int split(string str, char c, string array[], int size)
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

//Algorithm - Allows the user to change a date withen a spesficed range
//1. Shows the user what days they can change the date too
//2. Keeps asking the user to input a date untill the input a valid date
//3. Once a valid date is chosen, it sets the date too the users current date
void ChangeDate(int dateNums[])
{
	string input;
	bool stop = false;
	string date[3];

	cout << "Remember you can change it to any date between : 1847-03-01 to 1847-05-01" << endl;

	while (stop == false)
	{
		cout << "Date(YYYY-MM-DD) : ";
		cin >> input;

		split(input, '-', date, 3);

		//Checks to make sure the string can be converted to an int
		try
		{
			stop = true;
			//If the year is 1847...
			if (stoi(date[0]) == 1847)
			{
				dateNums[0] = stoi(date[0]);
			}
			//If its not then keep asking the user
			else
			{
				stop = false;
			}

			//If the month is between march and may...
			if (stoi(date[1]) > 2 && stoi(date[1]) < 6)
			{
				dateNums[1] = stoi(date[1]);
			}
			//If not keep asking the user for a valid date
			else
			{
				stop = false;
			}

			//If the day is valid...
			if (stoi(date[2]) > 0 && stoi(date[2]) < 31)
			{
				//If the user choses April then condier the fact that the day cant be 31
				if (dateNums[1] == 4 && stoi(date[2]) == 31)
				{
					stop = false;
				}
				else
				{
					dateNums[2] = stoi(date[2]);
				}
			}
			//If not keep asking the user for a valid input
			else
			{
				stop = false;
			}
		}
		//Will tell the user to select a valid option this time
		catch (std::exception& e)
		{
			stop = false;
		}

		if (stop == false)
		{
			cout << "Please select a valid option" << endl;
		}
	}

	cout << "The final date of departure is : " << dateNums[0] << "-" << dateNums[1] << "-" << dateNums[2] << endl;
	cout << "You must reach the Oregon City by 1847-11-30" << endl;
}

//Algorithm - Reads the text from both the river and fort milestone text files
//1. Opens the two milestone files in order to read them later
//2. Goes throuth each line of each text file and adds them too an array of milestones
//3. Adds a final milestone for winning the game
void ReadMilestones(Milestones mileStones[])
{
	ifstream myFile[2];
	myFile[0].open("river-milestones.txt"); //Opens the river milestones file
	myFile[1].open("fort-milestones.txt"); //Opens the fort milestones file

	string line;
	string milestoneInfo[2] = { "0","0" }; //Sets up an array that holds the milestone distance and depth

	//Goes throuth each line in both files
	int lineNum = 0;
	int mileStoneNum = 1;

	//Reads files twice. Once for each file
	for (int i = 0; i < 2; i++)
	{
		//Reads all the lines in a gile
		while (getline(myFile[i], line))
		{
			//If the line has the name...
			if (lineNum == 0)
			{
				mileStones[mileStoneNum].SetName(line);
				lineNum = 1;
			}
			//If the line has depth and distance
			else if (lineNum == 1)
			{
				split(line, ' ', milestoneInfo, 2); //Splits the 2nd line in case its a river
				mileStones[mileStoneNum].SetDistance(stoi(milestoneInfo[0]));
				mileStones[mileStoneNum].SetDepth(stoi(milestoneInfo[1]));
				//If the milestone is a fort...
				if (stoi(milestoneInfo[1]) == 0)
				{
					//Increse the price of items
					mileStones[mileStoneNum].SetPriceIncrease((.25*(mileStoneNum - 4))+1);
				}
				lineNum = 0;
				mileStoneNum++;
			}

			milestoneInfo[1] ="0"; //Reset the depth info
		}
	}

	//Sets a final milestone for winning the game
	mileStones[11].SetName("Oregon city");
	mileStones[11].SetDistance(2040);
	mileStones[11].SetDepth(0);
}

//Algorithm - Find the closest milestone too the player
//1. Goes throuth each milestone and finds the one closest too the player 
//2. Returns the next closest milestone
Milestones FindClosestMilestone(Milestones milestones[], int length, int travled)
{
	int distanceFromPlayer = -20000;
	int index = 0;
	//For each milestone
	for (int i = 0; i < length; i++)
	{
		int milestoneDistance = travled - milestones[i].GetDistance(); //Gets the distance of this milestone from start
		//Only counts the milestone if it ahead of the player and is not the first one
		if (milestoneDistance > distanceFromPlayer && milestoneDistance < 0)
		{
			distanceFromPlayer = milestoneDistance;
			index = i;
		}
	}
	
	//If the player beat the game
	if (travled >= 2040)
	{
		index = 11;
	}

	return milestones[index]; //Returns the milestone that is coming up next
}

//Algorithm - Checks to see if the palyer has lost the game, won the game, and saves player data.
//1. Checjs if the won condition for the game has been meet
//2. Checks if any of lose condition have been meet
//3. Saves the players resualt too a file if the game has endded
//4. Returns a bool wheather the game has endded
bool CheckIfThePlayerLostOrWon(Cart cart, Humans leader, int distance, int date[])
{
	bool endGame = false;

	cout << endl;

	//If the player has won the game...
	if (distance == 2040)
	{
		cout << "CONGRATS YOU MADE IT TO OREGON CITY!!!" << endl;
		endGame = true;
	}
	//If the player has not won the game...
	else
	{
		//If the player has run out of food
		if (cart.GetFood() <= 0)
		{
			cout << "The player has ran out of food." << endl;
			endGame = true;
		}

		//If the player has run out of oxen
		if (cart.GetOxen() == 0)
		{
			cout << "The player has ran out of oxen." << endl;
			endGame = true;
		}

		//If the player loses a part but has no parts to lose
		if (cart.GetParts() == -1)
		{
			cout << "Your wagon broke and you have no spare parts." << endl;
			endGame = true;
		}

		//If the leader dies
		if (leader.GetAlive() == false)
		{
			cout << "Your leader has died." << endl;
			endGame = true;
		}

		//If the player does not make it before november 30th
		if (date[1] > 11 && date[2] > 30 && distance < 2040)
		{
			cout << "You didn't make it too Oregon in time. With winter on your heels your fate looked grim..." << endl;
			endGame = true;
		}
	}

	//If the game has come too an end...
	if (endGame == true)
	{
		vector<Results> playerResualts; //A vector that has an array containg a players stats
		ifstream reFile;
		reFile.open("results.txt"); //Opens the resuats file

		string line;
		string playerInfo[2]; //Sets up an array that holds the string and int of each stat

		//Goes throuth each line in the results file
		int lineNum = 0;
		Results newResults;
		//Gets all the information for each player and fills a newResults class in order to compleate it
		while (getline(reFile, line))
		{
			if (lineNum == 4)
			{
				//Once a players info has been read then it skips a line, resets the line count num, and adds the completly read player to a vector
				lineNum = 0;
				playerResualts.push_back(newResults);
			}
			else
			{
				switch (lineNum)
				{
				//First line of a players info is their name
				case 0:
					newResults.SetName(line);
					break;

				//Second line of a players info is their distance travled
				case 1:
					split(line, ':', playerInfo, 2);
					newResults.SetMiles(stoi(playerInfo[1]));
					break;

				//Third line of a players info is food left
				case 2:
					split(line, ':', playerInfo, 2);
					newResults.SetFood(stoi(playerInfo[1]));
					break;

				//Forth line of a players info is money left
				case 3:
					split(line, ':', playerInfo, 2);
					newResults.SetMoney(stoi(playerInfo[1]));
					break;
				}
				lineNum++;
			}
		}

		//Adds the current players resaults too the pool
		newResults.SetName("Leader: " + leader.GetName());
		newResults.SetMiles(distance);
		newResults.SetFood(cart.GetFood());
		newResults.SetMoney(cart.GetMoney());
		playerResualts.push_back(newResults);

		//Finds the hidden score of each player
		for (int i = 0; i < playerResualts.size(); i++)
		{
			playerResualts[i].FindScore();
		}

		//Sorts all the players by their hidden score
		int timesSorted = 0;
		for (int j = 0; j < playerResualts.size(); j++)
		{
			for (int k = 0; k < playerResualts.size() - timesSorted; k++)
			{
				if (playerResualts[k + timesSorted].GetScore() >= playerResualts[timesSorted].GetScore())
				{
					playerResualts.insert(playerResualts.begin() + j, playerResualts[k + timesSorted]);
					playerResualts.erase(playerResualts.begin() + k + timesSorted + 1);
				}
			}
			timesSorted++;
		}

		//Prints out final stats of the game
		if (distance < 2040) //If the player lost
		{
			cout << endl << "YOU HAVE DIED OF DYSENTERY!" << endl;
		}
		cout << endl << "Leader: " << leader.GetName() << endl;
		cout << "Miles Travled: " << distance << endl;
		cout << "Food Remaning: " << cart.GetFood() << endl;
		cout << "Cash Remaning: " << cart.GetMoney() << endl;

		//Saves final stats of current player and past players of the game too a text file
		ofstream myFile;
		myFile.open("results.txt"); // Opens the file
		for (int i = 0; i < playerResualts.size(); i++)
		{
			myFile << playerResualts[i].GetName() << endl;
			myFile << "Miles Travled: " << playerResualts[i].GetMiles() << endl;
			myFile << "Food Remaning: " << playerResualts[i].GetFood() << endl;
			myFile << "Cash Remaning: " << playerResualts[i].GetMoney() << endl;
			myFile << "----" << endl;
		}
	}

	return endGame; //Returns if the game has endded to end the game loop if needed
}

//Algorithm - Prints out the current player stats after a turn is compleated
void PrintOutPlayerStatus(Cart cart, int dateNums[], int distance, Milestones nextM)
{
	cout << endl << "----CURRENT STATUS----" << endl;
	cout << "Current Date : " << dateNums[0] << "-" << dateNums[1] << "-" << dateNums[2] << endl;
	cout << "Miles Travelled : " << distance << endl;
	cout << "Next Landmark : " << nextM.GetDistance() - distance << endl;
	cout << "Food : " << cart.GetFood() << endl;
	cout << "Bullets : " << cart.GetAmmo() << endl;
	cout << "Cash : " << cart.GetMoney() << endl;
}

int main()
{
	//Class in game wide varaibles
	Cart CART;
	Humans HUMANS[5];
	Milestones MILESTONES[12];
	int dateNums[3] = { 1847, 3, 28 };
	int distanceTravled = 0;

	//Input and random number varaibles
	int randomNum;
	string nameInput;
	char charInput;
	bool validInput = false;
	srand(time(0));

	ReadMilestones(MILESTONES); //Reads the mile stones from the two next files and sorts them

	cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847." << endl;
	cout << "YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6 MONTHS --- IF YOU MAKE IT ALIVE." << endl << endl;

	cout << "Before you begin your jorney we would like to document some basic information about you and your family." << endl;
	cout << "If you could be so kind as to please tell us your name." << endl;

	cout << "Name : ";
	cin >> nameInput;
	HUMANS[0].SetName(nameInput);

	cout << endl << "Thank you kindly. Now if we could please tell us the names of your fellow travalers." << endl;

	//Asks for the name of each of the 4 other companions
	for (int i = 1; i < 5; i++)
	{
		cout << i << " : ";
		cin >> nameInput;
		HUMANS[i].SetName(nameInput);
	}

	cout << endl << "You are starting at mile: 0." << endl;
	cout << "There are 2040 that you must travel to reach your destination." << endl;
	cout << "Before the start of your trip, you can visit the store and buy supplies : food, oxen, bullets and wagon parts." << endl;
	CART = MILESTONES[0].PromptUser(0, CART, HUMANS); //Will bring up the starting store and ask the user if they want to visit

	//Asks the player if they are happy with the date or would like to change it
	cout << "Your departure date curently is : 1847-03-28. Would you like to change it?" << endl;
	bool stop = false;
	//While the user has not given a valid input
	while (stop == false)
	{
		cout << "Y / N" << endl;
		cin >> charInput;

		switch (charInput)
		{
		case 'Y':
		case 'y':
			stop = true;
			ChangeDate(dateNums);
			break;
		case 'N':
		case 'n':
			stop = true;
			break;
		default:
			cout << "Please enter a valid input" << endl;
		}
	}	

	//Starts the game and starts the players first turn
	cout << endl << endl << "Let the journey begin!" << endl << endl << endl;

	stop = false;
	//Will keep running untill the game comes too an end
	while (stop == false)
	{
		string input;
		int inputNum;
		cout << endl << dateNums[0] << "-" << dateNums[1] << "-" << dateNums[2] << endl;
		Milestones nextMilestone = FindClosestMilestone(MILESTONES, 12, distanceTravled); //Finds the closet milestone
		Events newEvent(distanceTravled); //Creates an event to be insiated later

		//Prints the next milestone and the users turn options
		cout << "Next milestone is " << nextMilestone.GetName() << " in " << nextMilestone.GetDistance() - distanceTravled << " miles" << endl;
		cout << "1. REST" << endl;
		cout << "2. CONTINUE" << endl;
		cout << "3. HUNT" << endl;
		cout << "4. QUIT" << endl;
		cin >> input;

		//Checks to make sure the string can be converted to an int
		try
		{
			inputNum = stoi(input);
		}
		//Will tell the user to select a valid option this time
		catch (std::exception& e)
		{
			inputNum = 5;
		}

		//Will check what choice the user made
		switch (inputNum)
		{
			case 1: //If the player rests
				randomNum = HUMANS[0].randomNumbers(1, 3); //Ramdonly chooses between 1 and 3 days of resting

				//For each player in the game
				for (int i = 0; i < 5; i++)
				{
					CART.SetFood(CART.GetFood() - HUMANS[i].Rest(randomNum, 3)); //Subtracts food from the players total for each human that is alive
				}
			
				CART.MoveDateForward(dateNums, randomNum); //Moves the date forward by the random number
				cout << "You have chosen to rest for " << randomNum << " days." << endl;

				//Checks if the player has a misfortune and then checks for raiders
				if (newEvent.GetMisfortune() == true)
				{
					CART = newEvent.Misfortune(CART, HUMANS, dateNums);
				}
				if (newEvent.GetAttacked() == true)
				{
					CART = newEvent.Raiders(CART);
				}

				PrintOutPlayerStatus(CART, dateNums, distanceTravled, nextMilestone); //Prints out current Status
				stop = CheckIfThePlayerLostOrWon(CART, HUMANS[0], distanceTravled, dateNums); //Checks to see if the player has lost
				break;
			case 2: //If the player contuines 
				//For each player in the game
				for (int i = 0; i < 5; i++)
				{
					CART.SetFood(CART.GetFood() - HUMANS[i].Rest(14, 3)); //Subtracts food from the players total for each human that is alive
				}

				//If the player has oxen...
				if (CART.GetOxen() != 0)
				{
					//Add to total distance
					distanceTravled += (HUMANS[0].randomNumbers(1, 7)*CART.GetOxen()) + 70;
					//If the player reached oregon
					if (distanceTravled > 2040)
					{
						distanceTravled = 2040;
					}
					else if (distanceTravled >= nextMilestone.GetDistance())
					{
						distanceTravled = nextMilestone.GetDistance();
						CART = nextMilestone.PromptUser(distanceTravled, CART, HUMANS);
						nextMilestone = FindClosestMilestone(MILESTONES, 12, distanceTravled); //Finds the closet milestone
					}
				}

				CART.MoveDateForward(dateNums, 14); //Moves the date forward by 2 weeks
				cout << "You pushed forward for two more weeks" << endl;

				//Checks if the player has a misfortune and then checks for raiders
				if (newEvent.GetMisfortune() == true)
				{
					CART = newEvent.Misfortune(CART, HUMANS, dateNums);
				}
				if (newEvent.GetAttacked() == true)
				{
					CART = newEvent.Raiders(CART);
				}

				PrintOutPlayerStatus(CART, dateNums, distanceTravled, nextMilestone); //Prints out current Status
				stop = CheckIfThePlayerLostOrWon(CART, HUMANS[0], distanceTravled, dateNums); //Checks to see if the player has lost
				break;
			case 3: //If the player hunts
				CART = HUMANS[0].Hunt(CART); //Runs the hunt function in the player class
				cout << "You now have " << CART.GetFood() << " pounds of food" << endl;

				//Asks the user how well they want to eat untill they give a valid answer
				validInput = false;
				//While the player has not gave a valid input
				while (validInput == false)
				{
					cout << endl << "How well would you like to eat?" << endl;
					cout << "1. Poorly" << endl;
					cout << "2. Moderately" << endl;
					cout << "3. Well" << endl;
					cin >> charInput;

					switch (charInput)
					{
					case '1': //If the player wishs to eat poorly
						validInput = true;
						//For each player in the game
						for (int i = 0; i < 5; i++)
						{
							CART.SetFood(CART.GetFood() - HUMANS[i].Rest(1, 2)); //Subtracts food from the players total for each human that is alive
						}
						break;
					case '2': //If the player wishes to eat moderarely
						validInput = true;
						//For each player in the game
						for (int i = 0; i < 5; i++)
						{
							CART.SetFood(CART.GetFood() - HUMANS[i].Rest(1, 3)); //Subtracts food from the players total for each human that is alive
						}
						break;
					case '3': //If the player wishes to eat well
						validInput = true;
						//For each player in the game
						for (int i = 0; i < 5; i++)
						{
							CART.SetFood(CART.GetFood() - HUMANS[i].Rest(1, 5)); //Subtracts food from the players total for each human that is alive
						}
						break;
					default:
						cout << "Please enter a valid input" << endl;
					}
				}

				//Checks if the player is over the max food limit
				if (CART.GetFood() > 1000)
				{
					cout << "Unfortunately your cart could not hold more then 1000 pounds of food so you had to leave some behind." << endl;
					CART.SetFood(1000);
				}

				CART.MoveDateForward(dateNums, 1); //Moves the date forward by 1 day
				cout << "You hunted for one day." << endl;

				//Checks if the player has a misfortune and then checks for raiders
				if (newEvent.GetMisfortune() == true)
				{
					CART = newEvent.Misfortune(CART, HUMANS, dateNums);
				}
				if (newEvent.GetAttacked() == true)
				{
					CART = newEvent.Raiders(CART);
				}

				PrintOutPlayerStatus(CART, dateNums, distanceTravled, nextMilestone); //Prints out current Status
				stop = CheckIfThePlayerLostOrWon(CART, HUMANS[0], distanceTravled, dateNums); //Checks to see if the player has lost
				break;
			case 4: //If the player quits the game
				cout << "Unfortunately you had to end your trip to Oregon, but who knows what the future will hold." << endl;
				stop = true;
				break;

			default:
				cout << "Please enter a valid input" << endl;
				break;
		}
	}
	//cin >> charInput; //Test code
}