#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#include <GLFW/glfw3.h>

#include "object.h"

using namespace std;

const int OBJECT_COUNT = 3;
Object* object_array[OBJECT_COUNT];
int object_index = 0;

Object::Object()
{
	Object* obj = object_array[object_index];

	if (object_index > 3)
	{
		cout << "INVALID OBJECT CREATION EXITING APPLICATION" << endl;
		exit(1);
	}

	if (obj)
	{
		cout << "OBJECT ALREADY IN ARRAY EXITING" << endl;
		exit(1);
	}

	object_array[object_index++] = this;

	cout << "CREATED OBJECT" << endl;
}

/* == Rectangle == */
Rect::Rect(Vector rect, Vector pos_)
{
	float half_width = rect.x / 2.0f;
	float half_height = rect.y / 2.0f;

	top_left = { pos_.x - half_width, pos_.y + half_height };
	top_right = { pos_.x + half_width, pos_.y + half_height };

	bottom_left = { pos_.x - half_width, pos_.y - half_height };
	bottom_right = { pos_.x + half_width, pos_.y - half_height };

	pos = pos_;
}

void Rect::draw() const
{
	glBegin(GL_QUADS);
	glVertex2f(top_left.x, top_left.y);
	glVertex2f(top_right.x, top_right.y);
	glVertex2f(bottom_right.x, bottom_right.y);
	glVertex2f(bottom_left.x, bottom_left.y);
	glEnd();
}
/* == End Rectangle == */

/* == Circle ==*/
Circle::Circle(Vector pos_)
{
	radius = 2;
	pos = pos_;
}

Circle::Circle(float radius_, Vector pos_)
{
	radius = radius_;
	pos = pos_;
}

void Circle::draw() const
{
	const float segments = 128.f;  // Higher = smoother circle

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(pos.x, pos.y); // center of the circle

	for (int i = 0; i < segments; ++i) {
		float angle = (2.0f * M_PI * i) / segments;
		float x = pos.x + cosf(angle) * radius;
		float y = pos.y + sinf(angle) * radius;
		glVertex2f(x, y);
	}
}
/* == End circle == */
