#pragma once
#include "Behavior.h"
#include "Vector.h"
#include "Player.h"
#include "AudioPlayer.h"
#include "Level.h"

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
		EnemyBehavior(Entity* parent, Level* level);
		~EnemyBehavior();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
};

