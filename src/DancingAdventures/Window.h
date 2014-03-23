#pragma once

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <glut.h>
#include <string>

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
	private:
		// OpenGL Configuration
		int SetupOpenGL(void);
		// SDL Initialization
		void InitializeSDL();
		// Rendering
		void Render();
};

