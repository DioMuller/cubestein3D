#include "GameManager.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
GameManager::GameManager()
{
	entities = std::list<Entity*>();
	renderer = new Renderer();
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
}

void GameManager::Render(long delta)
{
	renderer->Begin();

	for (Entity* entity : entities)
	{
		entity->Render(delta, renderer);
	}

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