#include "Data.h"
#include "Gradient.h"
#include "Function.h"
#include "Methods.h"

#include <iostream>

vector2d directionS1(0, 1);
vector2d directionS2(1, 0);

double gradientError = 0.01; 
double gradientStep = 0.0001;
double deltaStep = 0.1;

int main()
{
	Data data = Data();
	Gradient::gradientStep = gradientStep;

	size_t gradCalc{};
	
	while (Gradient::calcGrad(data.points.back()) >= gradientError)
	{
		for (auto i = 0; i < 4; ++i)
		{
			std::cout << "Gradient : " << Gradient::calcGrad(data.points.back()) << std::endl;
			vector2d direction;

			switch (i)
			{
			case 0:
				direction = directionS2;
				break;
			case 1:
				direction = directionS1;
				break;
			case 2:
				direction = directionS2;
				break;
			case 3:
				direction = (data.points.back() - data.points.at(data.points.size() - 3));
				directionS1 = directionS2;
				directionS2 = direction;
				break;
			}


			if (Gradient::calcGrad(data.points.back()) < gradientError)
			{
				break;
			}
			data.calcDelta(direction, deltaStep);

			std::pair<double, double> interval =
				Sven::findInterval(data.points.back(), direction, data.delta.back());

			data.lambda.push_back
			(
				GoldenRatio::findStep(interval, data.points.back(), direction, data.epsilone)
			);
			data.points.push_back(data.points.back() + data.lambda.back() * direction);


			{
				std::cout << "Lambda"	<< data.lambda.size() << " is " << data.lambda.back()	<< std::endl;
				std::cout << "X"		<< data.points.size() << " is " << data.points.back()	<< std::endl;
				std::cout << "f(x) = "	<< Function::calcFunction(data.points.back())			<< std::endl;
				std::cout << std::endl;
				++gradCalc;
			}

		}
	}

	std::cout << std::endl;
	std::cout << "FUNCTION CALLS    " << functionCallCounts <<  std::endl;
	std::cout << "GRAD COMPARISON   " << gradCalc << std::endl;
}