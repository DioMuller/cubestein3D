#include "TestEntity.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
TestEntity::TestEntity()
{
}


TestEntity::~TestEntity()
{
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
	renderer->DrawCube(position, scale, rotation);
	Entity::Render(delta, renderer);
}
