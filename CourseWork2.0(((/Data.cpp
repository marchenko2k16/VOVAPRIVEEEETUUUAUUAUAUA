#include "Data.h"



Data::Data()
{
	points.push_back(vector2d(-1.2, 0));
}

void Data::calcDelta(vector2d direction, double step)
{
	delta.push_back(step * points.at(delta.size()).magnitude() /
		direction.magnitude());
}
