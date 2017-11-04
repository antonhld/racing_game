#include "Obstacle.h"

Obstacle::Obstacle() : RoadObject(LEFT, LANE_LENGTH - OBSTACLE_LENGTH, OBSTACLE_LENGTH)
{
	identifier = OBSTACLE_BLOCK;
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
Obstacle::Obstacle(int obstacleIdentifier) : RoadObject(LEFT, LANE_LENGTH - OBSTACLE_LENGTH, OBSTACLE_LENGTH)
{
	identifier = obstacleIdentifier;
	if(identifier == OBSTACLE_BLOCK)
		model_ = {  "#####",
					"#####",
					"#####",
					"#####",
					"#####",
					"#####",
					"#####",
					"#####",
					"#####" };
	else if(identifier == OBSTACLE_CAR)
	{
		model_ = {  "     *****     *****",
					"     *****     *****",
					"     *****     *****",
					"*****     *****     ",
					"*****     *****     ",
					"*****     *****     ",
					"     *****     *****", 
					"     *****     *****", 
					"     *****     *****"};
		position_ = LANE_LENGTH - CAR_LENGTH;
		length_ = CAR_LENGTH;
	}
}
void Obstacle::decrementPosition()
{
	position_--;
	if (position_ <= 0)
	{
		position_ = LANE_LENGTH - length_;
		lane_ = rand() % 2;
	}
}