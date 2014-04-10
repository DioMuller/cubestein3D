#include "ImageScreen.h"
#include "Input.h"
#include "Parameters.h"
#include "Window.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
ImageScreen::ImageScreen(std::string texture, std::string bgm)
{
	this->image = new TextureInfo(texture, false, true);
	isButtonPressed = true;

	this->bgm = bgm;
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
	if (Input::input[BUTTON_ACTION])
	{
		if (!isButtonPressed)
		{
			isButtonPressed = true;
			return false;
		}
		else return true;
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

void ImageScreen::Activate()
{
	Window::GetAudioPlayer()->PlaySong(bgm);
}