#pragma once
#include "Behavior.h"

class ControllableBehavior : Behavior
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		bool hasShot;
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

