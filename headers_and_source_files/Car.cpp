#include "Car.h"

Car::Car() : RoadObject(RIGHT, CAR_POSITION, CAR_LENGTH)
{
	model_ = {  "*****     *****     ",
				"*****     *****     ",
				"*****     *****     ",
				"     *****     *****",
				"     *****     *****",
				"     *****     *****",
				"*****     *****     ",
				"*****     *****     ",
				"*****     *****     " };
}
void Car::moveLeft()
{
	lane_ = LEFT;
}
void Car::moveRight()
{
	lane_ = RIGHT;
}