#include "AllPrograms.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void AllPrograms::clearConsole()
{
	for (int i = 3; i >= 0; i--)
	{
		cout << "\rOutput will display for " << i << " second(s)";
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << endl;
	cout << "\033[2J\033[1;1H";
}
