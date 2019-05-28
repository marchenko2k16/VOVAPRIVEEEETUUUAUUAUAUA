#pragma once
#include <utility>
#include "vector2d.h"


namespace Sven
{
	std::pair<double, double> findInterval(vector2d _point, vector2d direction, double delta);
}

namespace GoldenRatio
{
	double findStep(std::pair<double, double> interval, vector2d _point, vector2d direction, double epsilone);
}

namespace Dichotomy
{
	double findStep(std::pair<double, double> interval, vector2d _point, vector2d direction, double epsilone);
}


namespace DSK
{
	double findStep(std::pair<double, double> interval, vector2d _point, vector2d direction, double epsilone);
}
