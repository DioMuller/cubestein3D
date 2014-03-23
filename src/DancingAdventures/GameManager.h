#pragma once

#include <list>
#include "Entity.h"

class GameManager
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	protected:
		std::list<Entity*> entities;
		Renderer* renderer;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		GameManager();
		~GameManager();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		virtual void Update(long delta);
		virtual void Render(long delta);

		void AddEntity(Entity* entity);
		void RemoveEntity(Entity* entity);
};

