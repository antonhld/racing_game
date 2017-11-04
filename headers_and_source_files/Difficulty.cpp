#include "Difficulty.h"


Difficulty::Difficulty()
	: difficultyLevel(NORMAL)
{}
Difficulty::Difficulty(int iDifficulty)
	: difficultyLevel(iDifficulty)
{}
void Difficulty::increaseDifficulty()
{
	if (difficultyLevel < HARD)
		difficultyLevel++;
	else
		difficultyLevel = EASY;
}
std::string Difficulty::toString()
{
	switch (difficultyLevel)
	{
	case EASY:
		return "Easy";
		break;
	case NORMAL:
		return "Normal";
		break;
	case HARD:
		return "Hard";
		break;
	}
	return "";
}