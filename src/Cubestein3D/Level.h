#pragma once
#include "TextureInfo.h"
#include "Entity.h"

// Level Scale
#define SCALE 4
#define COLLISION_ERROR Vector(0.9f, 0, 0.9f)

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
		int** collision;
		std::list<Entity*> entities;
		Vector start, end, scaledStart, scaledEnd;
		// Object size scale.
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
		bool CollidesWithLevel(Vector position, Vector size);
	private:
		void LoadLevel(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, char** map);
		void ProcessMap();
};

