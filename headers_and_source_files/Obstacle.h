#include "RoadObject.h"

class Obstacle : public RoadObject
{
public:
	Obstacle();
	Obstacle(int obstacleIdentifier);
	void decrementPosition();
	int identifier;
};