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

// Made by myself
Vector Vector::operator /(float e) const {
	return Vector(x/e, y/e, z/e);
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

// Based on 2D vector rotation from http://www.pontov.com.br/site/arquitetura/54-matematica-e-fisica/132-o-uso-de-vetores-nos-jogos
Vector Vector::rotateY(float angle)
{
	float s = sin(angle);
	float c = cos(angle);

	float newX = x * c - z * s;
	float newZ = x * s + z * c;

	x = newX;
	z = newZ;

	return *this;
}

float Vector::Distance(Vector other)
{
	return sqrtf(DistanceSquared(other));
}

float Vector::DistanceSquared(Vector other)
{
	return ((x - other.x) * (x - other.x)) + ((y - other.y) * (y - other.y)) + ((z - other.z) * (z - other.z));
}

float Vector::Angle()
{
	return atan2(x, z) * (180.0 / 3.14159);
}