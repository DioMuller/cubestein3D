#include "Player.h"
#include "ControllableBehavior.h"
#include "Parameters.h"
#include <sstream>

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Player::Player(Vector position) : Character("Content/Textures/Spiderman.png", position)
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
void Player::Render(long delta, Renderer* renderer)
{
	Character::Render(delta, renderer);
	
	std::ostringstream str;
	str << health;
	std::string healthText(str.str());

	renderer->DrawString(Vector(HEALTH_OFFSET_X, HEALTH_OFFSET_Y, 1.0f), 1.0f, 1.0f, 1.0f, healthText);
}

void Player::CollideWith(Entity* other)
{
	Character::CollideWith(other);

	if (other->tag == "Enemy")
	{
		health--;
	}
}