#pragma once

#include <list>
#include "Renderer.h"
#include "Behavior.h"

class Entity
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	public:
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;
	private:
		std::list<Behavior*> behaviors;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Entity();
		~Entity();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		virtual void Update(long delta);
		virtual void Render(long delta, Renderer* renderer);
};

