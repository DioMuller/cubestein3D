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

////////////////////////////////////////
// Behavior Methods
////////////////////////////////////////
void Entity::AddBehavior(Behavior* behavior)
{
	behaviors.push_back(behavior);
}

void Entity::RemoveBehavior(Behavior* behavior)
{
	behaviors.remove(behavior);
}

void Entity::ClearBehaviors()
{
	behaviors.clear();
}