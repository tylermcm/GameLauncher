#ifndef WINDCHILL_H
#define WINDCHILL_H

#include "AllPrograms.h"

class WindChill : public AllPrograms
{
private:
	double temperature = 0;
	double CalculateChill(double _temperature, double _wind) const;
	double getTemperature() const;
	void DisplayGetTemperature();

public:
	void DisplayWindChill();
};

#endif
