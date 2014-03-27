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

	camera->Render(delta, renderer);

	for (Entity* entity : entities)
	{
		entity->Render(delta, renderer);
	}

	renderer->DrawSkybox(0, 0, 0, 800, 400, 400);

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

	/* TODO: Remove from here */
	renderer->InitializeSkybox(
		"Textures/Nebular_rt.jpg",
		"Textures/Nebular_lf.jpg",
		"Textures/Nebular_ft.jpg",
		"Textures/Nebular_bk.jpg",
		"Textures/Nebular_up.jpg",
		"Textures/Nebular_dn.jpg");
}