#include "Window.h"
#include "Input.h"
#include <time.h>
#include "texture.h"
#include "Log.h"
#include "AudioPlayer.h"

////////////////////////////////////////
// Static Attributes
////////////////////////////////////////
Window* Window::instance = nullptr;

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Window::Window(std::string title, int width, int height, int bpp)
{
	instance = this;

	this->title = title;
	this->width = width;
	this->height = height;
	this->bpp = bpp;
	this->limitFps = true;

	SetFPS(60);

	InitializeSDL();

	renderer = new Renderer();
	audio = new AudioPlayer();
	textureLoader = new TextureLoader();

	this->titleScreen = new ImageScreen("Content/Textures/title.png");
	this->howToPlayScreen = new ImageScreen("Content/Textures/loading.png");
	this->gameOverScreen = new ImageScreen("Content/Textures/gameover.png");
	this->endingScreen = new ImageScreen("Content/Textures/gameover.png");

	currentState = STATE_TITLE;
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

				if (Input::input[BUTTON_QUIT]) return 0;
		
				switch (currentState)
				{
					case STATE_TITLE:
						if (!titleScreen->Update(delta))
						{
							currentState = STATE_PLAYING;

							this->game = new GameManager(this);

							game->AddLevel("Content/Levels/E1M1.xml");
							game->AddLevel("Content/Levels/E1M2.xml");
							game->AddLevel("Content/Levels/E1M3.xml");
							game->AddLevel("Content/Levels/E1M4.xml");
							game->InitializeCamera(60.0f, width, height, 1.0f, 800.0f);

							game->NextLevel();
						}
						titleScreen->Render(delta, renderer);
						break;
					case STATE_PLAYING:
						if (game != nullptr)
						{
							if (!game->Update(delta))
							{
								currentState = STATE_TITLE;
								delete game;
							}
							game->Render(delta);
						}
						break;
					default:
						break;
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
	waitingTime = round(1000.0f / (float)fps);
}

int Window::GetFPS()
{
	return fps;
}

GameManager* Window::GetGame()
{
	return this->game;
}

Renderer* Window::GetRenderer()
{
	return instance->renderer;
}

AudioPlayer* Window::GetAudioPlayer()
{
	return instance->audio;
}

TextureLoader* Window::GetTextureLoader()
{
	return instance->textureLoader;
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
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, this->bpp);

	return flags;
}