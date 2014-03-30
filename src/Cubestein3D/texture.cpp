#include "SDL/SDL_image.h"

#include "texture.h"

#include "glext.h"

//
//Função swap
//Objetivo: troca conteúdo de variáveis
//
void swap(unsigned char &a, unsigned char &b)
{
	unsigned char aux;

	aux = a;
	a = b;
	b = aux;
}


//
//Função loadTexture
//Objetivo: lê uma textura, inverte-a e retorna superfície
//
SDL_Surface *loadTextureExt(const char *filename, bool inverte)
{
	int i;

	//Superfície
	SDL_Surface *image, *aux;

	//Lê vários tipos de formatos
	aux = IMG_Load(filename);

	//Converte para formato atual
	if (aux->format->BytesPerPixel == 4)
		image = SDL_DisplayFormatAlpha(aux);
	else
		image = SDL_DisplayFormat(aux);

	//Libera superfície auxiliar
	SDL_FreeSurface(aux);

	//Largura e altura da imagem
	int width = image->w;
	int height = image->h;

	//Dados da imagem
	unsigned char *data = (unsigned char *)(image->pixels);

	//Formato da imagem
	int bytesPixel = image->format->BytesPerPixel;

	if (inverte)
	{
		//Se é TGA, não precisa de inversão
		//if (strstr(filename, "tga") == NULL)
		{

			//Troca pixels
			for (i = 0; i < (height / 2); i++)
			for (int j = 0; j < image->pitch; j += bytesPixel)
			for (int k = 0; k < bytesPixel; k++)
				swap(data[(i * width * bytesPixel) + j + k], data[((height - i - 1) * width * bytesPixel) + j + k]);
		}
	}

	//16 bit color não precisa de inversão
	if (image->format->BytesPerPixel == 2)
		return image;

	//Corrige cores RGB -> BGR
	unsigned char *pixels = new unsigned char[width*height*bytesPixel]; 	//Nova superfície
	int cont = 0;		//Caminha na superfície
	byte r, g, b, alpha;		    //Cor original
	Uint32 pixelValue;  //Valor do pixel

	for (i = 0; i < (width*height); i++)
	{
		pixelValue = 0;

		for (int j = bytesPixel - 1; j >= 0; j--)
		{
			pixelValue <<= 8;
			pixelValue |= data[(i * bytesPixel) + j];
		}

		switch (bytesPixel)
		{
		case 2:
		case 3:
			//Pega componentes
			SDL_GetRGB(pixelValue, image->format, (Uint8 *)&r, (Uint8 *)&g, (Uint8 *)&b);
			break;

		case 4:
			SDL_GetRGBA(pixelValue, image->format, (Uint8 *)&r, (Uint8 *)&g, (Uint8 *)&b, (Uint8 *)&alpha);
			break;
		}

		//Coloca na nova imagem
		if (bytesPixel >= 3)
		{
			pixels[cont++] = r;
			pixels[cont++] = g;
			pixels[cont++] = b;
			if (bytesPixel == 4)
				pixels[cont++] = alpha;
		}
		else
		if (bytesPixel == 2)
		{
			//pixels[cont] = r << image->format->Rshift + g << image->format->Gshift + b << image->format->Gshift;
			Uint8 rx = r << (image->format->Rshift - 8);
			Uint8 gx = g >> image->format->Gshift;
			Uint8 cx = rx + gx;
			pixels[cont++] = cx;
			gx = g << image->format->Gshift;
			cx = gx + b;
			pixels[cont++] = cx;
		}

	}

	//Refaz ligação
	image->pixels = pixels;

	//Retorna imagem alterada
	return image;

}


//
//Função setupTexture
//Objetivo: configura textura
//
void setupTexture(const char *filename, GLuint *texture, GLuint flags, GLboolean mipmap, bool inverte)
{
	//Textura
	SDL_Surface *image;

	//Lê textura
	image = loadTexture(filename, inverte);

	//Cria textura
	glGenTextures(1, &texture[0]);

	//Configura textura atual
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	//Cálculo linear quando a textura estiver bem perto
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Verifica se deve ser gerado mipmap
	if (mipmap)
	{
		//Configura parâmetros de cálculo de textura para minímo: linear, nearest
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

		//Gera texturas
		switch (image->format->BytesPerPixel)
		{
		case 2:
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, image->w, image->h, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, image->pixels);
			break;

		case 3:
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, image->w, image->h, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
			break;

		case 4:
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, image->w, image->h, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
			break;

		}

	}
	else
	{
		//Cria textura
		switch (image->format->BytesPerPixel)
		{
		case 2:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, image->pixels);
			break;

		case 3:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
			break;

		case 4:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
			break;
		}

		//Configura parâmetros de cálculo de textura para minímo: linear
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	}

	//Ativa parâmetros de desenho
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, flags);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, flags);

}



//
//Função loadTexture
//Objetivo: lê uma textura, inverte-a e retorna superfície
//
SDL_Surface *loadTexture(const char *filename, bool inverte)
{
	int i;

	//Superfície
	SDL_Surface *image;

	//Lê vários tipos de formatos
	image = IMG_Load(filename);

	//Largura e altura da imagem
	int width = image->w;
	int height = image->h;

	//Dados da imagem
	unsigned char *data = (unsigned char *)(image->pixels);

	//Formato da imagem
	int bytesPixel = image->format->BytesPerPixel;

	if (inverte)
	{
		//Troca pixels
		for (i = 0; i < (height / 2); i++)
		for (int j = 0; j < image->pitch; j += bytesPixel)
		for (int k = 0; k < bytesPixel; k++)
			swap(data[(i * width * bytesPixel) + j + k], data[((height - i - 1) * width * bytesPixel) + j + k]);
	}

	//Corrige cores RGB -> BGR
	unsigned char *pixels = new unsigned char[width*height*bytesPixel]; 	//Nova superfície
	int cont = 0;		//Caminha na superfície
	byte r, g, b, alpha;		    //Cor original
	Uint32 pixelValue;  //Valor do pixel

	for (i = 0; i < (width*height); i++)
	{
		pixelValue = 0;

		for (int j = bytesPixel - 1; j >= 0; j--)
		{
			pixelValue <<= 8;
			pixelValue |= data[(i * bytesPixel) + j];
		}

		switch (bytesPixel)
		{
		case 3:
			//Pega componentes
			SDL_GetRGB(pixelValue, image->format, (Uint8 *)&r, (Uint8 *)&g, (Uint8 *)&b);
			break;

		case 4:
			SDL_GetRGBA(pixelValue, image->format, (Uint8 *)&r, (Uint8 *)&g, (Uint8 *)&b, (Uint8 *)&alpha);
			break;
		}

		//Coloca na nova imagem
		if (bytesPixel >= 3)
		{
			pixels[cont++] = r;
			pixels[cont++] = g;
			pixels[cont++] = b;
			if (bytesPixel == 4)
				pixels[cont++] = alpha;
		}
	}

	//Refaz ligação
	image->pixels = pixels;

	//Retorna imagem alterada
	return image;

}
