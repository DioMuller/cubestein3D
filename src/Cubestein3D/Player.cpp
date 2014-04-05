#include "Player.h"
#include "ControllableBehavior.h"

Player::Player(Vector position) : Character("Textures/Spiderman.png", position)
{
	ControllableBehavior* control = new ControllableBehavior(this);

	AddBehavior((Behavior*)control);
}


Player::~Player()
{
}