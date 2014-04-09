#pragma once

#include <list>
#include "Entity.h"
#include "Level.h"
#include "Camera.h"
#include "AudioPlayer.h"

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
		// Level
		Level* currentLevel;
		std::vector<std::string> nextLevels;

		bool endGame;


	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	protected:
		static GameManager* instance;

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
		bool Update(long delta);
		virtual void Render(long delta);

		void AddEntity(Entity* entity);
		void RemoveEntity(Entity* entity);
		void ClearEntities();

		void LoadLevel(Level* level);
		bool NextLevel();

		void InitializeCamera(float fov, int width, int height, float zNear, float zFar);
		Camera* GetCamera();

	////////////////////////////////////////
	// Static Methods
	////////////////////////////////////////
	public:
		static void SetInstance(GameManager* game);
		static GameManager* GetInstance();
		static Level* GetCurrentLevel();
		static AudioPlayer* GetAudioPlayer();
};

