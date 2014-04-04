#include "ControllableBehavior.h"
#include "Entity.h"
#include "Input.h"


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

	parent->position +=  (rotatedDirection * (float) delta * SPEED);
	parent->rotation.y -= (Input::direction.x * (float)delta * SPEED) / 2.0;
}