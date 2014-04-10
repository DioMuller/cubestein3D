#pragma once
#include "Renderer.h"
#include "TextureInfo.h"

class ImageScreen
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		TextureInfo* image;
		std::string bgm;
		bool isButtonPressed;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		ImageScreen(std::string texture, std::string bgm);
		~ImageScreen();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Activate();
		bool Update(long delta);
		void Render(long delta, Renderer* renderer);
};

