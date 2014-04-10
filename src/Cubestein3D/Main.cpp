#include "Window.h"
#include <time.h>
#include "Definitions.h"

int main(int argc, char **argv)
{
	// Initializes window and game logic
	Window* window = new Window("Cubenstein 3D", SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);

	// Initializes RNG
	srand((unsigned int) time(0));

	// Run
	window->Run();

	return 0;
}

