#pragma once
#include "Behavior.h"
#include "Player.h"

class ControllableBehavior : Behavior
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		Player* player;
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
	private:
		bool CheckPositionAndSet(Vector newPos);
};

