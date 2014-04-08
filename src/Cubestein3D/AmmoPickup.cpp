#include "AmmoPickup.h"


AmmoPickup::AmmoPickup(Vector position) : Pickup("Content/Textures/pickup_ammo.png", position)
{
	tag = "AmmoPickup";
}


AmmoPickup::~AmmoPickup()
{
}
