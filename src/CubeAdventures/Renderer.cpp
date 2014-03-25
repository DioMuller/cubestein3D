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
void Renderer::DrawCube(Vector3 position, Vector3 scale, Vector3 rotation)
{
	glPushMatrix();

	// TODO: Use Matrix.
	glTranslatef(position.x, position.y, position.z);
	glScalef(scale.x, scale.y, scale.z);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glutWireCube(1);

	glPopMatrix();
}