#include "Entity.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////

Entity::Entity()
{
	behaviors = std::list<Behavior*>();
}


Entity::~Entity()
{
}

////////////////////////////////////////
// Public Methods
////////////////////////////////////////
void Entity::Update(long delta)
{
	for (Behavior* b : behaviors)
	{
		b->Update(delta);
	}
}

void Entity::Render(long delta, Renderer* renderer)
{

}