#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Car.h"
#include "Obstacle.h"
#include "Difficulty.h"
#include "MenuScreen.h"
using namespace std; 

class Racing
{
public:
	Racing();
	Racing(int difficulty);
	void play();

private:
	int speed_;
	int minSpeed_;
	int distance_;
	Car playerCar_;
	Obstacle obstacle_;
	Difficulty difficulty_;
	MenuScreen startScreen_;
	MenuScreen endScreen_;
	MenuScreen difficultyScreen_;
	uint startTime_;
	void increaseSpeed();
	void decreaseSpeed();
	void addTimeOnPause(uint amount);
	void showField();
	int getTime();
	int calculatePoints();
	bool detectHit();
};
