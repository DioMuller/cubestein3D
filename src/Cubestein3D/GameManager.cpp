#include "GameManager.h"
#include "Window.h"

////////////////////////////////////////
// Static Attributes
////////////////////////////////////////
GameManager* GameManager::instance = nullptr;

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
GameManager::GameManager(Window* parent)
{
	loadedLevel = nullptr;

	renderer = parent->GetRenderer();
	audio = parent->GetAudioPlayer();
	textureLoader = parent->GetTextureLoader();

	currentLevel = -1;
	nextLevels = std::vector<std::string>();

	endGame = false;

	camera = new Camera();
	GameManager::SetInstance(this);
}


GameManager::~GameManager()
{
	delete loadedLevel;
	delete camera;
}

////////////////////////////////////////
// Life Cycle Methods
////////////////////////////////////////

bool GameManager::Update(long delta)
{
	if (endGame)
	{
		loadedLevel = nullptr;
		return false;
	}

	if (loadedLevel == nullptr) return false;

	if (loadedLevel->GetPlayer()->GetHealth() <= 0) return false;

	loadedLevel->Update(delta);
	camera->Update(delta);

	return true;
}

void GameManager::Render(long delta)
{
	if (loadedLevel == nullptr || endGame) return;
	renderer->Begin();

	camera->Render(delta, renderer);

	loadedLevel->Render(delta, renderer);

	renderer->DrawSkybox(0, 0, 0, 800, 400, 400);

	renderer->End();
}

bool GameManager::FinishedGame()
{
	return endGame;
}

////////////////////////////////////////
// Entity Methods
////////////////////////////////////////
void GameManager::AddEntity(Entity* entity)
{
	if (loadedLevel != nullptr) loadedLevel->AddEntity(entity);
}

void GameManager::RemoveEntity(Entity* entity)
{
	if (loadedLevel != nullptr) loadedLevel->RemoveEntity(entity);
}

void GameManager::ClearEntities()
{
	if (loadedLevel != nullptr) loadedLevel->ClearEntities();
}

////////////////////////////////////////
// Camera Methods
////////////////////////////////////////
void GameManager::InitializeCamera(float fov, int width, int height, float zNear, float zFar)
{
	renderer->CameraInitialize(fov, width, height, zNear, zFar);

	/* TODO: Remove from here 
	renderer->InitializeSkybox(
		"Content/Textures/Nebular_rt.jpg",
		"Content/Textures/Nebular_lf.jpg",
		"Content/Textures/Nebular_ft.jpg",
		"Content/Textures/Nebular_bk.jpg",
		"Content/Textures/Nebular_up.jpg",
		"Content/Textures/Nebular_dn.jpg");
		*/
}

////////////////////////////////////////
// Level Methods
////////////////////////////////////////
void GameManager::AddLevel(std::string level)
{
	nextLevels.push_back(level);
}

bool GameManager::NextLevel()
{
	currentLevel++;
	delete loadedLevel;

	if (currentLevel < nextLevels.size())
	{
		loadedLevel = new Level(nextLevels[currentLevel]);
	}
	else
	{
		endGame = true;
	}

	return !endGame;
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
	return instance->loadedLevel;
}

AudioPlayer* GameManager::GetAudioPlayer()
{
	return instance->audio;
}

TextureLoader* GameManager::GetTextureLoader()
{
	return instance->textureLoader;
}