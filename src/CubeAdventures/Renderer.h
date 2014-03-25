#pragma once

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <glut.h>
#include <string>

#include "Vector.h"

class Renderer
{
	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Renderer();
		~Renderer();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Begin();
		void End();

		void DrawCube(Vector position, Vector scale, Vector rotation);
};

