#include "Window.h"
#include <time.h>


////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Window::Window(std::string title, int width, int height, int bpp)
{
	this->title = title;
	this->width = width;
	this->height = height;
	this->bpp = bpp;

	this->game = nullptr;

	SetFPS(60);
}


Window::~Window()
{
}

////////////////////////////////////////
// Public Methods
////////////////////////////////////////
int Window::Run()
{
	InitializeSDL();
	//SDL_Event event;

	long delta = waitingTime;

	do
	{
		clock_t start = clock();
		
		if (game != nullptr)
		{
			game->Update(delta);
			game->Render(delta);
		}

		clock_t end = clock();

		delta = ((end - start) * 1000) / CLOCKS_PER_SEC ;
		long sleeptime = waitingTime - delta;
		if (sleeptime > 0) Sleep(sleeptime);
	} while (1);

	return 0;
}

void Window::SetFPS(int value)
{
	fps = value;
	waitingTime = 1000 / (float)fps;
}

int Window::GetFPS()
{
	return fps;
}

void Window::SetGame(GameManager* game)
{
	this->game = game;
}

GameManager* Window::GetGame()
{
	return this->game;
}

////////////////////////////////////////
// Private Methods
////////////////////////////////////////
void Window::InitializeSDL()
{
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);

	SDL_Surface* janela = SDL_SetVideoMode(width, height, bpp, SetupOpenGL());
	SDL_WM_SetCaption(title.c_str(), NULL);

	glClearColor(0.0, 0.0, 0.0, 1);
}


int Window::SetupOpenGL(void)
{
	int flags = SDL_OPENGL | SDL_HWPALETTE | SDL_RESIZABLE;

	const SDL_VideoInfo* info = SDL_GetVideoInfo();

	if (info->hw_available)
		flags |= SDL_HWSURFACE;
	else
		flags |= SDL_SWSURFACE;

	if (info->blit_hw)
		flags |= SDL_HWACCEL;

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return flags;
}