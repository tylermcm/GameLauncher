#include <iostream>
#include "MontyHall.h"
using namespace std;

MontyHall::MontyHall() : gen(rd())
{
}

void MontyHall::PlayMontyHall()
{
	system("cls");
	do
	{
		wins = 0;
		losses = 0;
		DisplayGetIterations();
		cout <<
			"\nEnter 1 to ALWAYS change doors\nEnter 2 to NEVER change\nEnter 3 RANDOMLY choose at each iteration\n\nChoice: ";
		cin >> choice;
		uniform_int_distribution<> dis(0, 2);
		switch (choice)
		{
		case 1:
			for (int i = 0; i < iterations; i++)
			{
				output = CheckWin(dis(gen), 1, dis(gen), 0);
				output == true ? wins++ : losses++;
			}
			break;
		case 2:
			for (int i = 0; i < iterations; i++)
			{
				output = CheckWin(dis(gen), 0, dis(gen), 0);
				output == true ? wins++ : losses++;
			}
			break;
		case 3:
			uniform_int_distribution<> change(0, 1);
			for (int i = 0; i < iterations; i++)
			{
				output = CheckWin(dis(gen), change(gen), dis(gen), 0);
				output == true ? wins++ : losses++;
			}
			break;
		}
		cout << "After " << iterations << " iterations, you won " << wins << " times, and lost " << losses <<
			" times!\n";
		cout << "Would you like to play again? (y/n): ";
		cin >> playAgain;
		cout << "\n";
	}
	while (playAgain == "y");
	clearConsole();
}

bool MontyHall::CheckWin(int pickedDoor, int changeDoor, int winningDoor, int doorToRemove)
{
	switch (pickedDoor)
	{
	case 0:
		leftDoor = 1;
		rightDoor = 2;
		break;
	case 1:
		leftDoor = 0;
		rightDoor = 2;
		break;
	case 2:
		leftDoor = 0;
		rightDoor = 1;
		break;
	}

	keepDoor = doorToRemove == 0 ? rightDoor : leftDoor;

	if (changeDoor == 0)
	{
		win = winningDoor == pickedDoor;
	}
	else
	{
		win = winningDoor != pickedDoor;
	}

	return win;
}

void MontyHall::DisplayGetIterations()
{
	cout << "How many iterations would you like to run? ";
	cin >> iterations;
}
