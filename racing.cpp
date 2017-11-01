
#include "racing.h"


string RoadObject::getModelLine(int lineIndex)
{
	if (lineIndex < 0 || lineIndex > LANE_WIDTH)
		return "";
	return model_[lineIndex];
}
int RoadObject::getLane()
{
	return lane_;
}
int RoadObject::getPosition()
{
	return position_;
}
int RoadObject::getLength()
{
	return length_;
}
RoadObject::RoadObject(int iLane, int iPosition, int iLentgh)
	:	lane_(iLane),
		position_(iPosition),
		length_(iLentgh),
		model_()
{}

Car::Car() : RoadObject(RIGHT, CAR_POSITION, CAR_LENGTH)
{
	model_ = new string[LANE_WIDTH]{"*****     *****     ",
									"*****     *****     ",
									"*****     *****     ",
									"     *****     *****",
									"     *****     *****",
									"     *****     *****",
									"*****     *****     ",
									"*****     *****     ",
									"*****     *****     " };
}
void Car::moveLeft()
{
	lane_ = LEFT;
}
void Car::moveRight()
{
	lane_ = RIGHT;
}

Obstacle::Obstacle() : RoadObject(LEFT, LANE_LENGTH - OBSTACLE_LENGTH, OBSTACLE_LENGTH)
{
	model_ = new string[LANE_WIDTH]{"#####",
									"#####",
									"#####",
									"#####",
									"#####",
									"#####",
									"#####",
									"#####",
									"#####" };
}
void Obstacle::decrementPosition()
{
	position_--;
	if (position_ <= 0)
	{
		position_ = LANE_LENGTH - OBSTACLE_LENGTH;
		lane_     = rand() % 2;
	}
}

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
string Difficulty::toString()
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
}

