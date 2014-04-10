#ifndef __VECTOR_H__
#define __VECTOR_H__

// Based on the Vector class from Graflix, with a few changed/added operations when needed.
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

	// Based on 2D vector rotation from http://www.pontov.com.br/site/arquitetura/54-matematica-e-fisica/132-o-uso-de-vetores-nos-jogos
	Vector rotateY(float angle);

	Vector operator +(const Vector& v) const;
	
	bool operator ==(const Vector& v) const;

	Vector& operator =(const Vector& v);

	Vector& operator +=(const Vector& v);

	Vector operator *(float e) const;

	// Made by myself
	Vector operator /(float e) const;

	Vector& operator *=(float e);

	Vector operator -(const Vector& v) const;

	Vector& operator -=(const Vector& v);

	// Distance and DistanceSquared implemented by me.
	float Distance(Vector other);
	float DistanceSquared(Vector other);

	// Angle implemented by me
	float Angle();
};

#endif
