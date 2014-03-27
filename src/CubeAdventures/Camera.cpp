#include "Camera.h"

/* REMOVE AFTER */
//
//Função crossProduct
//Objetivo: calcula o produto vetorial
//
void crossProduct(float &x1, float &y1, float &z1, float x2, float y2, float z2)
{
	float x = x1, y = y1, z = z1;

	x1 = ((y * z2) - (z * y2));
	y1 = ((z * x2) - (x * z2));
	z1 = ((x * y2) - (y * x2));
}

//
//Função sizeVector
//Objetivo: calcula o tamanho (magnitude) do vetor
//
float sizeVector(float x, float y, float z)
{
	return (float)sqrt((x * x) + (y * y) + (z * z));
}

//
//Função normalizeVector
//Objetivo: torna o vetor unitário
//
void normalizeVector(float &x, float &y, float &z)
{
	//Calcula tamanho do vetor
	float size = sizeVector(x, y, z);

	//Normaliza vetor
	x /= size;
	y /= size;
	z /= size;
}


Camera::Camera()
{
	eye = Vector(0.0f, 1.5f, -15.0f);
	target = Vector(0.0f, 1.5f, 0.0f);
	up = Vector(0.0f, 1.0f, 0.0f);
}


Camera::~Camera()
{
}

void Camera::Update(long delta)
{
	eye.x += 0.01;
	eye.y += 0.01;
}

void Camera::Render(long delta, Renderer* renderer)
{
	renderer->CameraLookAt(eye, target, up);
}

void Camera::MoveCamera(float x, float y, float z)
{
	eye = Vector(x, y, z);
}

void Camera::TranslateCamera(float x, float y, float z)
{
	eye = eye + Vector(x, y, z);
}

void Camera::RotateCamera(float angle, float x, float y, float z)
{
	float nx = target.x - eye.x,
		ny = target.y - eye.y,
		nz = target.z - eye.z;

	float tx = nx,
		ty = ny,
		tz = nz;

	float cosang = (float)cos(angle);
	float sinang = (float)sin(angle);

	nx = (cosang + (1 - cosang) * x * x)       * tx;
	nx += ((1 - cosang) * x * y - z * sinang)   * ty;
	nx += ((1 - cosang) * x * z + y * sinang)   * tz;

	ny = ((1 - cosang) * x * y + z * sinang)   * tx;
	ny += (cosang + (1 - cosang) * y * y)       * ty;
	ny += ((1 - cosang) * y * z - x * sinang)   * tz;

	nz = ((1 - cosang) * x * z - y * sinang)   * tx;
	nz += ((1 - cosang) * y * z + x * sinang)   * ty;
	nz += (cosang + (1 - cosang) * z * z)       * tz;


	target.x = eye.x + nx;
	target.y = eye.y + ny;
	target.z = eye.z + nz;
}