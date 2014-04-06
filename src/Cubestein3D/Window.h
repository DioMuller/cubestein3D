#pragma once
#include "GameManager.h"
#include "Parameters.h"

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
		bool limitFps;

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
};

