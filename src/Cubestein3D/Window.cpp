#include "Window.h"
#include "Input.h"
#include <time.h>
#include "texture.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Window::Window(std::string title, int width, int height, int bpp)
{
	this->title = title;
	this->width = width;
	this->height = height;
	this->bpp = bpp;
	this->limitFps = true;

	this->game = nullptr;

	SetFPS(60);

	InitializeSDL();
}


Window::~Window()
{
}

////////////////////////////////////////
// Public Methods
////////////////////////////////////////
int Window::Run()
{
	SDL_Event event;


	long delta = (long) waitingTime;

	do
	{
		clock_t start = clock();

		// SDL EVENTS
		SDL_PollEvent(&event);

		Input::Update(event);

		if (Input::input[QUIT]) return 0;
		
		// GAME UPDATE
		if (game != nullptr)
		{
			game->Update(delta);
			game->Render(delta);
		}

		clock_t end = clock();

		delta = ((end - start) * 1000) / CLOCKS_PER_SEC ;
		long sleeptime = (long) waitingTime - delta;
		if (limitFps)
		{
			if (sleeptime > 0) Sleep(sleeptime);
			delta = max(delta, (long) waitingTime);
		}
		
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
	game->InitializeCamera(45.0f, width, height, 1.0f, 800.0f);
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
	SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_NOPARACHUTE);
	atexit(SDL_Quit);

	SDL_Surface* window = SDL_SetVideoMode(width, height, bpp, SetupOpenGL());
	SDL_WM_SetCaption(title.c_str(), NULL);

	// Removes mouse cursor
	SDL_ShowCursor(SDL_DISABLE);

	//Enables Textures and Depth Tests
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, width, height);
	glClearColor(0.0, 0.5, 0.75, 1);
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
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, SCREENBPP);

	return flags;
}