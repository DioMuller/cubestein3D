#include "Window.h"


////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Window::Window(std::string title, int width, int height, int bpp)
{
	this->title = title;
	this->width = width;
	this->height = height;
	this->bpp = bpp;
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

	SDL_Event event;

	do
	{
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) return 1;
				break;
			case SDL_QUIT:
				return 2;
			}
		}

		Render();

	} while (1);

	return 0;
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
	int flags = SDL_OPENGL;
	flags |= SDL_HWPALETTE;
	flags |= SDL_RESIZABLE;

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


void Window::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutWireCube(0.8);
	SDL_GL_SwapBuffers();
}