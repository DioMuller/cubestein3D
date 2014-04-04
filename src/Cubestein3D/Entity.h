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
		Vector position;
		Vector rotation;
		Vector scale;
	protected:
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

		void AddBehavior(Behavior* behavior);
		void RemoveBehavior(Behavior* behavior);
		void ClearBehaviors();
		Vector GetDirection();
};

