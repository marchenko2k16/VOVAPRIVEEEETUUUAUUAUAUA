#include "Gradient.h"
#include "Function.h"

#include <iostream>

double Gradient::gradientStep;


double Gradient::calcGrad(vector2d p)
{
	vector2d gradientVector
	(
		(Function::calcFunction(p.x + gradientStep, p.y) -
			Function::calcFunction(p.x - gradientStep, p.y)) /
				(2 * gradientStep),

		(Function::calcFunction(p.x, p.y + gradientStep) -
			Function::calcFunction(p.x, p.y - gradientStep)) /
				(2 * gradientStep)
	);

	double debugGrad = gradientVector.magnitude();
	return debugGrad;
}
