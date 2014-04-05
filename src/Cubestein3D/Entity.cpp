#include "Entity.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////

Entity::Entity()
{
	behaviors = std::list<Behavior*>();

	position = Vector();
	rotation = Vector();
	size = Vector(1, 1, 1);
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

Vector Entity::GetDirection()
{
	Vector origin = Vector(0, 0, 1);
	origin.rotateY(rotation.y);

	return origin;
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

////////////////////////////////////////
// Collision Methods
////////////////////////////////////////
bool Entity::CheckCollision(Entity* other)
{
	if (GetCollisionRect().Intersects(other->GetCollisionRect()) )
	{
		CollideWith(other);
		other->CollideWith(this);

		return true;
	}

	return false;
}

Rect Entity::GetCollisionRect()
{
	return Rect(position.x - (size.x / 2), position.z - (size.z / 2), size.x, size.z);
}

void Entity::CollideWith(Entity* other)
{

}