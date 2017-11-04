#pragma once

#define LEFT  0
#define RIGHT 1
#define LANE_LENGTH 100
#define LANE_WIDTH 9
#define CAR_LENGTH 20
#define CAR_POSITION 10
#define OBSTACLE_LENGTH 5
#define OBSTACLE_BLOCK 0
#define OBSTACLE_CAR 1
#define TIME_TO_SECONDS 1000
namespace speed
{
	#define MIN_SPEED_EASY 80
	#define MIN_SPEED_NORMAL 100
	#define MIN_SPEED_HARD 120
	#define SPEED_INC 10
	#define SPEED_DISPLAY 165
};
namespace difficulty
{
	#define EASY 1
	#define NORMAL 2
	#define HARD 3
};
#define SPACE ' '
#define uint unsigned int