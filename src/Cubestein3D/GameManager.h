#pragma once

#include <list>
#include "Entity.h"
#include "Level.h"
#include "Camera.h"
#include "AudioPlayer.h"
#include "TextureLoader.h"

class Window;

class GameManager
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	protected:
		// Media
		Camera* camera;
		Renderer* renderer;
		AudioPlayer* audio;
		TextureLoader* textureLoader;

		// Level
		int currentLevel;
		std::vector<std::string> nextLevels;
		Level* loadedLevel;
		Player* player;

		bool endGame;


	////////////////////////////////////////
	// Static Attributes
	////////////////////////////////////////
	protected:
		static GameManager* instance;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		GameManager(Window* parent);
		~GameManager();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		bool Update(long delta);
		virtual void Render(long delta);

		void AddEntity(Entity* entity);
		void RemoveEntity(Entity* entity);
		void ClearEntities();

		void LoadLevels(std::string levels);
		void AddLevel(std::string level);
		bool NextLevel();

		void InitializeCamera(float fov, int width, int height, float zNear, float zFar);
		Camera* GetCamera();

		bool FinishedGame();

	////////////////////////////////////////
	// Static Methods
	////////////////////////////////////////
	public:
		static void SetInstance(GameManager* game);
		static GameManager* GetInstance();
		static Level* GetCurrentLevel();
		static AudioPlayer* GetAudioPlayer();
		static TextureLoader* GetTextureLoader();
		static Player* GetPlayer();
};

