#include "ScorePickup.h"


ScorePickup::ScorePickup(Vector position) : Pickup("Content/Textures/pickup_points.png", position)
{
	tag = "ScorePickup";
}


ScorePickup::~ScorePickup()
{
}
