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
void Renderer::DrawCube(Vector position, Vector scale, Vector rotation)
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

void Renderer::DrawTexturedCube(Vector position, Vector scale, Vector rotation, TextureInfo* texture)
{
	/*
	glEnable(GL_LIGHTING);

	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHT0);

	glEnable(GL_CULL_FACE);

	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glScalef(scale.x, scale.y, scale.z);

	glPushMatrix();
	glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);

	glBindTexture(GL_TEXTURE_2D, texture->id);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	// Front Face
	glNormal3d(0, 0, 1);
	glTexCoord2f(texture->map[0], texture->map[1]); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(texture->map[2], texture->map[3]); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(texture->map[4], texture->map[5]); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(texture->map[6], texture->map[7]); glVertex3f(-1.0f, 1.0f, 1.0f);

	// Back Face
	glNormal3d(0, 0, -1);
	glTexCoord2f(texture->map[0] - texture->doubleOffset, texture->map[1]); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(texture->map[2] - texture->doubleOffset, texture->map[3]); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(texture->map[4] - texture->doubleOffset, texture->map[5]); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(texture->map[6] - texture->doubleOffset, texture->map[7]); glVertex3f(1.0f, 1.0f, -1.0f);

	// Top Face
	glNormal3d(0, 1, 0);
	glTexCoord2f(texture->map[0], texture->map[1] + texture->offset.y); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(texture->map[2], texture->map[3] + texture->offset.y); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(texture->map[4], texture->map[5] + texture->offset.y); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(texture->map[6], texture->map[7] + texture->offset.y); glVertex3f(-1.0f, 1.0f, -1.0f);

	// Bottom Face
	glNormal3d(0, -1, 0);
	glTexCoord2f(texture->map[0], texture->map[1] - texture->offset.y); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(texture->map[2], texture->map[3] - texture->offset.y); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(texture->map[4], texture->map[5] - texture->offset.y); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(texture->map[6], texture->map[7] - texture->offset.y); glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right face
	glNormal3d(1, 0, 0);
	glTexCoord2f(texture->map[0] + texture->offset.x, texture->map[1]); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(texture->map[2] + texture->offset.x, texture->map[3]); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(texture->map[4] + texture->offset.x, texture->map[5]); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(texture->map[6] + texture->offset.x, texture->map[7]); glVertex3f(1.0f, 1.0f, 1.0f);

	// Left Face
	glNormal3d(-1, 0, 0);
	glTexCoord2f(texture->map[0] - texture->offset.x, texture->map[1]); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(texture->map[2] - texture->offset.x, texture->map[3]); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(texture->map[4] - texture->offset.x, texture->map[5]); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(texture->map[6] - texture->offset.x, texture->map[7]); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPopMatrix();
	glDisable(GL_CULL_FACE);

	glDisable(GL_LIGHT0);

	glDisable(GL_LIGHTING);
	*/

	glPushMatrix();

	// TODO: Use Matrix.
	glTranslatef(position.x, position.y, position.z);
	glScalef(scale.x, scale.y, scale.z);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D, texture->id);
	glutSolidCube(1);
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);

	glPopMatrix();
}