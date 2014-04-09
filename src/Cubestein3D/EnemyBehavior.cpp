#include "EnemyBehavior.h"
#include "Entity.h"
#include "GameManager.h"
#include "Parameters.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
EnemyBehavior::EnemyBehavior(Entity* parent) : Behavior(parent)
{
	this->parent->rotation.y = (rand() % 4) * 90.0f;
	this->maxDistance = (float) 1.0f + (rand() % 5);

	this->walked = 0.0f;
	this->target = GameManager::GetCurrentLevel()->GetPlayer();
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

	float distance = parent->position.DistanceSquared(target->position);

	if (distance > ATTACK_DISTANCE)
	{
		float speed = delta * ENEMY_SPEED;
		Vector newPosition = parent->position + (parent->GetDirection() * speed);

		walked += speed;

		if (walked > maxDistance)
		{
			this->parent->rotation.y = (float)(((int) this->parent->rotation.y + 180) % 360);
			walked = 0.0f;
		}
		else if (GameManager::GetCurrentLevel()->CollidesWithLevel(newPosition, parent->size))
		{
			this->parent->rotation.y = (float)(((int) this->parent->rotation.y + 90) % 360);
			walked = 0.0f;
		}
		else
		{
			parent->position = newPosition;
		}
	}
	else
	{
		// Test
		parent->position.y += 0.01;
	}
}