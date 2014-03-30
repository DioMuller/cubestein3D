#include "Level.h"

Level::Level()
{
	entities = std::list<Entity*>();
}

Level::Level(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, char** map) : Level()
{
	LoadLevel(name, width, height, groundTexture, wallTexture, map);
}

Level::~Level()
{
}

////////////////////////////////////////
// Life Cycle Methods
////////////////////////////////////////

void Level::Update(long delta)
{
	for (Entity* entity : entities)
	{
		entity->Update(delta);
	}
}

void Level::Render(long delta, Renderer* renderer)
{
	int i, j;
	renderer->DrawPlane(start, end, groundTexture);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if( map[i][j] == 'W' ) renderer->DrawWall(Vector(start.x + j, 0, start.z + i), scale, wallTexture);
		}
	}

	for (Entity* entity : entities)
	{
		entity->Render(delta, renderer);
	}
}

////////////////////////////////////////
// Entity Methods
////////////////////////////////////////
void Level::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}

void Level::RemoveEntity(Entity* entity)
{
	entities.remove(entity);
}

void Level::ClearEntities()
{
	entities.clear();
}

////////////////////////////////////////
// Loading Methods
////////////////////////////////////////
void Level::LoadLevel(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, char** map)
{
	this->name = name;
	this->width = width;
	this->height = height;
	this->groundTexture = new TextureInfo(groundTexture);
	this->wallTexture = new TextureInfo(wallTexture);
	this->map = map;

	this->start = Vector(-(float)(width / 2), -2.0f, -(float)(height / 2));
	this->end = Vector((float)(width / 2), -2.0f, (float)(height / 2));

	this->scale = Vector(1.0f, 1.0f, 1.0f);
}

void Level::ProcessMap()
{
	// TODO: Load player and enemies.
}