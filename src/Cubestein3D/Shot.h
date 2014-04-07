#pragma once
#include "Entity.h"
#include "Player.h"

class Shot : Entity
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		Player* parentPlayer;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Shot(Vector position, Vector direction);
		Shot(Player* parent, Vector position, Vector direction);
		~Shot();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Render(long delta, Renderer* renderer);
		void CollideWith(Entity* other);
};

