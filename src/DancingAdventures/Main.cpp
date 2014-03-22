#include "Window.h"

int main(int argc, char **argv)
{
	Window* window = new Window("Cube Game", 800, 600, 0);
	window->Run();

	return 0;
}



