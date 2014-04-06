#include "Input.h"

Vector Input::direction = Vector();
bool Input::input[INPUTCOUNT] = { false, false, false, false, false, false, false };

////////////////////////////////////////
// Static Methods
////////////////////////////////////////
void Input::Update(SDL_Event lastEvent)
{
	Button pressed = SDLToButton(lastEvent.key.keysym.sym);

	switch (lastEvent.type)
	{
		case SDL_QUIT:
			Input::input[BUTTON_QUIT] = true;
			break;
		case SDL_KEYDOWN:
			if (pressed != BUTTON_NONE) Input::input[pressed] = true;
			break;
		case SDL_KEYUP:
			if (pressed != BUTTON_NONE) Input::input[pressed] = false;
			break;
		default:
			break;
	}

	if (Input::input[BUTTON_UP]) Input::direction.z = 1.0f;
	else if (Input::input[BUTTON_DOWN]) Input::direction.z = -1.0f;
	else Input::direction.z = 0.0f;

	if (Input::input[BUTTON_LEFT]) Input::direction.x = 1.0f;
	else if (Input::input[BUTTON_RIGHT]) Input::direction.x = -1.0f;
	else Input::direction.x = 0.0f;

	if (direction.x != 0 || direction.y != 0 || direction.z != 0) 
		Input::direction.normalize();
}

Button Input::SDLToButton(SDLKey original)
{
	switch (original)
	{
		case SDLK_w:
		case SDLK_UP:
			return BUTTON_UP;
		case SDLK_a:
		case SDLK_LEFT:
			return BUTTON_LEFT;
		case SDLK_s:
		case SDLK_DOWN:
			return BUTTON_DOWN;
		case SDLK_d:
		case SDLK_RIGHT:
			return BUTTON_RIGHT;
		case SDLK_SPACE:
			return BUTTON_ACTION;
		case SDLK_LCTRL:
		case SDLK_RCTRL:
			return BUTTON_SHOT;
		case SDLK_ESCAPE:
			return BUTTON_QUIT;
		default:
			return BUTTON_NONE;
	}
}