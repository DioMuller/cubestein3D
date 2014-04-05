#include "Character.h"


Character::Character(std::string texture, Vector position)
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

	this->scale = Vector(0.5, 1, 0.5);

	this->position = position;
}


Character::~Character()
{
}

void Character::Update(long delta)
{
	Entity::Update(delta);
}

void Character::Render(long delta, Renderer* renderer)
{
	renderer->DrawTexturedCube(position, scale, rotation, texture);
	Entity::Render(delta, renderer);
}