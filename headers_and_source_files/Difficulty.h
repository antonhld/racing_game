#include <string>
#include "Defines.h"

class Difficulty
{
public:
	Difficulty();
	Difficulty(int iDifficulty);
	int difficultyLevel;
	void increaseDifficulty();
	void inline setDifficulty(int iDifficulty);
	std::string toString();
};

void Difficulty::setDifficulty(int iDifficulty)
{
	difficultyLevel = iDifficulty;
}