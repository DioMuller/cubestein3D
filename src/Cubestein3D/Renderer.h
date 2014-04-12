#pragma once

#include <string>
#include "TextureInfo.h"

#include "Vector.h"
#include "Definitions.h"

// EVERYTHING that has rendering shound be here. Better if only
// this and windows use the OGL includes, will have to check.
class Renderer
{
	////////////////////////////////////////
	// Attribute
	////////////////////////////////////////
	private:
		unsigned int* skyboxTexture;

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
		void DrawSphere(Vector position, Vector scale);
		
		void DrawTexturedCube(Vector position, Vector scale, Vector rotation, TextureInfo* texture);

		void DrawPlane(Vector startPosition, Vector endPosition, TextureInfo* texture);
		void DrawWall(Vector position, Vector size, Vector repetitions, TextureInfo* texture);

		void DrawString(Vector position, float r, float g, float b, std::string text);
		void DrawString3D(Vector position, float rotation, float r, float g, float b, std::string text);
		void DrawDebug(Vector position, float r, float g, float b, std::string text);

		void DrawTexture(Vector startPosition, Vector endPosition, TextureInfo* texture);
		void DrawCrosshair();

		void CameraInitialize(float fov, int width, int height, float zNear, float zFar);
		void CameraLookAt(Vector eye, Vector target, Vector up);

		void InitializeSkybox(std::string left, std::string front, std::string right, std::string back, std::string top, std::string bottom);
		void DrawSkybox(float x, float y, float z, float width, float height, float length);

	private:
		void ChangeToOrtho();
		void ChangeToPerspective();
};

