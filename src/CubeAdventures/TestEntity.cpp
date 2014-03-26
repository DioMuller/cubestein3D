#include "TestEntity.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
TestEntity::TestEntity()
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
}


TestEntity::~TestEntity()
{
	delete texture;
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void TestEntity::Update(long delta)
{
	Entity::Update(delta);

	this->position.x += 0.01;
	this->rotation.y -= 1;
}

void TestEntity::Render(long delta, Renderer* renderer)
{
	renderer->DrawTexturedCube(position, scale, rotation, texture);
	Entity::Render(delta, renderer);
}
