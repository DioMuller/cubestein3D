#pragma once
#include "Entity.h"
class Character : public Entity
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	protected:
		TextureInfo* texture;
	public:
		Character(std::string texture, Vector position);
		~Character();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
		void Render(long delta, Renderer* renderer);
};

