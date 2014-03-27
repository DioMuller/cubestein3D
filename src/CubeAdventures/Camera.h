#pragma once
#include "Entity.h"

class Camera
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	public:
		Vector eye;
		Vector target;
		Vector up;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Camera();
		~Camera();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Update(long delta);
		void Render(long delta, Renderer* renderer);

	protected:
		void MoveCamera(float x, float y, float z);
		void TranslateCamera(float x, float y, float z);
		void RotateCamera(float angle, float x, float y, float z);

};

