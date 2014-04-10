#pragma once
#include "GameManager.h"
#include "Parameters.h"
#include "ImageScreen.h"

class Window
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		int width;
		int height;
		int bpp;
		int fps;
		float waitingTime;
		std::string title;
		GameManager* game;

		int currentState;
		ImageScreen* titleScreen;
		ImageScreen* howToPlayScreen;
		ImageScreen* gameOverScreen;
		ImageScreen* endingScreen;

		Renderer* renderer;
		AudioPlayer* audio;
		TextureLoader* textureLoader;

		bool limitFps;

	////////////////////////////////////////
	// Static Attributes
	////////////////////////////////////////
	protected:
		static Window* instance;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Window(std::string title, int width, int height, int bpp);
		~Window();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		int Run();
		void SetFPS(int value);
		int GetFPS();
		void SetGame(GameManager* game);
		GameManager* GetGame();
	private:
		// OpenGL Configuration
		int SetupOpenGL(void);
		// SDL Initialization
		void InitializeSDL();

	////////////////////////////////////////
	// Static Methods
	////////////////////////////////////////
	public:
		static Renderer* GetRenderer();
		static AudioPlayer* GetAudioPlayer();
		static TextureLoader* GetTextureLoader();
};

