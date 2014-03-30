#include "TestEntity2.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
TestEntity2::TestEntity2()
{
	float* map = new float[8];
	map[0] = 0.547;
	map[1] = 0.515;
	map[2] = 0.751;
	map[3] = 0.515;
	map[4] = 0.751;
	map[5] = 0.694;
	map[6] = 0.547;
	map[7] = 0.694;

	Vector offset = Vector(0.202, 0.202, 0);
	texture = new TextureInfo("Textures/Spiderman.png", map, 8, offset);

	this->scale = Vector(0.5, 0.5, 0.5);

	this->current = 0.0f;
	this->change = 0.03;

	this->position.y = 2.0;
	this->position.z = 2.0;
}


TestEntity2::~TestEntity2()
{
	delete texture;
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void TestEntity2::Update(long delta)
{
	Entity::Update(delta);

	current += change;
	if (current > 3.0f || current < -3.0f) change *= -1;

	this->position.x = current;
	this->rotation.y -= 1;
}

void TestEntity2::Render(long delta, Renderer* renderer)
{
	renderer->DrawTexturedCube(position, scale, rotation, texture);
	Entity::Render(delta, renderer);
}
