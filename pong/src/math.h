#pragma once

/* == Vector == */
struct Vector {
	float x;
	float y;

	Vector();
	Vector(float x_, float y_);

	Vector operator+(const Vector& vec) const;
	Vector operator-(const Vector& vec) const;
	Vector operator*(const Vector& vec) const;
	Vector operator/(const Vector& vec) const;
};
/* == End Vector == */
