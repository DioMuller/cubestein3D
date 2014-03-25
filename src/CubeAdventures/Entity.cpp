#include "Entity.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////

Entity::Entity()
{
	behaviors = std::list<Behavior*>();

	position = Vector();
	rotation = Vector();
	scale = Vector(1, 1, 1);
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