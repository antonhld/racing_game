#include "RoadObject.h"

class Obstacle : public RoadObject
{
public:
	Obstacle();
	void decrementPosition();
};