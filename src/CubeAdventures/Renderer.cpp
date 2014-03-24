#include "Renderer.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

////////////////////////////////////////
// Renderer Methods
////////////////////////////////////////
void Renderer::Begin()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::End()
{
	SDL_GL_SwapBuffers();
}

////////////////////////////////////////
// Drawing Methods
////////////////////////////////////////
void Renderer::DrawCube(float size)
{
	glutSolidCube(size);
}