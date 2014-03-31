#include "Window.h"
#include "TestEntity.h"
#include "TestEntity2.h"

Level* LoadLevel();

int main(int argc, char **argv)
{
	Window* window = new Window("Cube Game", 800, 600, 0);
	GameManager* game = new GameManager();

	/*TODO: READ FROM XML*/
	Level* level1 = LoadLevel();
	game->LoadLevel(level1);

	window->SetGame(game);
	window->Run();

	return 0;
}


Level* LoadLevel()
{
	char** map = new char*[15];
	map[0] =  "WWWWWWWWWWWWWWWWWWWWW";
	map[1] =  "WWGGEGGWWWWGGGGGGGGWW";
	map[2] =  "WWGGGGGWWWWGGGGGGGGWW";
	map[3] =  "WWGGGGGWWWWGGGGGWGGWW";
	map[4] =  "WWWWGWWWWWWWWWWWWGWWW";
	map[5] =  "WWWWGWWWWWWWWWWWWGWWW";
	map[6] =  "WWWWGWWGGGGGWWWWWGWWW";
	map[7] =  "WWWWGWWGGGGGGGGGGGWWW";
	map[8] =  "WWWWGWWGGGGGWWWWWGWWW";
	map[9] =  "WWWWGWWGGGGGWWWWWGWWW";
	map[10] = "WWWWGGGGGGGGWWWWWGWWW";
	map[11] = "WWWWWWWWWWWWWWWWWGWWW";
	map[12] = "WWWWWWWWWWWWWWGGGGGSW";
	map[13] = "WWWWWWWWWWWWWWGWWGWWW";
	map[14] = "WWWWWWWWWWWWWWWWWWWWW";

	Level* level1 = new Level("The Prision", 20, 15, "Textures/ground.png", "Textures/wall.png", map);

	return level1;
}
