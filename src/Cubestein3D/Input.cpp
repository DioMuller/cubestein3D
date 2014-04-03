#include "Input.h"

////////////////////////////////////////
// Static Methods
////////////////////////////////////////
void Input::Update(SDL_Event lastEvent)
{
	Button pressed = SDLToButton(lastEvent.key.keysym.sym);

	switch (lastEvent.type)
	{
		case SDL_QUIT:
			input[QUIT] = true;
			break;
		case SDL_KEYDOWN:
			if( pressed != ERROR ) input[pressed] = true;
			break;
		case SDL_KEYUP:
			if (pressed != ERROR) input[pressed] = false;
			break;
		default:
			break;
	}

	if (input[UP]) direction.y = 1;
	else if (input[DOWN]) direction.y = -1;
	else direction.y = 0;

	if (input[LEFT]) direction.x = -1;
	else if (input[RIGHT]) direction.x = 1;
	else direction.x = 0;

	direction.normalize();
}

void Input::Initialize()
{
	for (int i = 0; i < INPUTCOUNT; i++)
	{
		input[i] = false;
	}

	direction = Vector();
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
		default:
			return ERROR;
	}
}