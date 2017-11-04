#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Car.h"
#include "Obstacle.h"
#include "Difficulty.h"
using namespace std; 

class Racing
{
public:
	Racing();
	void play();

private:
	int speed_;
	int minSpeed_;
	int distance_;
	Car playerCar_;
	Obstacle obstacle_;
	Difficulty difficulty_;
	uint startTime_;
	void increaseSpeed();
	void decreaseSpeed();
	void addTimeOnPause(uint amount);
	void showField();
	int getTime();
	int calculatePoints();
	bool showStartScreen();
	bool showEndScreen();
	bool detectHit();
};
