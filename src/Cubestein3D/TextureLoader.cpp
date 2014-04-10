#include "TextureLoader.h"
#include "texture.h"

TextureLoader::TextureLoader()
{
	Initialize();
}


TextureLoader::~TextureLoader()
{
	// TODO: Unload textures?
}

void TextureLoader::Initialize()
{
	textureBank = std::vector<unsigned int>();
	loadedTextures = std::vector<std::string>();
}

unsigned int TextureLoader::LoadTexture(std::string texture, bool repeating, bool invert)
{
	for (int i = 0; i < loadedTextures.size(); i++)
	{
		if (loadedTextures[i] == texture) return textureBank[i];
	}

	unsigned int id = -1;

	setupTexture(texture.c_str(), &id, repeating ? GL_REPEAT : GL_CLAMP_TO_EDGE, invert);
	loadedTextures.push_back(texture);
	textureBank.push_back(id);

	return id;
}