#pragma once
#include "TextureInfo.h"
#include "Entity.h"
#include <vector>

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
		TextureInfo* ceilingTexture;
		char** map;
		int** collision;
		std::vector<Entity*> entities;
		std::vector<Entity*> toRemove;
		Vector start, end, scaledStart, scaledEnd;
		Vector ceilingStart, ceilingEnd;
		// Object size scale.
		Vector scale;

	////////////////////////////////////////
	// Constructors/Destructors
	////////////////////////////////////////
	public:
		Level();
		Level(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, std::string ceilingTexture, char** map);
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
		bool CollidesWithLevel(Vector position, Vector size);
	private:
		void LoadLevel(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, std::string ceilingTexture, char** map);
		void ProcessMap();
};

