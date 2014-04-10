#pragma once
#include "Behavior.h"
#include "Vector.h"
#include "Player.h"
#include "AudioPlayer.h"

class EnemyBehavior : public Behavior
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		Player* target;
		SFXId attackSound;
		bool nowAttacking;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		EnemyBehavior(Entity* parent);
		~EnemyBehavior();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
};

