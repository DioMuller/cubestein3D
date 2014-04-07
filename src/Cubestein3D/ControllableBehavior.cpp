#include "ControllableBehavior.h"
#include "Entity.h"
#include "Input.h"
#include "GameManager.h"
#include "Parameters.h"
#include "Shot.h"

ControllableBehavior::ControllableBehavior(Entity* parent) : Behavior(parent)
{
	hasShot = false;
}


ControllableBehavior::~ControllableBehavior()
{
}

void ControllableBehavior::Update(long delta)
{
	Behavior::Update(delta);

	// Movement
	Vector rotatedDirection = Vector(0, 0, Input::direction.z).rotateY(parent->rotation.y);

	Vector newPosition = parent->position + (rotatedDirection * (float) delta * CHARACTER_SPEED);
	
	if (!GameManager::GetCurrentLevel()->CollidesWithLevel(newPosition, parent->size))
	{
		parent->position = newPosition;
	}

	parent->rotation.y -= (Input::direction.x * (float)delta * CHARACTER_SPEED) / 2.0f;

	// Shooting
	if (Input::input[BUTTON_SHOT])
	{
		if (!hasShot)
		{
			Shot* shot = new Shot((Player*) parent, parent->position + parent->GetDirection(), parent->GetDirection() );
			GameManager::GetInstance()->AddEntity((Entity*)shot);

			// Small hack: Will make the player shot once if the button is pressed.
			hasShot = true;
		}

	}
	else
	{
		hasShot = false;
	}
}