Racing::Racing() 
	: distance_(0),
	speed_(SPEED_DISPLAY - MIN_SPEED_NORMAL),
	minSpeed_(MIN_SPEED_NORMAL),
	difficulty_(NORMAL),
	startTime_(clock())
{}
void Racing::increaseSpeed()
{
	if(speed_ > SPEED_INC)
		speed_ -= SPEED_INC;
}
void Racing::decreaseSpeed()
{
	if(speed_ < SPEED_DISPLAY - minSpeed_)
		speed_ += SPEED_INC;
}
void Racing::addTimeOnPause(uint amount)
{
	startTime_ += amount;
}
void Racing::showField()
{
	int playerLane    = playerCar_.getLane();
	int playerPos     = playerCar_.getPosition();
	int obstacle_Lane = obstacle_.getLane();
	int obstacle_Pos  = obstacle_.getPosition();

	for(int i=0; i<LANE_LENGTH; i++)
		cout<<'-';
	cout<<'\n';

	for(int i=0; i<LANE_WIDTH; i++)
	{
		string spacing = string(obstacle_Pos, SPACE);
		if(playerLane == LEFT)
			cout<<string(playerPos, SPACE)<<playerCar_.getModelLine(i);
		if(playerLane == obstacle_Lane)
			spacing = string(obstacle_Pos - CAR_LENGTH - CAR_POSITION, SPACE);
		if(obstacle_Lane == LEFT)
			cout<<spacing + obstacle_.getModelLine(i);
		cout<<'\n';
	}

	cout<<'\n';
	for(int i=0; i<LANE_LENGTH; i++)
		cout<<'-';
	cout<<'\n';

	for(int i=0; i<LANE_WIDTH; i++)
	{
		string spacing = string(obstacle_Pos, SPACE);
		if(playerLane == RIGHT)
			cout<<string(playerPos, SPACE)<<playerCar_.getModelLine(i);
		if(playerLane == obstacle_Lane)
			spacing = string(obstacle_Pos - CAR_LENGTH - CAR_POSITION, SPACE);
		if(obstacle_Lane == RIGHT)
			cout<<spacing + obstacle_.getModelLine(i);
		cout<<'\n';
	}

	cout<<'\n';
	for(int i=0; i<LANE_LENGTH; i++)
		cout<<'-';
	cout<<'\n';
	cout<<"   Speed: "<< SPEED_DISPLAY -speed_<<"   Time: "<<getTime()<<"   Distance: "<<distance_<<"   Points: "<<calculatePoints()<<"   \n";
}
int Racing::getTime()
{
	return (clock()-startTime_)/1000;
}
int Racing::calculatePoints()
{
	return (distance_/((clock()-startTime_)/1000 + 1));
}
bool Racing::showStartScreen()
{
	while(true)
	{
		system("cls");
		cout<< "                       \n"
			<< "                       \n"
			<< "        Racing         \n"
			<< "                       \n"
			<< "    Difficulty: " << difficulty_.toString() << '\n'
			<< "                       \n"
			<< "    Press s to start   \n"
			<< "    Press q to exit    \n"
			<< "    Press d to change difficulty\n"
			<< "                       \n"
			<< "                       \n";
		//if 's' is pressed
		if (GetAsyncKeyState(0x53))
			return true;
		//if 'q' is pressed
		if(GetAsyncKeyState(0x51))
			return false;
		//if 'd' is pressed
		if (GetAsyncKeyState(0x44))
		{
			difficulty_.increaseDifficulty();
			switch (difficulty_.difficultyLevel)
			{
			case EASY:
				minSpeed_ = MIN_SPEED_EASY;
				break;
			case NORMAL:
				minSpeed_ = MIN_SPEED_NORMAL;
				break;
			case HARD:
				minSpeed_ = MIN_SPEED_HARD;
				break;
			}
		}
		Sleep(500);
	}
}
bool Racing::showEndScreen()
{
	system("cls");
	cout<<"                       \n"
		<<"                       \n"
		<<"       GAME OVER       \n"
		<<"    Time:"<<getTime()<<"\n"
		<<"    Distance:"<<distance_<<"\n"
		<<"    Points:"<<calculatePoints()<<"\n"
		<<"                       \n"
		<<"    Press q to exit    \n" 
		<<"    Press s to start   \n"
		<<"                       \n"
		<<"                       \n";
	while(true)
	{
		//if 'q' is pressed
		if(GetAsyncKeyState(0x51))
			return false;
		//if 's' is pressed
		if(GetAsyncKeyState(0x53))
			return true;
	}
}
bool Racing::detectHit()
{
	if(playerCar_.getLane() == obstacle_.getLane() && obstacle_.getPosition() <= CAR_LENGTH + CAR_POSITION)
		return true;
	return false;
}
void Racing::play()
{
	bool exitCode;
	bool newGame = true;

	//show start screen
	exitCode = showStartScreen();

	while (exitCode)
	{
		if (newGame == true)
		{
			new(this) Racing();
			newGame = false;
		}

		//clear the screen
		system("cls");
		//output the field to the console
		showField();

		//move the car to the right
		if (GetAsyncKeyState(VK_DOWN))
			playerCar_.moveRight();
		//move the car to the left
		if (GetAsyncKeyState(VK_UP))
			playerCar_.moveLeft();
		//increase speed
		if (GetAsyncKeyState(VK_RIGHT))
			increaseSpeed();
		//decrease speed
		if (GetAsyncKeyState(VK_LEFT))
			decreaseSpeed();
		//manually exit
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			exitCode = showEndScreen();
			if (exitCode == true)
				newGame = true;
		}
		//pause
		if (GetAsyncKeyState(VK_RETURN))
		{
			uint pauseTime = clock();
			system("pause");
			addTimeOnPause(clock() - pauseTime);
		}

		//end the game if car hits the obstacle_
		if (detectHit())
		{
			exitCode = showEndScreen();
			if (exitCode == true)
				newGame = true;
		}

		//increase obstacle_ position or create a new obstacle_ if the previous one is out of view
		obstacle_.decrementPosition();

		distance_ += SPEED_DISPLAY - speed_;
		Sleep(speed_);
	}
}