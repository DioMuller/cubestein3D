#pragma once
#include "Behavior.h"

#define SPEED 0.01f

class ControllableBehavior : Behavior
{
	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		ControllableBehavior(Entity* parent);
		~ControllableBehavior();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
};

