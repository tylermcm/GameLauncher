#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include <vector>
#include "AllPrograms.h"

class TicTacToe : public AllPrograms
{
private:
	std::vector<char> boardArray;
	int choice = 0;
	int player = 1;
	bool win = false;
	std::string playAgain;
	void DisplayGameBoard() const;
	bool CheckGameStatus() const;

public:
	void PlayGame();
};

#endif
