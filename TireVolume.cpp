#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "TireVolume.h"
using namespace std;

TireVolume::TireVolume()
{
	DisplayGetVolume();
}

double TireVolume::volume(int _width, int _a_ratio, int _diameter) const
{
	return round(
		(M_PI * (pow(width, 2) * a_ratio * (width * a_ratio + 2540 * diameter)) / 10000000000.0) * 100) / 100;
}

void TireVolume::DisplayVolume() const
{
	cout << "The approximate volume is " << volume(getWidth(), getRatio(), getDiameter()) << " liters" <<
		endl;
	clearConsole();
}

int TireVolume::getWidth() const
{
	return width;
}

int TireVolume::getRatio() const
{
	return a_ratio;
}

int TireVolume::getDiameter() const
{
	return diameter;
}

void TireVolume::DisplayGetVolume()
{
	system("cls");
	cout << "Enter the width of the tire in mm (ex. 205): ";
	cin >> width;
	cout << "Enter the aspect ratio of the tire (ex. 60): ";
	cin >> a_ratio;
	cout << "Enter the diameter of the wheel (ex. 15): ";
	cin >> diameter;
}
