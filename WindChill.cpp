#include <iostream>
#include <cmath>
#include "WindChill.h"
using namespace std;

void WindChill::DisplayWindChill()
{
	system("cls");
	DisplayGetTemperature();
	for (int i = 1; i <= 10; ++i)
	{
		const double wind = i * 5;
		cout << "At " << getTemperature() << " degrees Fahrenheit and a windspeed of " << wind
			<< " mph, the windchill is " << CalculateChill(getTemperature(), wind) << " degrees." << endl;
	}
	clearConsole();
}

double WindChill::CalculateChill(double _temperature, double _wind) const
{
	return round(
		35.74 + 0.6215 * (_temperature) - 35.75 * (pow(_wind, 0.16)) + 0.4275 * (_temperature) * (
			pow(_wind, 0.16)) * 100) / 100;
}

double WindChill::getTemperature() const
{
	return temperature;
}

void WindChill::DisplayGetTemperature()
{
	cout << "What is the temperature in Fahrenheit? ";
	cin >> temperature;
}
