#include <iostream>
#include "TicTacToe.h"
using namespace std;

void TicTacToe::PlayGame()
{
	do
	{
		boardArray = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
		do
		{
			system("cls");
			DisplayGameBoard();
			cin >> choice;

			if (choice >= 1 && choice <= 9)
			{
				if (boardArray[choice] != 'X' && boardArray[choice] != 'O')
				{
					if (player % 2 == 0)
					{
						boardArray[choice] = 'O';
						player++;
					}
					else
					{
						boardArray[choice] = 'X';
						player++;
					}
				}
			}
			win = CheckGameStatus();
		}
		while (!win);
		system("cls");
		DisplayGameBoard();

		if (win)
		{
			cout << "Player " << ((player % 2) + 1) << " has won" << endl;
		}
		else
		{
			cout << "You tied." << endl;
		}
		cout << "Would you like to play again?(y/n) ";
		cin >> playAgain;
	}
	while (playAgain == "y");
	clearConsole();
}

void TicTacToe::DisplayGameBoard() const
{
	cout << "     |     |      " << endl;
	cout << "  " << boardArray[1] << "  |  " << boardArray[2] << "  |  " << boardArray[3] << endl;
	cout << "_____|_____|_____ " << endl;
	cout << "     |     |      " << endl;
	cout << "  " << boardArray[4] << "  |  " << boardArray[5] << "  |  " << boardArray[6] << endl;
	cout << "_____|_____|_____ " << endl;
	cout << "     |     |      " << endl;
	cout << "  " << boardArray[7] << "  |  " << boardArray[8] << "  |  " << boardArray[9] << endl;
	cout << "     |     |      " << endl;
}

bool TicTacToe::CheckGameStatus() const
{
	if (boardArray[1] == boardArray[2] && boardArray[2] == boardArray[3] ||
		boardArray[4] == boardArray[5] && boardArray[5] == boardArray[6] ||
		boardArray[6] == boardArray[7] && boardArray[7] == boardArray[8] ||
		boardArray[1] == boardArray[4] && boardArray[4] == boardArray[7] ||
		boardArray[2] == boardArray[5] && boardArray[5] == boardArray[8] ||
		boardArray[3] == boardArray[6] && boardArray[6] == boardArray[9] ||
		boardArray[1] == boardArray[5] && boardArray[5] == boardArray[9] ||
		boardArray[3] == boardArray[5] && boardArray[5] == boardArray[7])
	{
		return true;
	}
	for (int i = 1; i <= 9; ++i)
	{
		if (boardArray[i] == '0' + i)
		{
			return false;
		}
	}
	return true;
}
