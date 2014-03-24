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
}

void TestEntity::Render(long delta, Renderer* renderer)
{
	renderer->DrawCube(1.0);
	Entity::Render(delta, renderer);
}
