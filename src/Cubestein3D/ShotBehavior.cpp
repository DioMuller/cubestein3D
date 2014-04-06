#include "ShotBehavior.h"
#include "Parameters.h"
#include "Entity.h"
#include "GameManager.h"


ShotBehavior::ShotBehavior(Entity* parent, Vector direction) : Behavior(parent)
{
	this->direction = direction;
	elapsedLifetime = 0;
}


ShotBehavior::~ShotBehavior()
{
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void ShotBehavior::Update(long delta)
{
	float speed = delta * SHOT_SPEED;
	elapsedLifetime += delta;

	if (elapsedLifetime > SHOT_LIFETIME)
	{
		parent->Destroy();
		return;
	}

	parent->position = parent->position + (direction * speed);

	//Destroyed if hits a wall
	if ( SHOT_DESTROYONWALL && GameManager::GetCurrentLevel()->CollidesWithLevel(parent->position, parent->size))
	{
		parent->Destroy();
	}
}