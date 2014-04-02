#include "ControllableBehavior.h"
#include "SDL/SDL.h"
#include "Entity.h"


ControllableBehavior::ControllableBehavior(Entity* parent) : Behavior(parent)
{
}


ControllableBehavior::~ControllableBehavior()
{
}

void ControllableBehavior::Update(long delta)
{
	Behavior::Update(delta);

	/* Check: http://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinputkeyboard.html */
	/*
	SDL_Event event;

	SDL_PollEvent(&event);

	if (event.type == SDL_KEYDOWN)
	{
		switch ( event.key.keysym.sym )
		{
			case SDLK_LEFT:
				parent->position.x -= 1;
				break;
			case SDLK_RIGHT:
				parent->position.x += 1;
				break;
			case SDLK_UP:
				parent->position.z -= 1;
				break;
			case SDLK_DOWN:
				parent->position.z += 1;
				break;
			default:
				break;
		}
	}
	*/
}