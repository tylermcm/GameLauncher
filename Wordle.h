#ifndef WORDLE_H
#define WORDLE_H

#include <string>
#include <vector>
#include "AllPrograms.h"

class Wordle : public AllPrograms
{
private:
	int score, attempt, index, randIndex;
	bool correct, correctLength;
	std::string secretWord, hint, guess, playAgain;
	std::vector<std::string> words;

public:
	Wordle();
	void PlayWordle();
	void GiveHint();
};

#endif
