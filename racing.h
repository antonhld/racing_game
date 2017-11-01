
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include "defines.h"

using namespace std;

class RoadObject
{
public:
	virtual string getModelLine(int lineIndex);
	virtual inline int getLane();
	virtual inline int getPosition();
	virtual inline int getLength();
protected:
	RoadObject(int iLane, int iPosition, int iLentgh);
	int lane_;
	int position_;
	int length_;
	string* model_;
};

class Car : public RoadObject
{
public:
	Car();
	void moveLeft();
	void moveRight();
};

class Obstacle : public RoadObject
{
public:
	Obstacle();
	void decrementPosition();
};

class Difficulty
{
public:
	Difficulty();
	Difficulty(int iDifficulty);
	int difficultyLevel;
	void increaseDifficulty();
	string toString();
};

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
