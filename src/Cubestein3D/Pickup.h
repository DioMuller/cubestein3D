#pragma once
#include "Entity.h"
#include "AudioPlayer.h"

class Pickup : public Entity
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	protected:
		TextureInfo* texture;
		SFXId pickupSound;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Pickup(std::string texture, std::string sound, Vector position);
		~Pickup();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
		void Render(long delta, Renderer* renderer);

		void Destroy();
};

