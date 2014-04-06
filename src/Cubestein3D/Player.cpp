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

	// Initialize GUI
	guiBorder = new TextureInfo("Content/Textures/border.png");
	guiIconHealth = new TextureInfo("Content/Textures/icon_health.png");
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

	// Draw GUI
	renderer->DrawTexture(Vector(0, BORDER_HEIGHT, 0.9f), Vector(SCREEN_WIDTH, 0, 0.9f), guiBorder);
	renderer->DrawTexture(ICON_HEALTH_START, ICON_HEALTH_END, guiIconHealth);
	renderer->DrawString(HEALTH_OFFSET, 1.0f, 1.0f, 1.0f, healthText);
}

void Player::CollideWith(Entity* other)
{
	Character::CollideWith(other);

	if (other->tag == "Enemy")
	{
		health--;
	}
}