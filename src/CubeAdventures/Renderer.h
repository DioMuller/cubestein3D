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

#define SKY_BACK 0
#define SKY_FRONT 1
#define SKY_LEFT 2
#define SKY_RIGHT 3
#define SKY_TOP 4
#define SKY_BOTTOM 5

class Renderer
{
	////////////////////////////////////////
	// Attribute
	////////////////////////////////////////
	private:
		GLuint* skyboxTexture;

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

		void InitializeSkybox(std::string left, std::string front, std::string right, std::string back, std::string top, std::string bottom);
		void DrawSkybox(float x, float y, float z, float width, float height, float length);
};

