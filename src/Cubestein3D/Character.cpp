#include "Character.h"
#include "Definitions.h"
#include "Parameters.h"
#include "Log.h"

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

	this->size = CHARACTER_SIZE;

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
	renderer->DrawTexturedCube(position, size, rotation, texture);
	Entity::Render(delta, renderer);
}

void Character::CollideWith(Entity* other)
{
	Log::Message(tag + " collided with " + other->tag);
}