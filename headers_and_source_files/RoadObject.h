#ifndef ROADOBJECT_H
#define ROADOBJECT_H

#include <string>
#include <array>
#include "Defines.h"

class RoadObject
{
public:
	virtual ~RoadObject();
	virtual std::string getModelLine(int lineIndex);
	const inline int getLane();
	const inline int getPosition();
	const inline int getLength();
protected:
	RoadObject(int iLane, int iPosition, int iLentgh);
	int lane_;
	int position_;
	int length_;
	std::array<std::string, LANE_WIDTH> model_;
};

const int RoadObject::getLane()
{
	return lane_;
}
const int RoadObject::getPosition()
{
	return position_;
}
const int RoadObject::getLength()
{
	return length_;
}

#endif