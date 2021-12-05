
#include "pch.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

string randSuit();
int calcServerH();

int main()
{
	srand(time(NULL));
	//Variables
	char yesNo;
	int playerHand = 0;
	int playerHandA[3];
	int serverHandA[3];
	int serverHand;
	char drawCh;
	char playAgain;

	//Introduction Message
	cout << "Hello, would you like to play the 21 card game?" << endl;
	cout << "Y/N ";
	cin >> yesNo;
	if (yesNo == 'N' || yesNo == 'n')
	{
		return 0;
	}
	else 
	{
		cout << "Your first 2 cards have the values of... " << endl << endl;

		for (int i = 1; i < 3; i++) //Assign Numerical Value to each card
		{
			int randomN = (rand() % 11) + 1;
			cout << "Card #" << i << " is " << randomN << " of " << randSuit() << endl;
			playerHandA[i - 1] = randomN;
		}
		for (int j = 1; j < 3; j++)
		{
			playerHand += playerHandA[j - 1];
		}
		cout << "Your total amount is " << playerHand << " would you like to hit or sit?" << endl;
		cout << "Type 'H' to hit and 'S' to sit." << endl;
		cin >> drawCh;
		if (drawCh == 'H' || drawCh == 'h')
		{
			playerHand += ((rand() % 11) + 1);

		}
		cout << "Your new amount is " << playerHand << endl;
		if (playerHand > 21) 
		{
			cout << "Your amount is greater than 21 so you lose, sorry! " << endl;
		}
		else 
		{
			cout << "The server's total amount is " << calcServerH() << endl;
			if (playerHand > calcServerH())
			{
				cout << "Your amount is greater than the server's which means you win, congratulations!" << endl;
			}
			else
			{
				cout << "Your amount is equal or smaller than the server's which means you lose, sorry!" << endl;
			}
		}
		
	}

	return 0;
}

string randSuit() // Assigns suit types to each card
{
	string randSuitName;
	int randN2 = rand() % 3;

	switch (randN2)
	{
	case 0:
		randSuitName = "Hearts";
		break;
	case 1:
		randSuitName = "Diamonds";
		break;
	case 2:
		randSuitName = "Spades";
		break;
	case 3:
		randSuitName = "Clovers";
		break;
	default:
		cout << "ERROR" << endl;
	}
	return randSuitName;
}
int calcServerH() 
{
	int serverHandA[4];
	int serverHand = 0;
	for (int i = 1; i < 3; i++) //Assign Numerical Value to each card
	{
		int randomN = (rand() % 11) + 1;
		serverHandA[i - 1] = randomN;
	}
	for (int j = 1; j < 4; j++)
	{
		while (serverHand < 16) 
		{
			serverHand += serverHandA[j - 1];
		}
	}
	return serverHand;



}
