#pragma once
#include "math.h"

struct Object {
	Object();
	void Draw();
};

/* == Square == */
struct Square : Object {
	Vector top_left;
	Vector top_right;

	Vector bottom_left;
	Vector bottom_right;

	Square();
	Square(float perimeter, Vector pos);
};
/* == End Square == */

