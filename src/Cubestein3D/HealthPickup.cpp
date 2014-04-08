#include "HealthPickup.h"


HealthPickup::HealthPickup(Vector position) : Pickup("Content/Textures/pickup_health.png", "Content/Sound/pickup_health.wav", position)
{
	tag = "HealthPickup";
}


HealthPickup::~HealthPickup()
{
}
