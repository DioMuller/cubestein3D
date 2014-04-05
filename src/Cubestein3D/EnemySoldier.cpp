#include "EnemySoldier.h"
#include "WalkingBehavior.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
EnemySoldier::EnemySoldier(Vector position) : Character("Textures/Domo.png", position)
{
	WalkingBehavior* walking = new WalkingBehavior(this);
	AddBehavior((Behavior*)walking);
}


EnemySoldier::~EnemySoldier()
{

}