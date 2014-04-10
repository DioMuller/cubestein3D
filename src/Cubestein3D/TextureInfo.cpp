#include "TextureInfo.h"
#include "GameManager.h"

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

TextureInfo::TextureInfo(std::string filename, bool repeat) : TextureInfo()
{
	if (repeat) LoadRepeatingTexture(filename);
	else  LoadTexture(filename);
}

TextureInfo::TextureInfo(std::string filename) : TextureInfo(filename, false) { }

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

void TextureInfo::LoadTexture(std::string filename)
{
	id = GameManager::GetTextureLoader()->LoadTexture(filename.c_str(), false);
}

void TextureInfo::LoadRepeatingTexture(std::string filename)
{
	id = GameManager::GetTextureLoader()->LoadTexture(filename.c_str(), true);
}

void TextureInfo::LoadTexture(std::string filename, float* map, int mapSize, Vector offset)
{
	this->offset = offset;
	this->map = new float[mapSize];
	memcpy(this->map, map, sizeof(float)* mapSize);
	this->mapSize = mapSize;
	LoadTexture(filename);

	this->doubleOffset = offset.x * 2;
}