#include "Methods.h"
#include "Function.h"

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

std::pair<double, double> Sven::findInterval(vector2d _point, vector2d direction, double delta)
{
	int k = 1;
	if (Function::calcFunction(_point + direction * delta) >
		Function::calcFunction(_point - direction * delta))
	{
		delta = delta * (-1);
	}
	double lambda{};
	lambda += delta;

	while (Function::calcFunction(_point + lambda * direction) >
		Function::calcFunction(_point + (lambda + pow(2, k) * delta) * direction))
	{
		lambda += pow(2, k) * delta;
		++k;
	}

	lambda += pow(2, k - 1) * delta;
	std::pair<double, double> interval;

	if (Function::calcFunction(_point + lambda * direction) >
		Function::calcFunction(_point + (lambda + pow(2, k - 1) * delta) * direction))
	{
		interval.first = lambda - pow(2, k) * delta;
		interval.second = lambda;
	}
	else
	{
		interval.first = lambda - pow(2, k - 1) * delta;
		interval.second = lambda + pow(2, k - 1) * delta;
	}

	std::cout << "Sven interval: [" << interval.first << " ; " << interval.second << "]" << std::endl;
	return interval;
}


double Dichotomy::findStep(std::pair<double, double> interval, vector2d _point, vector2d direction, double epsilone)
{
	double a = interval.first;
	double b = interval.second;
	double middle = (a + b) / 2;
	while (b - a > epsilone)
	{
		double left = (a + middle) / 2;
		double right = (b + middle) / 2;
		double funcLeft = Function::calcFunction(_point + direction * left);
		double funcMid = Function::calcFunction(_point + direction * middle);
		double funcRight = Function::calcFunction(_point + direction * right);

		if (funcLeft < funcMid)
		{
			b = middle;
			middle = left;
		}
		else if (funcRight < funcMid)
		{
			a = middle;
			middle = right;
		}
		else
		{
			a = left;
			b = right;
		}
	}
	std::cout << "Dichotomy interval: [" << a << " ; " << b << "]" << std::endl;

	return (a + b) / 2;
}

double GoldenRatio::findStep(std::pair<double, double> interval, vector2d _point, vector2d direction, double epsilone)
{
	double left = interval.first;
	double right = interval.second;

	double x1 = left + 0.382 * (right - left);
	double x2 = left + 0.618 * (right - left);
	double f1 = Function::calcFunction(_point + direction * x1);
	double f2 = Function::calcFunction(_point + direction * x2);

	do
	{
		if (f1 <= f2)
		{
			right = x2;
			x2 = x1;
			f2 = f1;
			x1 = left + 0.382 * (right - left);
			f1 = Function::calcFunction(_point + direction * x1);
		}
		else
		{
			left = x1;
			x1 = x2;
			f1 = f2;
			x2 = left + 0.618 * (right - left);
			f2 = Function::calcFunction(_point + direction * x2);
		}
	} while ((right - left) > epsilone);

	std::cout << "Golden Ratio interval: [" << left << " ; " << right << "]" << std::endl;

	return (right + left) / 2;
}

double DSK::findStep(std::pair<double, double> interval, vector2d _point, vector2d direction, double epsilone)
{
	double left = interval.first;
	double right = interval.second;
	double middle = (left + right) / 2;

	double f1 = Function::calcFunction(_point + direction * left);
	double f2 = Function::calcFunction(_point + direction * middle);
	double f3 = Function::calcFunction(_point + direction * right);

	double X = middle + (middle - left) * (f1 - f3) / (2 * (f1 - 2 * f2 + f3));
	double F = Function::calcFunction(_point + direction * X);

	while ((abs(middle - X) > epsilone) && (abs(f2 - F) > epsilone)) {
		right = middle;
		f3 = f2;
		middle = X;
		f2 = F;
		double a1 = (f2 - f1) / (middle - left);
		double a2 = ((f3 - f1) / (right - left) - a1) / (right - middle);
		X = (left + middle) / 2 - a1 / (2 * a2);
	}

	std::cout << "DSK  interval: [" << left << " ; " << right << "]" << std::endl;

	return X;
}
