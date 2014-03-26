#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector {

public:
	float x;
	float y;
	float z;

	Vector();
	Vector(float _x, float _y, float _z);

	float magnitude();

	float magnitude2();

	void normalize();

	float dot(Vector &v);

	Vector operator +(const Vector& v) const;
	
	bool operator ==(const Vector& v) const;

	Vector& operator =(const Vector& v);

	Vector& operator +=(const Vector& v);

	Vector operator *(float e) const;

	Vector& operator *=(float e);

	Vector operator -(const Vector& v) const;

	Vector& operator -=(const Vector& v);


};

#endif
