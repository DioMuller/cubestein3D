#ifndef __TEXTURE_H__
#define __TEXTURE_H__

//Include windows
#ifdef WIN32
#include <windows.h>
#endif


//Inclui funções OpenGL
#include <GL/gl.h>
#include <GL/glu.h>

//Inclui SDL
#include "SDL/SDL.h"

//Constante Opengl 1.2
#define GL_CLAMP_TO_EDGE	0x812F



//troca conteúdo de variáveis
void swap(unsigned char &a, unsigned char &b);

//Faz a leitura do arquivo
SDL_Surface *loadTexture(const char *filename, bool inverte = true);

//Faz a leitura do arquivo (Requer GLU 1.3 para mipmap 16 bit color)
SDL_Surface *loadTextureExt(const char *filename, bool inverte = true);

//Configura textura
void setupTexture(const char *filename, GLuint *texture, GLuint flags = GL_CLAMP_TO_EDGE, GLboolean mipmap = false, bool inverte = true);

#endif