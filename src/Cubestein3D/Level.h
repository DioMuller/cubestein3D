#pragma once
#include "TextureInfo.h"
#include "Entity.h"
#include "Player.h"
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
		TextureInfo* decorationTexture;
		char** map;
		int** collision;
		std::vector<Entity*> entities;
		std::vector<Entity*> toRemove;
		Vector start, end, scaledStart, scaledEnd;
		Vector ceilingStart, ceilingEnd;
		// Object size scale.
		Vector scale;
		// The Player
		Player* player;

		std::string enemyTexture;
		std::string enemyAttackSound;
		std::string enemyDeathSound;

		Vector namePosition;

	////////////////////////////////////////
	// Constructors/Destructors
	////////////////////////////////////////
	public:
		//Level();
		Level(std::string path);
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
		Player* GetPlayer();
		std::string GetEnemyTexture();
		std::string GetEnemyAttackSound();
		std::string GetEnemyDeathSound();
	private:
		void LoadFromXML(std::string path);
		void LoadLevel(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, std::string ceilingTexture, std::string decorationTexture, std::string music, std::string enemyTexture, std::string enemyAttackSound, std::string enemyDeathSound, char** map);
		void ProcessMap();
};

