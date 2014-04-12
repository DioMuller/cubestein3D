#include "EndLevel.h"
#include "Parameters.h"

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
EndLevel::EndLevel(Vector position) : Entity()
{
	this->position = position;
	this->tag = "EndLevel";
	this->size = Vector(SCALE / 1.5f, SCALE, SCALE / 1.5f);
	textPosition = this->position + FINISH_OFFSET;
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
	renderer->DrawString3D(textPosition, 0, 1, 1, 1, "EXIT");
}