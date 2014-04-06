#include "EnemySoldier.h"
#include "EnemyBehavior.h"
#include "Log.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
EnemySoldier::EnemySoldier(Vector position) : Character("Content/Textures/Domo.png", position)
{
	EnemyBehavior* walking = new EnemyBehavior(this);
	AddBehavior((Behavior*)walking);

	tag = "Enemy";
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
		Destroy();
	}
	else if (other->tag == "Player")
	{
		Log::Debug("Enemy hit a player");
	}
}