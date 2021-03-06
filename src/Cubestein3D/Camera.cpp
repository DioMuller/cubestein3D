#include "Camera.h"
#include "HelperOperations.h"

Camera::Camera()
{
	eye = Vector(1.0f, 12.5f, -15.0f);
	target = Vector(1.0f, 1.5f, 1.0f);
	up = Vector(0.0f, 1.0f, 0.0f);

	targetEntity = nullptr;
	followEntity = false;
}


Camera::~Camera()
{
}

void Camera::Update(long delta)
{
	if (followEntity)
	{
		this->eye = targetEntity->position;
		this->target = this->eye + targetEntity->GetDirection();
	}
}

void Camera::Render(long delta, Renderer* renderer)
{
	renderer->CameraLookAt(eye, target, up);
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

void Camera::MoveCamera(float speed)
{
	//Calcula vetor dire��o
	float x = this->target.x - this->eye.x,
		y = this->target.y - this->eye.y,
		z = this->target.z - this->eye.z;

	//Normaliza vetor dire��o
	normalizeVector(x, y, z);

	//Calcula posi��o e alvo da c�mera
	this->eye.x += x * speed;
	this->eye.y += z * speed;
	this->target.x += x * speed;
	this->target.z += z * speed;
}

void Camera::StrafeCamera(float speed)
{
	//Vetor strafe
	float x = this->target.x - this->eye.x,
		y = this->target.y - this->eye.y,
		z = this->target.z - this->eye.z;

	//Calcula produto vetorial
	crossProduct(x, y, z,
		this->up.x, this->up.y, this->up.z);

	//Normaliza vetor dire��o
	normalizeVector(x, y, z);

	//Calcula posi��o e alvo da c�mera
	this->eye.x += x * speed;
	this->eye.z += z * speed;
	this->target.x += x * speed;
	this->target.z += z * speed;
}

void Camera::FollowEntity(Entity* toFollow)
{
	this->targetEntity = toFollow;
	this->followEntity = true;
}

void Camera::StopFollowingEntity()
{
	this->targetEntity = nullptr;
	this->followEntity = false;
}