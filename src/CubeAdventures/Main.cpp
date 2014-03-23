#include "Window.h"
#include "TestEntity.h"

int main(int argc, char **argv)
{
	Window* window = new Window("Cube Game", 800, 600, 0);
	GameManager* game = new GameManager();

	TestEntity* ent = new TestEntity();
	game->AddEntity(ent);

	window->SetGame(game);
	window->Run();

	return 0;
}



