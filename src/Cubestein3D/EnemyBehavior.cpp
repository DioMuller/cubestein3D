#include "EnemyBehavior.h"
#include "Entity.h"
#include "GameManager.h"
#include "Parameters.h"
#include <math.h>

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
EnemyBehavior::EnemyBehavior(Entity* parent) : Behavior(parent)
{
	this->parent->rotation.y = (rand() % 4) * 90.0f;

	this->target = nullptr;

	this->attackSound = GameManager::GetAudioPlayer()->LoadSFX("Content/Sound/enemy.wav");

	this->nowAttacking = false;
}


EnemyBehavior::~EnemyBehavior()
{
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void EnemyBehavior::Update(long delta)
{
	if (target == nullptr)
	{
		this->target = GameManager::GetCurrentLevel()->GetPlayer();
	}
	else
	{	
		float distance = parent->position.DistanceSquared(target->position);
		float speed = delta * ENEMY_SPEED;

		Vector newPosition;
		Vector direction;

		if (distance > ATTACK_DISTANCE)
		{
			direction = parent->GetDirection();
			if (nowAttacking) nowAttacking = false;
		}
		else
		{
			direction = target->position - parent->position;
			direction.y = 0.0f;
			direction.normalize();
			parent->rotation.y = direction.Angle();

			if (!nowAttacking)
			{
				nowAttacking = true;
				GameManager::GetAudioPlayer()->PlaySFX(attackSound);
			}
		}

		newPosition = parent->position + (direction * speed);

		if ( GameManager::GetCurrentLevel()->CollidesWithLevel(newPosition, parent->size))
		{
			this->parent->rotation.y = (float)(((int) this->parent->rotation.y + 90) % 360);
		}
		else
		{
			parent->position = newPosition;
		}
	}
}