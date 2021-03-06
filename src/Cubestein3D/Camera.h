#pragma once
#include "Entity.h"

class Camera
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	public:
		// Camera vectors
		Vector eye;
		Vector target;
		Vector up;

		// Will the camera follow an entity?
		bool followEntity;
		Entity* targetEntity;

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

		void FollowEntity(Entity* toFollow);
		void StopFollowingEntity();

	protected:
		void RotateCamera(float angle, float x, float y, float z);
		void MoveCamera(float speed);
		void StrafeCamera(float speed);
};

