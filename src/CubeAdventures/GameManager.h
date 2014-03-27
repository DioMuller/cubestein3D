#pragma once

#include <list>
#include "Entity.h"
#include "Camera.h"

class GameManager
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	protected:
		std::list<Entity*> entities;
		Camera* camera;
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

		void InitializeCamera(float fov, int width, int height, float zNear, float zFar);
};

