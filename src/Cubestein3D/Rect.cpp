#include "Rect.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Rect::Rect(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}


Rect::~Rect()
{
}

bool Rect::Intersects(Rect other)
{
	if (x >= (other.x + other.width) || (x + width) <= other.x || y <= (other.y + other.height) || (y + height) >= other.y)
	{
		return false;
	}

	return true;
}