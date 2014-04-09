#include "EnemySoldier.h"
#include "EnemyBehavior.h"
#include "Log.h"
#include "GameManager.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
EnemySoldier::EnemySoldier(Vector position) : Character("Content/Textures/enemy.png", position)
{
	EnemyBehavior* walking = new EnemyBehavior(this);
	AddBehavior((Behavior*)walking);

	tag = "Enemy";

	isDead = false;

	attackSound = GameManager::GetAudioPlayer()->LoadSFX("Content/Sound/enemy.wav");
	dieSound = GameManager::GetAudioPlayer()->LoadSFX("Content/Sound/enemy_die.wav");
}


EnemySoldier::~EnemySoldier()
{

}

void EnemySoldier::CollideWith(Entity* other)
{
	Character::CollideWith(other);

	if (other->tag == "Shot")
	{
		other->Destroy();
		Die();
	}
	else if (other->tag == "Player")
	{
		Log::Message("Enemy hit a player");
	}
}

void EnemySoldier::Die()
{
	if (isDead) return;

	ClearBehaviors();
	Vector direction = GetDirection();

	size = Vector(size.x, size.z / 2.0f, size.y);

	GameManager::GetAudioPlayer()->PlaySFX(dieSound);

	// Hard coded for now, change later if i have time...
	rotation.x = 270.0f;
	rotation.y = 0.0f;
	position.y = -1.25f;

	isDead = true;
}