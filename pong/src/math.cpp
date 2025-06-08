#include "math.h"

/* == Vector == */
Vector::Vector()
{
	x = 0;
	y = 0;
}

Vector::Vector(float x_, float y_)
{
	x = x_;
	y = y_;
}

Vector Vector::operator+(const Vector& vec) const
{
	return Vector{ x + vec.x, y + vec.y };
}

Vector Vector::operator-(const Vector& vec) const
{
	return Vector{ x - vec.x, y - vec.y };
}


Vector Vector::operator*(const Vector& vec) const
{
	return Vector{ x * vec.x, y * vec.y };
}

Vector Vector::operator/(const Vector& vec) const
{
	return Vector{ x / vec.x, y / vec.y };
}
/* == End Vector == */
