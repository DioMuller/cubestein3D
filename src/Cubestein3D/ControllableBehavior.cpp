#include "ControllableBehavior.h"
#include "Entity.h"
#include "Input.h"
#include "GameManager.h"
#include "Parameters.h"


ControllableBehavior::ControllableBehavior(Entity* parent) : Behavior(parent)
{
}


ControllableBehavior::~ControllableBehavior()
{
}

void ControllableBehavior::Update(long delta)
{
	Behavior::Update(delta);
	Vector rotatedDirection = Vector(0, 0, Input::direction.z).rotateY(parent->rotation.y);

	Vector newPosition = parent->position + (rotatedDirection * (float) delta * CHARACTER_SPEED);
	
	if (!GameManager::GetCurrentLevel()->CollidesWithLevel(newPosition, parent->size))
	{
		parent->position = newPosition;
	}

	parent->rotation.y -= (Input::direction.x * (float)delta * CHARACTER_SPEED) / 2.0f;
}