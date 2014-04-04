#pragma once

#include <string>
#include "Vector.h"
#include "texture.h"

// Helper class for some textures. Will contain an id, offsets, map...
// Not every render will use those attributes.
class TextureInfo
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	public:
		unsigned int id;
		float* map;
		int mapSize;
		Vector offset;
		float doubleOffset;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		TextureInfo();
		TextureInfo(std::string filename);
		TextureInfo(std::string filename, float* map, int mapSize);
		TextureInfo(std::string filename, float* map, int mapSize, Vector offset);
		~TextureInfo();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void LoadTexture(std::string filename);
		void LoadTexture(std::string filename, float* map, int mapSize, Vector offset);
};