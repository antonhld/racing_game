#include "Obstacle.h"

Obstacle::Obstacle() : RoadObject(LEFT, LANE_LENGTH - OBSTACLE_LENGTH, OBSTACLE_LENGTH)
{
	model_ = {  "#####",
				"#####",
				"#####",
				"#####",
				"#####",
				"#####",
				"#####",
				"#####",
				"#####" };
}
void Obstacle::decrementPosition()
{
	position_--;
	if (position_ <= 0)
	{
		position_ = LANE_LENGTH - OBSTACLE_LENGTH;
		lane_ = rand() % 2;
	}
}