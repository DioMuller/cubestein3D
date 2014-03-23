#pragma once
#include "GameManager.h"

////////////////////
// Constants
////////////////////
#define SCREENWIDTH 800
#define SCREENHEIGHT 600
#define SCREENBPP 0

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

