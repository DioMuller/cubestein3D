#include "AmmoPickup.h"


AmmoPickup::AmmoPickup(Vector position) : Pickup("Content/Textures/pickup_ammo.png", "Content/Sound/pickup_ammo.wav", position)
{
	tag = "AmmoPickup";
}


AmmoPickup::~AmmoPickup()
{
}
