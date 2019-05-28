#include "Function.h"
#include <cmath>

std::vector<std::pair<vector2d, double>> Function::functionValues;

unsigned int functionCallCounts;

double Function::calcFunction(vector2d point)
{
	for (auto e : functionValues)
	{
		if (point == e.first)
		{
			return e.second;
		}
	}
	
	double functionValue = pow(1 - point.x,2) + 100*pow(point.y - pow(point.x,2),2);

	++functionCallCounts;
	functionValues.push_back(std::make_pair(point, functionValue));
	return functionValue;
}


double Function::calcFunction(double x1, double x2)
{
	return Function::calcFunction(vector2d(x1, x2));
}
