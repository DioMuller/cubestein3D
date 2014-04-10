#include "Shot.h"
#include "Parameters.h"
#include "ShotBehavior.h"
#include "GameManager.h"


////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
Shot::Shot(Vector position, Vector direction) : Entity()
{
	this->position = position;
	this->rotation = Vector( 0, 0, 0);
	this->size = Vector(SHOT_SIZE, SHOT_SIZE, SHOT_SIZE);

	ShotBehavior* shot = new ShotBehavior(this, direction);
	AddBehavior((Behavior*)shot);

	this->tag = "Shot";
}

Shot::~Shot()
{
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void Shot::Render(long delta, Renderer* renderer)
{
	Entity::Render(delta, renderer);

	if (SHOWDEBUG)
	{
		renderer->DrawSphere(position, size);
	}
}