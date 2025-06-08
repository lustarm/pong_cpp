#include <iostream>

#include "object.h"

using namespace std;

Object::Object()
{
	all_objects.push_back(this);
}

void Object::draw()
{

}

/* == Square == */
Square::Square(Vector pos_)
{
	float side = 4 / 4.0f;
	float h = side / 2.0f;

	top_left = { pos.x - h, pos.y + h };
	top_right = { pos.x + h, pos.y + h };
	bottom_left = { pos.x - h, pos.y - h };
	bottom_right = { pos.x + h, pos.y - h };

	pos = pos_;
}

Square::Square(float perimeter, Vector pos_)
{
	float side = perimeter / 4.0f;
	float h = side / 2.0f;

	top_left = { pos_.x - h, pos_.y + h };
	top_right = { pos_.x + h, pos_.y + h };
	bottom_left = { pos_.x - h, pos_.y - h };
	bottom_right = { pos_.x + h, pos_.y - h };

	pos = pos_;
}
/* == End Square == */

/* == Circle ==*/
Circle::Circle(Vector pos_)
{
	radius = 4;
	pos = pos_;
}

Circle::Circle(float radius_, Vector pos_)
{
	radius = radius_;
	pos = pos_;
}
/* == End circle == */
