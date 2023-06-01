#ifndef TIREVOLUME_H
#define TIREVOLUME_H

#include "AllPrograms.h"

class TireVolume : public AllPrograms
{
private:
	int width, a_ratio, diameter;

public:
	TireVolume();
	double volume(int _width, int _a_ratio, int _diameter) const;
	void DisplayVolume() const;
	int getWidth() const;
	int getRatio() const;
	int getDiameter() const;
	void DisplayGetVolume();
};

#endif
