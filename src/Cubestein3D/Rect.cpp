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
	this->x2 = x + width;
	this->y2 = y + height;
}


Rect::~Rect()
{
}

bool Rect::Intersects(Rect other)
{
	if (x < other.x2 && x2 > other.x && y < other.y2 && y2 > other.y)
	{
		return true;
	}

	return false;
}