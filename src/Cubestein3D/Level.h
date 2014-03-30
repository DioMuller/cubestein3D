#pragma once
#include "TextureInfo.h"
#include "Entity.h"

class Level
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		std::string name;
		int width;
		int height;
		TextureInfo* wallTexture;
		TextureInfo* groundTexture;
		char** map;
		std::list<Entity*> entities;
		Vector start, end;
		Vector scale;

	////////////////////////////////////////
	// Constructors/Destructors
	////////////////////////////////////////
	public:
		Level();
		Level(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, char** map);
		~Level();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		virtual void Update(long delta);
		virtual void Render(long delta, Renderer* renderer);

		void AddEntity(Entity* entity);
		void RemoveEntity(Entity* entity);
		void ClearEntities();
	private:
		void LoadLevel(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, char** map);
		void ProcessMap();
};

