
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <Windows.h>

#define LEFT  0
#define RIGHT 1
#define LANE_LENGTH 75
#define LANE_WIDTH 9
#define CAR_WIDTH 22
#define OBSTACLE_LENGTH 5
#define MIN_SPEED 20
#define MAX_SPEED 150
#define SPEED_INC 20
#define SPACE ' '
#define uint unsigned int

using namespace std;
using namespace System;

class Racing
{
private:
	int playerSide_, obstaclePos_, obstacleSide_, speed_, distance_;
	uint startTime_;

public:
	//default constructor
	Racing();
	//move the car to the left
	void moveLeft();
	//move the car to the right
	void moveRight();
	//move the obstacle down the road
	void increaseObstaclePos();
	void increaseSpeed();
	void decreaseSpeed();
	int getSpeed();
	//subtract pause time from whole time
	void addTimeOnPause(uint amount);
	void increaseDistance(int amount);
	void showField();
	int getTime();
	int calculatePoints();
	bool showStartScreen();
	bool showEndScreen();
	//check if the car collides with an obstacle
	bool detectHit();
};
