#include "ControllableBehavior.h"


ControllableBehavior::ControllableBehavior(Entity* parent) : Behavior(parent)
{
}


ControllableBehavior::~ControllableBehavior()
{
}

void ControllableBehavior::Update(long delta)
{
	Behavior::Update(delta);

	/* Check: http://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinputkeyboard.html */
}