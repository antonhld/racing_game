#include "RoadObject.h"

std::string RoadObject::getModelLine(int lineIndex)
{
	if (lineIndex < 0 || lineIndex > LANE_WIDTH)
		return "";
	return model_[lineIndex];
}

RoadObject::RoadObject(int iLane, int iPosition, int iLentgh)
	: lane_(iLane),
	position_(iPosition),
	length_(iLentgh)
{}
RoadObject::~RoadObject()
{}
