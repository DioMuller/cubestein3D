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

	parent->position += (Input::direction * (float) delta * SPEED);
}