#include "Window.h"
#include "TestEntity.h"
#include "TestEntity2.h"

int main(int argc, char **argv)
{
	Window* window = new Window("Cube Game", 800, 600, 0);
	GameManager* game = new GameManager();

	TestEntity* ent = new TestEntity();
	game->AddEntity(ent);

	TestEntity2* ent2 = new TestEntity2();
	game->AddEntity(ent2);

	window->SetGame(game);
	window->Run();

	return 0;
}



