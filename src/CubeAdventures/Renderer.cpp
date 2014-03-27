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

// TEXTURE
GLuint init_texture(std::string path) 
{
	GLuint texture;

	//Load the image from the file into SDL's surface representation
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL) { //If it failed, say why and don't continue loading the texture
		printf("Error: \"%s\"\n", SDL_GetError()); return -1;
	}

	//Generate an array of textures.  We only want one texture (one element array), so trick
	//it by treating "texture" as array of length one.
	glGenTextures(1, &texture);
	//Select (bind) the texture we just generated as the current 2D texture OpenGL is using/modifying.
	//All subsequent changes to OpenGL's texturing state for 2D textures will affect this texture.
	glBindTexture(GL_TEXTURE_2D, texture);
	//Specify the texture's data.  This function is a bit tricky, and it's hard to find helpful documentation.  A summary:
	//   GL_TEXTURE_2D:    The currently bound 2D texture (i.e. the one we just made)
	//               0:    The mipmap level.  0, since we want to update the base level mipmap image (i.e., the image itself,
	//                         not cached smaller copies)
	//         GL_RGBA:    The internal format of the texture.  This is how OpenGL will store the texture internally (kinda)--
	//                         it's essentially the texture's type.
	//      surface->w:    The width of the texture
	//      surface->h:    The height of the texture
	//               0:    The border.  Don't worry about this if you're just starting.
	//          GL_RGB:    The format that the *data* is in--NOT the texture!  Our test image doesn't have an alpha channel,
	//                         so this must be RGB.
	//GL_UNSIGNED_BYTE:    The type the data is in.  In SDL, the data is stored as an array of bytes, with each channel
	//                         getting one byte.  This is fairly typical--it means that the image can store, for each channel,
	//                         any value that fits in one byte (so 0 through 255).  These values are to interpreted as
	//                         *unsigned* values (since 0x00 should be dark and 0xFF shold be bright).
	// surface->pixels:    The actual data.  As above, SDL's array of bytes.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
	//Set the minification and magnification filters.  In this case, when the texture is minified (i.e., the texture's pixels (texels) are
	//*smaller* than the screen pixels you're seeing them on, linearly filter them (i.e. blend them together).  This blends four texels for
	//each sample--which is not very much.  Mipmapping can give better results.  Find a texturing tutorial that discusses these issues
	//further.  Conversely, when the texture is magnified (i.e., the texture's texels are *larger* than the screen pixels you're seeing
	//them on), linearly filter them.  Qualitatively, this causes "blown up" (overmagnified) textures to look blurry instead of blocky.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Unload SDL's copy of the data; we don't need it anymore because OpenGL now stores it in the texture.
	SDL_FreeSurface(surface);

	return texture;
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

void Renderer::InitializeSkybox(std::string left, std::string front, std::string right, std::string back, std::string top, std::string bottom)
{
	skyboxTexture = new GLuint[6];

	/*
	setupTexture(right.c_str(), &skyboxTexture[SKY_RIGHT]);
	setupTexture(left.c_str(), &skyboxTexture[SKY_LEFT]);
	setupTexture(front.c_str(), &skyboxTexture[SKY_FRONT]);
	setupTexture(back.c_str(), &skyboxTexture[SKY_BACK]);
	setupTexture(top.c_str(), &skyboxTexture[SKY_TOP]);
	setupTexture(bottom.c_str(), &skyboxTexture[SKY_BOTTOM]);
	*/
	skyboxTexture[SKY_RIGHT] = init_texture(right.c_str());
	skyboxTexture[SKY_LEFT] = init_texture(left.c_str());
	skyboxTexture[SKY_FRONT] = init_texture(front.c_str());
	skyboxTexture[SKY_BACK] = init_texture(back.c_str());
	skyboxTexture[SKY_TOP] = init_texture(top.c_str());
	skyboxTexture[SKY_BOTTOM] = init_texture(bottom.c_str());
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