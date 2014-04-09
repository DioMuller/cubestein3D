#include "EndLevel.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
EndLevel::EndLevel(Vector position) : Entity()
{
	this->position = position;
	this->tag = "EndLevel";
}


EndLevel::~EndLevel()
{
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void EndLevel::Render(long delta, Renderer* renderer)
{
	renderer->DrawCube(position, size, rotation);
}