#include "Player.h"
#include "ControllableBehavior.h"
#include "Parameters.h"
#include "StringHelper.h"
#include "GameManager.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Player::Player(Vector position) : Character("Content/Textures/Spiderman.png", position)
{
	ControllableBehavior* control = new ControllableBehavior(this);

	AddBehavior((Behavior*)control);

	tag = "Player";
	health = 100;
	ammo = 100;
	kills = 0;
	points = 0;

	// Initialize GUI
	guiBorder = new TextureInfo("Content/Textures/border.png");
	guiIconHealth = new TextureInfo("Content/Textures/icon_health.png");
	guiIconAmmo = new TextureInfo("Content/Textures/icon_ammo.png");
	guiIconKills = new TextureInfo("Content/Textures/icon_kills.png");
	guiIconPoints = new TextureInfo("Content/Textures/icon_points.png");

	// Initialize sound
	sfxShoot = GameManager::GetAudioPlayer()->LoadSFX("Content/Sound/shoot.wav");
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
	
	//////////////
	// Draw GUI
	//////////////

	// Border
	renderer->DrawTexture(Vector(0, BORDER_HEIGHT, 0.9f), Vector(SCREEN_WIDTH, 0, 0.9f), guiBorder);

	// Health
	renderer->DrawTexture(ICON_HEALTH_START, ICON_HEALTH_END, guiIconHealth);
	renderer->DrawString(HEALTH_OFFSET, 1.0f, 1.0f, 1.0f, IntToString(health));

	// Ammo
	renderer->DrawTexture(ICON_AMMO_START, ICON_AMMO_END, guiIconAmmo);
	renderer->DrawString(AMMO_OFFSET, 1.0f, 1.0f, 1.0f, IntToString(ammo));

	// Kills
	renderer->DrawTexture(ICON_KILLS_START, ICON_KILLS_END, guiIconKills);
	renderer->DrawString(KILLS_OFFSET, 1.0f, 1.0f, 1.0f, IntToString(kills));

	// Points
	renderer->DrawTexture(ICON_POINTS_START, ICON_POINTS_END, guiIconPoints);
	renderer->DrawString(POINTS_OFFSET, 1.0f, 1.0f, 1.0f, IntToString(points));

	renderer->DrawCrosshair();
}

void Player::CollideWith(Entity* other)
{
	Character::CollideWith(other);

	if (other->tag == "Enemy")
	{
		health--;
	}
}

void Player::AddKill()
{
	kills++;
	points += 100;
}

bool Player::Shoot()
{
	if (ammo <= 0) return false;

	ammo--;
	GameManager::GetAudioPlayer()->PlaySFX(sfxShoot);

	return true;
}