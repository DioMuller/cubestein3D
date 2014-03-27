#pragma once

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <glut.h>
#include <string>
#include "TextureInfo.h"

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
		void DrawTexturedCube(Vector position, Vector scale, Vector rotation, TextureInfo* texture);

		void CameraInitialize(float fov, int width, int height, float zNear, float zFar);
		void CameraLookAt(Vector eye, Vector target, Vector up);
};

