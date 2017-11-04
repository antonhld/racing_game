#include <string>
#include "Defines.h"

class Difficulty
{
public:
	Difficulty();
	Difficulty(int iDifficulty);
	int difficultyLevel;
	void increaseDifficulty();
	std::string toString();
};