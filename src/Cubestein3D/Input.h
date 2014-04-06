#pragma once
#include "Vector.h"
#include "SDL/SDL.h"
#include "Definitions.h"

class Input
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	public:
		static Vector direction;
		static bool input[INPUTCOUNT];
	
	////////////////////////////////////////
	// Static Methods
	////////////////////////////////////////
	public:
		static void Update(SDL_Event lastEvent);
	private:
		static Button SDLToButton(SDLKey original);
};

