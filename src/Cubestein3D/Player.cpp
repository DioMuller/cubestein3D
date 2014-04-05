#include "Player.h"
#include "ControllableBehavior.h"
#include <iostream>

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Player::Player(Vector position) : Character("Textures/Spiderman.png", position)
{
	ControllableBehavior* control = new ControllableBehavior(this);

	AddBehavior((Behavior*)control);

	tag = "Player";
	health = 100;
}


Player::~Player()
{
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void Player::CollideWith(Entity* other)
{
	std::cout << "Collided with: " << other->tag << std::endl;
	
	if (other->tag == "Enemy")
	{
		health--;
	}
}