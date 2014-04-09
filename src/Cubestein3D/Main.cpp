#include "Window.h"
#include <time.h>
#include "Definitions.h"

int main(int argc, char **argv)
{
	// Initializes window and game logic
	Window* window = new Window("Cubenstein 3D", SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
	GameManager* game = new GameManager();

	// Initializes RNG
	srand((unsigned int) time(0));

	// Initializes level
	Level* level = new Level("Content/Levels/E1M1.xml");
	game->LoadLevel(level);

	// Links game with window and runs.
	window->SetGame(game);
	window->Run();

	return 0;
}

