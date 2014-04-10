#pragma once
#include <vector>
#include "TextureInfo.h"

class TextureLoader
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	public: 
		std::vector<unsigned int> textureBank;
		std::vector<std::string> loadedTextures;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		TextureLoader();
		~TextureLoader();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		// Initialization
		void Initialize();

		unsigned int LoadTexture(std::string texture, bool repeating, bool invert);
};

