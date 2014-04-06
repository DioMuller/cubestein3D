#include "Window.h"
#include "TestEntity.h"
#include "TestEntity2.h"
#include <time.h>
#include "Definitions.h"

Level* LoadLevel();

int main(int argc, char **argv)
{
	// Initializes window and game logic
	Window* window = new Window("Cubenstein 3D", SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
	GameManager* game = new GameManager();

	// Initializes RNG
	srand(time(0));

	// Initializes level
	/*TODO: READ FROM XML*/
	Level* level1 = LoadLevel();
	game->LoadLevel(level1);

	// Links game with window and runs.
	window->SetGame(game);
	window->Run();

	return 0;
}


Level* LoadLevel()
{
	char** map = new char*[15];
	map[0] =  "WWWWWWWWWWWWWWWWWWWWW";
	map[1] =  "WWGGEGGWWWWGGGGGGGGWW";
	map[2] =  "WWGGEGGWWWWGGGEGGGGWW";
	map[3] =  "WWGGGGGWWWWGGGGGWGGWW";
	map[4] =  "WWWWGWWWWWWWWWWWWGWWW";
	map[5] =  "WWWWGWWWWWWWWWWWWGWWW";
	map[6] =  "WWWWGWWGGGGGWWWWWGWWW";
	map[7] =  "WWWWGWWGGEGGGGGGGGWWW";
	map[8] =  "WWWWGWWGGGGGWWWWWGWWW";
	map[9] =  "WWWWGWWGGEGGWWWWWGWWW";
	map[10] = "WWWWGGGGGGGGWWWWWGWWW";
	map[11] = "WWWWWWWWWWWWWWWWWGWWW";
	map[12] = "WWWWWWWWWWWWWWGGGGGSW";
	map[13] = "WWWWWWWWWWWWWWGWWGWWW";
	map[14] = "WWWWWWWWWWWWWWWWWWWWW";

	Level* level1 = new Level("The Prision", 21, 15, "Content/Textures/ground.tga", "Content/Textures/wall.tga", "Content/Textures/ceiling.tga", map);

	return level1;
}
