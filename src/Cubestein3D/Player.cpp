#include "Player.h"


Player::Player()
{
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
	Entity::Render(delta, renderer);
}