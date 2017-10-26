
#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>

#define LEFT  0
#define RIGHT 1
#define uint unsigned int

//move the cursor to write over previous data
//and avoid blinking of console screen
void clearscreen();

class Racing
{
private:
	int playerSide_, obstaclePos_, obstacleSide_, speed_, distance_;
	uint startTime_;
	char field_[25][25];

public:
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
	void renderField();
	void showField();
	bool showStartScreen();
	bool showEndScreen();
	//check if the car collides with an obstacle
	bool detectHit();
	//default constructor
	Racing();
};
