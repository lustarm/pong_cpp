#pragma once

#include <vector>

#include "math.h"

const int OBJECT_COUNT = 3;

Object* object_array[OBJECT_COUNT];

int object_index = 0;

struct Object {
	Vector pos;

	Object();

	void draw();
};

/* == Square == */
struct Square : Object {
	Vector top_left;
	Vector top_right;

	Vector bottom_left;
	Vector bottom_right;

	Square(Vector pos);
	Square(float perimeter, Vector pos);
};
/* == End Square == */

/* == Circle == */
struct Circle : Object {
	float radius;

	Circle(Vector pos);
	Circle(float radius, Vector pos);
};
/* == End Circle */
