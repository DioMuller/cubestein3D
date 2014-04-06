#include "EnemySoldier.h"
#include "WalkingBehavior.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
EnemySoldier::EnemySoldier(Vector position) : Character("Content/Textures/Domo.png", position)
{
	WalkingBehavior* walking = new WalkingBehavior(this);
	AddBehavior((Behavior*)walking);

	tag = "Enemy";
}


EnemySoldier::~EnemySoldier()
{

}