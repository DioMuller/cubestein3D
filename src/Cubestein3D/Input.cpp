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
			Input::input[QUIT] = true;
			break;
		case SDL_KEYDOWN:
			if (pressed != ERROR) Input::input[pressed] = true;
			break;
		case SDL_KEYUP:
			if (pressed != ERROR) Input::input[pressed] = false;
			break;
		default:
			break;
	}

	if (Input::input[UP]) Input::direction.y = 1;
	else if (Input::input[DOWN]) Input::direction.y = -1;
	else Input::direction.y = 0;

	if (Input::input[LEFT]) Input::direction.x = -1;
	else if (Input::input[RIGHT]) Input::direction.x = 1;
	else Input::direction.x = 0;

	Input::direction.normalize();
}

Button Input::SDLToButton(SDLKey original)
{
	switch (original)
	{
		case SDLK_w:
		case SDLK_UP:
			return UP;
		case SDLK_a:
		case SDLK_LEFT:
			return LEFT;
		case SDLK_s:
		case SDLK_DOWN:
			return DOWN;
		case SDLK_d:
		case SDLK_RIGHT:
			return RIGHT;
		case SDLK_SPACE:
			return ACTION;
		case SDLK_LCTRL:
		case SDLK_RCTRL:
			return SHOT;
		case SDLK_ESCAPE:
			return QUIT;
		default:
			return ERROR;
	}
}