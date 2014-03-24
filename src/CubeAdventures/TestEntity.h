#pragma once
#include "Entity.h"
class TestEntity : public Entity
{
	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		TestEntity();
		~TestEntity();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
		void Render(long delta, Renderer* renderer);
};
