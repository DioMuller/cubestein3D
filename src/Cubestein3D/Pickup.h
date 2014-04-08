#pragma once
#include "Entity.h"
class Pickup : public Entity
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	protected:
		TextureInfo* texture;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Pickup(std::string texture, Vector position);
		~Pickup();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
		void Render(long delta, Renderer* renderer);
};
