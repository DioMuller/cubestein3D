#include "GameManager.h"

////////////////////////////////////////
// Static Attributes
////////////////////////////////////////
GameManager* GameManager::instance = nullptr;

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
GameManager::GameManager()
{
	currentLevel = new Level();
	renderer = new Renderer();

	camera = new Camera();
	GameManager::SetInstance(this);
}


GameManager::~GameManager()
{
}

////////////////////////////////////////
// Life Cycle Methods
////////////////////////////////////////

void GameManager::Update(long delta)
{
	currentLevel->Update(delta);

	camera->Update(delta);
}

void GameManager::Render(long delta)
{
	renderer->Begin();

	camera->Render(delta, renderer);

	currentLevel->Render(delta, renderer);

	renderer->DrawSkybox(0, 0, 0, 800, 400, 400);

	renderer->End();
}

////////////////////////////////////////
// Entity Methods
////////////////////////////////////////
void GameManager::AddEntity(Entity* entity)
{
	if (currentLevel != nullptr) currentLevel->AddEntity(entity);
}

void GameManager::RemoveEntity(Entity* entity)
{
	if (currentLevel != nullptr) currentLevel->RemoveEntity(entity);
}

void GameManager::ClearEntities()
{
	if (currentLevel != nullptr) currentLevel->ClearEntities();
}

////////////////////////////////////////
// Camera Methods
////////////////////////////////////////
void GameManager::InitializeCamera(float fov, int width, int height, float zNear, float zFar)
{
	renderer->CameraInitialize(fov, width, height, zNear, zFar);

	/* TODO: Remove from here */
	renderer->InitializeSkybox(
		"Content/Textures/Nebular_rt.jpg",
		"Content/Textures/Nebular_lf.jpg",
		"Content/Textures/Nebular_ft.jpg",
		"Content/Textures/Nebular_bk.jpg",
		"Content/Textures/Nebular_up.jpg",
		"Content/Textures/Nebular_dn.jpg");
}

////////////////////////////////////////
// Level Methods
////////////////////////////////////////
void GameManager::LoadLevel(Level* level)
{
	currentLevel = level;
}

////////////////////////////////////////
// Static Methods
////////////////////////////////////////
void GameManager::SetInstance(GameManager* game)
{
	GameManager::instance = game;
}

GameManager* GameManager::GetInstance()
{
	return GameManager::instance;
}

Camera* GameManager::GetCamera()
{
	return camera;
}

Level* GameManager::GetCurrentLevel()
{
	return instance->currentLevel;
}