#include "ImageScreen.h"
#include "Input.h"
#include "Parameters.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
ImageScreen::ImageScreen(std::string texture)
{
	this->image = new TextureInfo(texture, false, true);
	isButtonPressed = true;
}

ImageScreen::~ImageScreen()
{
	delete image;
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
bool ImageScreen::Update(long delta)
{
	if (Input::input[BUTTON_ACTION] && !isButtonPressed)
	{
		return false;
	}
	else
	{
		isButtonPressed = false;
		return true;
	}
}

void ImageScreen::Render(long delta, Renderer* renderer)
{
	renderer->Begin();
	renderer->DrawTexture(SCREEN_START, SCREEN_END, image);
	renderer->End();
}