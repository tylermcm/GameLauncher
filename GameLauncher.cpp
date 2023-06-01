#include <iostream>
#include "Menu.h"
#include "MontyHall.h"
#include "TicTacToe.h"
#include "Wordle.h"
#include "LoanAmortization.h"
#include "TireVolume.h"
#include "WindChill.h"
using namespace std;

int main()
{
	int choice = 0;
	do
	{
		Menu menu;
		choice = menu.DisplayMainMenu();
		switch (choice)
		{
		case 1:
			{
				int gameSelection = menu.DisplayGamesMenu();
				switch (gameSelection)
				{
				case 1:
					{
						MontyHall mh;
						mh.PlayMontyHall();
						break;
					}
				case 2:
					{
						TicTacToe tic;
						tic.PlayGame();
						break;
					}
				case 3:
					{
						Wordle wordle;
						wordle.PlayWordle();
						break;
					}
				case 4:
					break;
				default:
					cout << "Invalid selection. Please try again." << endl;
					break;
				}
				break;
			}
		case 2:
			{
				int calcSelection = menu.DisplayCalculatorMenu();
				switch (calcSelection)
				{
				case 1:
					{
						LoanAmortization loan;
						loan.DisplayTable();
						break;
					}
				case 2:
					{
						TireVolume volume;
						volume.DisplayVolume();
						break;
					}
				case 3:
					{
						WindChill chill;
						chill.DisplayWindChill();
						break;
					}
				case 4:
					break;
				default:
					cout << "Invalid selection. Please try again." << endl;
					break;
				}
				break;
			}
		case 3:
			cout << "Goodbye!" << endl;
			break;
		default:
			break;
		}
	}
	while (choice != 3);

	return 0;
}
