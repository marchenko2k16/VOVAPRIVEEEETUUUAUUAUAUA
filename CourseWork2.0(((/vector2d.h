#pragma once
#include <iosfwd>

class vector2d
{
public:
	double x;
	double y;
	vector2d operator* (double coef);
	vector2d operator+ (vector2d v2);
	vector2d operator- (vector2d v2);
	vector2d operator* (vector2d v2);
	vector2d operator/ (vector2d v2);
	vector2d operator/ (double devideBy);
	bool operator< (vector2d v2);
	double magnitude() const;

	double distance(const vector2d& vec2d) const;
	vector2d normalizedVec();
	void makeNormalized();

	vector2d();
	vector2d(double _x, double _y);

	bool operator== (const vector2d v2) const;

	friend bool operator<(const vector2d& v1, const vector2d& v2);
	friend vector2d operator*(const double coef, vector2d& v);
	friend std::ostream& operator<<(std::ostream& os, const vector2d& v);
};
