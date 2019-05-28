#pragma once

#include <vector>
#include "vector2d.h"

class Data
{
public:
	double epsilone{ 0.01 };
	std::vector<vector2d> points;
	std::vector<double> lambda;
	std::vector<double> delta;
	Data();
	void calcDelta(vector2d, double);
};

