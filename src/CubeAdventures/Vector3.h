#pragma once
class Vector3
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		float x;
		float y;
		float z;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Vector3();
		~Vector3();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		float GetX();
		float GetY();
		float GetZ();
		void Translate(float x, float y, float z);
};

