#ifndef MONTYHALL_H
#define MONTYHALL_H

#include <random>
#include "AllPrograms.h"

class MontyHall : public AllPrograms
{
private:
	int wins = 0;
	int losses = 0;
	int iterations = 0;
	int choice = 0;
	int keepDoor = 0;
	int leftDoor = 0;
	int rightDoor = 0;
	bool output = false;
	std::random_device rd;
	std::mt19937 gen;
	std::string playAgain;
	bool win = false;

public:
	MontyHall();
	void PlayMontyHall();
	bool CheckWin(int pickedDoor, int changeDoor, int winningDoor, int doorToRemove);
	void DisplayGetIterations();
};

#endif
