#include "Renderer.h"
#include <SDL/SDL_image.h> 

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void Renderer::End()
{
	SDL_GL_SwapBuffers();
}


////////////////////////////////////////
// Object Methods
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
}

void Renderer::DrawPlane(Vector startPosition, Vector endPosition, TextureInfo* texture)
{
	glBindTexture(GL_TEXTURE_2D, texture->id);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	// This way, it'll probably work for X,Y and X,Z planes.
	glNormal3d(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(startPosition.x, startPosition.y, startPosition.z);
	glTexCoord2f(0, 1); glVertex3f(endPosition.x, startPosition.y, startPosition.z);
	glTexCoord2f(1, 1); glVertex3f(endPosition.x, endPosition.y, endPosition.z);
	glTexCoord2f(1, 0); glVertex3f(startPosition.x, endPosition.y, endPosition.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Renderer::DrawWall(Vector position, Vector size, TextureInfo* texture)
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glScalef(size.x, size.y, size.z);

	glBindTexture(GL_TEXTURE_2D, texture->id);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	// Front Face
	glNormal3d(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(0, 1); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1, 1); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1, 0); glVertex3f(-1.0f, 1.0f, 1.0f);

	// Back Face
	glNormal3d(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0, 1); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1, 1); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1, 0); glVertex3f(1.0f, 1.0f, -1.0f);

	// Top Face
	glNormal3d(0, 1, 0);
	glTexCoord2f(0, 0); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0, 1); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1, 1); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1, 0); glVertex3f(-1.0f, 1.0f, -1.0f);

	// Bottom Face
	glNormal3d(0, -1, 0);
	glTexCoord2f(0, 0); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0, 1); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1, 1); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1, 0); glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right face
	glNormal3d(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0, 1); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1, 1); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1, 0); glVertex3f(1.0f, 1.0f, 1.0f);

	// Left Face
	glNormal3d(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0, 1); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1, 1); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1, 0); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

////////////////////////////////////////
// Camera Methods
////////////////////////////////////////
void Renderer::CameraInitialize(float fov, int width, int height, float zNear, float zFar)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (GLfloat)width / (GLfloat)height, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
}

void Renderer::CameraLookAt(Vector eye, Vector target, Vector up)
{
	gluLookAt(eye.x, eye.y, eye.z,
		target.x, target.y, target.z,
		up.x, up.y, up.z);
}

////////////////////////////////////////
// Skybox methods
////////////////////////////////////////
void Renderer::InitializeSkybox(std::string left, std::string front, std::string right, std::string back, std::string top, std::string bottom)
{
	skyboxTexture = new GLuint[6];

	
	setupTexture(right.c_str(), &skyboxTexture[SKY_RIGHT]);
	setupTexture(left.c_str(), &skyboxTexture[SKY_LEFT]);
	setupTexture(front.c_str(), &skyboxTexture[SKY_FRONT]);
	setupTexture(back.c_str(), &skyboxTexture[SKY_BACK]);
	setupTexture(top.c_str(), &skyboxTexture[SKY_TOP]);
	setupTexture(bottom.c_str(), &skyboxTexture[SKY_BOTTOM]);
}

void Renderer::DrawSkybox(float x, float y, float z, float width, float height, float length)
{
	glColor3f(1.0f, 1.0f, 1.0f);

	// Center Skybox
	x -= width / 2;
	y -= height / 2;
	z -= length / 2;
	

	// Bottom
	glBindTexture(GL_TEXTURE_2D, skyboxTexture[SKY_BOTTOM]);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + width, y, z);
	glEnd();

	// Top
	glBindTexture(GL_TEXTURE_2D, skyboxTexture[SKY_TOP]);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + height, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + width, y + height, z);
	glEnd();

	// Back
	glBindTexture(GL_TEXTURE_2D, skyboxTexture[SKY_BACK]);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y + height, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + width, y, z);
	glEnd();

	// Front
	glBindTexture(GL_TEXTURE_2D, skyboxTexture[SKY_FRONT]);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + width, y, z + length);
	glEnd();

	// Left
	glBindTexture(GL_TEXTURE_2D, skyboxTexture[SKY_LEFT]);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, y, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y + height, z);
	glEnd();

	// Right
	glBindTexture(GL_TEXTURE_2D, skyboxTexture[SKY_RIGHT]);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x + width, y + height, z);
	glEnd();

	// Resets Texture Binding
	glBindTexture(GL_TEXTURE_2D, 0);
}