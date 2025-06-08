#include <iostream>

#include "object.h"

using namespace std;

Object::Object()
{

}

void Object::Draw()
{
	cout << "Drawing" << endl;
}

/* == Square == */
Square::Square()
{
	top_left     = Vector();
	top_right    = Vector();
	bottom_left  = Vector();
	bottom_right = Vector();
}

Square::Square(float perimeter, Vector pos)
{
	// one side
	float side = perimeter / 4.0f;

	// center?
	float h = side / 2.0f;

	top_left = { pos.x - h, pos.y + h };
	top_right = { pos.x + h, pos.y + h };
	bottom_left = { pos.x - h, pos.y - h };
	bottom_right = { pos.x + h, pos.y - h };
}
/* == End Square == */


