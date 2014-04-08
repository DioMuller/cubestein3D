#include "HealthPickup.h"


HealthPickup::HealthPickup(Vector position) : Pickup("Content/Textures/pickup_health.png", position)
{
	tag = "HealthPickup";
}


HealthPickup::~HealthPickup()
{
}
