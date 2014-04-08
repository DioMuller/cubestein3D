#include "ScorePickup.h"


ScorePickup::ScorePickup(Vector position) : Pickup("Content/Textures/pickup_points.png","Content/Sound/pickup_points.wav", position)
{
	tag = "ScorePickup";
}


ScorePickup::~ScorePickup()
{
}
