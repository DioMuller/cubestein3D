#include "TextureInfo.h"
#include "Window.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
TextureInfo::TextureInfo()
{
	this->map = nullptr;
	this->mapSize = 0;
	this->offset = Vector(); 
	this->doubleOffset = 0;
}

TextureInfo::TextureInfo(std::string filename, bool repeat, bool invert) : TextureInfo()
{
	if (repeat) LoadRepeatingTexture(filename, invert);
	else  LoadTexture(filename, invert);
}

TextureInfo::TextureInfo(std::string filename) : TextureInfo(filename, false, true) { }

TextureInfo::TextureInfo(std::string filename, float* map, int mapSize) : TextureInfo(filename)
{
	this->map = map;
	this->mapSize = mapSize;
}

TextureInfo::TextureInfo(std::string filename, float* map, int mapSize, Vector offset) : TextureInfo(filename, map, mapSize)
{
	this->offset = offset;
	this->doubleOffset = offset.x * 2;
}

TextureInfo::~TextureInfo()
{
	delete map;
}

////////////////////////////////////////
// Methods
////////////////////////////////////////

void TextureInfo::LoadTexture(std::string filename, bool invert)
{
	id = Window::GetTextureLoader()->LoadTexture(filename.c_str(), false, invert);
}

void TextureInfo::LoadRepeatingTexture(std::string filename, bool invert)
{
	id = Window::GetTextureLoader()->LoadTexture(filename.c_str(), true, invert);
}

void TextureInfo::LoadTexture(std::string filename, float* map, int mapSize, Vector offset, bool invert)
{
	this->offset = offset;
	this->map = new float[mapSize];
	memcpy(this->map, map, sizeof(float)* mapSize);
	this->mapSize = mapSize;
	LoadTexture(filename, invert);

	this->doubleOffset = offset.x * 2;
}