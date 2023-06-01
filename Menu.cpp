#include <iostream>
#include "Menu.h"
using namespace std;


Menu::Menu()
{
	mainMenu = {
		"Program categories:",
		"1. Games",
		"2. Calculators",
		"3. Quit"
	};
	gamesMenu = {
		"Available programs:",
		"1. Monty Hall Problem",
		"2. Tic Tac Toe",
		"3. Wordle",
		"4. Quit"
	};
	calculatorsMenu = {
		"Available programs:",
		"1. Loan Amortization Generator",
		"2. Tire Volume",
		"3. Wind Chill",
		"4. Quit"
	};
}

int Menu::DisplayMainMenu() const
{
    for (const string& menuItem : mainMenu)
    {
        cout << menuItem << endl;
    }
    string input;
    int choice;
    while (true)
    {
        cout << "What type of program would you like to launch?: ";
        cin >> input;

        if (input.find('.') != string::npos)
        {
            cout << "Invalid input. Please enter an integer." << endl;
            continue;
        }

        try
        {
            choice = stoi(input);
            break;
        }
        catch (const exception&)
        {
            cout << "Invalid input. Please enter an integer." << endl;
        }
    }
    return choice;
}


int Menu::DisplayGamesMenu() const
{
    for (const string& menuItem : gamesMenu)
    {
        cout << menuItem << endl;
    }
    string input;
    int choice;
    while (true)
    {
        cout << "What program would you like to run?: ";
        cin >> input;

        if (input.find('.') != string::npos)
        {
            cout << "Invalid input. Please enter an integer." << endl;
            continue;
        }

        try
        {
            choice = stoi(input);
            break;
        }
        catch (const exception&)
        {
            cout << "Invalid input. Please enter an integer." << endl;
        }
    }
    return choice;
}

int Menu::DisplayCalculatorMenu() const
{
    for (const string& menuItem : calculatorsMenu)
    {
        cout << menuItem << endl;
    }
    string input;
    int choice;
    while (true)
    {
        cout << "What program would you like to run?: ";
        cin >> input;

        if (input.find('.') != string::npos)
        {
            cout << "Invalid input. Please enter an integer. " << endl;
            continue;
        }

        try
        {
            choice = stoi(input);
            break;
        }
        catch (const exception&)
        {
            cout << "Invalid input. Please enter an integer. " << endl;
        }
    }
    return choice;
}
