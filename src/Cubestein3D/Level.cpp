#include "Level.h"
#include "Player.h"
#include "GameManager.h"
#include "EnemySoldier.h"
#include "Parameters.h"
#include "Log.h"
#include <sstream>

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Level::Level()
{
	entities = std::vector<Entity*>();
	toRemove = std::vector<Entity*>();
}

Level::Level(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, std::string ceilingTexture, std::string decorationTexture, char** map) : Level()
{
	LoadLevel(name, width, height, groundTexture, wallTexture, ceilingTexture, decorationTexture, map);
}

Level::~Level()
{
}

////////////////////////////////////////
// Life Cycle Methods
////////////////////////////////////////

void Level::Update(long delta)
{
	int i, j;
	int count = entities.size();
	
	for (i = 0; i < count; i++)
	{
		entities[i]->Update(delta);
		
		for (j = i + 1; j < count; j++)
		{
			entities[i]->CheckCollision(entities[j]);
		}
	}

	// Remove the ones marked for removing after this update
	while (toRemove.size() != 0)
	{
		Entity* removed = toRemove[toRemove.size() - 1];
		toRemove.pop_back();

		std::vector<Entity*>::iterator position = std::find(entities.begin(), entities.end(), removed);
		if (position != entities.end()) entities.erase(position);

		try
		{
			if (removed != nullptr)
			{
				delete removed;
				removed = nullptr;
			}
		}
		catch (...)
		{
			Log::Error("Could not delete Entity: It probably was removed before.");
		}
	}
}

void Level::Render(long delta, Renderer* renderer)
{
	int i, j;
	renderer->DrawPlane(scaledStart, scaledEnd, groundTexture);

	renderer->DrawPlane(ceilingStart, ceilingEnd, ceilingTexture);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			switch (map[i][j])
			{
				case 'W':
					renderer->DrawWall(Vector((start.x + j) *  SCALE, 0, (start.z + i) * SCALE), scale, TEXTURE_WALL_REPETITIONS, wallTexture);
					break;
				case 'P':
					renderer->DrawWall(Vector((start.x + j) *  SCALE, 0, (start.z + i) * SCALE), scale, TEXTURE_PAINTING_REPETITIONS, decorationTexture);
					break;
			}
		}
	}

	for (Entity* entity : entities)
	{
		entity->Render(delta, renderer);
	}

	// Debug Info
	if (SHOWDEBUG)
	{
		std::ostringstream str;
		str << "Entities: " << entities.size() << "; To Remove: " << toRemove.size() << "; FPS: " << 1000 / delta;
		std::string entitiesText(str.str());
		renderer->DrawDebug(Vector(DEBUGPOSITION_X, DEBUGPOSITION_Y, 1.0f), 1, 1, 0, entitiesText);
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
	if (std::find(toRemove.begin(), toRemove.end(), entity) == toRemove.end()) // Member not on vector
		toRemove.push_back(entity);
}

void Level::ClearEntities()
{
	entities.clear();
}

////////////////////////////////////////
// Loading Methods
////////////////////////////////////////
void Level::LoadLevel(std::string name, int width, int height, std::string groundTexture, std::string wallTexture, std::string ceilingTexture, std::string decorationTexture, char** map)
{
	this->name = name;
	this->width = width;
	this->height = height;
	this->groundTexture = new TextureInfo(groundTexture, true);
	this->wallTexture = new TextureInfo(wallTexture, true);
	this->ceilingTexture = new TextureInfo(ceilingTexture, true);
	this->decorationTexture = new TextureInfo(decorationTexture, false);
	this->map = map;

	this->start = Vector(-(float)(width / 2), -1.5f, -(float)(height / 2));
	this->end = Vector((float)(width / 2), -1.5f, (float)(height / 2));
	this->scaledStart = Vector(start.x * SCALE, start.y,  start.z * SCALE);
	this->scaledEnd = Vector(end.x * SCALE, end.y, end.z * SCALE);

	this->ceilingStart = Vector(scaledStart.x, scale.y + 1.5f, scaledStart.z);
	this->ceilingEnd = Vector(scaledEnd.x, scale.y + 1.5f, scaledEnd.z);

	this->scale = Vector(0.5f * SCALE, 1.5f, 0.5f * SCALE);

	ProcessMap();
}

void Level::ProcessMap()
{
	int i, j;
	Camera* camera = GameManager::GetInstance()->GetCamera();
	Player* player = nullptr;
	EnemySoldier* enemy = nullptr;

	collision = new int*[height];
	for (i = 0; i < height; i++) collision[i] = new int[width];

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			switch (map[i][j])
			{
				case 'W':
				case 'P':
					collision[i][j] = 1;
					break;
				case 'S':
					player = new Player(Vector((start.x + j) * SCALE, CHARACTER_Y, (start.z + i) * SCALE));
					AddEntity((Entity*)player);
					camera->FollowEntity((Entity*)player);
					collision[i][j] = 0;
					break;
				case 'E':
					enemy = new EnemySoldier(Vector((start.x + j) * SCALE, CHARACTER_Y, (start.z + i) * SCALE));
					AddEntity((Entity*)enemy);
					collision[i][j] = 0;
				default:
					collision[i][j] = 0;
					break;
			}
		}
	}
}

////////////////////////////////////////
// Collision Methods
////////////////////////////////////////
bool Level::CollidesWithLevel(Vector position, Vector size)
{
	// Better results and easier to undersand than changing
	// between trunc and ceil, depending on condition.
	Vector min = position - (size / 2.0f) - COLLISION_ERROR;
	Vector max = position + (size / 2.0f) + COLLISION_ERROR;

	int minX = (int) round((min.x - (start.x * SCALE)) / SCALE);
	int minZ = (int) round((min.z - (start.z * SCALE)) / SCALE);
	int maxX = (int) round((max.x - (start.x * SCALE)) / SCALE);
	int maxZ = (int) round((max.z - (start.z * SCALE)) / SCALE);

	if (minX < 0 || minZ < 0 || maxX >= width || maxZ >= height) return true;

	if (collision[minZ][minX] == 1 ||
		collision[minZ][maxX] == 1 ||
		collision[maxZ][minX] == 1 ||
		collision[maxZ][maxX] == 1 )
	{
		return true;
	}

	return false;
}