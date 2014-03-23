#include "Vector3.h"


Vector3::Vector3()
{
}


Vector3::~Vector3()
{
}

float Vector3::GetX()
{
	return x;
}

float Vector3::GetY()
{
	return y;
}

float Vector3::GetZ()
{
	return z;
}

void Vector3::Translate(float x, float y, float z)
{
	this->x += x;
	this->y += y;
	this->z += z;
}