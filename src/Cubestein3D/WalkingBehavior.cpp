#include "WalkingBehavior.h"
#include "Entity.h"
#include "GameManager.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
WalkingBehavior::WalkingBehavior(Entity* parent) : Behavior(parent)
{
	this->parent->rotation.y = (rand() % 4) * 90.0f;
	this->maxDistance = (float) 1.0f + (rand() % 5);

	this->walked = 0.0f;
}


WalkingBehavior::~WalkingBehavior()
{
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void WalkingBehavior::Update(long delta)
{
	float speed = delta * ENEMYSPEED;
	Vector newPosition = parent->position + (parent->GetDirection() * speed);

	walked += speed;

	if (walked > maxDistance )
	{
		this->parent->rotation.y = (float) (((int) this->parent->rotation.y + 180) % 360);
		walked = 0.0f;
	}
	else if (GameManager::GetCurrentLevel()->CollidesWithLevel(newPosition, parent->scale))
	{
		this->parent->rotation.y = (float)(((int) this->parent->rotation.y + 90) % 360);
		walked = 0.0f;
	}
	else
	{
		parent->position = newPosition;
	}
}