#pragma once
#include "Vector.h"
#include "SDL/SDL.h"

#define Button int

#define ERROR -1
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define QUIT 4
#define SHOT 5
#define ACTION 6

#define INPUTCOUNT 7

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

