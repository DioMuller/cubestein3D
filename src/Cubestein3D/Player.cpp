#include "Player.h"
#include "ControllableBehavior.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Player::Player(Vector position) : Character("Textures/Spiderman.png", position)
{
	ControllableBehavior* control = new ControllableBehavior(this);

	AddBehavior((Behavior*)control);

	health = 100;
}


Player::~Player()
{
}