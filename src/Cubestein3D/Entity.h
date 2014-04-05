#pragma once

#include <list>
#include "Renderer.h"
#include "Behavior.h"
#include "Rect.h"

class Entity
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	public:
		Vector position;
		Vector rotation;
		Vector size;

		std::string tag;

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

		bool CheckCollision(Entity* other);
		Rect GetCollisionRect();
		virtual void CollideWith(Entity* other);

		void AddBehavior(Behavior* behavior);
		void RemoveBehavior(Behavior* behavior);
		void ClearBehaviors();
		Vector GetDirection();
};

