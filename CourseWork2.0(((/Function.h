#pragma once

#include "vector2d.h"
#include <vector>
extern unsigned int functionCallCounts;

class Function
{
private:
	static std::vector<std::pair<vector2d, double>> functionValues;
public:

	static double calcFunction(vector2d);
	static double calcFunction(double, double);
};

