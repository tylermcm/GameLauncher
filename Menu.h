#pragma once
#include <string>
#include <vector>

class Menu
{
private:
	std::vector<std::string> mainMenu;
	std::vector<std::string> gamesMenu;
	std::vector<std::string> calculatorsMenu;

public:
	Menu();
	int DisplayMainMenu() const;
	int DisplayGamesMenu() const;
	int DisplayCalculatorMenu() const;
};
