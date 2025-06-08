#pragma once

#include <vector>

#include "math.h"

struct Object {
	Vector pos;
	Object();
	virtual void draw() const = 0;
};

extern const int OBJECT_COUNT;
extern Object* object_array[];
extern int object_index;

/* == Rectangle == */
struct Rect : Object {
	Vector top_left;
	Vector top_right;

	Vector bottom_left;
	Vector bottom_right;

	Rect(Vector rect, Vector pos);

	void draw() const;
};
/* == End Rectangle == */

/* == Circle == */
struct Circle : Object {
	float radius;

	Circle(Vector pos);
	Circle(float radius, Vector pos);

	void draw() const;
};
/* == End Circle */
