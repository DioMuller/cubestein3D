#include "Pickup.h"
#include "Parameters.h"


Pickup::Pickup(std::string texture, Vector position)
{
	float* map = new float[8];
	map[0] = 0.547f;
	map[1] = 0.515f;
	map[2] = 0.751f;
	map[3] = 0.515f;
	map[4] = 0.751f;
	map[5] = 0.694f;
	map[6] = 0.547f;
	map[7] = 0.694f;

	Vector offset = Vector(0.202, 0.202, 0);
	this->texture = new TextureInfo(texture, map, 8, offset);

	this->size = PICKUP_SIZE;

	this->position = position;
}


Pickup::~Pickup()
{
}


void Pickup::Update(long delta)
{
	Entity::Update(delta);

	this->rotation.y += (delta * PICKUP_ROTATION);

	if (this->rotation.y > 360.0f) this->rotation.y -= 360.0f;
}

void Pickup::Render(long delta, Renderer* renderer)
{
	renderer->DrawTexturedCube(position, size, rotation, texture);
	Entity::Render(delta, renderer);
}