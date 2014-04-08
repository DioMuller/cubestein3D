#pragma once
#include "Pickup.h"
class HealthPickup : public Pickup
{
	public:
		HealthPickup(Vector position);
		~HealthPickup();
};

