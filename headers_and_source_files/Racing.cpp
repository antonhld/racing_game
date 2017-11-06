
#include "racing.h"


Racing::Racing() 
	: distance_(0),
	speed_(SPEED_DISPLAY - MIN_SPEED_NORMAL),
	minSpeed_(MIN_SPEED_NORMAL),
	difficulty_(NORMAL),
	startTime_(clock()),
	startScreen_("Racing", vector<string>{"Start", "Exit"}),
	difficultyScreen_("Difficulty", vector<string>{"Easy", "Normal", "Hard"}),
	endScreen_("GAME OVER", vector<string>{"Restart", "Exit"})
{}
Racing::Racing(int difficulty)
	: distance_(0),
	difficulty_(difficulty),
	startTime_(clock()),
	startScreen_("Racing", vector<string>{"Start", "Difficulty", "Exit"}),
	difficultyScreen_("Difficulty", vector<string>{"Easy", "Normal", "Hard"}),
	endScreen_("GAME OVER", vector<string>{"Restart", "Exit"})
{
	switch (difficulty)
	{
		case EASY:
		{
			speed_ = SPEED_DISPLAY - MIN_SPEED_EASY;
			minSpeed_ = MIN_SPEED_EASY;
		}break;
		case NORMAL:
		{
			speed_ = SPEED_DISPLAY - MIN_SPEED_NORMAL;
			minSpeed_ = MIN_SPEED_NORMAL;
		}break;
		case HARD:
		{
			speed_ = SPEED_DISPLAY - MIN_SPEED_HARD;
			minSpeed_ = MIN_SPEED_HARD;
			obstacle_ = Obstacle(OBSTACLE_CAR);
		}break;
	}
}
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

	string roadMark = string(LANE_LENGTH, '-');
	cout<<roadMark<<'\n';

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

	cout<<'\n' << roadMark << '\n';

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

	cout<<'\n' << roadMark << '\n';
	
	cout<<"   Speed: "<< SPEED_DISPLAY -speed_<<"   Time: "<<getTime()<<"   Distance: "<<distance_<<"   Points: "<<calculatePoints()<<"   \n";
}
int Racing::getTime()
{
	return (clock()-startTime_)/TIME_TO_SECONDS;
}
int Racing::calculatePoints()
{
	return (distance_/((clock()-startTime_)/TIME_TO_SECONDS + 1));
}
bool Racing::detectHit()
{
	if(playerCar_.getLane() == obstacle_.getLane() && obstacle_.getPosition() <= CAR_LENGTH + CAR_POSITION)
		return true;
	return false;
}
void Racing::play()
{
	bool exitCode = true;
	bool newGame = true;

	int menuCode = startScreen_.Show();
	switch (menuCode)
	{
		case MENU_START:
			difficulty_.setDifficulty(difficultyScreen_.Show());
			break;
		case MENU_EXIT:
			return;
		default:
			break;
	}
	
	while (exitCode)
	{
		if (newGame == true)
		{
			new(this) Racing(difficulty_.difficultyLevel);
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
			exitCode = !(endScreen_.Show());
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
			exitCode = !(endScreen_.Show());
			if (exitCode == true)
				newGame = true;
		}

		//increase obstacle_ position or create a new obstacle_ if the previous one is out of view
		obstacle_.decrementPosition();

		distance_ += SPEED_DISPLAY - speed_;
		if (obstacle_.identifier == OBSTACLE_BLOCK)
			Sleep(speed_);
		else if(obstacle_.identifier == OBSTACLE_CAR)
			Sleep(speed_/3);
	}
}