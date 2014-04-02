#include "Player.h"
#include "ControllableBehavior.h"

Player::Player(Vector position)
{
	float* map = new float[8];
	map[0] = 0.547;
	map[1] = 0.515;
	map[2] = 0.751;
	map[3] = 0.515;
	map[4] = 0.751;
	map[5] = 0.694;
	map[6] = 0.547;
	map[7] = 0.694;

	Vector offset = Vector(0.202, 0.202, 0);
	texture = new TextureInfo("Textures/Spiderman.png", map, 8, offset);

	this->scale = Vector(0.5, 0.5, 0.5);

	this->position = position;

	ControllableBehavior* control = new ControllableBehavior(this);

	AddBehavior((Behavior*)control);
}


Player::~Player()
{
}

void Player::Update(long delta)
{
	Entity::Update(delta);
}

void Player::Render(long delta, Renderer* renderer)
{
	renderer->DrawTexturedCube(position, scale, rotation, texture);
	Entity::Render(delta, renderer);
}