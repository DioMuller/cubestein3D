#pragma once
#include "Entity.h"

class Shot : Entity
{
	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Shot(Vector position, Vector direction);
		~Shot();
};

