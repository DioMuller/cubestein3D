#include "Vector.h"
#include <math.h>

Vector::Vector() : x(0), y(0), z(0) {}
Vector::Vector(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

float Vector::magnitude2() {
	return x*x + y*y + z*z;
}

float Vector::magnitude() {

	return sqrt(magnitude2());
}

void Vector::normalize() {

	x /= magnitude();
	y /= magnitude();
	z /= magnitude();

}


float Vector::dot(Vector &v) {

	return x * v.x + y * v.y + z * v.z;
}

Vector Vector::operator +(const Vector& v) const {
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector& Vector::operator +=(const Vector& v) {
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

Vector Vector::operator -(const Vector& v) const {
	return Vector(x - v.x, y - v.y, z - v.z);
}

Vector& Vector::operator -=(const Vector& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}

Vector Vector::operator *(float e) const {
	return Vector(x*e, y*e, z*e);
}

Vector& Vector::operator *=(float e) {

	x *= e;
	y *= e;
	z *= e;

	return *this;
}

Vector& Vector::operator =(const Vector& v) {

	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

bool Vector::operator ==(const Vector& v) const {

	if (fabs(x - v.x) <= 0.1 &&
		fabs(y - v.y) <= 0.1 &&
		fabs(z - v.z) <= 0.1)
		return true;

	return false;
}
