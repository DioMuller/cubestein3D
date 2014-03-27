#include "GameManager.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
GameManager::GameManager()
{
	entities = std::list<Entity*>();
	renderer = new Renderer();

	camera = new Camera();
}


GameManager::~GameManager()
{
}

////////////////////////////////////////
// Life Cycle Methods
////////////////////////////////////////

void GameManager::Update(long delta)
{
	for (Entity* entity : entities)
	{
		entity->Update(delta);
	}

	camera->Update(delta);
}

void GameManager::Render(long delta)
{
	renderer->Begin();

	for (Entity* entity : entities)
	{
		entity->Render(delta, renderer);
	}

	camera->Render(delta, renderer);

	renderer->End();
}

////////////////////////////////////////
// Entity Methods
////////////////////////////////////////
void GameManager::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}

void GameManager::RemoveEntity(Entity* entity)
{
	entities.remove(entity);
}

////////////////////////////////////////
// Camera Methods
////////////////////////////////////////
void GameManager::InitializeCamera(float fov, int width, int height, float zNear, float zFar)
{
	renderer->CameraInitialize(fov, width, height, zNear, zFar);
}