#pragma once
#include "Behavior.h"
#include "Vector.h"

#define ENEMYSPEED 0.005f

class WalkingBehavior : public Behavior
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		float maxDistance;
		float walked;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		WalkingBehavior(Entity* parent);
		~WalkingBehavior();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
};

