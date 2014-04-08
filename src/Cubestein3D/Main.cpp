#include "Window.h"
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
	/*****************************************
	* Descriptions:							 *
	* W = Wall								 *
	* G = Ground							 *
	* S = Player Start						 *
	* F = Level Ending						 *
	* E = Enemy								 *
	* P = Decoration						 *
	* H = Hidden Passage					 *
	* M = Medkit							 *
	* T = Treasure							 *
	* A = Ammo								 *
	******************************************/
	char** map = new char*[15];
	map[0] =  "WWWWWWWWWWWWWWWWWWWWW";
	map[1] =  "WWGGFGGWWWWGGGGGGGGWW";
	map[2] =  "WWGGEGGWWWWGGGEGGEGPW";
	map[3] =  "WWGGGGGWWWWGGGGGWGGWW";
	map[4] =  "WWWWGWWWWWWWWWWWWGWWW";
	map[5] =  "WWWWGWWWWWPWWWWWWGWWW";
	map[6] =  "WWWPGWWGGGGGWWWWWGPWW";
	map[7] =  "WWWWGWWGGEGGGGGGGGWWW";
	map[8] =  "WWWWGWPGGAGGWPWWWGWWW";
	map[9] =  "WWWWGWWGGEGGGGGGGGWWW";
	map[10] = "WWWPGGGGGGGGWWWWWGWWW";
	map[11] = "WWWWWWWGWPWWWWWWWGWWW";
	map[12] = "WWWPGGGGGGGWWTGGHGGSW";
	map[13] = "WWWWGGGGGGGWWMAWWGWWW";
	map[14] = "WWWWWWWPWWWWWWWWWWWWW";

	Level* level1 = new Level("The Prision", 21, 15, "Content/Textures/ground.png", "Content/Textures/wall.png", "Content/Textures/ceiling.png", "Content/Textures/painting.png", "Content/Music/level.ogg", map);

	return level1;
}
